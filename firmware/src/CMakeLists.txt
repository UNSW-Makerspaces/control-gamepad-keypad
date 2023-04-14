
# ...

add_subdirectory(monitor)
add_subdirectory(event)
target_link_libraries(your_target monitor event)
