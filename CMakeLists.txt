cmake_minimum_required(VERSION 3.10)

# project name
project(DS18B20 VERSION 1.0)

# C++ files to compile
add_library(ds18b20 SHARED src/ds18b20.cpp)

# Include folder
include_directories(include)

# Set target properties
set_target_properties(ds18b20 PROPERTIES
    PUBLIC_HEADER include/ds18b20.h
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    CXX_STANDARD 17
    CMAKE_CXX_STANDARD_REQUIRED True
    )

# Install rule
include(GNUInstallDirs)
install(TARGETS ds18b20
    EXPORT ds18b20
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libraries
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
