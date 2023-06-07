#include <ncurses.h>
#include "src/Board.hpp"

//Board의 너비 높이 결정
#define BOARD_DIM 20 //board dimension
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5 //shell에서 높이(rows)가 너비(cols)보다 길기 때문. 

int main(int argc,char *argv[]){

    initscr(); //ncurses 모드 시작
    refresh(); // 출력

    //기본 벽 생성
    Board board(BOARD_ROWS,BOARD_COLS); 
    board.initialize();

    getch();
    endwin();

    return 0;
}