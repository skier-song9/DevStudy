# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.26)
cmake_policy(SET CMP0048 NEW)
project(
	Ex00
	LANGUAGES CXX
	DESCRIPTION Ex01_Project
	VERSION 0.1)
message(STATUS ">> PROJECT_NAME: ${PROJECT_NAME}")
# the name of the executable to be built
add_executable(${PROJECT_NAME} Main.cpp)
