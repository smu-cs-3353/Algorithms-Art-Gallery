//
// Created by tallb on 9/6/2021.
//

#include "ArtGallery.h"

ArtGallery::ArtGallery() {

}

ArtGallery::ArtGallery(std::string inputFileName) {
    std::ifstream inputFile;
    inputFile.open(inputFileName);
    if(inputFile.is_open()){
        std::cout<<inputFileName<<" opened."<<std::endl;
        while(!inputFile.eof()){
            int integer;
            inputFile>>integer;
            std::cout<<integer<<std::endl;
        }
    }
}
