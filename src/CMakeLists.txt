
add_subdirectory(queue)
add_subdirectory(state)
add_subdirectory(sort)
add_subdirectory(visualizer)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(${_BINARY_NAME} main.c)
target_compile_options(${_BINARY_NAME} PRIVATE -Ofast -Wall -Wextra -pedantic)
target_link_libraries(${_BINARY_NAME} PUBLIC
  sort
  visualizer
)