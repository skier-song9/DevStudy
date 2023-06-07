#pragma once

class Drawable{
public:
    Drawable(){ //default ctor
        y = x = 0;
        icon = ' ';
    }
    Drawable(int y, int x, chtype ch)
    : y(y),x(x),icon(ch){}

    //getter
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    chtype getIcon(){
        return icon;
    }
    
protected:
    int y,x;
    chtype icon; // represents player of game
private:

};
