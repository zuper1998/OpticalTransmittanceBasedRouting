//
// Created by narcano on 2021. 12. 13..
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_LOADSAT_H
#define OPTICALTRANSMITTANCEBASEDROUTING_LOADSAT_H


#include <cstdio>
#include "../SatData/Network.h"
#include <iostream>
#include <unordered_map>

class LoadSat {
private:
    std::unordered_map<std::string,SatelliteNode> name_sat;

public:
     Network LoadFromFile(std::string  const& f);

     Edge loadEdge(std::string const& basicString);

     static std::vector<double> parseFloat(std::string const& basicString) ;


    SatelliteNode *getSatelliteNode(const std::string &basicString);
};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_LOADSAT_H
