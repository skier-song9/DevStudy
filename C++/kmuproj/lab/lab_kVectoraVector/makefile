all : main

main: main.cpp kvector.o
	g++ -o main main.cpp kvector.o

kvector.o : kvector.cpp
	g++ -o kvector.o kvector.cpp

clean :
	rm *.o main