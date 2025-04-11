# CMakeLists.txt file for Bag project
cmake_minimum_required(VERSION 3.10)
project(BagExample VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable target with source files
add_executable(bag
    main.cpp
    Bag.cpp
)
