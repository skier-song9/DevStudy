#pragma once
#include <ncurses.h>
#include "Drawable.hpp"
#include <queue>

enum Direction {
    //assign values for easly checking opposite directin by adding two directions
    up = -1,
    down = 1,
    left = -2,
    right = 2
};

class SnakePiece : public Drawable{
public:
    //Implement constructor
    SnakePiece(){
        this->x = this->y = 0;
        this->icon = '#';
    }
    SnakePiece(int y, int x){
        this->x = x;
        this->y = y;
        this->icon ='#';
    }

private:

};


class Snake{
public:
    Snake(){
        cur_direction = down;
    }
    void addPiece(SnakePiece piece){
        prev_pieces.push(piece);
    }
    void removePiece(){
        prev_pieces.pop();
    }
    SnakePiece tail(){ //front of the queue
        return prev_pieces.front();
    }
    SnakePiece head(){ //back of the queue
        return prev_pieces.back();
    }

    Direction getDirection(){
        return cur_direction;
    }
    void setDirection(Direction d){
        // check if input direction is not opposite to cur_direction
        if (cur_direction + d !=0){ //if they're opposite, "cur + d" is 0.
            cur_direction = d;
        }

    }
    SnakePiece nextHead(){
        int row = head().getY();
        int col = head().getX();

        switch(cur_direction){
            case up:
                row--;
                break;
            case down:
                row++;
                break;
            case left:
                col--;
                break;
            case right:
                col++;
                break;
        }
        return SnakePiece(row,col);
    }
private:
    std::queue<SnakePiece> prev_pieces;
    Direction cur_direction;

};
