cmake_minimum_required(VERSION 3.10)
project(SortingVisualiser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(sorting_visualiser ${SOURCES})

# Include directories
target_include_directories(sorting_visualiser PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Compiler flags
if(MSVC)
    target_compile_options(sorting_visualiser PRIVATE /W4)
else()
    target_compile_options(sorting_visualiser PRIVATE -Wall -Wextra -O2)
endif()

# Optional: Graphics library (SDL2, SFML, or Web)
option(USE_SDL2 "Use SDL2 for graphics" OFF)
option(USE_SFML "Use SFML for graphics" OFF)
option(WEB_VERSION "Build web version" ON)

if(USE_SDL2)
    find_package(SDL2 REQUIRED)
    target_link_libraries(sorting_visualiser PUBLIC SDL2::SDL2)
    target_compile_definitions(sorting_visualiser PRIVATE USE_SDL2)
endif()

if(USE_SFML)
    find_package(SFML REQUIRED COMPONENTS graphics window system)
    target_link_libraries(sorting_visualiser PUBLIC sfml-graphics sfml-window sfml-system)
    target_compile_definitions(sorting_visualiser PRIVATE USE_SFML)
endif()
