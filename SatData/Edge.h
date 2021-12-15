//
// Created by narcano on 2021. 12. 13..
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_EDGE_H
#define OPTICALTRANSMITTANCEBASEDROUTING_EDGE_H


#include <ctime>
#include <vector>
#include <cstdio>


class SatelliteNode;
class Edge {
    std::vector<double> transmittance;
    double startTime;
    double endTime;

public:
    Edge(std::vector<double> const &t,double s,double end,SatelliteNode* dest) : transmittance(t),startTime(s), endTime(end), destination(dest) {

    }
    Edge()=default;
    SatelliteNode* destination;
    [[nodiscard]] double getStart() const {
        return startTime;
    }
    [[nodiscard]] double getEnd() const {
        return endTime;
    }
    [[nodiscard]] double getTransmittanceBetween(int start,int end)const{
        double out =0;

        for(int i=start;i <((int)transmittance.size()-end);i++){
            out+=transmittance[i];
        }
        return out;
    }
};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_EDGE_H
