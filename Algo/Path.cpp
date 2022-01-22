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

void Path::printGraphToFile(std::ostream &os, const std::string& sstart) const {
    std::string first = sstart;
    for(auto const& edge : path){
        os << first << " -> " << edge.getEndNode()->name << edge.GraphData()  << std::endl;
        first = edge.getEndNode()->name;
    }

}
void Path::printDataToFile(std::ostream &os, double throughput) const {
    os << "TR: " << throughput << std::endl;
    for(auto const& edge : path){
        edge.printTransmissionData(os);
    }

}
