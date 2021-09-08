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

class ArtGallery {

private:
    std::vector<Painting> paintings;
    Wall wall;

public:
    ArtGallery();
    ArtGallery(std::string);

    void placePaintings();
    void displayAllPaintings();

    void expensiveFirst();
    void bruteForce();

    void writeToFile(vector<Painting> inPaintings, ofstream &outFile);
};


#endif //INC_21F_PA01_MILLER_AND_SCHMITT_ARTGALLERY_H
