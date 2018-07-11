//
// Created by Hong Man Hou on 11/7/2018.
//

#include "World.h"

using namespace std;

World::World(const WorldConfig &config) {
    conf = config;
    // assume agents arrival in the first 1/5 of simulation
    // average agent arrival in a step is num
    num = max(1.0, conf.num_a / (0.2 * conf.duration));
    time = 0;
    net = new Network(conf.n, conf.x, conf.y);
}

bool World::step() {
    if (time == conf.duration || time > 0.2 * conf.duration && agents.empty())
        return false;

    conf.rho = 0;

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

    // update the agents' condition
    // including the queues
    for (auto it = agents.begin(); it != agents.end();) {
        Agent *agn = *it;
        if(! (agn->update(time)) ) {
            // if has reached dest, remove agent
            // and maintain stats
            it = agents.erase(it);
            reap(agn);
        } else
            it++;
    }

    // introduce gossips

    time++;
    return true;
}

Agent *World::create() {
    // gossip or not?
    cnt++;
    Agent * agn;
    if ((randReal() < conf.rho))
        agn = new GossipAgent(net, time);
    else
        agn = new Agent(net, time);

    agents.push_back(agn);
}

void World::reap(Agent *agn) {
    cout <<"Source is " <<agn->src <<" dest is " <<agn->dest <<endl;
    cout <<--cnt <<"  Used time " <<(time - agn -> born) <<endl;
    cout <<"The history is ";
    for (int i = 0; i < agn -> history.size() ;i++)
        cout << agn -> history[i] <<"  ";
    cout <<endl;
    delete(agn);
}

World::~World() {
    printStats();
    delete net;
}

void World::printStats() {

}