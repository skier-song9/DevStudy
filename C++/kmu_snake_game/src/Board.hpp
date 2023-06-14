#pragma once
#include "Drawable.hpp"
#include <cstdlib>

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

    void getEmptyCoordinates(int &y, int &x){
        //mvwinch(window, y,x) : move cursor to location in window, and return which char is in that location
        do {
            y = rand() % height;
            x = rand() % width;
        } while((mvwinch(board_win,y,x)) != ' ');
    }

    void clear(){ //clear the whole board_win
        wclear(board_win);
        addBorder();
    }

    // for checking gmae over
    chtype getCharAt(int y, int x){
        return mvwinch(board_win,y,x);
    }

    void refresh(){ //refresh the board_win window
        wrefresh(board_win);
    }

    void setTimeout(int timeout){
        wtimeout(board_win,timeout);
    }

    int getStartRow(){
        return start_row;
    }

    int getStartCol(){
        return start_col;
    }

private:
    void construct(int height, int width){
        int xMax, yMax;
        getmaxyx(stdscr,yMax,xMax);
        this->height = height;
        this->width = width;

        start_row = (yMax/2)-(height/2);
        start_col = (xMax/2)-(width/2);
        board_win = newwin(height,width,start_row,start_col);

        // Timeout to repeat
        wtimeout(board_win,1000);

        // activate keypad
        keypad(board_win,true);

    }
private:
    WINDOW *board_win;
    int height, width, start_row, start_col;
};
