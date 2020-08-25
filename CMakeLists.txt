# Set minimum cmake version
cmake_minimum_required (VERSION 3.5)

# Some configuration
set (INCLUDE_DIR "include")
set (SOURCE_DIR "src")

# Define project name
set (PROJECT_NAME "LegendOfKrya")
project(${PROJECT_NAME})

# Include headers
include_directories(${INCLUDE_DIR})

# Add all cpp files as sources
file (GLOB SOURCE_FILES "${SOURCE_DIR}/*.cpp")

# Add executable
add_executable(LegendOfKrya ${SOURCE_FILES})
