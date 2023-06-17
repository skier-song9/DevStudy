#include <ncurses.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    initscr();
    noecho();

    // Input Mode
    //cbreak(); // allows line bufferring
    // halfdelay(10); // while waiting user inputs, system returns ERR value(-1).
    // nodelay(stdscr,true); //opposite to halfdelay()
    timeout(500); // similar to halfdelay()


    int c;
    while((c=getch())!='x'){ //get char until get 'x' character
        printw("%d\n",c);
    }

    getch();
    endwin();
    return 0;
}
