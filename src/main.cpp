#include "World.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    //cout <<"fdsf" <<endl;
    //srand(time(NULL));
    srand(0);
    WorldConfig conf;
    conf.n = 5;
    conf.x = 100;
    conf.y = 100;
    conf.T = 5;
    conf.duration = 150;
    conf.num_a = 10;
    conf.p_com = 0.1;
    conf.p_gas = 0.1;
    conf.p_reroute = 0.1;
    conf.rho = 0.2;
    World world(conf);
    while(world.step());
    return 0;
}