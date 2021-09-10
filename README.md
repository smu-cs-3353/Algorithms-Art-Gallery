# Fall 2021 CS 3353 PA 01
Blake Miller & Logan Schmitt

## Introduction:
Welcome to Programming Assignment 01 - The Art Gallery! 

## Background:
In this program, we are working for a consulting firm that has been hired by a chain of art galleries to increase revenues. Specifically, we are tasked to design a more effective way of hanging art pieces on the gallery walls. Each wall of the gallery has a set dimension, and each picture a designated value and dimension. We must ultimately determine which pieces should be displayed on the wall in order to maximize revenue.

## Implementation:
In this program, we used a "shelving" algorithm for placement, and three different algorithms for determining the order of painting placement.
The shelving algorithm used works like this:
1. Select the next unplaced painting from the set of paintings; make sure its dimensions are less than the walls dimensions.
2. If the painting fits in the current position (starting at 0,0), place the painting and move the current position to the right of the placed painting (x = x + paintingWidth). If the placed painting is taller than any painting in the row, then we make its height the row height. Restart the loop.
3. If the painting is too wide to fit on the shelf, then we start a new row and attempt to place it on that new row.
4. If the painting is too tall to fit on any new shelf, then we discard it and restart the loop.\
\
It is called the shelving algorithm because it places each painting in rows, almost like a shelf. The order in which objects are placed into these shelves is also based on three different algorithms: 
* The Brute Force Approach - This algorithm will be used for paintings under our 10 painting limit. This algorthm finds every permutation of the list of paintings, and attempts to add them using the shelving algorithm. Whichever permutation results in the greatest value is saved.
* The Most Expensive First - In this algorithm, we sort the pictures in decreasing order by value, and add them to the wall in order, skipping any that will not fit.
* The Custom - Our custom algorithm places the paintings based on the cost per pixel (or unit) of the painting. This algorithm sorts the paintings based on the value of each painting divided by each painting's total area.

## Performance
The effectiveness of the shelving algorithm used in this project depends greatly on the set of input paintings used. Not suprisingly, the brute force algorithm performed the best in every test, since it finds every possible configuration of the paintings placed using the shelving algorithm. The next best performance on average was from our custom algorithm, the price per pixel sorting. This is because placing paintings with the greatest pixel cost guaruntees that you get the most value from the wall space that you cover. The most expensive sorting works differently depending on each data set, but in general it performed the worst. If the most expensive paintings are large and have a lower price per pixel, then this sorting does very poorly. On the other hand, if the price per pixel of each painting is similar, then the most expensive sorting works well because the most expensive tends to maximize the area of the wall covered.

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



The output of the program will be in the form of 3 text files. The prefixes "-highvalue.txt", "bruteforce.txt", and "custom.txt" will be appended on the end of a newly generated file depending on the algorithm that was used to place paintings.  

The format of the output file is as follows:  
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
