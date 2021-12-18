//
// Created by narcano on 2021. 12. 14..
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_OPTICALTRANSMITTANCEOPTIMIZER_H
#define OPTICALTRANSMITTANCEBASEDROUTING_OPTICALTRANSMITTANCEOPTIMIZER_H

#include <vector>
#include "Path.h"
#include <memory>

#include "../SatData/SatelliteNode.h"

class OpticalTransmittanceOptimizer {
public:
    static double calculatePathOpticalThroughput(Path p);
    static void optimizePath(Path p);
    static void optimize(ProxyEdge &edge, ProxyEdge &edge1);

    static std::vector<Path> BFS(const SatelliteNode &start, const SatelliteNode &end);
    static void CullPaths(std::vector<std::shared_ptr<Path>>);
};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_OPTICALTRANSMITTANCEOPTIMIZER_H
