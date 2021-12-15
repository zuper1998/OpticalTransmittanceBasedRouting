//
// Created by narcano on 2021. 12. 14..
//

#include "Path.h"

bool Path::containsNode(SatelliteNode &sn) const {

    for (ProxyEdge pe: path) {
        if ((*pe.getEndNode()) == sn) return true;
    }
    return false;

}
