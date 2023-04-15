cmake_minimum_required(VERSION 3.12)

project(event_tests C CXX ASM)

# Google Test
add_subdirectory(test)
enable_testing()

# Test files
set(TEST_FILES
    #event_test.cpp
    #event_dispatcher_test.cpp
    #event_factory_test.cpp
)

add_executable(${PROJECT_NAME} ${TEST_FILES})
target_link_libraries(${PROJECT_NAME} event gtest gtest_main)
add_test(NAME all_tests COMMAND ${PROJECT_NAME})
