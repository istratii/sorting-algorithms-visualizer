
cmake_minimum_required(VERSION 3.22)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(_BINARY_NAME visualize)
set(_TEST_BINARY_NAME check)

project(visualizer LANGUAGES C)

add_subdirectory(src)
add_subdirectory(tests)
