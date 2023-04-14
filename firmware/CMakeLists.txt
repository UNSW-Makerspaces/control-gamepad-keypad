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
    hardware_pio
    pico_binary_info
    tinyusb_device 
    tinyusb_board
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(usb_keypad)

#find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)
#if(CPPCHECK_EXECUTABLE)
#    add_custom_target(cppcheck
#        COMMAND ${CPPCHECK_EXECUTABLE}
#            --enable=all
#            --std=c++17
#            --language=c++
#            --platform=native
#            --suppress=missingIncludeSystem
#            --force
#            --inline-suppr
#            -I include/
#            -I src/
#            src/
#            include/
#        COMMENT "Running cppcheck"
#    )
#endif()
