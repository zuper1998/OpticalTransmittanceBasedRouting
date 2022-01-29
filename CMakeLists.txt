cmake_minimum_required(VERSION 3.21)
project(OpticalTransmittanceBasedRouting)

set(CMAKE_CXX_STANDARD 20)

add_executable(OpticalTransmittanceBasedRouting main.cpp SatData/SatelliteNode.cpp SatData/SatelliteNode.h SatData/Edge.cpp SatData/Edge.h loadSats/LoadSat.cpp loadSats/LoadSat.h SatData/Network.cpp SatData/Network.h Algo/OpticalTransmittanceOptimizer.cpp Algo/OpticalTransmittanceOptimizer.h Algo/Path.cpp Algo/Path.h Algo/ProxyEdge.cpp Algo/ProxyEdge.h Algo/Constants.h Utility.cpp Utility.h)
