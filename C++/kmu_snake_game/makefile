all : clean main

main : main.cpp src/Board.hpp
	g++ main.cpp -o main -lncurses && ./main

clean :
	rm -f *.o main
