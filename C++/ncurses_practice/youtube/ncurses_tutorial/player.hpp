#ifndef PLAYER_H
#define PLAYER_H

class Player{
public:
    /*
        win : the window where player start
        y,x : the start location of player
        c : literally represents player
    */
    Player(WINDOW *win, int y, int x, char c);

    void mvup();
    void mvdown();
    void mvleft();
    void mvright();
    int getmv();
    void display();

private:
    int xloc,yloc,xmax,ymax;
    char chr;
    WINDOW *curwin;
};

#endif /* end of include guard: */
