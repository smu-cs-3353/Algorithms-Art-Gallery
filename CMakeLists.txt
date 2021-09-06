#Add version and set EXE_NAME
cmake_minimum_required(VERSION 3.20)
project(21f_pa01_miller_and_schmitt)
set(EXE_NAME art_gallery)

#Set inputs
set (input01 "input/input01.txt")

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 14)

add_executable(${EXE_NAME} src/main.cpp src/Wall.cpp src/Wall.hpp)
