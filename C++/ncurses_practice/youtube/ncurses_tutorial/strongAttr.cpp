#include <ncurses.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[]) {
    initscr();
    // if(has_colors()==FALSE) {
    //     endwin();
    //     printf("Color can't be used.");
    //     exit();
    // }

    start_color();

    // Define 2 color pairs
    init_pair(1,COLOR_YELLOW, COLOR_WHITE);
    init_pair(2,COLOR_RED, COLOR_WHITE);


    // attr_t type : store the attributes by "|".
    attr_t emphasis = A_REVERSE | COLOR_PAIR(2);

    attron(emphasis);
    mvaddch(5,5,'a');
    mvaddch(6,6,'b');
    mvaddch(7,7,'c');
    attroff(emphasis);

    attron(A_BLINK | emphasis);
    mvaddch(8,5,'a');
    mvaddch(9,6,'b');
    mvaddch(10,7,'c');
    attroff(A_BLINK | emphasis);


    // add character's attributes. >> usefull for programming player of games
    chtype c = 'a' | A_REVERSE | COLOR_PAIR(1);
    mvaddch(20,20,c);


    getch();
    endwin();
    return 0;
}
