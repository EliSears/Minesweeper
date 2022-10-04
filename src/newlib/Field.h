#ifndef FIELD_H
#define FIELD_H

class Field
{
public:
  int x;
  int column;
  int y;
  int row;
  int mine;
  int marked;
  int exploded;
  int unsure;
  int probed;
  int neighbors;
  bool out;

  Field(int column, int row, int mine, int marked, int exploded, int unsure, int probed, int neighbors)
  {
    this->column = column;
    this->row = row;
    this->mine = mine;
    this->marked = marked;
    this->exploded = exploded;
    this->unsure = unsure;
    this->probed = probed;
    this->neighbors = neighbors;
  }

};



#endif //FIELD_H