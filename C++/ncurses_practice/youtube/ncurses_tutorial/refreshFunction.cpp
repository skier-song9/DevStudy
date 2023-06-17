#include <ncurses.h>
using namespace std;
int main(int argc, char const *argv[]) {
    initscr();

    //when you add sth to screen, it actually add to a virtual screen,
    // not showing it directly.
    // by calling refresh() it will be shown.

    WINDOW *win = newwin(10,30,0,0);
    box(win,0,0); // this box window is in virtual memory.
    refresh(); // update the standard screen(stdscr).
    // wrefresh(win);

    /*
if there's some windows to show, call wrefresh() rather than refresh().
    refresh() function refreshes windows have no changes.
if you want to show window with an user inputs, do not use wrefresh() and wgetch()
    at the same time. wgetch() can also refreshing windows.
    */
    wgetch(win);

    getch();
    endwin();


    return 0;
}
