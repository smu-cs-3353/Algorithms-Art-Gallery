//
// Created by tallb on 9/6/2021.
//

#include <algorithm>
#include "ArtGallery.h"
#include "fstream"
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
        for(int i=0;i<numPaintings;i++) {
            int id, value, width, height;
            inputFile >> id;
            inputFile >> value;
            inputFile >> width;
            inputFile >> height;
            Painting painting(id, value, width, height);
            paintings.push_back(painting);
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------

void ArtGallery::displayAllPaintings() {
    for (Painting painting: paintings) {
        painting.display();
    }
}

//----------------------------------------------------------------------------------------------------------------------

void ArtGallery::placePaintings() {
//    wall.addPaintings(paintings);
}

//----------------------------------------------------------------------------------------------------------------------

void ArtGallery::expensiveFirst() {
    ofstream outFile("./output/output-highvalue.txt");

    if (paintings.size() == 0) {
        return;
    }
    vector<Painting> sortedPaintings = paintings;

    sort(sortedPaintings.begin(), sortedPaintings.end(), [](Painting lhs, Painting &rhs) {
        return lhs.getValue() > rhs.getValue();
    });

    for(int i = 0; i < sortedPaintings.size(); ++i) {
        cout << "id: " << sortedPaintings[i].getID() << " : " << "value: " << sortedPaintings[i].getValue() << endl;
    }

    wall.addPaintings(sortedPaintings);
    vector<Painting> wallPaintings = wall.getPaintings();
    writeToFile(wallPaintings, outFile);
}

//----------------------------------------------------------------------------------------------------------------------

void ArtGallery::bruteForce() {
    if (paintings.size() == 0) {
        cout << "No paintings found." << endl;
        return;
    } else if (paintings.size() > 10) {
        cout << "data set size exceeds maximum" << endl;
        return;
    }
//TODO: BruteForce implementation
}

//----------------------------------------------------------------------------------------------------------------------

void ArtGallery::writeToFile(vector<Painting> inPaintings, ofstream &outFile) {
    outFile << wall.getTotalValue() << endl;
    for(int i = 0; i < inPaintings.size(); ++i) {
        Painting currPainting = inPaintings[i];
        outFile << currPainting.getID() << " "
                << currPainting.getValue() << " "
                << currPainting.getWidth() << " "
                << currPainting.getHeight() << " "
                << currPainting.getX() << " "
                << currPainting.getY() << " "
                << endl;
    }
}

