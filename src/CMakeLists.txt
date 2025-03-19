cmake_minimum_required(VERSION 3.10)

# Set the project name
project(cppgui)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(glfw3 REQUIRED)

include(FetchContent)
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG master
)
FetchContent_MakeAvailable(glad)

add_subdirectory(windowmanager)

add_subdirectory(includes)


# Add the executable
add_executable(cppgui main.cpp)

target_link_libraries(cppgui windowmanager)