cmake_minimum_required(VERSION 3.16)
project(hierarchical_pathfinding CXX)
set(CMAKE_CXX_STANDARD 20)

include(CTest)

####### Target #######
add_subdirectory(include/pugixml)
add_library(hierarchical_pathfinding SHARED src/node.h src/path.h src/haversine.h src/graph.h
        src/node.cpp src/path.cpp src/haversine.cpp src/graph.cpp src/astar.cpp src/cluster.cpp)
target_link_libraries(hierarchical_pathfinding pugixml)

####### Tests #######
add_subdirectory(include/doctest)
add_executable(UnitTests tests/unittests.cpp)
target_link_libraries(UnitTests hierarchical_pathfinding doctest)
add_test(NAME UnitTests COMMAND UnitTests)

add_executable(TestUnclustered tests/test_unclustered.cpp)
target_link_libraries(TestUnclustered hierarchical_pathfinding)
add_test(NAME TestUnclustered COMMAND TestUnclustered)

add_executable(TestClustered tests/test_clustered.cpp)
target_link_libraries(TestClustered hierarchical_pathfinding)
add_test(NAME TestClustered COMMAND TestClustered)
