
include_directories(${CMAKE_SOURCE_DIR}/src)

find_library(CRITERION_LIB criterion REQUIRED)

if (NOT CRITERION_LIB)
  message(WARNING "Criterion not found, `check` is disabled.")
else ()
  add_executable(${_TEST_BINARY_NAME} test_queue.c test.c utils.c)
  target_compile_options(${_TEST_BINARY_NAME} PRIVATE -Ofast -Wall -Wextra -pedantic)
  set_target_properties(${_TEST_BINARY_NAME} PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
  )
  target_link_libraries(${_TEST_BINARY_NAME} PUBLIC
    sort
    ${CRITERION_LIB}
  )
endif ()