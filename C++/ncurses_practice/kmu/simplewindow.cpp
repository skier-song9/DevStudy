#include <ncurses.h>
int main(){
	initscr(); //Curses 모드 시작
	start_color(); //Color 사용 선언
	init_pair(1, COLOR_RED, COLOR_WHITE); //색 속성 설정 (속성식별자, 글자색1,배경색2)
	attron(COLOR_PAIR(1)); //1번 설정으로 속성 적용
	printw("Hello World");
	attroff(COLOR_PAIR(1)); //1번 속성 설정 해제

	refresh(); //실제 스크린에 출력
	getch(); //사용자입력대기
	endwin(); //Curses 모드 종료

	return 0;
}
