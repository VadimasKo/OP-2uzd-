cmake_minimum_required(VERSION 3.20)

set(This OP-2uzd-plus)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99) # seting c version
set(CMAKE_CXX_STANDARD 11) #seting c++ version
set(CMAKE_POSITION_INDEPENDENT_CODE ON)  # ~not required nice to have

enable_testing() # tells cmake - we will do unit testigng

add_subdirectory(googletest)

set(Headers 
    Include/Classes.hpp
)


set(Sources
    Source/Classes.cpp   
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)