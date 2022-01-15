//
// Created by narcano on 2021. 12. 13..
//


#include <sstream>
#include <chrono>
#include <fstream>
#include "Network.h"

void Network::addSatellite(const SatelliteNode &sat) {
    satellites.push_back(sat);
}

std::string EdgeToStr(Edge const &e) {
    std::stringstream buffer;
    buffer << e.destination->name.c_str();
    buffer << e.getStart();
    buffer << e.getEnd();
    return buffer.str();
}



void Network::generateBest() {
    auto start = std::chrono::system_clock::now();

    std::vector<SatelliteNode> endNodes;

    for (SatelliteNode const &s: satellites) {
        if (s.name.find("SAT") == std::string::npos) {
            endNodes.push_back(s);
        }
    }


    //this is where the stuff starts
    for(int i = 0; i<endNodes.size();i++) {
        GeneratPathFrom(endNodes,i);
    }
    auto end = std::chrono::system_clock::now();
    std::time_t endtime = std::chrono::system_clock::to_time_t(end);
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "finished computation at " << std::ctime(&endtime)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

}

void Network::GeneratPathFrom(std::vector<SatelliteNode> &endNodes, int index) {
    SatelliteNode startN = endNodes[index];

    auto paths = OpticalTransmittanceOptimizer::BFS(startN, endNodes);

    std::unordered_map<std::string, double> edges_best;
    std::unordered_map<std::string, Path> path_best;

    for (auto &s: endNodes) {
        if(s==startN) continue;
        for (auto &edge: startN.edges) {
            std::string combined = EdgeToStr(edge) + s.name;
            //printf("%s\n",combined.c_str());
            edges_best.try_emplace(combined.c_str(), 0);
        }
    }
    double cnt = 0;
    for (auto const &p_ptr: paths) {
        //double progress = cnt++ / (double) paths.size();
        //std::cout << progress << " | " << paths.size() << "                               \r" << std::flush;
        //OpticalTransmittanceOptimizer::optimizePath(p_ptr);
        double val = OpticalTransmittanceOptimizer::calculatePathOpticalThroughput(p_ptr) *
                     constants::entangledPhotonDetectionRateHz;
        std::string endNodeName = p_ptr.getLastEdge().getEndNode()->name;
        std::string pathEdge = EdgeToStr(*p_ptr.path[0].getEdge())+endNodeName;
        if (edges_best[pathEdge] < val) {
            edges_best[pathEdge] = val;
            path_best[pathEdge]=p_ptr;
        }
    }

    for(auto& endN : endNodes) {
        if(endN==startN) continue;
        double sum = 0;
        std::stringstream s;
        s << "..\\Outputs\\";
        s <<startN.name.c_str() << endN.name.c_str()<<".txt";
        std::ofstream out(s.str(),std::ios_base::out);
        out<<"digraph G{\n"
             "layout=dot\n"
             "graph [ dpi = 300 ];\n"
             "rankdir=LR;"<<std::endl;

        for (auto &edge: startN.edges) {
            std::string combined = EdgeToStr(edge) + endN.name;
            sum += edges_best[combined];
            path_best[combined].printToFile(out,endNodes[index].name);
            //printf("%s: %f\n", combined.c_str(), edges_best[combined]);
        }
        out<<"}"<<std::endl;
        printf("For the path between %s and %s avarage bitrate was %f sent bits: %f\n", startN.name.c_str(),
               endN.name.c_str(), sum / (3600 * 3), sum);

    }
}


unsigned long long countDistinctDestinations(std::vector<Edge> const &edges) {
    std::map<std::string, int> out;
    for (Edge const &e: edges) {
        out.emplace(e.destination->name, 0);
    }
    return out.size();

}

void Network::printStats() const {
    unsigned long long satNum = satellites.size();
    unsigned long long edges = 0;
    for (auto &sat: satellites) {
        edges += countDistinctDestinations(sat.edges);
    }

    printf("Sats: %llu Avarege distinct edges: %llu \n", satNum, edges / satNum);
}



