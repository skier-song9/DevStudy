#include <ncurses.h>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    //initialize screen
    //sets up memory and clears the screen
    //start ncurses mode
    initscr();

    //moves the cursor to the specified location
    //in this case, size of cursor equals to row,column size.
    // it means row size is bigger than column size.
    int x,y;
    x = y = 10;
    move(y,x);

    //prints a string(const char *) to a window
    printw("Hello world");
    // cout << "\n"; // this doesn't work
    printw("\n"); // for linefeed, do this.

    //show(refresh) the screen with whats in memory
    refresh();

    //wait for use input, returns int value of that key(keyboard key)
    int c = getch();
    refresh();
    // move(0,0);
    // printw("printw works like printf: %d",c);

    //mvprintw() : move() + printw()
    mvprintw(0,0,"printw works like printf: %d",c);
    refresh();

    // clears the screen
    // 
    clear();

    getch();
    endwin();
    // deallocate memory and ends ncurses mode

    return 0;
}
