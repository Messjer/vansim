//
// Created by Hong Man Hou on 11/7/2018.
//

#include "GossipAgent.h"
#include <cassert>
#include <iostream>

using namespace std;

int GossipAgent::adj(int i, int j) {
    return net ->a[i][j] + K * w[i][j]/net->c[i][j];
}

int GossipAgent::update(int time) {
    if (RANDOM_REAL() < net -> p_reroute)
        plan();

    // if ready to left queue, pop it out
    if (ttm == 1 && a != b) {
        assert(net -> agents[a][b].front() == this);
        net -> agents[a][b].pop_front();
    }

    int code = Agent::update(time);

    // if enter queue, update the global queue
    if (code == 3) {
        w[a][b] = net -> w[a][b];
        t[a][b] = time;
        net -> agents[a][b].push_back(this);
    }

    return code;
}

pair<int, double> GossipAgent::reap(int time) {
    //cout <<"Source is " <<src <<" dest is " <<dest <<endl;
    //cout <<"  Used time " <<(time - born) <<endl;
    // reached destination
    cur = -1;
    return make_pair(1, time - born);
};