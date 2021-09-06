//
// Created by tallb on 9/6/2021.
//

#include "ArtGallery.h"

ArtGallery::ArtGallery() {

}

ArtGallery::ArtGallery(std::string inputFileName) {
    //open file
    std::ifstream inputFile;
    inputFile.open(inputFileName);
    if (inputFile.is_open()) {
        std::cout << "File: \"" << inputFileName << "\" opened successfully." << std::endl;

        //reading in wall dimensions and number of paintings
        int wallWidth, wallHeight, numPaintings;
        inputFile >> wallWidth;
        inputFile >> wallHeight;
        inputFile >> numPaintings;
        std::cout << "Wall dimensions: " << wallWidth << "x" << wallHeight << std::endl;
        std::cout << "Receiving " << numPaintings << " paintings." << std::endl;

        //sets the attributes of our wall object
        wall.setHeight(wallHeight);
        wall.setWidth(wallWidth);

        //reading in individual painting attributes
        while (!inputFile.eof()) {
            int id, value, width, height;
            inputFile >> id;
            inputFile>>value;
            inputFile>>width;
            inputFile>>height;
            Painting painting(id,value,width,height);
            paintings.push_back(painting);
        }

    }
}

void ArtGallery::displayAllPaintings() {
    for(Painting painting : paintings){
        painting.display();
    }
}
