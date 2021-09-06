//
// Created by Logan Schmitt on 9/6/21.
//

#ifndef INC_21F_PA01_MILLER_AND_SCHMITT_WALL_HPP
#define INC_21F_PA01_MILLER_AND_SCHMITT_WALL_HPP

using namespace std;
#include <iostream>

class Wall {

public:
    Wall();
    Wall(int inWidth, int inHeight);
    void printDimensions();

    void setWidth(int inWidth);
    void setHeight(int inHeight);

    int getWidth() { return mWidth; }
    int getHeight() { return mHeight; }

private:
    int mWidth;
    int mHeight;


};


#endif //INC_21F_PA01_MILLER_AND_SCHMITT_WALL_HPP
