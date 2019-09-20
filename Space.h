#ifndef SPACE_H
#define SPACE_H


class Space
{
private:
        bool revealed=false;
        bool mine;
        int near;
    public:
        Space(bool mine=false,int near=0) { ///constructor
            this-> mine=mine;
            this-> near=near;
        }
        bool Getrevealed() { return revealed; } //getters
        bool Getmine() { return mine; }
        int Getnear() { return near; }
        void Setrevealed(bool val) { revealed = val; }  //setters
        void Setnear(int val) { near = val; }
        void Setmine(bool val) { mine = val; }

        void print(){       //only prints object if revealed = true
            if(revealed==false) cout<<'-';
            else cout<<near;
        }///print
        void printMaster(){     //prints all objects--for debugging
            if (mine==true) cout<<'M';
            else cout<<near;
        }///debug
};

#endif // SPACE_H
