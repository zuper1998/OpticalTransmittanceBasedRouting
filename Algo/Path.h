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
    explicit Path( ProxyEdge pe) {path.push_back(pe);}

    Path(Path const &p){
        path.insert(path.end(),p.path.begin(),p.path.end());
    }



    void addEdge(ProxyEdge const& pe) {
        path.push_back(pe);
    }
    ProxyEdge const& getLastEdge() const{
        return path.back();
    }

    bool isViable(Edge const&edge) const {
        double delta = edge.getStart() - path[0].getEnd();
        if(delta>(constants::max_time_delta)){ // soft check for the duration of the math, if the time between the end of first transmission and the start of the last one exceeds the maximum allowed time it returns false
            return false;
        } else if(!containsNode(*edge.destination)) { // the route didnt already visited the node
            return (edge.getEnd() > getLastEdge().getStart()); // the new transmissions end time is before the current path's last transmissions start returns false
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
        return false;
    }

    bool operator==(Path const&outer){
        for(int i = 0; i< std::min(path.size(),outer.path.size());i++) {
            if (ProxyEdgeToStr(path[i]) != ProxyEdgeToStr(outer.path[i]))
                return false;
        }
        return true;
    }

    bool containsNode(SatelliteNode& sn) const;
    void printGraphToFile(std::ostream &os, const std::string &sstart)const;

    friend std::ostream& operator<<(std::ostream& os, const Path& p);

    static std::string ProxyEdgeToStr(const ProxyEdge &e);

    void printDataToFile(std::ostream &os,double, const std::string&) const;
};

#endif //OPTICALTRANSMITTANCEBASEDROUTING_PATH_H
