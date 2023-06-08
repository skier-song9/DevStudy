all : clean main

main : main.cpp src/Board.hpp src/SnakeGame.hpp src/Apple.hpp src/Drawable.hpp src/Empty.hpp
	g++ main.cpp -o main -lncurses && ./main

clean :
	rm -f *.o main
