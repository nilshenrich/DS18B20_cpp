cmake_minimum_required(VERSION 3.10)

# project name
project(DS18B20 VERSION 1.0)

# C++ files to compile
add_executable(DS18B20 ds18b20_test.cpp src/ds18b20.cpp)

# Include folder
include_directories(include)

# Set compiler and linker flags
target_compile_options(DS18B20 PRIVATE -O2 -Wall -fexceptions)
target_link_libraries(DS18B20 -s)

# Set C++17 standard
set_target_properties(DS18B20 PROPERTIES
    CXX_STANDARD 17
    CMAKE_CXX_STANDARD_REQUIRED True
    )
