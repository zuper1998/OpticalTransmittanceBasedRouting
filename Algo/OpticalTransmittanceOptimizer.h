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
    static void optimize(ProxyEdge &edge, ProxyEdge &edge1);

    static std::vector<Path> BFS(const SatelliteNode &start, const SatelliteNode &end);

    static double calculatePathOpticalThroughput(const Path &p);

    static void
    Pathing(const SatelliteNode &end, std::vector<std::shared_ptr<Path>> &tmp_paths, std::vector<Path> &good_paths,
            const std::shared_ptr<Path> &path, const Edge &edge);


    static Path& optimizePath(Path &p);
};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_OPTICALTRANSMITTANCEOPTIMIZER_H
