

add_subdirectory(window)
add_subdirectory(objects)
add_subdirectory(errors)

add_library(windowmanager windowmanager.cpp windowmanager.h)

target_link_libraries(windowmanager PRIVATE window objects errors stb glad glfw)