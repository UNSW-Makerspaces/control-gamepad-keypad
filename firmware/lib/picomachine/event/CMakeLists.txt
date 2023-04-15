cmake_minimum_required(VERSION 3.12)

project(event C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    event.h
    event.tpp
    event_factory.h
    event_factory.cpp
    event_dispatcher.h
    event_dispatcher.cpp
)

add_library(event STATIC ${SOURCES})
target_link_libraries(event PRIVATE monitor)
