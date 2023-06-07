all: main

main: main.cpp point
	g++ -o -fsanitize=leak,address main main.cpp

point: point.cpp point.hpp
	g++ -o -fsanitize=leak,address point.o