/*****************************************************************//**
 * \file   RL_M6D.cpp
 * \brief  Delete Repeated Numbers
 *
 * Write a function called fill() that takes in an entire array, 
 * and the size of the array as parameters. It will fill an array 
 * with integers specified by the user. 
 * 
 * Write a function called isRepeat() that takes in the entire array,
 * the size, and a target number as parameters. The function
 * will check if the target number is repeated in the array, and 
 * return true or false. 
 * 
 * Write a function called delete_numbers that takes in an entire 
 * array, and the size as paramaeters. This function
 * will call isRepeat() and overwrite the array only if the current
 * target number is not repeated. 
 * 
 * Write a function called print() that takes in an entire array and
 * the size, and prints the values. 
 * 
 * Test your functions in main() as shown in the test cases. 
 * 
 * Limit the max size of the array to 25.
 * 
 * Hint: One method is to a new size after overwriting your array, and
 * only print up until this size. 
 *
 * Psuedocode:
 * (1) User inputs size of array
 * (2) Create function called fill() to prompt user for array elements
 * (3) Create function called print() to print array elements
 * (4) Create function called isRepeat, finds if number is repeated
 * (5) Create function called deleteNumbers(), deletes number
 *		if repeat turns true.
 * (6) Call fill(), print(), deleteNumbers(), isRepeat(), and print().
 *
 *
 * \author Ryan Laur
 * \date   February 23, 2021
 *********************************************************************/

// function prototypes
void fill(int numArray[], int size);
bool isRepeat(int numArray[], int repeatedNum, int size);
void deleteNumbers(int numArray[], int& size);
void print(int numArray[], int size);

#include <iostream>
using namespace std;

// main
int main()
{
	// initialize variables
    const int MAX_SIZE = 25;
    int userArray[MAX_SIZE] = {};
    int userSize = 1;

	// only allow users to enter array size 1-25
	do
	{
		if (userSize < 1 || userSize > 25) 
		{
			cout << "Invalid entry! " << endl;
		}
		cout << "Enter the number of elements in your array (1-25): " << endl;
		cin >> userSize;

	} while (userSize < 1 || userSize > 25);

	// function call to fill array
	fill(userArray, userSize);

	// function call to print user-entered array
	cout << "\nArray Entered: ";
	print(userArray, userSize);

	// function call to overwrite array and size with only non-repeating
	deleteNumbers(userArray, userSize);

	// function call to print new array without repeating numbers
	cout << "\nArray with repeated numbers deleted: ";
	print(userArray, userSize);	

	cout << endl;

    return 0;
}

// this function fills an array with user input
void fill(int numArray[], int size)
{
	cout << "Enter " << size << " numbers:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> numArray[i];
	}	
}

// this function finds if a number is repeated, and returns true or false
bool isRepeat(int numArray[], int repeatedNum, int size)
{
	for (int i = 0; i < size; i++)
	{
		// return true if current index is repeated in array
		if (numArray[i] == repeatedNum)
		{
			return true;
		}		
	}
    return false;
}

// this function overwrites the array with only non-repeating values
void deleteNumbers(int numArray[], int& size)
{
	int n = 0;
	for (int i = 0; i < size; i++)
	{
		// only overwrite if current index is not repeated in array
		if (!isRepeat(numArray, numArray[i], n))
		{
			numArray[n] = numArray[i];
			n++;
		}		
	}
	size = n;
}

// this function prints an entire array 
void print(int numArray[], int size)
{
	for (int i = 0; i < size; i++)	
		cout << numArray[i] << ' ';
}
