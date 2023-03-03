
include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(sort STATIC
  bubble.c
  cocktail.c
  count.c
  heap.c
  insertion.c
  merge.c
  quick.c
  selection.c
  swap.c
)

target_link_libraries(sort PRIVATE
  queue
  state
)