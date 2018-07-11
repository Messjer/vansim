//
// Created by Hong Man Hou on 11/7/2018.
//

#include "Network.h"
#include "GossipAgent.h"
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

Network::Network(int n, int x, int y): N(n) {
    // generate city positions
    assert(x * y > n && "bounded region should be larger!");
    vector<int> xx, yy;
    for (int i = 0; i < n; i++) {
        xx.push_back(rand() % x);
        yy.push_back(rand() % y);
    }
    // compute weights of edges
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = a[j][i] = hypot(abs(xx[i] - xx[j]), abs(yy[i] - yy[j]));

}

Agent* Network::createAgent(double rho) {
    Agent *agent;
    if (((double) rand() / (RAND_MAX) < rho))
        agent = new GossipAgent(this);
    else
        agent = new Agent(this);
    return agent;
}