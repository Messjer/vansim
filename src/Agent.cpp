//
// Created by Hong Man Hou on 11/7/2018.
//

#include "Network.h"
#include <iostream>
#include <cassert>
#define INF 1000000000

static int dist[MAX_NODE];
static int back[MAX_NODE];
static bool visited[MAX_NODE];

using namespace std;

int Agent::adj(int i, int j) {
    return net -> a[i][j];
}

void Agent::plan() {
    // dijkstra's algorithm

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < net -> N; i++)
        dist[i] = INF;
    dist[cur] = 0;
    back[cur] = -1;
    visited[cur] = true;

    int now = cur;
    while (now != dest) {
        visited[now] = true;
        for (int j = 0; j < net -> N; j++)
            if (dist[j] > dist[now] + adj(now, j)) {
                dist[j] = dist[now] + adj(now, j);
                back[j] = now;
            }

        now = -1;
        int best = INF;
        for (int i = 0; i < net -> N; i++)
            if (!visited[i] && dist[i] < best) {
                best = dist[i];
                now = i;
            }

        assert(now != -1);
    }

    route.clear();
    now = dest;
    while (now != -1) {
        route.push_back(now);
        now = back[now];
    }

    // if current on a node
    if (cur == a) {
        route.pop_back();
        cur = route.back();
    }
}

int Agent::update(int time) {
    //history.push_back(a);
    if (--ttm == 0) {
        if (a != b) {
            net -> w[a][b]--;

            // if agent has reached destination
            if (b == dest)
                return 0;

            // move to the node
            ttm = 1;
            a = b;
            route.pop_back();
            cur = route.back();
            return 1;
        } else {
            // currently on node a == b

            // if next edge is full
            // wait at the same node
            if (net -> c[a][cur] == net -> w[a][cur]) {
                ttm = 1;
                return 2;
            }

            b = cur;
            ttm = net -> a[a][b] + K * net -> w[a][b] / net -> c[a][b];
            net -> w[a][b]++;
            return 3;
        }
    }
    return 1;
}