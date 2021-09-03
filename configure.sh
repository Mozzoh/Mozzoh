#! /usr/bin/sh

#use -D with option form external/glfw/CMakeLists.txt
#options can be turned ON or OFF using the -D
cmake -DGLFW_BUILD_DOCS=OFF -S . -B out/build/
