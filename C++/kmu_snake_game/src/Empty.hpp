#pragma once
#include <ncurses.h>
#include "Drawable.hpp"

class Empty : public Drawable{
public:
    //Implement ctor
    Empty(int y, int x){
        this->y = y;
        this->x = x;
        this->icon = ' ';
    }

};
