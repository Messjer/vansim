//
// Created by Hong Man Hou on 11/7/2018.
//

#ifndef VANSIM_GOSSIPSESSION_H
#define VANSIM_GOSSIPSESSION_H
#include "GossipAgent.h"
#include <cstdio>

class GossipSession {
    // agent number
    GossipAgent *a, *b;
    int cur;
public:
    GossipSession(GossipAgent *A, GossipAgent *B, int Cur): a(A), b(B), cur(Cur) {}
    int close();
};


#endif //VANSIM_GOSSIPSESSION_H
