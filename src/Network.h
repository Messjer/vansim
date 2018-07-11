//
// Created by Hong Man Hou on 11/7/2018.
//

#ifndef VANSIM_NETWORK_H
#define VANSIM_NETWORK_H
#include <string>
#include "Agent.h"
#define MAX_NODE 1000

class Network {
    int N;
    int a[MAX_NODE][MAX_NODE];
public:
    // generate a random network
    // with n vertices and bounded in [0,x], [0,y]
    Network(int n, int x, int y);
    Agent * createAgent();
};


#endif //VANSIM_NETWORK_H
