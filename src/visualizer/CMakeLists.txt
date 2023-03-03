
include_directories(${CMAKE_SOURCE_DIR}/src)

find_library(SDL2_LIB SDL2 SDL-2.0)
find_library(SDL2_IMAGE_LIB SDL2_image)
find_library(SDL2_TTF_LIB SDL2_ttf)

if (NOT SDL2_LIB)
  message(WARNING "SDL2 not found, `visualize` is disabled.")
elseif (NOT SDL2_IMAGE_LIB)
  message(WARNING "SDL2-image not found, `visualize` is disabled.")
elseif (NOT SDL2_TTF_LIB)
  message(WARNING "SDL2-ttf not found, `visualize` is disabled.")
else ()
  include_directories(${SDL2_INCLUDE_DIRS})
  add_library(visualizer STATIC visualizer.c)
  target_link_libraries(visualizer PRIVATE
    sort
    ${SDL2_LIB}
    ${SDL2_IMAGE_LIB}
    ${SDL2_TTF_LIB}
  )
endif ()