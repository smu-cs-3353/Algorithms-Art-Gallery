//
// Created by tallb on 9/6/2021.
//

#ifndef INC_21F_PA01_MILLER_AND_SCHMITT_ARTGALLERY_H
#define INC_21F_PA01_MILLER_AND_SCHMITT_ARTGALLERY_H

#include "Painting.h"
#include "Wall.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

class ArtGallery {

private:
    std::string inputFileName;
    std::vector<Painting> paintings;
    Wall wall;

public:
    ArtGallery();
    ArtGallery(std::string);

    void expensiveFirst();
    void bruteForce();
    void costPerPixel();
    void smallestHeight();

    void writeToFile(vector<Painting> inPaintings, std::string outputName);
    void displayAllPaintings();
};


#endif //INC_21F_PA01_MILLER_AND_SCHMITT_ARTGALLERY_H
