cmake_minimum_required(VERSION 3.20)

project(Cube LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(cube
	src/main.cpp
	src/input/Input.cpp
	src/Player.cpp
)

target_link_libraries(cube PRIVATE raylib)
