#pragma once
#include <ncurses.h>
#include "Board.hpp"
#include "Drawable.hpp"

class SnakeGame{ // main controller class
public:
    SnakeGame(int height, int width){
        board = Board(height,width);
        board.initialize();
        game_over = false;

    }

    // get input from user
    void processInput(){
        chtype input = board.getInput();
        // process the input

    }

    // update state
    void updateState(){
        board.add(Drawable(3,3,'#'));
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
};
