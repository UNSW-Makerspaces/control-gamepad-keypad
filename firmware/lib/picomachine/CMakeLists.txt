cmake_minimum_required(VERSION 3.12)

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

pico_enable_stdio_usb(picomachine 1)
pico_enable_stdio_uart(picomachine 0)

pico_add_extra_outputs(picomachine)

