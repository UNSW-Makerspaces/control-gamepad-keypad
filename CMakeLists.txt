cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Include the pico-sdk
set(PICO_SDK_PATH "/usr/share/pico-sdk")
include(pico_sdk_import.cmake)

project(usb_keypad C CXX ASM)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Create the executable
add_executable(usb_keypad
    ./src/main.cpp
    ./src/usb_descriptors.cpp
)

target_include_directories(usb_keypad PRIVATE
    ./include
    )

# Link the pico-sdk and tinyusb libraries
target_link_libraries(usb_keypad 
    pico_stdlib
    tinyusb_device 
    tinyusb_board
    )

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(usb_keypad)
