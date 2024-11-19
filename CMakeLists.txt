# CMakeLists.txt
cmake_minimum_required(VERSION 3.31.0)

# Set C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the project name
project(Prolog++)

# Add executable
add_executable(prolog++ src/main.cpp)
