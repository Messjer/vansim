//
// Created by Hong Man Hou on 11/7/2018.
//

#include "Network.h"
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

Network::Network(int n, int x, int y): N(n) {
    // generate city positions
    assert(x * y > n && "bounded region should be larger!")
    vector<int> xx, yy;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        xx[i] = rand() % x;
        yy[i] = rand() % y;
    }

    // compute weights of edges
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = a[j][i] = hypot(abs(xx[i] - xx[j]), abs(yy[i] - yy[j]));

}
Agent* Network::createAgent() {}