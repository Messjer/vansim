//
// Created by Hong Man Hou on 11/7/2018.
//

#include "World.h"
#include <cstdlib>

using namespace std;
// fraction of time to releace agents
const double FRAC = 0.1;

using namespace std;

World::World(const WorldConfig &config) {
    conf = config;
    cnt_gos = cnt_norm = 0;
    ttl_gos = ttl_norm = 0;
    // assume agents arrival in the first 1/10 of simulation
    // average agent arrival in a step is num
    num = max(1.0, conf.num_a / (FRAC * conf.duration));
    time = 0;
    net = new Network(conf.n, conf.x, conf.y, conf.p_reroute, conf.p_gas);
}

bool World::step() {
    if (time == conf.duration || (time > FRAC * conf.duration && agents.empty()))
        return false;

    // add agents during the first 1 / 5 of the simulation
    int to_add = min(num, conf.num_a);
    conf.num_a -= to_add;
    for (int i = 0; i < to_add; i++)
        create();

    // check completed gossips
    int cur_T = time % conf.T;
    for (int i = 0; i < gossips[cur_T].size(); i++)
        gossips[cur_T][i].close();
    gossips[cur_T].clear();

    // recycle complete agents
    for (int i = 0; i < garbage[cur_T].size(); i++)
        delete garbage[cur_T][i];
    garbage[cur_T].clear();

    // update the agents' condition
    // including the queues
    int wa;
    for (auto it = agents.begin(); it != agents.end();) {
        Agent *agn = *it;

        int code;
        if(! (code = agn->update(time)) ) {
            // if has reached dest, remove agent
            // and maintain stats
            it = agents.erase(it);
            reap(agn);
        } else
            it++;
    }

    // introduce gossips
    for (int i = 0; i < net -> N; i++)
        for (int j = 0; j < net -> N; j++) {
            const deque<GossipAgent *> &edge = net -> agents[i][j];
            if (edge.size() > 1) {
                for (int a = 0; a < edge.size(); a++)
                    for (int b = a + 1; b < edge.size(); b++)
                        if (RANDOM_REAL() < conf.p_com) {
                            GossipSession gs(edge[a], edge[b], j);
                            gossips[time % conf.T].push_back(gs);
                        }
            }
        }

    time++;
    return true;
}

void World::create() {
    // gossip or not?
    cnt++;
    Agent * agn;
    if ((RANDOM_REAL() < conf.rho)) {
        agn = new GossipAgent(net, time);
        //cout <<"I am gossiping" <<endl;
        if (agn -> src == 55)
            exit(1100);
    }
    else
        agn = new Agent(net, time);

    agents.push_back(agn);
}

void World::reap(Agent *agn) {
    pair<int, double> ret = agn -> reap(time);
    if (ret.first) {
        ttl_gos += ret.second;
        cnt_gos++;
    } else {
        ttl_norm += ret.second;
        cnt_norm++;
    }
    // push into garbage for recycle
    garbage[time % conf.T].push_back(agn);
}

World::~World() {
    printStats();
    delete net;
}

void World::printStats() {
    cout <<"Gossip Agents :";
    cout <<"Total number : " <<cnt_gos <<endl;
    cout <<"Avg time : " <<ttl_gos / cnt_gos <<endl;
    cout <<"Normal Agents :";
    cout <<"Total number : "<<cnt_norm <<endl;
    cout <<"Avg time : " <<ttl_norm / cnt_norm <<endl;
}