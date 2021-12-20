//
// Created by narcano on 2021. 12. 13..
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_NETWORK_H
#define OPTICALTRANSMITTANCEBASEDROUTING_NETWORK_H


#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include "SatelliteNode.h"

#include "../Algo/OpticalTransmittanceOptimizer.h"

class Network {
    std::vector<SatelliteNode> satellites;
public:
    void addSatellite(SatelliteNode const&);
    void printAllNodes(){
        for(auto sat : satellites){
            std::cout<<sat.name<<std::endl;
        }
    }
    void printStats()const;
    void generateBest();
};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_NETWORK_H
