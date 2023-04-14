cmake_minimum_required(VERSION 3.12)

project(event C CXX ASM)

set(CMAKE_C_STANDARD 11) 
set(CMAKE_CXX_STANDARD 17)

add_library(event STATIC event.cpp event.h)
target_link_libraries(event PRIVATE monitor)
