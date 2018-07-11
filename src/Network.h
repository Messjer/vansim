//
// Created by Hong Man Hou on 11/7/2018.
//

#ifndef VANSIM_NETWORK_H
#define VANSIM_NETWORK_H
#include <string>
#include <vector>

#define MAX_NODE 1000

class Agent;

class Network {
public:
    // number of nodes
    int N;
    // adjacency matrix
    int a[MAX_NODE][MAX_NODE];

    // generate a random network
    // with n vertices and bounded in [0,x], [0,y]
    Network(int n, int x, int y);
    Agent *createAgent(double p_rho);
};


class Agent {
public:
    // reference to network
    Network *net;

    // source & destination
    int src, dest;

    // planned route and
    // current position in the path
    // where the back of the vector is the next hop
    std::vector<int> route;
    int cur;

    // expected travel time based on cong
    virtual int adj(int i, int j);

    Agent(Network *Net): net(Net) {};

    // dijkstra's algorithm
    void plan();
};


#endif //VANSIM_NETWORK_H
