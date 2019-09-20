/***************
*****UNUSED*****
***************/
#ifndef BOARD_H
#define BOARD_H
#include <Space.h>


class Board
{
private:
    Space B[100][100];      //maximum size
    int width;
    int height;
public:
    Board(int xx, int yy){}
    int widthGet(){ return width;}
    int heightGet(){ return height;}
    void setWidth(int xx)
    {
        if (xx>100 && 1>xx)
            width=10;
        else
            width=xx;
    }
    void setHeight(int yy)
    {
        if (yy>100 && 1>yy)
            height=10;
        else
            width=yy;
    }
    void countMine()
    {
    int updateBoard()
    {
    int ccount=0;
    for (int i=-1;i<2;i++){
        if ((choice[0]==0&&i<0)||(choice[1]==(n-1)&&i>0)) continue;   //otherwise detection loops around
        for (int j=-1;j<2;j++){
            if ((choice[1]==0&&j<0)||(choice[1]==(n-1)&&j>0)) continue;   //^^^
            if (Mines[choice[0]+i][choice[1]+j]==1) ccount++;
        }
    }
    Board[choice[0]][choice[1]]=ccount;
    return ccount;
    }


};

#endif // BOARD_H
