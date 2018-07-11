//
// Created by Hong Man Hou on 11/7/2018.
//

#include "World.h"

using namespace std;

void World::createSimualtion(int n, int x, int y, int duration, int num_a) {
    net = new Network(n, x, y);
    this -> num_a = num_a;
    // assume agents arrival in the first 1/5 of simulation
    // average agent arrival in a step is num
    num = num_a / (0.2 * duration);
    this -> duration = duration;
    time = 0;
}

bool World::step() {
    if (time == duration)
        return false;
    cout <<"hello world" <<endl;
    time++;
    return true;
}

void World::clearSimulation() {
    delete net;
}