//
// Created by tallb on 9/6/2021.
//

#include <algorithm>
#include "ArtGallery.h"
#include "fstream"

ArtGallery::ArtGallery() {

}

ArtGallery::ArtGallery(std::string p_inputFileName) {
    std::ifstream inputFile;
    inputFileName = p_inputFileName;
    inputFile.open("input/" + p_inputFileName);
    if (inputFile.is_open()) {
        std::cout << "File: \"" << inputFileName << "\" opened successfully." << std::endl;

        //reading in wall dimensions and number of paintings
        int wallWidth, wallHeight, numPaintings;
        inputFile >> wallWidth;
        inputFile >> wallHeight;
        inputFile >> numPaintings;
/*        std::cout << "Wall dimensions: " << wallWidth << "x" << wallHeight << std::endl;
        std::cout << "Receiving " << numPaintings << " paintings." << std::endl;*/

        //sets the attributes of our wall object
        wall.setHeight(wallHeight);
        wall.setWidth(wallWidth);

        //reading in individual painting attributes
        for (int i = 0; i < numPaintings; i++) {
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

void ArtGallery::expensiveFirst() {
    if (paintings.size() == 0) {
        return;
    }
    vector<Painting> sortedPaintings = paintings;

    sort(sortedPaintings.begin(), sortedPaintings.end(), [](Painting lhs, Painting &rhs) {
        return lhs.getValue() > rhs.getValue();
    });

    wall.addPaintings(sortedPaintings);
    vector<Painting> wallPaintings = wall.getPaintings();
    writeToFile(wallPaintings, "highvalue");
}

//----------------------------------------------------------------------------------------------------------------------

void ArtGallery::costPerPixel() {
    if (paintings.size() == 0) {
        return;
    }
    vector<Painting> sortedPaintings = paintings;

    sort(sortedPaintings.begin(), sortedPaintings.end(), [](Painting lhs, Painting &rhs) {
        return ((double)lhs.getValue()/(lhs.getWidth()*lhs.getHeight())) > ((double)rhs.getValue()/(rhs.getWidth()*rhs.getHeight()));
    });
    wall.addPaintings(sortedPaintings);
    vector<Painting> wallPaintings = wall.getPaintings();
    writeToFile(wallPaintings, "custom");
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
    //get all possible permutations of the list of paintings using an STL algo
    vector<vector<Painting>> paintingPermutations;
    //list must be sorted in order to use STL algo
    sort(paintings.begin(), paintings.end());
    do {
        paintingPermutations.push_back(paintings);
    } while (std::next_permutation(paintings.begin(), paintings.end()));
    int greatestCost = 0;
    int greatestCostIndex = 0;
    for (int i = 0; i < paintingPermutations.size(); i++) {
        wall.addPaintings(paintingPermutations[i]);
        if (wall.getTotalValue() > greatestCost) {
            greatestCost = wall.getTotalValue();
            greatestCostIndex = i;
        }
    }
    wall.addPaintings(paintingPermutations[greatestCostIndex]);
    vector<Painting> wallPaintings = wall.getPaintings();
    writeToFile(wallPaintings, "bruteforce");
}

//----------------------------------------------------------------------------------------------------------------------

void ArtGallery::smallestHeight() {
    if (paintings.size() == 0) {
        return;
    }
    vector<Painting> sortedPaintings = paintings;

    sort(sortedPaintings.begin(), sortedPaintings.end(), [](Painting lhs, Painting &rhs) {
        return lhs.getHeight() < rhs.getHeight();
    });

    wall.addPaintings(sortedPaintings);
    vector<Painting> wallPaintings = wall.getPaintings();
    writeToFile(wallPaintings, "custom");
}

//----------------------------------------------------------------------------------------------------------------------

void ArtGallery::writeToFile(vector<Painting> inPaintings, std::string outputName) {
    bool debugOutputFile = false;
    //remove the last 4 letters because we assume ith input ends with .txt
    std::string fileEndingRemoved = inputFileName.substr(0, inputFileName.length() - 4);
    std::string fullFileName = fileEndingRemoved + "-" + outputName + ".txt";
    //std::string fullFileName = "../output/" + fileEndingRemoved + "-" + outputName + ".txt";
    ofstream outFile(fullFileName);
    if (debugOutputFile && outFile.is_open()) {
        std::cout << fullFileName << " open." << std::endl;
    }
    outFile << wall.getTotalValue() << endl;
    for (int i = 0; i < inPaintings.size(); ++i) {
        Painting currPainting = inPaintings[i];
        outFile << currPainting.getID() << " "
                << currPainting.getValue() << " "
                << currPainting.getWidth() << " "
                << currPainting.getHeight() << " "
                << currPainting.getX() << " "
                << currPainting.getY() << " "
                << endl;
    }
    outFile.close();
}

