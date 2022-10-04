#include "Board.h"

#include <stdlib.h>
#include <time.h>

Board::Board(uint width, uint height, uint mines){
  this->createBoard(width, height, mines);
}

Board::~Board()
{
  for (uint i = 0; i < this->_width; i++)
  {  
    for (uint j = 0; j < this->_height; j++)
    {
      delete this->_board[i][j];
    }
    delete[] this->_board[i];
  }
  delete this->_board;
}

int Board::createBoard(uint width, uint height, uint mines)
{
  if( width == 0 || height ==0 ) return 1; //cannot have either dimension as 0
  this->_width = width;
  this->_height = height;
  this->_mines = mines;

  //create array of spaces
  this->_board = new Space**[width]; 
  for (uint i = 0; i < this->_width; i++)
  {
    this->_board[i] = new  Space*[height];
    for (uint j = 0; j < this->_height; j++)
    {
      this->_board[i][j] = new Space();
    }
  }
  
  //fill mines
  this->deployMines();

}

void Board::deployMines()
{
  int mine_arr[this->_mines][this->_mines];
  srand(time(NULL));



}

int Board::updateNear(uint x, uint y)
{
  int new_near = 0;
  for(int i = -1; i < 2; i++)
  {
    if((x +i) < 0 || (x + i) > this->_width)  continue;
    for(int j = -1; j < 2; j++)
    {
      if((y + j) < 0 || (y + j) > this->_height)  continue;
      
      if(this->_board[x+i][y+j]->_state & mineMask) new_near++;
    }
  }
  this->_board[x][y]->_near = new_near;

  return new_near;
}