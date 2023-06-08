#pragma once
#include <ncurses.h>
#include "Drawable.hpp"

class Apple : public Drawable{
public:
    //Implement constructor
    Apple(int y,int x){
        this->y = y;
        this->x = x;
        this->icon = 'A';
    }




};
