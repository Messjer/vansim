//
// Created by Hong Man Hou on 11/7/2018.
//

#include "Network.h"
#include <cassert>
#define INF 1000000000

using namespace std;

int Agent::adj(int i, int j) {
    return net -> a[i][j];
}

void Agent::plan() {
    // dijkstra's algorithm
    src = route[cur];

    int dist[MAX_NODE];
    int back[MAX_NODE];
    bool visited[MAX_NODE];

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < net -> N; i++)
        dist[i] = INF;
    dist[src] = 0;
    back[src] = -1;
    visited[src] = true;

    int now = src;
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
    cur = route.size() - 1;
}