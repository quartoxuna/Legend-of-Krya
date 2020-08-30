cmake_minimum_required(VERSION 3.10)

project(PacMan VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# Define source files
file (GLOB SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(PacMan ${SOURCE_FILES})
