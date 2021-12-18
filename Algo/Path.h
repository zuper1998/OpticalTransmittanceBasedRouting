//
// Created by narcano on 2021. 12. 14..
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_PATH_H
#define OPTICALTRANSMITTANCEBASEDROUTING_PATH_H


#include <vector>
#include "ProxyEdge.h"
#include "../Algo/Constants.h"
#include "../SatData/SatelliteNode.h"

class Path {
public:
    std::vector<ProxyEdge> path;
    Path()=default;
    Path(ProxyEdge pe) {path.push_back(pe);}

    Path(Path const &p){
        std::for_each(p.path.begin(), p.path.end(), [this](ProxyEdge const& pe){this->path.push_back(pe);});
    }

    void addEdge(ProxyEdge pe) {path.push_back(pe);}
    ProxyEdge getLastEdge() const{
        return path.back();
    }

    bool isViable(Edge const&edge) const {
        if((edge.getStart()- path[0].getEnd())>constants::max_time_delta){
            return false;
        } else if(!containsNode(*edge.destination)) {
            return ((edge.getEnd()-getLastEdge().getStart())>0);
        }

        return false;

    }
    bool operator<(Path const& outer){
        for(int i = 0; i< std::min(path.size(),outer.path.size());i++){
            if(ProxyEdgeToStr(path[i])< ProxyEdgeToStr(outer.path[i]))
                return true;
            if(ProxyEdgeToStr(path[i])== ProxyEdgeToStr(outer.path[i]))
                continue;
            else{return false;}
        }
    }

    bool operator==(Path const&outer){
        for(int i = 0; i< std::min(path.size(),outer.path.size());i++) {
            if (ProxyEdgeToStr(path[i]) != ProxyEdgeToStr(outer.path[i]))
                return false;
        }
        return true;
    }

    bool containsNode(SatelliteNode& sn) const;


    friend std::ostream& operator<<(std::ostream& os, const Path& p);

    static std::string ProxyEdgeToStr(const ProxyEdge &e);
};

#endif //OPTICALTRANSMITTANCEBASEDROUTING_PATH_H