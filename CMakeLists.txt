# Set minimum cmake version
cmake_minimum_required (VERSION 3.5)

# Define include as source directory
set (INCLUDE_DIR "include")
set (SOURCE_DIR "src")

# Define linked libraries
set (LINKED_LIBS "-lsfml-graphics -lsfml-window -lsfml-system")

# Define project name
set (PROJECT_NAME "LegendOfKrya")
project(${PROJECT_NAME})

# Include headers
include_directories(${INCLUDE_DIR})

# Add all cpp files as sources
file (GLOB SOURCE_FILES "${SOURCE_DIR}/*.cpp")

# Add executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LINKED_LIBS})
