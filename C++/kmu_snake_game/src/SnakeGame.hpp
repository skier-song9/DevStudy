#pragma once
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include "Board.hpp"
#include "Drawable.hpp"
#include "Apple.hpp"
#include "Empty.hpp"

class SnakeGame{ // main controller class
public:
    SnakeGame(int height, int width){
        board = Board(height,width);
        board.initialize();
        game_over = false;
        // Initialize random seed
        srand(time(nullptr));

    }

    ~SnakeGame(){
        delete apple;
    }

    // get input from user
    void processInput(){
        chtype input = board.getInput();
        // process input

    }

    // update state
    void updateState(){
        int y,x;
        // Create Apple
        board.getEmptyCoordinates(y,x); //get empty location and store y,x coordinates
        if(apple != NULL)
            board.add(Empty(apple->getY(),apple->getX()));
        apple = new Apple(y,x);
        //add an apple to an the location
        board.add(*apple);

        board.add(Drawable(3,5,'#'));

    }

    void redraw(){
        board.refresh();
    }

    // check if the game is over.
    bool isOver(){
        return game_over;
    }

private:
    Board board;
    bool game_over;
    Apple *apple;
};
