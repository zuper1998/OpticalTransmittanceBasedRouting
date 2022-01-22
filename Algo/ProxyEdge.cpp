//
// Created by narcano on 2021. 12. 14..
//

#include "ProxyEdge.h"

void ProxyEdge::printTransmissionData(std::ostream &ostream) const {
    ostream << edge->getStart()+ start << " | ";
    std::for_each(edge->transmittance.begin()+start,edge->transmittance.end()-end,[&](double tr){ostream<<tr << " ";});
    ostream << std::endl;

}
