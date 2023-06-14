#pragma once

class Scoreboard {
public:
    Scoreboard(){

    }

    Scoreboard(int width, int y, int x){
        score_win = newwin(3, width, y, x);
    }

    void initialize(int initial_score){
        clear();
        mvwprintw(score_win, 1,1, "Score: ");
        updateState(initial_score);
        refresh();
    }

    void updateState(int score){
        // llu = unsinged long long => print 11 width number, if not filled leave the space empty.
        mvwprintw(score_win, 1, (score_win->_maxx)-10, "%11llu", score);

    }

    void clear(){
        wclear(score_win);
    }

    void refresh(){
        wrefresh(score_win);
    }


private:
    WINDOW *score_win;


};
