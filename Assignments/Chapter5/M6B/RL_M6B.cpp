/*****************************************************************//**
 * \file   RL_M6B.cpp
 * \brief  Bubble Sort
 *
 * Use a bubble sorting algorithmm to sort elements of an array. 
 * 
 * 1. Create a function called fill that fills an array with
 * integers from the user with user-specified size. The size
 * of the array can be assumed to be no larger than 25. 
 * 
 * 2. Create a function called print() that takes in an entire 
 * array and the size, and prints the array. 
 * 
 * 3. Create a function called bubbleSort() that takes in an
 * array, array size, and option as paramaters. The option will
 * determine if the sorting algorithm sorts in ascending or 
 * descending order. 
 * 
 * 4. Test your functions in main as shown in the test cases. 
 * 
 *
 * Psuedocode:
 * (1) User inputs size of array
 * (2) Create function called fill() to prompt user for array elements
 * (3) Create function called print() to print array elements
 * (4) Create function called bubbleSort to sort elements
 * (5) Call fill(), print() in main()
 * (6) prompt user for option to sort in descending or ascending order
 * (7) call bubbleSort and print().
 * 
 *
 * \author Ryan Laur
 * \date   February 23, 2021
 *********************************************************************/

void fill(int userArray[], int size);
void print(int numArray[], int size);
void bubbleSort(int numArray[], int size, int option);

#include <iostream>
using namespace std;

int main()
{
	const int MAX_SIZE = 25;
	int userSize = 1, userOption = 1;
	int numArr[MAX_SIZE]{};

	// only allow users to enter array size 1-25
	do
	{
		if (userSize < 1 || userSize > 25)
		{
			cout << "Invalid entry" << endl;
		}
		cout << "Enter the size of the array (1-25): ";
		cin >> userSize;

	} while (userSize < 1 || userSize > 25);

	cout << endl;

	// function call to fill array
	fill(numArr, userSize);

	// prompt user to sort ascending or descending
	cout << "(1) Sort Ascending" << endl;
	cout << "(2) Sort Descending" << endl;
	cout << "\nChoose an option (Enter 1 or 2): ";
	cin >> userOption;

	// only allow users to enter option 1 or 2
	while (userOption != 1 && userOption != 2) {
		cout << "Invalid entry. ";
		cout << "Choose an option (Enter 1 or 2): ";
		cin >> userOption;
	}

	// function call to print user-entered array
	cout << "\nArray Entered: ";
	print(numArr, userSize);

	// function call to sort array 
	bubbleSort(numArr, userSize, userOption);

	// function call to print user-entered array
	cout << "\nSorted Array: ";
	print(numArr, userSize);

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

// this function prints an entire array 
void print(int numArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << numArray[i] << ' ';
	}
	cout << endl;
}

// bubble sorting algorithm for descending or ascending
void bubbleSort(int numArray[], int size, int option)
{
	int n = 1;
	// iterates through the entire array from right to left. 
	for (int i = size - 1; i > 0; i--)
	{
		// loops from 0 to i, with i getting smaller by 1 each time
		for (int j = 0; j < i; j++)
		{
			// ascending
			if (option == 1)
			{
				// if current position is larger than next position, swap
				if (numArray[j] > numArray[j + 1])
				{
					// Swap the numbers
					int temp = numArray[j + 1];
					numArray[j + 1] = numArray[j];
					numArray[j] = temp;
				}
			}
			else
			{
				// if current position is less than next position, swap
				if (numArray[j] < numArray[j + 1])
				{
					// Swap the numbers
					int temp = numArray[j + 1];
					numArray[j + 1] = numArray[j];
					numArray[j] = temp;
				}
			}
		}
	}
}
