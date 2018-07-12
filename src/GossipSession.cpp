//
// Created by Hong Man Hou on 11/7/2018.
//

#include "GossipSession.h"

void GossipSession::close() {
    // if gossip aborted
    // due to car leaving edges
    if (a -> cur != cur || b -> cur != cur)
        return;

    // exchange information
    int N = a -> net -> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (a -> t[i][j] < b -> t[i][j]) {
                a -> t[i][j] = b -> t[i][j];
                a -> w[i][j] = b -> w[i][j];
            } else {
                b -> t[i][j] = a -> t[i][j];
                b -> w[i][j] = a -> w[i][j];
            }
    }


}