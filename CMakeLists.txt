cmake_minimum_required(VERSION 3.23)
project(CC2)

set(CMAKE_CXX_STANDARD 23)

add_executable(CC2 main.cpp Menu.cpp Menu.hpp Business.cpp Business.hpp CCcore.cpp CCcore.hpp)
