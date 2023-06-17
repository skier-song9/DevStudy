#include <ncurses.h>
#include <string>

using namespace std;

void start_ncurses(bool useRaw, bool useNoecho);
void printMenu(WINDOW *menu, string choices[], int size, int highlight);

int main(int argc, char const *argv[]) {
    initscr();
    noecho();
    cbreak();

    int y,x,yBeg,yMax,xBeg,xMax;

    WINDOW *win = newwin(10,20,10,10);

    // get___yx(screen or window obj,y,x) : get location of screen or windows
    getyx(stdscr, y, x); // get cursor location
    // getbegyx(stdscr, yBeg, xBeg); //get top-left location
    getbegyx(win, yBeg,xBeg);
    getmaxyx(stdscr, yMax, xMax); //get max height, width

    // printw("y,x: %d %d, Beg: %d %d, Max: %d %d",y,x,yBeg,xBeg,yMax,xMax);

    //move cursor to the middle of the screen
    mvprintw(yMax/2,xMax/2,"%d %d",yBeg,xBeg);

    getch();
    endwin();
    return 0;
}
