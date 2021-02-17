cmake_minimum_required(VERSION 3.17)
project(CoMa)

set(CMAKE_CXX_STANDARD 17)

find_package(Catch2 REQUIRED)
find_package(Boost REQUIRED)
add_library(CoMa STATIC library.cpp library.h util.h src/NonlinearEq/NonlinearEquations.h SystemOfEquations.h MatrixOperations.h Matrix.h)
add_executable(tests main.cpp)
TARGET_LINK_LIBRARIES(tests CoMa Catch2::Catch2)
TARGET_LINK_LIBRARIES(tests CoMa Boost)
include(CTest)
include(Catch)
catch_discover_tests(tests)
