cmake_minimum_required(VERSION 3.6)
project(ds)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp list.cpp list.h MaxOperator.cpp MaxOperator.h stacktest.cpp tree_isomorphism.cpp tree_leaves.cpp test.cpp tree_travelagain.cpp oneSearchTree.cpp tree_ROOTofAVL.cpp tree_searchTree_operate.cpp)
add_executable(ds ${SOURCE_FILES})