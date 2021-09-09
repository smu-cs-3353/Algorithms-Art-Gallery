//
// Created by tallb on 9/6/2021.
//
#include "ArtGallery.h"

ArtGallery::ArtGallery() {

}

/***********************************************************************************************************************
 *
 * @param inputFileName \n the name of the file to parse, assuming the file is in the folder \<working-directory\>/input
 * @description Parses the given file for wall dimensions and number of paintings, then reads in each painting;
 * saving it in a Painting object, and then adding each object to the paintings vector of this object
 *
 */
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

        //sets the attributes of our wall object
        wall.setHeight(wallHeight);
        wall.setWidth(wallWidth);

        //reading in individual painting attributes, add them to vector
        for (int i = 0; i < numPaintings; i++) {
            int id, value, width, height;
            inputFile >> id;
            inputFile >> value;
            inputFile >> width;
            inputFile >> height;
            Painting painting(id, value, width, height);
            paintings.push_back(painting);
        }
    } else {
        cout << "Input File not opened. Make sure the input file exists and is in the form of 'input01.txt'" << endl;
    }
}

/***********************************************************************************************************************
 *
 * @description Only executes with \<=10 paintings. Finds all permutations of the paintings vector and then checks
 * which permutation results in the highest wall cost (using a shelving placement algorithm).
 *
 */
void ArtGallery::bruteForce() {
    if (paintings.size() == 0) {
        cout << "No paintings found." << endl;
        return;
    } else if (paintings.size() > 10) {
        std::cout << "Data set size exceeds maximum for brute force. ";
        std::string fileEndingRemoved = inputFileName.substr(0, inputFileName.length() - 4);
        std::string fullFileName = fileEndingRemoved + "-bruteforce.txt";
        std::cout << fullFileName << " will not be created."<<std::endl;
        return;
    }
    //get all possible permutations of the list of paintings using an STL algo
    vector<vector<Painting>> paintingPermutations;
    sort(paintings.begin(), paintings.end());
    do {
        paintingPermutations.push_back(paintings);
    } while (std::next_permutation(paintings.begin(), paintings.end()));
    //find which permutation has the largest cost
    int greatestCost = 0;
    int greatestCostIndex = 0;
    for (int i = 0; i < paintingPermutations.size(); i++) {
        wall.addPaintings(paintingPermutations[i]);
        if (wall.getTotalValue() > greatestCost) {
            greatestCost = wall.getTotalValue();
            greatestCostIndex = i;
        }
    }
    //place most expensive permutation on wall and output
    wall.addPaintings(paintingPermutations[greatestCostIndex]);
    vector<Painting> wallPaintings = wall.getPaintings();
    writeToFile(wallPaintings, "bruteforce");
}

/***********************************************************************************************************************
 *
 * @description Sorts the paintings vector by value (greatest value first), and then places the paintings on the wall
 * (using a shelving placement algorithm).
 *
 */
void ArtGallery::expensiveFirst() {
    if (paintings.size() == 0) {
        return;
    }
    vector<Painting> sortedPaintings = paintings;
    //sort paintings by value
    sort(sortedPaintings.begin(), sortedPaintings.end(), [](Painting lhs, Painting &rhs) {
        return lhs.getValue() > rhs.getValue();
    });
    //place on wall and output
    wall.addPaintings(sortedPaintings);
    vector<Painting> wallPaintings = wall.getPaintings();
    writeToFile(wallPaintings, "highvalue");
}

/***********************************************************************************************************************
 *
 * @description Sorts the paintings vector by price per pixel ( value / (width * height) ), and then places the
 * paintings on the wall (using a shelving placement algorithm).
 *
 */
void ArtGallery::costPerPixel() {
    if (paintings.size() == 0) {
        return;
    }
    vector<Painting> sortedPaintings = paintings;
    //sort paintings by cost per pixel
    sort(sortedPaintings.begin(), sortedPaintings.end(), [](Painting lhs, Painting &rhs) {
        return ((double)lhs.getValue()/(lhs.getWidth()*lhs.getHeight())) > ((double)rhs.getValue()/(rhs.getWidth()*rhs.getHeight()));
    });
    //place on wall and output
    wall.addPaintings(sortedPaintings);
    vector<Painting> wallPaintings = wall.getPaintings();
    writeToFile(wallPaintings, "custom");
}

/***********************************************************************************************************************
 *
 * NOT USED IN THIS PROJECT
 * @description Sorts the paintings vector by height (smallest first), and then places the paintings on the wall
 * (using a shelving placement algorithm).
 *
 */
void ArtGallery::smallestHeight() {
    if (paintings.size() == 0) {
        return;
    }
    vector<Painting> sortedPaintings = paintings;
    //sort by smallest height
    sort(sortedPaintings.begin(), sortedPaintings.end(), [](Painting lhs, Painting &rhs) {
        return lhs.getHeight() < rhs.getHeight();
    });
    //add to wall and output
    wall.addPaintings(sortedPaintings);
    vector<Painting> wallPaintings = wall.getPaintings();
    writeToFile(wallPaintings, "custom");
}

/***********************************************************************************************************************
 *
 * @param inPaintings \n vector representing the paintings placed on the wall
 * @param outputName \n the type of the output file (highvalue, bruteforce, or custom).
 * @description creates an output file with the specified output. The output file is located in the working directory
 * named inputFileName-outputName.txt.
 *
 */
void ArtGallery::writeToFile(vector<Painting> inPaintings, std::string outputName) {
    //remove the last 4 letters because we assume the input file ends with .txt
    std::string fileEndingRemoved = inputFileName.substr(0, inputFileName.length() - 4);
    std::string fullFileName = fileEndingRemoved + "-" + outputName + ".txt";
    //create and print to file
    ofstream outFile(fullFileName);
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
    std::cout<<fullFileName<<" created successfully."<<std::endl;
}

void ArtGallery::displayAllPaintings() {
    for (Painting painting: paintings) {
        painting.display();
    }
}

