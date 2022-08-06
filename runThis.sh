/snap/bin/cmake -DCMAKE_BUILD_TYPE=Release .
/snap/bin/cmake --build .  --target OpticalTransmittanceBasedRouting -- -j 9
mv OpticalTransmittanceBasedRouting  cmakeLoc/
cd cmakeLoc 
nohup ./OpticalTransmittanceBasedRouting &
