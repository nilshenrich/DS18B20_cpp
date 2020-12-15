cmake_minimum_required(VERSION 3.10)

# project name
project(DS18B20 VERSION 1.0)

# C++ files to compile
add_library(ds18b20 STATIC src/ds18b20.cpp)

# Include folder
include_directories(include)

# Set C++17 standard
set_target_properties(ds18b20 PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    CXX_STANDARD 17
    CMAKE_CXX_STANDARD_REQUIRED True
    )
