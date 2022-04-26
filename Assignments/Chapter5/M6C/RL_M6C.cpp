/*****************************************************************//**
 * \file   RL_M6C.cpp
 * \brief  Partially Filled Arrays
 *
 * Write a void function called fill() that takes an entire array, 
 * the maximum size of the array, and a new size for the array
 * as parameters. Prompt the user to enter up to 10 positive integers,
 * when they are finished entering numbers, they will enter a negative
 * number. The new size of the array will be the number of values
 * that the user entered. 
 *
 * Write a function of type double called average(), that takes in a whole
 * array and the new size as parameters, and returns the mean. 
 *
 * In main, fill the numbers using fill(), and print the mean in main 
 * displaying to 2 decimal places as shown  in the test case. 
 *
 * Limit the max size of the array to 10.
 *
 *
 * Psuedocode:
 * (1) Create function called fill() to prompt user for array elements
 * (2) Create function called average, to calculate the mean
 * (3) Call fill() and average()
 *
 * \author Ryan Laur
 * \date   February 23, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// funtion prototypes
void fill(int numArr[], int size, int& newSize);
double average(const int numArr[], int size);

// main
int main()
{
	// initialize variables
	const int MAX_SIZE = 10;
	int numArray[MAX_SIZE];
	int actualSize = 0;
	
	// function call to fill array
	fill(numArray, MAX_SIZE, actualSize);

	cout << "The average of the " << actualSize << " numbers is: ";

	// set display to 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// function call to calculate mean
	cout << average(numArray, actualSize) << endl;

	return 0;
}

// this function fills an array with user input
void fill(int numArr[], int size, int& newSize)
{
	int i = 0, num;

	// prompt user input
	cout << "Enter up to " << size << " positive numbers: ";
	cin >> num;

	// read up to 10 numbers, only when positive
	while ((num >= 0) && (i < size))
	{
		numArr[i] = num; 
		i++;
		cin >> num;
	}

	// new size is number of values entered, available to main()
	newSize = i;
}

// this function calculates the average of the array
double average(const int numArr[], int size)
{
	double mean = 0.0;

	// sum all values
	for (int i = 0; i < size; i++)
	{
		mean += numArr[i];
	}
	return mean /= static_cast<double>(size);
}
