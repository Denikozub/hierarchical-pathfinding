cmake_minimum_required(VERSION 3.22)
project(hierarchical_pathfinding CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(hierarchical_pathfinding
        node.h types.h)
