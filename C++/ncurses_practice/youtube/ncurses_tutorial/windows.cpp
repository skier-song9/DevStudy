#include <ncurses.h>
using namespace std;
int main(int argc, char const *argv[]) {
    initscr();

    // Line buffering disabled.
    //if you press any key, it will show on screen immidiately
    //But if you press "ctrl + c" you can exit program
    // cbreak(); //this is default setting

    // same as cbreak() but you can't exit even though you press ctrl+c
    raw();

    // inputs that users type don't show up on screen
    noecho();


    //set values
    int height,width,start_y,start_x;
    height = 10;
    width = 20;
    start_y = start_x = 10;
    //just create window, it doesn't show window on screen
    WINDOW *win = newwin(height,width,start_y,start_x);
    refresh(); //refresh the whole screen.

    //put an border around window
    //box(window obj, left&right char, top&bottom char)
    // box(win,65,69);

    int left,right,top,bottom,tlc,trc,blc,brc;
    left = right = (int)'g';
    top = bottom = (int)'h';
    tlc = trc = blc = brc = (int)'+';
    //wborder(window obj, ~~~) : customize border shape
    wborder(win,left,right,top,bottom,tlc,trc,blc,brc);

    wrefresh(win); //refresh the specific window

    //print sth on window
    //wprintw(window obj, const char *)
    //wprintw(win,"this is my box");
    // move the cursor and then wprintw() >> mvwprintw(win,location,string)
    mvwprintw(win,1,1,"this is my box");
    wrefresh(win);

    getch();
    getch();

    endwin();

    return 0;
}
