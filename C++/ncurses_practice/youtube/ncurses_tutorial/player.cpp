#include "player.hpp"
#include <ncurses.h>
Player::Player(WINDOW *win, int y, int x, char c){
    curwin = win;
    yloc = y;
    xloc = x;
    getmaxyx(curwin, ymax,xmax);
    keypad(curwin,true);
    chr = c;
};

void Player::mvup(){
    mvwaddch(curwin,yloc,xloc,' ');
    yloc--;
    // make sure yloc does not go out of bounds.
    if(yloc < 1){
        yloc = 1;
    }
};
void Player::mvdown(){
    mvwaddch(curwin,yloc,xloc,' ');
    yloc++;
    if(yloc > ymax-2){
        yloc = ymax-2;
    }
};
void Player::mvleft(){
    mvwaddch(curwin,yloc,xloc,' ');
    xloc--;
    if(xloc<1){
        xloc = 1;
    }
};
void Player::mvright(){
    mvwaddch(curwin,yloc,xloc,' ');
    xloc++;
    if(xloc>xmax-2){
        xloc = xmax - 2;
    }
};
int Player::getmv(){
    int choice = wgetch(curwin);
    switch (choice) {
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
            mvleft();
            break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
            break;
    }
    return choice;
};
void Player::display(){
    mvwaddch(curwin,yloc,xloc,chr);
};
