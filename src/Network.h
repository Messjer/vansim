//
// Created by Hong Man Hou on 11/7/2018.
//

#ifndef VANSIM_NETWORK_H
#define VANSIM_NETWORK_H
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>

#define MAX_NODE 10

class Agent;
class GossipAgent;

// delay factor
const double K = 10;
// capacity factor
const double K2 = 0.1;

class Network {
public:
    // number of nodes
    int N;
    // adjacency matrix
    int a[MAX_NODE][MAX_NODE];

    // current flow and capacity on the edge
    int w[MAX_NODE][MAX_NODE];
    int c[MAX_NODE][MAX_NODE];
    std::deque<GossipAgent *> agents[MAX_NODE][MAX_NODE];

    // generate a random network
    // with n vertices and bounded in [0,x], [0,y]
    Network(int n, int x, int y);
};


class Agent {
public:
    std::vector<int> history;

    // reference to network
    Network *net;

    // source & destination
    int src, dest;

    // planned route and
    // current position in the path
    // where the back of the vector is the next hop
    std::vector<int> route;
    int cur;

    // time to move (used by World::step())
    int ttm, born;

    // a != b means in edge, a == b means in node a
    int a, b;

    // expected travel time based on cong
    virtual int adj(int i, int j);

    Agent(Network *Net, int time): net(Net), ttm(1), born(time) {
        src = rand() % net -> N;
        dest = rand() % net -> N;
        if (dest == src)
            dest = (src + 1) % net -> N;
        cur = a = b = src;
        plan();
    };

    // dijkstra's algorithm
    void plan();

    virtual int update(int time);
};


#endif //VANSIM_NETWORK_H
