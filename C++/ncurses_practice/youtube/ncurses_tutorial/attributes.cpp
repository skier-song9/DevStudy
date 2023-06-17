#include <ncurses.h>
using namespace std;

int main(int argc, char const *argv[]) {
    // NCURSES START
    initscr();
    //check if the terminal can use color attributes
    if(!has_colors()){
        printw("Terminal does not support color");
        getch();
        return -1;
    }

    //set up color of terminal
    start_color();

    /*
      COLOR_PAIR(n)
      COLOR_BLACK   0
      COLOR_RED     1
      COLOR_GREEN   2
      COLOR_YELLOW  3
      ''_BLUE       4
      ''_MAGENTA    5
      ''_CYAN       6
      ''_WHITE      7
    */

    //init_pair(pari_ID, contents color, bg color)
    //: set a pair1 as contents color yellow and bg color blue.
    init_pair(1,COLOR_YELLOW, COLOR_BLUE);


    //check if user can customize const value
    if(can_change_color()){
        printw("terminal can change color");
        //change COLOR_YELLOW to customized RGB color.
        init_color(COLOR_YELLOW, 0,243,199);
    }

    init_pair(2, COLOR_MAGENTA,COLOR_GREEN);

    /*
     A_NORMAL
     A_STANDOUT
     A_REVERSE      : reverse the color of background and contents
     A_BLINK        : make contents blinking continuously
     A_DIM
     A_BOLD
     A_PROTECT
     A_INVIS        : make contents invisible
     A_ALTCHARSET
     A_CHARTEXT
    */

    attron(COLOR_PAIR(1));
    attron(A_BLINK);
    printw("This is some text");
    attroff(COLOR_PAIR(1));
    attroff(A_BLINK);

    getch();

    endwin();
    return 0;
}
