#pragma once

class Scoreboard {
public:
    Scoreboard(){

    }

    Scoreboard(int width, int y, int x){
        score_win = newwin(7, width, y, x);
        mission_win = newwin(7, width, y+8, x);
    }

    void initialize(int initial_score){
        clear();
        addBorder();
        mvwprintw(score_win, 1,1, "Score Board");
        mvwprintw(score_win, 2,1, "B : %5d / %5d", cur_length, max_length);
        mvwprintw(score_win, 3,1, "+ : %10d", apple_ctn);
        mvwprintw(score_win, 4,1, "- : %10d", poison_ctn);
        mvwprintw(score_win, 5,1, "G : %10d", gate_ctn);

        mvwprintw(mission_win, 1,1, "Mission Board");
        mvwprintw(mission_win, 2,1, "B: %8d (%s)", mission_length, isMission_length?"v":" ");
        mvwprintw(mission_win, 3,1, "+: %8d (%s)", mission_apple, isMission_apple?"v":" ");
        mvwprintw(mission_win, 4,1, "-: %8d (%s)", mission_poison, isMission_poison?"v":" ");
        mvwprintw(mission_win, 5,1, "G: %8d (%s)", mission_gate, isMission_gate?"v":" ");

        updateScore(initial_score);

        refresh();
    }

    void addBorder(){ //add basic border to a board_win
        box(score_win,0,0);
        box(mission_win,0,0);
    }

    void updateScore(int score){
        // llu = unsinged long long => print 11 width number, if not filled leave the space empty.
        //mvwprintw(score_win, 1, (score_win->_maxx)-11, "%11llu", score);

    }

    void clear(){
        wclear(score_win);
        wclear(mission_win);
    }

    void refresh(){
        wrefresh(score_win);
        wrefresh(mission_win);
    }


private:
    WINDOW *score_win;
    WINDOW *mission_win;
    int cur_length{},max_length{},apple_ctn{},poison_ctn{},gate_ctn{};
    int mission_length{},mission_apple{},mission_poison{},mission_gate{};
    bool isMission_length{},isMission_apple{},isMission_poison{},isMission_gate{};
};
