//
// Created by Hong Man Hou on 11/7/2018.
//

#ifndef VANSIM_WORLD_H
#define VANSIM_WORLD_H
#include "GossipSession.h"
#include <vector>
#include "Network.h"
#include <set>
#include <iostream>
#include <list>
#define MAX_COM_TIME 100


struct WorldConfig {
    double p_com, p_reroute, p_gas, rho;
    int n, x, y, T, duration, num_a;
};

class World {
private:
    std::vector<GossipSession> gossips[MAX_COM_TIME];
    std::list<Agent*> agents;
    Network *net;
    WorldConfig conf;
    int cnt;
    int num, time;

    void reap(Agent *agn);
    Agent* create();
    double randReal() {
        return (double) rand() / (RAND_MAX);
    }
public:
    World(const WorldConfig &config);
    ~World();

    // a single step in simulation
    // return 0 on completion
    bool step();

    void printStats();
};


#endif //VANSIM_WORLD_H
