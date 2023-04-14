cmake_minimum_required(VERSION 3.12)

project(picogamepad C CXX ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Include the pico-sdk
set(PICO_SDK_PATH "/usr/share/pico-sdk")
include(pico_sdk_import.cmake)

# Initialize the SDK
pico_sdk_init()

add_subdirectory(picogamepad-board)

target_link_libraries(picomachine # FIXME ##
    )
