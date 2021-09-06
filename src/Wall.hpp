//
// Created by Logan Schmitt on 9/6/21.
//

#ifndef INC_21F_PA01_MILLER_AND_SCHMITT_WALL_HPP
#define INC_21F_PA01_MILLER_AND_SCHMITT_WALL_HPP

using namespace std;
#include <iostream>

class Wall {

public:
    void createWall(ifstream &inFile);
    void printDimensions();

private:
    int mWidth;
    int mLength;

    void setLength(int inLength);
    void setWidth(int inWidth);

    int getLength() { return mLength; }
    int getWidth() { return mWidth; }
};


#endif //INC_21F_PA01_MILLER_AND_SCHMITT_WALL_HPP
