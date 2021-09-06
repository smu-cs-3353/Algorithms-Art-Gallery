//
// Created by Logan Schmitt on 9/6/21.
//
#include "Wall.hpp"

Wall::Wall() {

}

Wall::Wall(int inWidth, int inHeight) {
    setWidth(inWidth);
    setHeight(inHeight);
}

void Wall::setWidth(int inWidth) {
    mWidth = inWidth;
}
void Wall::setHeight(int inHeight) {
    mHeight = inHeight;
}

void Wall::printDimensions() {
    cout << "width: " << mWidth  << '\n' << "height: " << mHeight;
}
