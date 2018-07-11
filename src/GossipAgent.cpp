//
// Created by Hong Man Hou on 11/7/2018.
//

#include "GossipAgent.h"

int GossipAgent::adj(int i, int j) {
    return (cong[i][j] ? 2 * (net -> a[i][j]) : net->a[i][j]);
}