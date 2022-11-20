cmake_minimum_required(VERSION 3.0.0)
project(DataStructures VERSION 0.1.0)

include(CTest)
enable_testing()

# Include 'include' directory
include_directories(include)
FILE(GLOB_RECURSE SOURCES "src/*.c")

# Execute with the --test flag
add_executable(DataStructures ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
