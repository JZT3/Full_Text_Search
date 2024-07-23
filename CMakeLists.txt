cmake_minimum_required(VERSION 3.5.0)

project(
    "full_text_search" 
    VERSION 0.1.0 
    LANGUAGES C CXX)

# Global CMake variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)
enable_testing()

add_executable(full_text_search main.cpp)

set_property(TARGET full_text_search PROPERTY CXX_STANDARD 17)