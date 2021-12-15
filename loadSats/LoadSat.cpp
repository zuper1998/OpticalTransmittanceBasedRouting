//
// Created by narcano on 2021. 12. 13..
//

#include <fstream>
#include <cstring>
#include <sstream>
#include "LoadSat.h"


Network LoadSat::LoadFromFile(std::string const& f) {
    auto file = std::ifstream(f,std::ifstream::in);
    auto network = Network();
    while(!file.eof()){

        std::string name;
        std::string num_lines;
        getline(file,name,'|');
        getline(file,num_lines);
        //std::cout<<name << "|  |" << num_lines<<std::endl;
        if(name=="") return network;
        auto satelliteNode = getSatelliteNode(name);


    for( int i =0;i< std::stoi(num_lines);i++ ){

        std::string line; getline( file, line );
        //std::cout<<line<<std::endl;
        satelliteNode->addEdge(loadEdge(line));
    }
    network.addSatellite(*satelliteNode);
    }
    return network;

}

Edge LoadSat::loadEdge(std::string const& basicString) {
    std::stringstream ss(basicString);
    //Separate
    std::string values;
    std::string name;
    std::string start;
    std::string end;

    getline(ss,values,'|');
    getline(ss,name,'|');
    getline(ss,start,'|');
    getline(ss,end,'|');


    return {parseFloat(values),std::stod(start),std::stod(end), getSatelliteNode(name)};
}

std::vector<double> LoadSat::parseFloat(std::string const& basicString) {
    std::vector<double> out;
    std::stringstream ss(basicString);
    for(std::string line; getline( ss, line ,',');out.push_back(std::stod(line)));
    return out;
}

SatelliteNode* LoadSat::getSatelliteNode(std::string const& basicString) {
    auto tmp = name_sat.find(basicString);
    if(tmp!=name_sat.end())
    {
        return &tmp->second;
    } else {
        name_sat.try_emplace(basicString , SatelliteNode(basicString));
        return &name_sat[basicString];
    }


}

