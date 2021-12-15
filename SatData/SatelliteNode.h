//
// Created by narcano on 2021. 12. 13..
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_SATELLITENODE_H
#define OPTICALTRANSMITTANCEBASEDROUTING_SATELLITENODE_H


#include <string>
#include <vector>
#include "Edge.h"
#include "../Algo/Path.h"

class SatelliteNode {
public:
    std::string name;
    std::vector<Edge> edges;
    SatelliteNode(std::string const &n) : name(n){}
    void addEdge(Edge const&);
    SatelliteNode(SatelliteNode const& s) =default;
    SatelliteNode() = default;

    bool operator ==(const SatelliteNode&outer) const;
};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_SATELLITENODE_H
