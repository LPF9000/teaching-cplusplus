/*****************************************************************//**
 * \file   RL_M2C.cpp
 * \brief  Calculate the Distance between objects.
 * 
 * Write a program that reads three doubles from the user for the mass 
 * of two objects in kilograms (m1 and m2), and the 
 * gravitational force (F), between the two objects in Newtons(N). 
 * Calculate the distance between the two objects.
 * In physics, the distance can be calculated by rearranging the 
 * the formula F=G*(m1*m2/r^2), where:
 * G = gravitational constant = 6.67 x 10^-11 N*m^2/kg^2
 * r = distance between the objects
 * 
 * Display the final distance in meters (m), using an integer type with
 * the appropriate size modifier.
 * 
 * Hint: What is the maximum number of digits for type int?
 * 
 * You may use the sqrt function in the library cmath
 * 
 * Pseudocode:
 * 
 * (1) INITIALIZE variables
 * (2) READ m1, m2, and F
 * (3) CALCULATE the distance r
 * (4) DISPLAY the distance r in meters
 * 
 * 
 * \author Ryan Laur
 * \date   January 15, 2021
 *********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	// INITIALIZE variables
	const double G = 6.67430e-11;
	double m1 = 0;
	double m2 = 0;
	double F = 0;
	long long int r = 0;

	// READ m1, m2, and F
	cout << "Welcome to the Universal Distance Calculator!" << endl;
	cout << "Enter the mass of object 1 and object 2 in kilograms (kg), "
		"repsectively: ";
	cin >> m1 >> m2;
	cout << "Enter the graviational Force between the objects in "
		"Newtons (N): ";
	cin >> F;
	
	// CALCULATE the distance r
	r = sqrt(G * m1 * m2 / F);

	// DISPLAY the distance r in meters
	cout << endl << "The distance between the two objects is: ";
	cout << r << " meters";

	return 0;
}