#! /usr/bin/sh

#
#use -D with option form external/glfw/CMakeLists.txt
#options can be turned ON or OFF using the -D
#cmake -D CMAKE_C_COMPILER=/usr/bin/gcc -D CMAKE_CXX_COMPILER=/usr/bin/g++ -DGLFW_BUILD_DOCS=OFF -S . -B out/build/

cmake -DGLFW_BUILD_DOCS=OFF -S . -B out/build/
   
