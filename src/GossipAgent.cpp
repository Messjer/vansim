//
// Created by Hong Man Hou on 11/7/2018.
//

#include "GossipAgent.h"

int GossipAgent::adj(int i, int j) {
    return net ->a[i][j] + K * w[i][j]/net->c[i][j];
}

int GossipAgent::update(int time) {
    // if ready to left queue, pop it out
    if (time == 1 && a != b)
        net -> agents[a][b].pop_front();

    int code = Agent::update(time);

    // if enter queue, update the global queue
    if (code == 3) {
        w[a][b] = net -> w[a][b];
        t[a][b] = time;
        net -> agents[a][b].push_back(this);
    }
}