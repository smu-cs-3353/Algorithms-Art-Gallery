//
// Created by tallb on 9/6/2021.
//

#ifndef INC_21F_PA01_MILLER_AND_SCHMITT_PAINTING_H
#define INC_21F_PA01_MILLER_AND_SCHMITT_PAINTING_H

#include <iostream>
#include <fstream>

using namespace std;

class Painting {

private:
    int id;
    int value;
    int width, height;
    int x, y;

public:
    Painting();
    Painting(int id, int value, int width, int height);

    int getID() { return id; }
    int getValue(){ return value; }
    int getWidth(){ return width; }
    int getHeight(){ return height; }
    int getX(){ return x; }
    int getY(){ return y; }

    void setID(int);
    void setValue(int);
    void setWidth(int);
    void setHeight(int);
    void setX(int);
    void setY(int);

    void display();

    bool operator<(const Painting &) const;
};


#endif //INC_21F_PA01_MILLER_AND_SCHMITT_PAINTING_H
