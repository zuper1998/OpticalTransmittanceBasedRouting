//
// Created by narcano on 2021. 12. 13..
//

#include "SatelliteNode.h"



void SatelliteNode::addEdge(Edge const& e) {
    edges.push_back(e);
}



bool SatelliteNode::operator==(const SatelliteNode &outer) const {
    return name==outer.name;
}
