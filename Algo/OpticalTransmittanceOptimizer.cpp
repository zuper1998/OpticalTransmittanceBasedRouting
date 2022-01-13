//
// Created by narcano on 2021. 12. 14..
//

#include <iostream>
#include "OpticalTransmittanceOptimizer.h"

std::vector<Path> OpticalTransmittanceOptimizer::BFS(SatelliteNode const &start, std::vector<SatelliteNode> const &ends) {

    std::vector<std::shared_ptr<Path>> paths;
    std::vector<std::shared_ptr<Path>> tmp_paths;
    std::vector<Path> good_paths;
    std::random_device rd;
    std::default_random_engine rng(rd());

    for (auto const &startEdge: start.edges) {
        paths.push_back(std::make_shared<Path>(ProxyEdge(&startEdge, 0, 0)));
    }
    std::printf("Path: %lu, ProxyEdge: %lu Edge %lu\n", sizeof(Path), sizeof(ProxyEdge), sizeof(Edge));
    int count = 0;
    while (true) {
        double best = 0;
        printf("%d  %zu  %zu \n", ++count, paths.size(), good_paths.size());
        for (auto const &path: paths) {
            if(tmp_paths.size()>1000000) break; //if it hits this part it no longer get new goodpaths

            for (auto const &edge: path->getLastEdge().getEndNode()->edges) {
                if (path->isViable(edge)) {
                    best = std::max(best, Pathing(ends, tmp_paths, good_paths, path, edge)*constants::entangledPhotonDetectionRateHz);
                }
            }
        }
        //printf("TMPPATH %lu\n",sizeof( Path)*tmp_paths.size());
        printf("Best of round %d is total: %f avarage:%f\n",count,best,best/3600);
        paths.clear();
        paths.insert(std::end(paths), std::begin(tmp_paths), std::end(tmp_paths));
        tmp_paths.clear();
        std::shuffle(paths.begin(),paths.end(),rng);
        if (paths.empty()) break;
    }

    return good_paths;

}

double
OpticalTransmittanceOptimizer::Pathing(std::vector<SatelliteNode> const &ends, std::vector<std::shared_ptr<Path>> &tmp_paths,
                                       std::vector<Path> &good_paths, const std::shared_ptr<Path> &path,
                                       const Edge &edge) {
    auto path1 = std::make_shared<Path>(*path) ;
    path1->addEdge(ProxyEdge(&edge, 0, 0));

    bool found = false;

    for (auto const &s : ends){
        if(s==*path1->getLastEdge().getEndNode()){
            found = true;
        }
    }

    if ( found ) {//this can be expanded by making it clip to every end node that is desired
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

//Paprion van rata az algo
bool OpticalTransmittanceOptimizer::optimize(ProxyEdge &edge, ProxyEdge &edge1) {
    double t1 = edge.getStart();
    double t2 = edge.getEnd();
    //Masik
    double t3 = edge.getStart();
    double t4 = edge.getEnd();

    if (t4 < t2) { // III. eset
        edge.removeFromEnd((int) (t2 - t4));
    } else if (t3 < t1) { // IV. es V eset
        edge.removeFromEnd((int) (t1 - t3));
    }
    if (edge.getDuration() < constants::min_time_delta || edge1.getDuration() < constants::min_time_delta) {
        return false;
    }
    return true;
}

/*
  double delta = edge.getEnd() - edge1.getStart();
    while(delta-->0) {  //overlap amount
        if(edge.getOverallTransmittanceTroughput() < edge1.getOverallTransmittanceTroughput()){
            edge1.removeFromStart();
        } else {
            edge.removeFromEnd();
        }
    }
*/
bool OpticalTransmittanceOptimizer::optimizePath(Path &p) {
    if(!cutInShape(p)) return false;
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
    double delta =pe->getEnd() - ps->getStart();
    if(delta>constants::max_time_delta){
        while(delta-->0){
            if(ps->getOverallTransmittanceTroughput() < ps->getOverallTransmittanceTroughput()){
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





