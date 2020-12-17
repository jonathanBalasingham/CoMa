cmake_minimum_required(VERSION 3.17)
project(CoMa)

set(CMAKE_CXX_STANDARD 17)
add_library(CoMa STATIC library.cpp library.h util.h NonlinearEquations.h)
add_executable(test main.cpp)
TARGET_LINK_LIBRARIES(test CoMa)
