#include <ncurses.h>
#include "src/Board.hpp"

#define BOARD_DIM 17
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.0

int main(int argc, char const *argv[]) {
    initscr();
    refresh();

    Board board(BOARD_ROWS, BOARD_COLS);


    getch();
    endwin();

    return 0;
}
