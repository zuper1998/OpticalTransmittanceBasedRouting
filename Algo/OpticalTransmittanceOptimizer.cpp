//
// Created by narcano on 2021. 12. 14..
//

#include <iostream>
#include "OpticalTransmittanceOptimizer.h"

std::vector<Path>  OpticalTransmittanceOptimizer::BFS(SatelliteNode const& start, SatelliteNode const &end) {

    std::vector<std::shared_ptr<Path>> paths;
    std::vector<std::shared_ptr<Path>> tmp_paths;
    std::vector<Path> good_paths;
    for (auto const& startEdge: start.edges) {
        paths.push_back(std::make_shared<Path>(ProxyEdge(&startEdge, 0, 0)));
    }
    int count = 0;
    while (true) {
        if(count ==8) return good_paths;
        printf("%d  %d  %d \n", count++, paths.size(), good_paths.size());
        for (auto const &path: paths) {
            for (auto const&edge: path->getLastEdge().getEndNode()->edges) {
                if (path->isViable(edge)) {
                    auto path1 = std::make_shared<Path>(*path);
                    path1->addEdge(ProxyEdge(&edge, 0 ,0));
                    if ((*edge.destination) == end) {
                        good_paths.push_back(*path1);
                    } else {
                        tmp_paths.push_back(path1);
                    }
                }
            }
        }
        paths.clear();
        std::for_each(tmp_paths.begin(), tmp_paths.end(), [&paths](auto const &path) { paths.push_back(path); });
        tmp_paths.clear();
        if (paths.empty()) break;
    }

    return  good_paths;

}



double OpticalTransmittanceOptimizer::calculatePathOpticalThroughput(Path p) {
    double out=p.path[0].getOverallTransmittanceTroughput();
    std::for_each(p.path.begin(), p.path.end(), [&](ProxyEdge& edge){
        out= std::min(edge.getOverallTransmittanceTroughput(),out);
    });
    return out;
}

void OpticalTransmittanceOptimizer::optimize(ProxyEdge &edge, ProxyEdge &edge1) {
    while((edge.getEnd() - edge1.getStart())>0) {  //overlap amount
        if(edge.getOverallTransmittanceTroughput() < edge1.getOverallTransmittanceTroughput()){
            edge1.removeFromStart();
        } else {
            edge.removeFromEnd();
        }
    }
}

void OpticalTransmittanceOptimizer::optimizePath(Path p) {
    for(int i =0;i<p.path.size()-1;i++){
        optimize(p.path[i],p.path[i+1]);
    }
}





void OpticalTransmittanceOptimizer::CullPaths(std::vector<std::shared_ptr<Path>> vector1) {
    std::sort(std::begin(vector1),std::end(vector1), [](const std::shared_ptr<Path>& p1, const std::shared_ptr<Path>&  p2){
        return *p1<*p2;
    });
    /*
    std::for_each(vector1.begin(), vector1.end(), [](const std::shared_ptr<Path>& p1){
        std::cout << *p1 << std::endl;
    });
    */
}
