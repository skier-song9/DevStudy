#pragma once
#include <ncurses.h>
#include <ctime>
#include <cstdlib>
#include "Board.hpp"
#include "Drawable.hpp"
#include "Apple.hpp"
#include "Empty.hpp"
#include "Snake.hpp"
#include "Scoreboard.hpp"

// @Controller

class SnakeGame{ // main controller class
public:
    SnakeGame(int height, int width, int speed = 400){
        board = Board(height,width,speed);
        int sb_row{board.getStartRow() + height};
        int sb_col{board.getStartCol()};
        scoreboard = Scoreboard(width, sb_row, sb_col);
        initialize();
    }

    ~SnakeGame(){
        delete apple;
    }

    void initialize(){
        apple = NULL;
        board.initialize();

        score = 0;
        scoreboard.initialize(score);

        game_over = false;
        srand(time(NULL));

        snake.setDirection(down); //set the first direction of snake.
        // 1. make SnakePiece and set location
        // 2. draw on board
        // 3. add to snake queue
        handleNextPiece(SnakePiece(1,1));

        // 4. add other pieces. repeating.
        handleNextPiece(snake.nextHead());
        handleNextPiece(snake.nextHead());
        // set the start direction
        snake.setDirection(right);
        handleNextPiece(snake.nextHead());

        // Create apple
        if(apple == NULL){
            createApple();
        }
    }

    // get input from user
    void processInput(){
        chtype input = board.getInput();
        // process input : handle directional keys and pause state(timeout)

        int old_timeout = board.getTimeout();

        switch(input){
            case KEY_UP:
            case 'w':
                snake.setDirection(up);
                break;
            case KEY_DOWN:
            case 's':
                snake.setDirection(down);
                break;
            case KEY_RIGHT:
            case 'd':
                snake.setDirection(right);
                break;
            case KEY_LEFT:
            case 'a':
                snake.setDirection(left);
                break;
            case 'p': //pause
                board.setTimeout(-1); // block input
                while(board.getInput() != 'p'){ // until user press p again, continue pause
                }
                board.setTimeout(old_timeout);
                break;
            default:
                break;
        }

    }

    // update state
    void updateState(){
        handleNextPiece(snake.nextHead());
        // Create Apple if Apple is not on board
        if(apple == NULL){
            createApple();
        }
    }

    void redraw(){
        board.refresh();
        scoreboard.refresh();
    }

    // check if the game is over.
    bool isOver(){
        return game_over;
    }

    int getScore(){
        return score;
    }

private:
    // 1. check if the next SnakePiece is on blank or apple or wall
    // 2.
    void handleNextPiece(SnakePiece next){
        if(apple != NULL){
            switch (board.getCharAt(next.getY(),next.getX())) {
                case 'A': //if next piece on apple, eatApple
                    eatApple();
                    break;
                case ' ': //if next piece is not on border or apple, move snake ahead.
                {
                    int emptyRow = snake.tail().getY();
                    int emptyCol = snake.tail().getX();
                    // erase the tail on board
                    board.add(Empty(emptyRow,emptyCol));
                    // remove the tail of snake
                    snake.removePiece();
                    break;
                }
                default: // otherwise, game over
                    game_over = true;
                    break;
            }//switch
        }//if

        // add next to board
        board.add(next);
        // add next to snake
        snake.addPiece(next);
    }

    void createApple(){
        int y,x;
        //srand(time(NULL));
        board.getEmptyCoordinates(y,x); //get empty location and store y,x coordinates
        // if(apple != NULL)
        //     board.add(Empty(apple->getY(),apple->getX()));
        apple = new Apple(y,x);
        //add an apple to an the location
        board.add(*apple);
    }

    void eatApple(){
        delete apple;
        apple = NULL;
        score += 100;
        scoreboard.updateScore(score);
    }

private:
    Board board;
    bool game_over;
    Apple *apple;
    Snake snake;
    Scoreboard scoreboard;
    int score;
};
