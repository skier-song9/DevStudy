all : clean main

main : main.cpp src/Board.hpp src/SnakeGame.hpp
	g++ main.cpp -o main -lncurses && ./main

clean :
	rm -f *.o main
