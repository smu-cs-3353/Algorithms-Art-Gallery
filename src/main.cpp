#include "ArtGallery.h"
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char *argv[] ){
    string inputFileName(argv[1]);
    ArtGallery gallery(inputFileName);
    gallery.bruteForce();
    gallery.expensiveFirst();
    gallery.costPerPixel();
}

