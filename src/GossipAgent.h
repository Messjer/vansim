//
// Created by Hong Man Hou on 11/7/2018.
//

#ifndef VANSIM_GOSSIPAGENT_H
#define VANSIM_GOSSIPAGENT_H
#include "Network.h"

class GossipAgent : public Agent {
private:
    // local congestion table
    bool cong[MAX_NODE][MAX_NODE];
    // record of timing
    unsigned int t[MAX_NODE][MAX_NODE];

    int adj(int i, int j);
public:
    GossipAgent(Network * net): Agent(net) {
        memset(cong, 0, sizeof(cong));
        memset(t, 0, sizeof(t));
    }
};


#endif //VANSIM_GOSSIPAGENT_H
