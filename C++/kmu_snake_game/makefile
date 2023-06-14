all : clean main

main : main.cpp src/*
	g++ main.cpp -o main -lncurses && ./main

clean :
	rm -f *.o main
