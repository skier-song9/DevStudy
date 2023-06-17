#include <ncurses.h>
#include <string>
using namespace std;

void start_ncurses(bool useRaw, bool useNoecho);
void printMenu(WINDOW *menu, string choices[], int size, int highlight);

int main(int argc, char const *argv[]) {
    initscr();
    noecho();
    cbreak();

    // get screen size
    int yMax,xMax;
    getmaxyx(stdscr,yMax,xMax);

    // create a window for our input
    WINDOW *inputwin = newwin(3, xMax-12, yMax-5, 5);
    box(inputwin,0,0);
    refresh();
    wrefresh(inputwin);

    // makes it so we can use arrow keys
    keypad(inputwin,true);
    
    int c = wgetch(inputwin);
    if(c == KEY_UP){
        mvwprintw(inputwin,1,1,"You pressed key up!!!");
        wrefresh(inputwin);
        // refresh();
    }



    getch();
    endwin();
    return 0;
}
