#pragma once
#include "Drawable.hpp"
#include <cstdlib>
#include <ncurses.h>
#include "Time.hpp"

class Board{
public:
    Board(){ //default ctor
        construct(0,0, 500);
    }
    Board(int height, int width, int speed){
        construct(height,width,speed);
    }

    void initialize(){ //initialize the board_win
        clear();
        refresh();
    }

    void addBorder(){ //add basic border to a board_win
        char corner{'0'}, leftright{'1'}, topbottom{'2'};

        init_pair(1,COLOR_BLACK,COLOR_BLACK);//corner color pair
        init_pair(2,COLOR_YELLOW,COLOR_YELLOW);//wall color pair

        chtype '1'

        wborder(board_win,leftright,leftright,topbottom,topbottom,corner,corner,corner,corner);

    }

    void add(Drawable drawable){ // addAt() by Drawable class
        addAt(drawable.getY(),drawable.getX(),drawable.getIcon());
    }

    void addAt(int y, int x, chtype ch){ //move cursor to location and add char
        mvwaddch(board_win, y,x,ch);
    }

    chtype getInput(){
        time_t time_last_input = Time::milliseconds();

        chtype input = wgetch(board_win);
        chtype new_input = ERR;

        setTimeout(0);
        while(time_last_input + timeout >= Time::milliseconds()){
            new_input = wgetch(board_win);
        }

        setTimeout(timeout);

        if(new_input != ERR){
            input = new_input;
        }

        return input;
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

    int getTimeout(){
        return timeout;
    }

private:
    void construct(int height, int width, int speed){
        int xMax, yMax;
        getmaxyx(stdscr,yMax,xMax);
        this->height = height;
        this->width = width;

        start_row = (yMax/2)-(height/2);
        start_col = (xMax/2)-(width);
        board_win = newwin(height,width,start_row,start_col);

        timeout = speed;

        // Timeout to repeat
        setTimeout(speed);

        // activate keypad
        keypad(board_win,true);

    }
private:
    WINDOW *board_win;
    int height, width, start_row, start_col;
    int timeout;
};
