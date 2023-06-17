#include <ncurses.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include "player.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
    initscr();
    cbreak();
    noecho();

    int y,x,ymax,xmax;
    getmaxyx(stdscr,ymax,xmax);
    WINDOW *bgwin = newwin(30,60,ymax/2-15,xmax/2-30);
    box(bgwin,0,0);
    refresh();
    wrefresh(bgwin);

    //make player object and move it
    Player *p = new Player(bgwin, 1,1,'@');
    do {
        p->display();
        wrefresh(bgwin);
        refresh();
    }while(p->getmv()!='x');


    endwin();
    return 0;
}
