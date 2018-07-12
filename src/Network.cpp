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
#define MIN_CAP 5.0

using namespace std;

Network::Network(int n, int x, int y, double P, double Q): N(n), p_reroute(P), p_gas(Q) {
    // generate city positions
    assert(x * y > n && "bounded region should be larger!");
    vector<int> xx, yy;
    for (int i = 0; i < n; i++) {
        is_station[i] = RANDOM_REAL() < Q;
        xx.push_back(rand() % x);
        yy.push_back(rand() % y);
    }
    // compute weights of edges
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            // random road length
            a[i][j] = a[j][i] = (0.5 + 0.5 * RANDOM_REAL()) * hypot(abs(xx[i] - xx[j]), abs(yy[i] - yy[j]));
            //a[i][j] = a[j][i] = rand() % 100;
            c[i][j] = c[i][j] = max(MIN_CAP, K2 * a[i][j]);
        }

}