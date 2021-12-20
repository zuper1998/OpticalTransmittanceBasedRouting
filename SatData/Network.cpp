//
// Created by narcano on 2021. 12. 13..
//


#include <sstream>
#include <chrono>
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
    auto start = std::chrono::system_clock::now();

    auto paths = OpticalTransmittanceOptimizer::BFS(satellites[17], satellites.back());

    std::unordered_map<std::string, double> edges_best;


    for (auto &edge: satellites[17].edges) {
        //printf("%s\n",EdgeToStr(edge).c_str());
        edges_best.try_emplace(EdgeToStr(edge).c_str(), 0);
    }

    double cnt = 0;
    for (auto const&p_ptr: paths) {
        double progress = cnt++/(double )paths.size() ;
        std::cout << progress << " | " << paths.size() << "                               \r" << std::flush;
        //OpticalTransmittanceOptimizer::optimizePath(p_ptr);
        double val = OpticalTransmittanceOptimizer::calculatePathOpticalThroughput(p_ptr) * constants::entangledPhotonDetectionRateHz;
        std::string pathEdge = EdgeToStr(*p_ptr.path[0].getEdge());
        if (edges_best[pathEdge] < val) {
            edges_best[pathEdge] = val;
        }
    }
    double sum = 0;
    for (auto &edge: satellites[17].edges) {
        sum+=edges_best[EdgeToStr(edge)];
       printf("%s: %f\n", EdgeToStr(edge).c_str() , edges_best[EdgeToStr(edge)]);
    }
    printf("For the path between %s and %s avarage bitrate was %f\n",satellites[17].name.c_str(),satellites.back().name.c_str(),sum/(3600*3));


    auto end = std::chrono::system_clock::now();
    std::time_t endtime = std::chrono::system_clock::to_time_t(end);
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "finished computation at " << std::ctime(&endtime)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

}
