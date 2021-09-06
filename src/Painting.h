//
// Created by tallb on 9/6/2021.
//

#ifndef INC_21F_PA01_MILLER_AND_SCHMITT_PAINTING_H
#define INC_21F_PA01_MILLER_AND_SCHMITT_PAINTING_H
#include <iostream>

class Painting {
private:
    int id;
    int value;
    int width, height;
    int x, y;
public:
    Painting();
    Painting(int id, int value, int width, int height);

    void display();

    int getID();
    int getValue();
    int getWidth();
    int getHeight();
    int getX();
    int getY();

    void setID(int);
    void setValue(int);
    void setWidth(int);
    void setHeight(int);
    void setX(int);
    void setY(int);
};


#endif //INC_21F_PA01_MILLER_AND_SCHMITT_PAINTING_H
