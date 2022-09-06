cmake_minimum_required(VERSION 3.21)
project(tinyConfig)

set(CMAKE_CXX_STANDARD 23)

add_library(tinyConfig SHARED config.cpp config.h json.hpp)

set_target_properties(tinyConfig PROPERTIES PUBLIC_HEADER "config.h;json.hpp")

install(TARGETS tinyConfig
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})