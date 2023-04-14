cmake_minimum_required(VERSION 3.12)

option(PICOMACHINE_DEBUG_MODE "Enable debug mode" OFF)

if(PICOMACHINE_DEBUG_MODE)
    add_compile_definitions(PICOMACHINE_DEBUG_MODE)
endif()

project(picomachine C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Include the pico-sdk
set(PICO_SDK_PATH "/usr/share/pico-sdk")

include(pico_sdk_import.cmake)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(monitor)
add_subdirectory(event)

target_link_libraries(picomachine pico_stdlib monitor event)
