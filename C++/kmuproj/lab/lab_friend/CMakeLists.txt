cmake_minimum_required(VERSION 3.22)
project(
    main
    VERSION 0.1
    DESCRIPTION "friend function lab"
    LANGUAGES CXX)

set(GREETING_MESSAGE "Kookmin Univ.")
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak,address")
add_executable(
    ${PROJECT_NAME}
    main.cpp point.cpp
)