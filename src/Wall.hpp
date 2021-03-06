//
// Created by Logan Schmitt on 9/6/21.
//

#ifndef INC_21F_PA01_MILLER_AND_SCHMITT_WALL_HPP
#define INC_21F_PA01_MILLER_AND_SCHMITT_WALL_HPP

using namespace std;
#include "Painting.h"
#include <iostream>
#include <vector>

class Wall {

private:
    int mWidth;
    int mHeight;
    int totalValue;
    vector<Painting> paintings;

public:
    Wall();
    Wall(int inWidth, int inHeight);

    void placePainting(Painting&, int, int);
    void addPaintings(vector<Painting>);
    void clearWall();
    void printDimensions();

    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }
    int getTotalValue() { return totalValue; }
    vector<Painting> getPaintings() { return paintings; }

    void setWidth(int inWidth);
    void setHeight(int inHeight);
};


#endif //INC_21F_PA01_MILLER_AND_SCHMITT_WALL_HPP
