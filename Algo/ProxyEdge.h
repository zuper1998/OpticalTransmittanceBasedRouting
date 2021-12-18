//
// Created by narcano on 2021. 12. 14..
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_PROXYEDGE_H
#define OPTICALTRANSMITTANCEBASEDROUTING_PROXYEDGE_H


#include <string>
#include <sstream>
#include "../SatData/Edge.h"

class ProxyEdge {
    Edge const* edge;
    int start;
    int end;

public:
    ProxyEdge(Edge const* _edge,int _start,int _end): edge(_edge), start(_start), end(_end)  {}

    SatelliteNode* getEndNode() {
        return edge->destination;
    }
    [[nodiscard]] double getStart() const{
        return edge->getStart()+start;
    }
    [[nodiscard]] double getEnd() const{
        return edge->getEnd()-end;
    }

    double getOverallTransmittanceTroughput() {
        return edge->getTransmittanceBetween(start,end);
    }
    void removeFromStart(){
        start++;
    }
    void removeFromEnd(){
        end++;
    }
    [[nodiscard]] Edge const* getEdge() const{
        return edge;
    }




};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_PROXYEDGE_H
