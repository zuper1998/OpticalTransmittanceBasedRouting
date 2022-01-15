//
// Created by narcano on 2021. 12. 14..
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_PROXYEDGE_H
#define OPTICALTRANSMITTANCEBASEDROUTING_PROXYEDGE_H


#include <string>
#include <sstream>
#include "../SatData/Edge.h"
#include "Constants.h"

class ProxyEdge {
    Edge const* edge;
    int start;
    int end;

public:
    ProxyEdge(Edge const* _edge,int _start,int _end): edge(_edge), start(_start), end(_end)  {}

    [[nodiscard]] SatelliteNode * getEndNode() const {
        return edge->destination;
    }
    [[nodiscard]] double getStart() const{
        return edge->getStart()+start;
    }
    [[nodiscard]] double getEnd() const{
        return edge->getEnd()-end;
    }

    [[nodiscard]] double getOverallTransmittanceTroughput() const{
        return edge->getTransmittanceBetween(start,end);
    }
    void removeFromStart(){
        start++;
    }
    void removeFromEnd(){
        end++;
    }

    void removeFromEnd(int d){
        end+=d;
    }
    void removeFromStart(int d){
        start+=d;
    }
    [[nodiscard]] Edge const* getEdge() const{
        return edge;
    }

    [[nodiscard]] double getDuration()const{
        return getEnd()-getStart();
    }

    [[nodiscard]] double getOverallTransmittanceTroughputUntil(double d) const {
        return edge->getTransmittanceBetweenUntil(start,end,d);
    }

    [[nodiscard]] std::string GraphData() const {
        std::stringstream s ;
        s << " [label =  \"[" << getStart() << " , " << getEnd() << "]  " << getOverallTransmittanceTroughput()*constants::entangledPhotonDetectionRateHz << "\"];";
        return s.str();
    }
};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_PROXYEDGE_H
