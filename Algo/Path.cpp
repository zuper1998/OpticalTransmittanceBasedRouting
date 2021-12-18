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

std::string Path::ProxyEdgeToStr(ProxyEdge const&e) {
    std::stringstream buffer;
    buffer << e.getEdge()->destination->name.c_str();
    buffer << e.getStart();
    buffer << e.getEnd();
    return buffer.str();
}

std::ostream &operator<<(std::ostream &os, const Path &p) {
    for(auto& pe: p.path){
        os << Path::ProxyEdgeToStr(pe);
    }
    return os;

}