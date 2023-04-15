cmake_minimum_required(VERSION 3.12)

project(event C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# -DPICOMACHINE_TEST=ON
option(PICOMACHINE_BUILD_TESTS "Autotest the picomachine library" OFF)

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


if(PICOMACHINE_TEST)

    # Include the Google testing framework 
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    # event/tests
    add_subdirectory(tests)

    set(SOURCES
        gtest_pmevent.h
        gtest_pmevent.cpp
    )

    # Add an executable for the tests
    # FIXME: All of the files in tests/ are empty currently. 
    add_executable(test_event tests/gtest_pmevent.cpp)
    target_sources(test_event PRIVATE 
        tests/gtest_pmevent.h 
        tests/gtest_pmevent_factory.cpp
        tests/gtest_pmevent_factory.h
        tests/gtest_pmevent_dipatcher.cpp
        tests/gtest_pmevent_dispatcher.h
    )

    # Link the Google Test libraries to the test executable
    target_link_libraries(test_event event ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

endif()
