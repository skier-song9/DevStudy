#pragma once
#include "Drawable.hpp"

class Board{
public:
    Board(){ //default ctor
        construct(0,0);
    }
    Board(int height, int width){
        construct(height,width);
    }

    void initialize(){ //initialize the board_win
        clear();
        refresh();
    }

    void addBorder(){ //add basic border to a board_win
        box(board_win,0,0);
    }

    void add(Drawable drawable){ // addAt() by Drawable class
        addAt(drawable.getX(),drawable.getY(),drawable.getIcon());
    }

    void addAt(int y, int x, chtype ch){ //move cursor to location and add char
        mvwaddch(board_win, y,x,ch);
    }

    chtype getInput(){
        return wgetch(board_win);
    }

    void clear(){ //clear the whole board_win
        wclear(board_win);
        addBorder();
    }

    void refresh(){ //refresh the board_win window
        wrefresh(board_win);
    }
private:
    void construct(int height, int width){
        int xMax, yMax;
        getmaxyx(stdscr,yMax,xMax);
        board_win = newwin(height,width,(yMax/2)-(height/2),(xMax/2)-(width/2));
    }
private:
    WINDOW *board_win;

};
