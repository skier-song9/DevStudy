#include <iostream>
#include "Board.hpp"

Board::Board(int b, int g,int p,int d){
    //mission clear;
    //score = s;
    //mission = m;
    body_mission = b;
    grow_mission = g;
    poison_mission = p;
    gate_mission = d;
}

    void ScoreBoard(int body, int body_max, int grow, int poison, int gate){
        init_pair(3,COLOR_BLACK,COLOR_WHITE);
        wmove(score,0,0);
        wattron(score,COLOR_PAIR(3));
    };
    bool MissionBoard(int body, int gorw, int poision, int gate);
    void gameover();