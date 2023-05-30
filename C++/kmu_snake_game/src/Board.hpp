#pragma once

class Board{
public:
    int body_mission;
    int grow_mission;
    int poison_mission;
    int gate_mission;
    WINDOW *score = newwin(15,50,5,100);
    WINDOW *mission = newwin(15,50,26,100);
    Board(int b, int g, int p, int d);
    void ScoreBoard(int body, int body_max, int grow, int poison, int gate);
    bool MissionBoard(int body, int gorw, int poision, int gate);
    void gameover();
private:

};