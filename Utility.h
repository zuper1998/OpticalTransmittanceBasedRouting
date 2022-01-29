//
// Created by Narcano on 1/28/2022.
//

#ifndef OPTICALTRANSMITTANCEBASEDROUTING_UTILITY_H
#define OPTICALTRANSMITTANCEBASEDROUTING_UTILITY_H

#include <filesystem>

class Utility {
public:
    static std::string get_stem(const std::filesystem::path &p) { return (p.stem().string()); }

};


#endif //OPTICALTRANSMITTANCEBASEDROUTING_UTILITY_H
