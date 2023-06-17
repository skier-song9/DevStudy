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
    WINDOW *menuwin = newwin(6, xMax-12, yMax-8, 5);
    box(menuwin,0,0);
    refresh();
    wrefresh(menuwin);
    // makes it so we can use arrow keys
    keypad(menuwin,true);

    string choices[3] = {"Walk","Jog","Run"};
    int choice;
    int highlight = 0;

    while(1){
        for(int i{}; i<3; i++){
            if(i == highlight){
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin,i+1,1,choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }

        // get user input
        choice = wgetch(menuwin);
        // change the highlight depends on user input
        switch (choice) {
            case KEY_UP:
                highlight--;
                if(highlight==-1){highlight=0;}
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight==3) {highlight=2;}
                break;
            default:
                break;
        }
        // enter key = 10 >> so if press enter, break the while statement
        if(choice == 10) break;
    }

    printw("Your choice was: %s",choices[highlight].c_str());

    getch();
    endwin();
    return 0;
}
