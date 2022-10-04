/***************
*****UNUSED*****
***************/
#ifndef BOARD_H
#define BOARD_H
#include "Space.h"

#include <new>

class Board
{

public:
    Board() {}
    //If all parameters given are non-zero board will begin generation
    Board(uint width, uint height, uint mines);
    ~Board();

    uint width(){ return _width;}
    uint height(){ return _height;}
    uint mines(){ return _mines;}
    bool isGenerated()
    { 
        if( _width == 0) return false;
        return true;
    }

    /**Returns:
     * Success = 0
     * Invalid Dimensions = 1
     */
    int createBoard(uint x, uint y, uint mines);


private:
    Space*** _board;
    uint _width = 0;
    uint _height = 0;
    uint _mines = 0;

    void deployMines();

    int updateNear(uint x, uint y);

    void calcBoardNear();

public:
    bool isReady = false;


};

#endif // BOARD_H
