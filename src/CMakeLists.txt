# Author: Adam Ali
# Date: 03/12/2022
# Description: CMakeLists.txt for the project src directory
set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp *.c)

set(SOURCES ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})
