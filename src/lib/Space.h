#ifndef SPACE_H
#define SPACE_H

#include <iostream>

#define mineMask 0xfe
#define revealMask 0xfd
#define flaggedMask 0xfc
#define unsureMask 0xfb

class Space
{
public:
    uint8_t _state; //0:mine 1:revealed 2:flagged 3:unsure 
    int _near;

    Space(uint8_t state = 0,int near=0) ///constructor
    { 
        this->_state = state;
        this->_near= near;
    }
// public:

//     int isRevealed() { return this->_state_; }
//     bool isMine() { return _mine; }
//     int near() const { return _near; }
//     u_char state() const { return _state; }
//     void reveal() { _revealed = true; }  //set space to revealed
//     void setNear(int val) { _near = val; }
//     void mined() { _mine = true; } //set space to mined

//     void print()
//     {
//         if(_revealed==false) std::cout<<'-';
//         else std::cout<<near;
//     }///print
//     void printMaster()
//     {
//         if (_mine==true) std::cout<<'M';
//         else std::cout<<near;
//     }///debug
};

#endif // SPACE_H
