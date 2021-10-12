cmake_minimum_required(VERSION 3.20)
project(CPPGame)

set(CMAKE_CXX_STANDARD 11)

set(SFML_INCLUDE_DIR "./SFML/include")
set(SFML_LIBRARY_DIR "./SFML/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

file(COPY assets DESTINATION assets)

add_executable(CPPGame main.cpp Player.cpp Player.h Tile.cpp Tile.h Level.cpp Level.h)
target_link_libraries (CPPGame sfml-graphics sfml-window sfml-system)
