//
// Created by Logan Schmitt on 9/6/21.
//
#include "Wall.hpp"
#include <fstream>

void Wall::createWall(ifstream &inFile) {
    string rawLength;
    string rawWidth;
    getline(inFile, rawLength, ' ');
    getline(inFile, rawWidth, '\n');

    int length = stoi(rawLength);
    int width = stoi(rawWidth);

    setLength(length);
    setWidth(width);
}

void Wall::setWidth(int inWidth) {
    mWidth = inWidth;
}
void Wall::setLength(int inLength) {
    mLength = inLength;
}

void Wall::printDimensions() {
    cout << "length: " << mLength  << '\n' << "width: " << mWidth;
}
