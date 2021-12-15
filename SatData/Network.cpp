//
// Created by narcano on 2021. 12. 13..
//


#include <sstream>
#include "Network.h"

void Network::addSatellite(const SatelliteNode &sat) {
    satellites.push_back(sat);
}

std::string EdgeToStr(Edge const&e) {
    std::stringstream buffer;
    buffer << e.destination->name.c_str();
    buffer << e.getStart();
    buffer << e.getEnd();
    return buffer.str();
}

void Network::generateBest() {
    auto paths = OpticalTransmittanceOptimizer::BFS(satellites[17], satellites.back());

    std::unordered_map<std::string, double> edges_best;


    for (auto &edge: satellites[17].edges) {
        printf("%s\n",EdgeToStr(edge).c_str());
        edges_best.try_emplace(EdgeToStr(edge).c_str(), 0);
    }


    for (auto p_ptr: paths) {
        OpticalTransmittanceOptimizer::optimizePath(p_ptr);
        double val = OpticalTransmittanceOptimizer::calculatePathOpticalThroughput(p_ptr);
        std::string pathEdge = EdgeToStr(*p_ptr.path[0].getEdge());
        if (edges_best[pathEdge] < val) {
            edges_best[pathEdge] = val;
        }
    }

    for (auto &edge: satellites[17].edges) {
       printf("%s: %f\n", EdgeToStr(edge).c_str() , edges_best[EdgeToStr(edge)]);
    }


}
