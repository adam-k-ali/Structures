# Author: Adam Ali
# Date: 03/12/2022
# Description: The root CMakeLists.txt file for the project.
cmake_minimum_required(VERSION 3.10)
project(DSLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)
