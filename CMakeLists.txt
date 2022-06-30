cmake_minimum_required(VERSION 3.16)
project(hierarchical_pathfinding CXX)

set(CMAKE_CXX_STANDARD 20)



add_executable(hierarchical_pathfinding
        node.h types.h cluster.h edge.h path.h graph.h)

set_target_properties(hierarchical_pathfinding PROPERTIES LINKER_LANGUAGE CXX)
