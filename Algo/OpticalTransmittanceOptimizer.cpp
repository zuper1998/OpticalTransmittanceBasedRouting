//
// Created by narcano on 2021. 12. 14..
//

#include <iostream>
#include <fstream>
#include "OpticalTransmittanceOptimizer.h"
#include "../Utility.h"

std::vector<Path> OpticalTransmittanceOptimizer::BFS(SatelliteNode const &start, std::vector<SatelliteNode> const &ends,
                                                     const std::filesystem::directory_entry &f) {

    std::vector<std::shared_ptr<Path>> paths;
    std::vector<std::shared_ptr<Path>> tmp_paths;
    std::vector<Path> good_paths;
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::stringstream dataFileName;
    dataFileName << R"(..\Outputs\)" << Utility::get_stem(f) << R"(\genData\)";
    std::filesystem::create_directories(dataFileName.str());

    dataFileName << start.name.c_str() << ".txt";

    std::ofstream dataFile(dataFileName.str(), std::ios_base::out);
    for (auto const &startEdge: start.edges) {
        paths.push_back(std::make_shared<Path>(ProxyEdge(&startEdge, 0, 0)));
    }
    //std::printf("Path: %lu, ProxyEdge: %lu Edge %lu\n", sizeof(Path), sizeof(ProxyEdge), sizeof(Edge));
    int Best_count = 1;
    double trueBest = 0;
    int count = 0;
    while (true) {

        double best = 0;
        printf("%d  %zu  %zu \n", ++count, paths.size(), good_paths.size());
        for (auto const &path: paths) {
            if (tmp_paths.size() > constants::maxSimPaths) break; //if it hits this part it no longer get new goodpaths

            for (auto const &edge: path->getLastEdge().getEndNode()->edges) {
                if (path->isViable(edge)) {
                    best = std::max(best, Pathing(ends, tmp_paths, good_paths, path, edge) *
                                          constants::entangledPhotonDetectionRateHz);
                }
            }
        }
        dataFile << best << " | " << best / 3600 << " | " << paths.size() << std::endl;
        trueBest = std::max(best,trueBest);

        if(best==0){ //if there is a steady decline in the best
            if(Best_count--<0) break;
        }

        paths.clear();
        paths.insert(std::end(paths), std::begin(tmp_paths), std::end(tmp_paths));
        tmp_paths.clear();
        std::shuffle(paths.begin(), paths.end(), rng);
        if (paths.empty()) break;
    }


    return good_paths;

}

/*
 * Calculates best throughput by using the algorithm
 */
double
OpticalTransmittanceOptimizer::Pathing(std::vector<SatelliteNode> const &ends,
                                       std::vector<std::shared_ptr<Path>> &tmp_paths,
                                       std::vector<Path> &good_paths, const std::shared_ptr<Path> &path,
                                       const Edge &edge) {
    auto path1 = std::make_shared<Path>(*path); // copy path so we dont modify the original one
    path1->addEdge(ProxyEdge(&edge, 0, 0));


    bool found = std::any_of(ends.begin(), ends.end(), [&](auto s) {
        return s == *path1->getLastEdge().getEndNode();
    }); // is there an end node that can be found in the last elemnent in the path

    if (found) {
        if (optimizePath(*path1)) {
            good_paths.emplace_back(*path1);
            return calculatePathOpticalThroughput(*path1);
        }
    } else {
        tmp_paths.emplace_back(std::move(path1));
    }
    return 0;
}


double OpticalTransmittanceOptimizer::calculatePathOpticalThroughput(Path const &p) {
    double out = p.path[0].getOverallTransmittanceTroughput();
    std::for_each(p.path.begin(), p.path.end(), [&](ProxyEdge const &edge) {
        out = edge.getOverallTransmittanceTroughputUntil(out);
    });
    return out;
}

/*
 * Omtimize the two transmission intervals
 *
 * case III:
 * A  t1----------t2 B
 * B    t3----t4 C
 *
 * case IV:
 * A     t1-------t2 B
 * B t3-----------------t4 C
 *
 * case V:
 * A     t1--------------------t2 B
 * B t3-----------------t4 C
 *
 */
bool OpticalTransmittanceOptimizer::optimize(ProxyEdge &edge, ProxyEdge &edge1) {
    double t1 = edge.getStart();
    double t2 = edge.getEnd();
    //Masik
    double t3 = edge1.getStart();
    double t4 = edge1.getEnd();

    if (t4 < t2) { // case III.
        edge.removeFromEnd((int) (t2 - t4));
    }
    if (t3 < t1) { // case IV. and V -- case V is when both if's are true
        edge1.removeFromStart((int) (t1 - t3));
    }
    if (edge.getDuration() < constants::min_time_delta || edge1.getDuration() <
                                                          constants::min_time_delta) { //check if the lenghth of the transmission has fallen below the min amount
        return false;
    }
    return true;
}

/*\
 *  Optimize all path's
 *  @return was the optimization successful
 */
bool OpticalTransmittanceOptimizer::optimizePath(Path &p) {
    if (!cutInShape(p)) return false; // if can't be cut in shape return false
    for (int i = 0; i < p.path.size() - 1; i++) {
        if (!optimize(p.path[i], p.path[i + 1]))
            return false;
    }
    return true;
}

/*
 *  Tries to fit the path in the max time delta value while respecting the min time delta
 */
bool OpticalTransmittanceOptimizer::cutInShape(Path &path) {
    auto ps = &path.path[0];
    auto pe = &path.path.back();
    double delta = pe->getEnd() - ps->getStart();
    if (delta > constants::max_time_delta) {
        while (delta-- > 0) {
            if (ps->getOverallTransmittanceTroughput() < pe->getOverallTransmittanceTroughput()) {
                ps->removeFromStart();
            } else {
                pe->removeFromEnd();
            }
            if (pe->getDuration() < constants::min_time_delta || ps->getDuration() < constants::min_time_delta) {
                return false;
            }
        }
    }
    return true;
}





