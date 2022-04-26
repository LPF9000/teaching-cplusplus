/*****************************************************************//**
 * \file   RL_M5B.cpp
 * \brief  Function Overloading
 *
 * Write a void function called area() that takes in
 * a double for the radius, and prints the area of a circle.
 * 
 * Overload area() to take in an integer for the side length of a 
 * square, and print the area of the square.
 * 
 * Overload area() to take in two integers for length and width, 
 * and print the area of a rectangle. 
 * 
 * Test all the overloaded functions by calling them with their
 * argument(s) as shown in the test case. 
 * 
 * Note: use pi = 3.1459 for area of a circle = pi*r^2
 *
 * Psuedocode:

 * (1) CALL overloaded function area() using double argument 
 *      (a) Calculate area of a circle
 * (2) CALL overloaded function area() using integer argument 
 *      (a) Calculate area of a square
 * (3) CALL overloaded function area() using two integer arguments 
 *      (a) Calculate area of a rectangle
 *
 *
 * \author Ryan Laur
 * \date   February 9, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

void area(double);
void area(int);
void area(int, int);

int main() {
   
    // CALL overloaded function area() using double argument 
    area(1.75);

    // CALL overloaded function area() using integer argument 
    area(5);
    
    // CALL overloaded function area() using two integer arguments 
    area(4, 6);

    return 0;
}

// calculate area of a circle
void area(double radius) 
{
    cout << "Area of circle with radius " << radius << ": " 
        << 3.1459 * radius * radius << endl;
}

// calculate area of a square
void area(int sideLength)
{
    cout << "Area of a square with with a side length of "
        << sideLength << ": " << sideLength * sideLength << endl;
}

// caculate area of a rectangle
void area(int length, int width) {
    cout << "Area of rectancle with a length of " << length <<
        " and a width of " << width << ": " << length * width << endl;
}

