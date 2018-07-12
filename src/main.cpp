#include "World.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    //cout <<"fdsf" <<endl;
    //srand(time(NULL));
    int seed;
    cout <<"seed = " <<(seed = time(NULL)) <<endl;
    srand(seed);
    WorldConfig conf;
    conf.n = 10;
    conf.x = 100;
    conf.y = 100;
    conf.T = 1;
    conf.duration = 2000;
    conf.num_a = 1000;
    conf.p_com = 0.5;
    conf.p_gas = 0.1;
    conf.p_reroute = 0.3;
    conf.rho = 0.10;
    World world(conf);
    while(world.step());
    return 0;
}