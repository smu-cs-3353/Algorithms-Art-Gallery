//
// Created by Logan Schmitt on 9/6/21.
//
#include "Wall.hpp"

Wall::Wall() {
    totalValue = 0;
}

//----------------------------------------------------------------------------------------------------------------------

Wall::Wall(int inWidth, int inHeight) {
    setWidth(inWidth);
    setHeight(inHeight);
    totalValue = 0;
}

//----------------------------------------------------------------------------------------------------------------------

void Wall::setWidth(int inWidth) {
    mWidth = inWidth;
}

//----------------------------------------------------------------------------------------------------------------------

void Wall::setHeight(int inHeight) {
    mHeight = inHeight;
}

//----------------------------------------------------------------------------------------------------------------------

void Wall::printDimensions() {
    cout << "width: " << mWidth << '\n' << "height: " << mHeight;
}

//----------------------------------------------------------------------------------------------------------------------

void Wall::placePainting(Painting painting, int x, int y) {
    painting.setX(x);
    painting.setY(y);
    paintings.push_back(painting);
    totalValue+=painting.getValue();
}

//----------------------------------------------------------------------------------------------------------------------

void Wall::addPaintings(vector <Painting> paintingsToAdd) {
    int currX = 0;
    int currY = 0;
    int rowHeight = 0;
    int vectorSize = paintingsToAdd.size();
    for (int i = 0; i < vectorSize; i++) {
        //set the current painting
        Painting currPainting = paintingsToAdd[i];
        //if the painting fits in the current location, place the painting
        if (currX + currPainting.getWidth() < mWidth && currY + currPainting.getHeight() < mHeight) {
            currPainting.setX(currX);
            currPainting.setY(currY);
            placePainting(currPainting,currX,currY);
            //update the x position
            currX = currX + currPainting.getWidth();
            //if the painting's height is greater than the tallest painting in the row,
            //set the new row height to the taller painting
            if (rowHeight < currPainting.getHeight()) {
                rowHeight = currPainting.getHeight();
            }
            currPainting.display();
        }
        //if the current painting goes over the width, start a new row
        else if (currX + currPainting.getWidth() > mWidth) {
            currY = currY + rowHeight;
            rowHeight=0;
            currX=0;
            //decrement i to attempt to place the current painting on the new row (instead of skip it)
            i--;
        }
    }
}
