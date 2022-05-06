//
// Created by narcano on 2021. 12. 13..
//


#include <sstream>
#include <chrono>
#include <fstream>
#include "Network.h"
#include "../Utility.h"

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



void Network::generateBest(const std::filesystem::directory_entry& f) {
    auto start = std::chrono::system_clock::now();

    std::vector<SatelliteNode> endNodes;


    std::copy_if(satellites.begin(),satellites.end(),
                 std::back_inserter(endNodes),
                 [](SatelliteNode const& satelliteNode){return satelliteNode.name.find("SAT")==std::string::npos;});

    //this is where the stuff starts
    for(int i = 0; i<endNodes.size();i++) {
        GeneratPathFrom(endNodes,i,f);
    }
    auto end = std::chrono::system_clock::now();
    std::time_t endtime = std::chrono::system_clock::to_time_t(end);
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "finished computation at " << std::ctime(&endtime)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

}

void Network::GeneratPathFrom(std::vector<SatelliteNode> &endNodes, int index, const std::filesystem::directory_entry& f) {
    SatelliteNode startN = endNodes[index];

    auto paths = OpticalTransmittanceOptimizer::BFS(startN, endNodes,f);

    std::unordered_map<std::string, double> edges_best;
    std::unordered_map<std::string, Path> path_best;

    for (auto const &s: endNodes) {
        if(s==startN) continue;
        for (auto const&edge: startN.edges) {
            std::string combined = EdgeToStr(edge) + s.name;
            edges_best.try_emplace(combined.c_str(), 0);
        }
    }
    for (auto const &p_ptr: paths) {
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
        std::stringstream outputFileGraph;
        std::stringstream outputFileData;

        outputFileGraph << R"(..\Outputs\)" << Utility::get_stem(f)  <<  R"(\Graph\)";
        outputFileData  << R"(..\Outputs\)" << Utility::get_stem(f)  <<  R"(\Data\)";

        std::filesystem::create_directories(outputFileData.str());
        std::filesystem::create_directories(outputFileGraph.str());

        outputFileGraph << startN.name.c_str() << endN.name.c_str() << ".txt";
        outputFileData <<  startN.name.c_str() << endN.name.c_str() << ".txt";

        std::ofstream outGraph(outputFileGraph.str(), std::ios_base::out);
        std::ofstream outData(outputFileData.str(),std::ios_base::out);
        outGraph << "digraph G{\n"
             "layout=dot\n"
             "graph [ dpi = 300 ];\n"
             "rankdir=LR;" << std::endl;

        for (auto &edge: startN.edges) {
            std::string combined = EdgeToStr(edge) + endN.name;
            sum += edges_best[combined];
            path_best[combined].printGraphToFile(outGraph, endNodes[index].name);
            path_best[combined].printDataToFile(outData, edges_best[combined],endNodes[index].name);

        }
        outGraph << "}" << std::endl;
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

    edges = std::accumulate(satellites.begin(),satellites.end(),0L,
                            [](long long before, SatelliteNode const& newVal)\
                            {return before + countDistinctDestinations(newVal.edges);});

    printf("Sats: %llu Avarege distinct edges: %llu \n", satNum, edges / satNum);
}



