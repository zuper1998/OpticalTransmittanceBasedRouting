#include <iostream>
#include "loadSats/LoadSat.h"

int main() {
    auto loader = LoadSat();
    Network network = loader.LoadFromFile("/home/narcano/CLionProjects/OpticalTransmittanceBasedRouting/QSAT_RETRO_LOW.satNetwork");
    network.generateBest();
    return 0;
}
