add_subdirectory(drawables)

add_library(objects objects.cpp objects.h)

target_link_libraries(objects drawables)