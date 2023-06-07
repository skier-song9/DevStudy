#include <ncurses.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //스크린 초기화
    //메모리 set up & 스크린 클리어
    initscr();

    // refreshes the screen to match whats in memory
    refresh();

    // whats for user input, returns int value of that key
    getch();


    endwin(); //ncurses에 대한 메모리를 해제하고 ncurses모드 종료
    
    return 0;
}
