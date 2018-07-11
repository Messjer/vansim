//
// Created by Hong Man Hou on 11/7/2018.
//

#ifndef VANSIM_WORLD_H
#define VANSIM_WORLD_H
#include "GossipSession.h"
#include <vector>
#include "Network.h"
#include <iostream>
#define MAX_COM_TIME 100

using namespace std;

class World {
private:
    vector<GossipSession> gossips[MAX_COM_TIME];
    Network *net;
    int num_a, num;
    int duration;
    int time;
public:
    World() {};
    void createSimualtion(int n, int x, int y, int duration, int Num_a);
    // a single step in simulation
    // return 0 on completion
    bool step();
    void printStats();
    void clearSimulation();
};


#endif //VANSIM_WORLD_H
