/*****************************************************************//**
 * \file   RL_M11C.cpp
 * \brief  Functions (with pointers and dynamic arrays)

 * Write a function called getNumbers() that takes in a size and
 * returns a pointer to a double variable that points to a dynamic
 * array of that size created in the function. The dynamic
 * array will get inputs from the user. If the size is less than 1,
 * then the function will return a null pointer (nullptr).

 * Write another function called dropLowest() that takes in
 * a pointer to a double parameter that points to a dynamic array
 * of integers and its size, and removes the smallest number.
 *
 * Hint: You can save the numbers back into the array except the
 * smallest index.
 *
 * Write a function called print() that takes in a pointer to a double
 * parameter that points to a dynamic array of doubles and its size,
 * and prints the test numbers entered.
 * 
 * In main, test your functions according to the test cases. 
 *
 * Psuedocode:
 * 
 * 1. function getNumbers to get user input
 * 2. function dropLowest to remove lowest number
 *		i. find index of lowest number
 *		ii. re-initialize array, skipping index
 * 3. function to print numbers
 * 
 * 4. Main
 *		i. get user input
 *			a. if size < 0, save to nullptr and exit
 *		ii. print numbers entered
 *		iii. call dropLowest to remove lowest number
 *		iv. print new numbers
 * 
 *
 * \author Ryan Laur
 * \date   April 2, 2021
 *********************************************************************/

double* getNumbers(int size);
double* dropLowest(double* arr, int& size);
void print(double* arr, int size);

#include <iostream>
using namespace std;

// main
int main()
{
	int num(0);

	// get user input
	cout << "How many numbers would you like to enter? ";
	cin >> num;
	double* arr = getNumbers(num);

	// if size is less than 1, exit 
	if (arr == NULL)
	{
		exit(1);
	}

	// print numbers entered
	cout << "\nNumbers entered: \n";
	print(arr, num);

	// delete the smallest number
	arr = dropLowest(arr, num);
	cout << "\nNumbers after dropping lowest: \n";

	// print the new array of numbers
	print(arr, num);

	// deallocate dynamic memory
	delete[] arr;
	arr = nullptr;

	return 0;
}

// function to get the user input
double* getNumbers(int size)
{
	// return null if size is less than 1
	if (size < 1)
	{
		cout << "Array not valid!" << endl;
		return nullptr;
	}
	double* numArr = new double[size];
	cout << "Please enter " << size << " numbers separated by space: ";
	for (int i = 0; i < size; i++)
	{
		cin >> *(numArr + i);
	}
	return numArr;
}

// this function removes the smallest number from an array
double* dropLowest(double* arr, int& size)
{
	int smallest = 0;
	int j = 0;

	// find smallest index
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < arr[smallest])
			smallest = i;
	}

	--size;

	// skip smallest index when creating new array
	for (int i = 0; i < size; i++)
	{
		if (j == smallest)
		{
			++j;
		}
		arr[i] = arr[j];
		j++;
	}

	return arr;
}


// this function prints the array
void print(double* arr, int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

