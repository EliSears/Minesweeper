// Eli Sears  Minesweeper
#include <iostream>
using namespace std;
#include <sstream>
#include <fstream>      //for reading config.txt
#include <vector>       //for vector data type
#include <cstdlib>      //for rand() and srand()
#include <ctime>        //for time()
#include "Space.h"      //for Space Board

int side;     //side length
int mine;    //index of number of mines
Space Board[20][20];      //largest possible board
int choice[2];            //player choice

vector <string> readConfig();
void parseConfig(vector <string> Cfg);
void print(void);
void fillBoard(void);
void setMines(void);
void nearCalc(void);
void updateBoard(int x,int y);
bool checkWin(void);
void printFinal(bool win);

int main()
{
    srand((unsigned int)time(0));
    char option;
    vector <string> Cfg;        //stores config file output
    Cfg=readConfig();    parseConfig(Cfg);  //get board size and number of mines
    do{

        fillBoard();    setMines();     nearCalc();  //generate board

        bool win=false,boom=false;         //win and lose variables

        //printFinal(true);   cout<<endl;                  //for debugging

        cout<<"***********************************************************\n"       //splash screen
        <<"*          --MINESWEEPER--                                *\n"
        <<"* There are "<<mine<<" mines hidden in an "<<side<<"x"<<side<<" board               *\n"
        <<"* Enter coordinates to reveal a space on the board        *\n"
        <<"* Each space will display the number of mines touching it *\n"
        <<"* If you reveal a mine you EXPLODE                        *\n"
        <<"* If you reveal all space except for the mines you WIN    *\n"
        <<"***********************************************************";
        print();
        while(!boom||!win){                                         //game loop

            cout<<"\nEnter your coordinates? Enter as \"X[SPACE]Y\": ";
            cin>>choice[1]>>choice[0];
            boom=Board[choice[0]][choice[1]].Getmine(); //check for mine
            updateBoard(choice[0],choice[1]);
            if (boom){                          //losing actions
                cout<<"\nBOOM\nYOU EXPLODED\n";
                printFinal(win);
                cout<<"\nGAME OVER";
                break;
            }
            win=checkWin();
            if (win){                       //winning actions
                cout<<"\n\nYOU WIN!\n";
                printFinal(win);
                cout<<"\nGOOD JOB\n";
                break;
            }
            print();

        }
    (win)?cout<<"try again?":cout<<"New game?"; cout<<"(y/n) ";
    cin>>option;
    }while(option=='y'||option=='Y');
    return 0;
}///main
vector <string> readConfig()        ///reads config file and exempts comment lines from output
{
    vector <string> V;
    string data;
    ifstream fin ("config.txt");
    if (!fin.is_open()) cout<<"NO CONFIG FILE";
    while (!fin.eof()){
        getline(fin,data);
        if (data[0]!='*') V.push_back(data);    //stops lines beginning in * (comments) from being output
    }
    fin.close();
    return V;
}
void parseConfig(vector <string> Cfg)   //gets useful information from config file output
{                                    //it uses .append() because i couldn't get .copy() to work
    string label;
    string data;
    label.append(Cfg[0],0,4);       //takes side length
    if (label=="side") {
        data.append(Cfg[0],13,2);
        stringstream tt(data);
        tt >> side;
    }
    if(side>20 || side<2) side=8;   //if side length is invalid

    label.clear();  data.clear();
    label.append(Cfg[1],10,5);      //takes mines
    if (label=="mines") {
        data.append(Cfg[1],17,3);
        stringstream tt(data);
        tt >> mine;
    }

    if(mine>(side*side)-2){         //if number of mines is invalid
        if (10>side*side) mine=10;
        else mine=(side*side)-2;
    }
    //cout<<"side length: "<<side<<"\tmines: "<<mine;     //for debugging -- outputs info gathered
}
void print(void)    ///prints a 2D array as a grid
{
    cout<<"\n  ";                            //header
    for(int i=0;i<side;i++){ cout<<i<<" ";}
    cout<<"\n-|";
    for(int i=0;i<side;i++){ cout<<"--";}
    cout<<endl;

    for (int i=0;i<side;i++) {
        cout<<i<<"|";                   //side numbers
        for (int j=0;j<side;j++){
            Board[i][j].print();        //prints main grid
            if (j<side-1) cout<<",";
        }
        if (i<side-1) cout<<endl;
    }
}///print
void fillBoard(void)    ///fills Board[][] array with Space objects
{
    for (int i=0;i<side;i++) {
        for (int j=0;j<side;j++){
            Board[i][j]=Space();
        }
    }
}///fillBoard
void setMines(void)     ///sets a certain number of objects in Board[][] as mines -- no pattern
{
    int x,y;
    bool valid=false;
    for (int i=0;i<mine;i++) {      //one cycle per mine
        do{
            x=rand()%side;
            y=rand()%side;
            if(!Board[x][y].Getmine()) valid=true;      //only advances if object chosen is not already a mine

        }while (! valid);
        Board[x][y].Setmine(true);
    }
}///setMines
void nearCalc(void)         ///calculates number of mines bordering each space
{
    int ccount=0;
    for(int x=0;x<side;x++){
        for(int y=0;y<side;y++){
            for (int i=-1;i<2;i++){
                if ((x==0 && i==-1) || (x==(side-1) && i==1)) continue;   //makes sure it doesn't scan outside boundaries of array
                for (int j=-1;j<2;j++){
                    if ((y==0 && j==-1) || (y==(side-1) && j==1 )) continue;   //^^^
                    if (Board[x+i][y+j].Getmine()) ccount++;
                }
            }
            Board[x][y].Setnear(ccount);
            ccount=0;
        }
    }
}///nearCalc
void updateBoard(int x, int y)      ///recursive--takes user input and reveals neighboring tiles if the one chosen is 0
{
    Board[x][y].Setrevealed(true);      //marks chosen space as revealed--will appear in print()
    if(Board[x][y].Getnear()!=0) return;  //base case

    for (int i=-1;i<2;i++){
        if ((x==0 && i==-1) || (x==(side-1) && i==1)) continue;   //prevents scanning outside boundaries of array
        for (int j=-1;j<2;j++){
            if ((y==0 && j==-1) || (y==(side-1) && j==1 )) continue;   //^^^
            if (Board[x+i][y+j].Getrevealed()) continue;      //prevents re-checking already revealed spaces
            Board[x+i][y+j].Setrevealed(true);
            if (Board[x+i][y+j].Getnear()==0) updateBoard(x+i,y+j);     //re-calls function
        }
    }

}///updateBoard
bool checkWin(void) ///checks if player has won -> all non-mine objects are revealed
{
    for (int i=0;i<side;i++) {
        for (int j=0;j<side;j++){
            if(!Board[i][j].Getmine() && !Board[i][j].Getrevealed()) return false;      // if a mine or not revealed->returns false
        }
    }
    return true;
}///checkWin
void printFinal(bool win)       ///for debugging/final game screen
{
    cout<<"\n  ";                            //header
    for(int i=0;i<side;i++){ cout<<i<<" ";}
    cout<<"\n-|";
    for(int i=0;i<side;i++){ cout<<"--";}
    cout<<endl;

    for (int i=0;i<side;i++) {
        cout<<i<<"|";                          //side numbers
        for (int j=0;j<side;j++){
            if(!win && (choice[0]==i && choice[1]==j)) cout<<'X';     //shows mine that killed you (if applicable)
            else Board[i][j].printMaster();     //prints main grid
            if (j<side-1) cout<<",";
        }
        if (i<side-1) cout<<endl;
    }
}///printFinal

