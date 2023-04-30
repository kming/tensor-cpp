cmake_minimum_required(VERSION 3.1...3.26)

# set the project name and version
project(
    tensor-cpp
    VERSION 1.0
    LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# subdirectory
add_subdirectory(libs)
add_subdirectory(test)

target_link_libraries(test PRIVATE tensor tensor-ops)
