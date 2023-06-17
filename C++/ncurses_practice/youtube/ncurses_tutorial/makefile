all: clean basicPlayerMovement && ./main

hello: hello.cpp
	g++ -o hello hello.cpp -lncurses

windows: windows.cpp
	g++ -o main windows.cpp -lncurses

attr: attributes.cpp
	g++ -o main attributes.cpp -lncurses

getters: getters.cpp
	g++ -o main getters.cpp -lncurses

userInput: userInputs.cpp
	g++ -o main userInputs.cpp -lncurses

menu: menu.cpp
	g++ -o main menu.cpp -lncurses

basicPlayerMovement: basicPlayerMovement.cpp
	g++ -o main basicPlayerMovement.cpp -lncurses

clean:
	rm -f *.o main
