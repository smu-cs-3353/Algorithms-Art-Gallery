# Fall 2021 CS 3353 PA 01
Blake Miller & Logan Schmitt

## Introduction:
Welcome to Programming Assignment 01 - The Art Gallery! 

## Background:
In this program, we are working for a consulting firm that has been hired by a chain of art galleries to increase revenues. Specifically, we are tasked to design a more effective way of hanging art pieces on the gallery walls. Each wall of the gallery has a set dimension, and each picture a designated value and dimension. We must ultimately determine which pieces should be displayed on the wall in order to maximize revenue.

## Implementation:
In this program, there are three algorithms for determining which painting will be on the wall. 
1. The Brute Force Approach - This algorithm will be used for paintings under our 10 painting limit. The objective of this algorithm is to find the maximum value of a subset of pictures on the wall through a 'brute-force' approach.
2. The Most Expenisve First - In this algorithm, we sort the pictures in decreasing order by value, add them to the wall in order, and skip any that will not fit.
3. The Custom - The algorithm we implemented will place the painting based on the cost per unit of the painting. This algorithm takes the value of the painting and divides it by the paintings total area to then sort the paintings based on greatest cost per unit.

## Build and Run:
This program takes in a single command line argument representative of the name of the input file. If this argument is not supplied or improperly supplied, the program will return a message to the console asking the user to make sure the file is in the correct format.

## Sample Input & Output:
The formatting of the input file is as follows:
* Line 1 contains two integers separated by a space representing the length and height of the wall, respectively 
* Line 2 contains a single integer n that represents the total number of art pieces to follow 
* Lines 3 to (3 + (n-1)) contain 4 integers each separated by spaces:
  * first integer is the picture ID 
  * second integer is the value of the picture 
  * third integer is the width of the picture 
  * fourth integer is the height of the picture.


Sample Input:

**1024 768  
4  
12 300 1023 767  
9 200 300 100  
23 250 800 700  
1 100 100 100**  
---
The output of the program will be in the form of 3 text files. The prefixes "-highvalue.txt", "bruteforce.txt", and "custom.txt" will be appended on the end of a newly generated file depending on the algorithm that was used to place paintings.  

The format of the ouput file is as follows:  
* The first line should contain a single integer representing the cumulative value of all pieces of art placed on the wall for this particular algo. 
* Each additional line represents a picture and should consist of 6 integers, each separated by a space 
  * first integer is the picture id 
  * second integer is the value of that picture 
  * third integer is the width of that picture 
  * fourth integer is the height of that picture 
  * fifth integer is the x coordinate of the upper left corner of the picture on the wall 
  * sixth integer is the y coordinate of the upper left corner of the picture on the wall
  
Sample Output:

**300  
1 100 100 100 0 0  
9 200 300 100 100 0**  
