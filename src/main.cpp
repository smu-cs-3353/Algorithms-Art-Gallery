#include "ArtGallery.h"
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char *argv[] ){
    if(!argv[1]){
        cout<<"Incorrect command line args. Please pass one name of a file inside your input folder."<<endl;
        return 0;
    }
    string inputFileName(argv[1]);
    ArtGallery gallery(inputFileName);
    gallery.bruteForce();
    gallery.expensiveFirst();
    gallery.costPerPixel();
}

