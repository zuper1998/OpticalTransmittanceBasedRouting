//
// Created by narcano on 2021. 12. 14..
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_OPTICALTRANSMITTANCEOPTIMIZER_H
#define OPTICALTRANSMITTANCEBASEDROUTING_OPTICALTRANSMITTANCEOPTIMIZER_H

#include <vector>
#include "Path.h"
#include <memory>
#include <random>
#include <algorithm>

#include "../SatData/SatelliteNode.h"

class OpticalTransmittanceOptimizer {
public:
    static bool optimize(ProxyEdge &edge, ProxyEdge &edge1);

    static std::vector<Path> BFS(const SatelliteNode &start, const std::vector<SatelliteNode> &ends);

    static double calculatePathOpticalThroughput(const Path &p);

    static double
    Pathing(std::vector<SatelliteNode> const &ends, std::vector<std::shared_ptr<Path>> &tmp_paths, std::vector<Path> &good_paths,
            const std::shared_ptr<Path> &path, const Edge &edge);


    static bool optimizePath(Path &p);

    static bool cutInShape(Path &path);
};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_OPTICALTRANSMITTANCEOPTIMIZER_H
