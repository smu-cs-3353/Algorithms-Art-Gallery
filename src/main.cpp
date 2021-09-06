#include <iostream>
#include <fstream>
#include "Wall.hpp"

using namespace std;

int main( int argc, char *argv[] ){
    string inputFileName(argv[1]);
    ArtGallery gallery(inputFileName);
    gallery.displayAllPaintings();

}



}
