//
// Created by Hong Man Hou on 11/7/2018.
//

#ifndef VANSIM_GOSSIPAGENT_H
#define VANSIM_GOSSIPAGENT_H
#include "Network.h"

class GossipAgent : public Agent {
public:
    // local congestion table
    int w[MAX_NODE][MAX_NODE];
    // record of timing
    int t[MAX_NODE][MAX_NODE];

    int adj(int i, int j);

    GossipAgent(Network * net, int time): Agent(net, time) {
        memset(w, 0, sizeof(w));
        memset(t, 0, sizeof(t));
    }
    int update(int time);
};


#endif //VANSIM_GOSSIPAGENT_H
