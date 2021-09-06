#include <iostream>
#include <fstream>
#include "Wall.hpp"

using namespace std;

<<<<<<< Updated upstream
int main(int argc, char ** argv) {

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cout << "Could not open file" << endl;
        return -1;
    }

    Wall wall;
    wall.createWall(inputFile);
    wall.printDimensions();
=======
int main( int argc, char *argv[] ){
    string inputFileName(argv[1]);
    ArtGallery gallery(inputFileName);
    gallery.displayAllPaintings();

}
>>>>>>> Stashed changes



}
