#include "World.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    //cout <<"fdsf" <<endl;
    srand(time(NULL));
    World world;
    int n = 20, x = 100, y = 100, T = 10, num_a = 10000;
    world.createSimualtion(n, x, y, T, num_a);
    while(world.step()) {
    }
    return 0;
}