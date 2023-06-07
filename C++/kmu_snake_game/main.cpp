#include <ncurses.h>
#include "src/Board.hpp"
#include "src/SnakeGame.hpp"
#include "src/Drawable.hpp"

#define BOARD_DIM 25
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.0

int main(int argc, char const *argv[]) {
    initscr();
    //for test
    cbreak();
    noecho();
    //////////
    refresh();

    SnakeGame game(BOARD_ROWS, BOARD_COLS);

    while(!game.isOver()){
        // 1. get Input from user
        game.processInput();

        // 2. update game state
        game.updateState();

        // 3. redraw display
        game.redraw();
    }

    getch();
    endwin();

    return 0;
}
