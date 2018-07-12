#include "World.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cassert>

double K = 100;
double K2 = 1;

using namespace std;

int main(int argc, char **argv) {
    //cout <<"fdsf" <<endl;
    //srand(time(NULL));
    int seed;
    cout <<"seed = " <<(seed = time(NULL)) <<endl;
    WorldConfig conf;
    if (argc == 14) {
        conf.n = atoi(argv[1]); // 10 by default
        conf.x = atoi(argv[2]);
        conf.y = atoi(argv[3]);
        conf.T = atoi(argv[4]);
        conf.duration = atoi(argv[5]);
        conf.num_a = atoi(argv[6]);
        conf.p_com = stod(argv[7]);
        conf.p_gas = stod(argv[8]);
        conf.p_reroute = stod(argv[9]);
        conf.rho = stod(argv[10]);
        K = stod(argv[11]);
        K2 = stod(argv[12]);
        seed = atoi(argv[13]);
    } else {
        assert(argc == 1 && "Provide exactly 11 arguments or none!");
        conf.n = 10;
        conf.x = conf.y = 20;
        conf.T = 2;
        conf.duration = 1000;
        conf.num_a = 10;
        conf.p_com = 0.5;
        conf.p_gas = 1;
        conf.p_reroute = 0.7;
        conf.rho = 0.1;
    }
    srand(seed);
    World world(conf);
    while(world.step());
    return 0;
}