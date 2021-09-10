//
// Created by Logan Schmitt on 9/6/21.
//
#include "Wall.hpp"

Wall::Wall() {
    totalValue = 0;
}

Wall::Wall(int inWidth, int inHeight) {
    setWidth(inWidth);
    setHeight(inHeight);
    totalValue = 0;
}

/***********************************************************************************************************************
 *
 * @param painting
 * @param x
 * @param y
 * @description
 * Adds the painting to the wall at the specified (x,y) and it updates the total price of the wall.
 */
void Wall::placePainting(Painting &painting, int x, int y) {
    painting.setX(x);
    painting.setY(y);
    paintings.push_back(painting);
    totalValue += painting.getValue();
}


/***********************************************************************************************************************
 *
 * @param paintingsToAdd
 * @description
 *  This algorithm uses placement on "shelves". It takes a vector of paintings representing all the paintings that can
 *  be placed, and it places the items on the wall by adding them to vector in a Wall object.\n
 *  The Algorithm works like this:\n
 *  1. Select the next unplaced painting from the vector; make its dimensions are less than the walls dimensions.\n
 *  2. If the painting fits in the current position (starting at 0,0), place the painting and move the current position
 *     to the right of the placed painting (x = x + paintingWidth). If the painting is taller than any painting in the
 *     row, then we set the new row height.\n
 *  3. If the painting is too wide to fit on the shelf, then we start a new row and attempt to place it on that new row.\n
 *  4. If the painting is too tall to fit, then we discard it and restart the loop.\n
 *
 */
void Wall::addPaintings(vector<Painting> paintingsToAdd) {
    clearWall();
    //debugPlacement shows step by step what the algorithm is doing when set to true
    bool debugPlacement = false;
    int currX = 0;
    int currY = 0;
    int rowHeight = 0;
    int vectorSize = paintingsToAdd.size();
    for (int i = 0; i < vectorSize; i++) {
        //set the current painting
        Painting currPainting = paintingsToAdd[i];
        if(currPainting.getWidth()>mWidth||currPainting.getHeight()>mHeight){
            continue;
        }
        if (debugPlacement) {
            std::cout << "Attempting to place painting #" << currPainting.getID() << " at ("
                      << currX << ", " << currY << ")" << std::endl;
        }
        //if the painting fits in the current location, place the painting
        if (currX + currPainting.getWidth() < mWidth && currY + currPainting.getHeight() < mHeight) {
            placePainting(currPainting, currX, currY);
            if (debugPlacement) {
                std::cout << "Painting #" << currPainting.getID() << " placed at ("
                          << currPainting.getX() << ", " << currPainting.getY() << ")" << std::endl;
            }
            //update the x position
            currX = currX + currPainting.getWidth();
            //if the painting's height is greater than the tallest painting in the row,
            //set the new row height to the taller painting
            if (rowHeight < currPainting.getHeight()) {
                rowHeight = currPainting.getHeight();
                if (debugPlacement) {
                    std::cout << rowHeight << " is the new row height." << std::endl;
                }
            }
        }
            //if the current painting goes over the width, start a new row
        else if (currX + currPainting.getWidth() > mWidth) {
            currY = currY + rowHeight;
            if (debugPlacement) {
                std::cout << "Could not place painting #" << currPainting.getID() << ". "
                          << currX << " + " << currPainting.getWidth() << " > " << mWidth << std::endl;
                std::cout << "Starting new row at y=" << currY << std::endl;
            }
            rowHeight = 0;
            currX = 0;
            //decrement i to attempt to place the current painting on the new row (instead of skip it)
            i--;
        }
        else{
            if(debugPlacement){
                std::cout <<"Painting #" <<currPainting.getID() << " will not fit on the canvas." << std::endl;
            }
        }
        if (debugPlacement) {
            std::cout << std::endl;
        }
    }
}
/***********************************************************************************************************************
 *
 * @description:
 * Removes all paintings from the wall and resets the value of the wall
 *
 */
void Wall::clearWall() {
    paintings.clear();
    totalValue = 0;
}

void Wall::setWidth(int inWidth) {
    mWidth = inWidth;
}

void Wall::setHeight(int inHeight) {
    mHeight = inHeight;
}

void Wall::printDimensions() {
    cout << "width: " << mWidth << '\n' << "height: " << mHeight;
}
