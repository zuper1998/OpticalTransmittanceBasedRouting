#include <iostream>
#include "loadSats/LoadSat.h"

int main() {
    auto loader = LoadSat();
    Network network = loader.LoadFromFile("..\\QSAT_RETRO_MID.satNetwork");
    network.printStats();
    network.generateBest();
    //getchar();
    return 0;
}
