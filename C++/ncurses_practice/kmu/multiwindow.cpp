#include <ncurses.h>
int main(){
	initscr();
	start_color();
	init_pair(1,COLOR_RED,COLOR_WHITE);
	box(stdscr,0,0);
	attron(COLOR_PAIR(1));
	wbkgd(stdscr, COLOR_PAIR(1)); // 윈도우 바탕색 컬러 설정

	//기본 윈도우 내의 서브윈도우 생성
	WINDOW *win = subwin(stdscr,5,60,10,10); //(,left-top x, width, left-top y, height)
	init_pair(2,COLOR_BLACK,COLOR_BLUE);
	box(win,0,0);
	attron(COLOR_PAIR(2));
	wbkgd(win, COLOR_PAIR(2));
	refresh();

	getch();
	delwin(win);
	endwin();

	return 0;
}
