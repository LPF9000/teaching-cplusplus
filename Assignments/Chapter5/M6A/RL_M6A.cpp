/*****************************************************************//**
 * \file   RL_M6A.cpp
 * \brief  Arrays with Functions - Calculating scores
 *
 * Write a void function called fill() that fills an array with
 * doubles with the size of the array given by the user. The array and
 * the size are parameters of fill(). Prompt the user for values
 * as shown in the test case. 
 * 
 * Write a void function called print() that takes in two whole arrays
 * and the size as parameters, and prints the values. 
 * 
 * Write a void function called scoreCalc(), that calculates the minimum,
 * maximum, and mean of the array entered by the user. The funtion will
 * take in an array of scores, an array to hold the minimum, maximum,
 * and mean, and the size of the user-entered array as parameters. 
 * 
 * In main, get the size of the array from the user and fill the 
 * array with scores using fill(). Print the scores entered using
 * print(). Then, find the minimum, maximum, and mean score
 * using scoreCalc(). Print the min, max, and mean scores 
 * in main displaying to 2 decimal places. 
 * 
 * Limit the max size of the array of scores to 15. 
 * 
 * Hint: Store the min/max/mean in an array of size 3.  
 *
 * Psuedocode:
 * (1) User inputs size of array
 * (2) Create function called fill() to prompt user for array elements
 * (3) Create function called print() to print array elements
 * (4) Create function called scoreCalc, to calculate min/max/mean
 * (6) Call fill(), print(), scoreCalc() and print()
 *
 * \author Ryan Laur
 * \date   February 23, 2021
 *********************************************************************/

// function prototypes
void fill(double scoreArray[], int size);
void print(double scoreArray[], double calcArray[], int size);
void scoreCalc(double scoreArray[], double calcArray[], int size);

#include <iostream>
using namespace std;

// main
int main()
{
	// initialize variables
	const int MAX_SIZE = 15;
	int userSize = 1;
	double scores[MAX_SIZE]{};
	double calcArr[3]{ 0.0 };

	// only allow users to enter array size 1-15
	do
	{
		if (userSize < 1 || userSize > 15)
		{
			cout << "Invalid entry" << endl;
		}
		cout << "Enter the number of scores to enter (1-15): ";
		cin >> userSize;

	} while (userSize < 1 || userSize > 15);

	cout << endl;

	// set display to 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// function call to fill array
	fill(scores, userSize);

	// function call to calculate min, max, and mean score
	scoreCalc(scores, calcArr, userSize);

	// function call to print user-entered array
	print(scores, calcArr, userSize);

    return 0;
}

// this function fills an array with user input
void fill(double scoreArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		do
		{
			// only allow numbers greater or equal to 0
			if (scoreArray[i] < 0.0)
			{
				cout << "Invalid entry" << endl;
			}
			cout << "Enter score " << i + 1 << ": ";
			cin >> scoreArray[i];

		} while (scoreArray[i] < 0.0);
	}
}

// this function prints an entire array and displays the min/max/mean
void print(double scoreArray[], double calcArray[], int size)
{
	cout << "\nScores Entered: ";

	for (int i = 0; i < size; i++)
		cout << scoreArray[i] << ' ';

	// display min, max, and mean
	cout << "\nMin: " << calcArray[0] << endl;
	cout << "Max: " << calcArray[1] << endl;
	cout << "Mean: " << calcArray[2] << endl;
}

// this function calculates the min, max, and mean of the scores
void scoreCalc(double numArray1[], double calcArray[], int size)
{
	calcArray[0] = numArray1[0];
	calcArray[1] = numArray1[0];

	for (int i = 0; i < size; i++)
	{
		// save the MIN in calcArray[0]
		if (numArray1[i] < calcArray[0]) 
		{
			calcArray[0] = numArray1[i];
		}
		
		// save the max in calcArray[1]
		if (numArray1[i] > calcArray[1]) {
			calcArray[1] = numArray1[i];
		}

		// sum of array values for the mean in calcArray[2]
		calcArray[2] += numArray1[i];
	}
	// place the mean in calcArray[2]
	calcArray[2] /= static_cast<double>(size);
}
