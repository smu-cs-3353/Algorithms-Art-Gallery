#include "ArtGallery.h"
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char *argv[] ){
    if(argc!=2){
        cout<<"Incorrect number of command line args. Please pass one name of a file inside your input folder."<<endl;
        return 0;
    }
    string inputFileName(argv[1]);
    ArtGallery gallery(inputFileName);
    gallery.bruteForce();
    gallery.expensiveFirst();
    gallery.costPerPixel();
}

