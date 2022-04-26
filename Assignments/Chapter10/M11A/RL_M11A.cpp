/*****************************************************************//**
 * \file   RL_M11A.cpp
 * \brief  Functions (with pointers and dynamic arrays)

 * Write a function called getNumbers() that takes in a pointer 
 * to an integer variable that points to
 * a size from the user, and fills a dynamic array with integers 
 * from the user. The function will return a pointer to
 * an integer variable that points to a dynamic array of that size
 * created in the function. 
 * 
 * Write a function called duplicate() that takes in an array,
 * the size of the array, and the number of copies. Create a new
 * dynamic array with the capacity determined by the original 
 * array size * the number of copies. The function will return a 
 * new array with each number copied n times as shown in the test
 * case. 
 * 
 * Create a function called print() that takes in an array and
 * a size, and prints all the integers in the array. 
 * 
 * Test your functions in main as shown in the test case. 
 * 
 * Psuedocode:
 * (1) function getNumbers() to get numbers from user
 * (2) function duplicate() to duplicate numbers
 * (3) function print() to print array of numbers
 * (4) main
 *		get user input for number of integers
 *		create dynamic array with capacity of user input
 *		call getNumbers to get user input for integers
 *		print the array of integers
 *		get user input for number of copies to make
 *		call duplicate to duplicate numbers
 *		print the new array of integers
 *
 * \author Ryan Laur
 * \date   April 2, 2021
 *********************************************************************/

void print(int arr[], int size);
int* getNumbers(int* size);
int* duplicate(int arr[], int sizeArr, int numCopies);

#include <iostream>
using namespace std;

// main
int main()
{
	int num(0), numCopies(0);

	// get user input for number of integers
	cout << "How many numbers would you like to enter? ";
	cin >> num;
	//int* myArray = new int[num];

	// get user input to fill array with integers
	int *myArray = getNumbers(&num);

	// get user input for number of copies to make
	cout << "How many duplicates numbers do you want? ";
	cin >> numCopies;
	
	
	// duplicated array is saved into array
	// print new array
	print(duplicate(myArray, num, numCopies), num*numCopies);

	return 0;
}

// this function prints an array
void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// this fills a dynamic array with user input
int* getNumbers(int* size)
{
	if (*size == 0)
		return nullptr;
	int* arr = new int[*size];
	cout << "Enter " << *size << " integers: " << endl;
	
	for (int i = 0; i < *size; i++)
	{
		cin >> arr[i];
	}
	return arr;
}

int* duplicate(int arr[], int sizeArr, int numCopies)
{
	int* newArr = new int[sizeArr*numCopies];
	int index = 0;
	cout << "After duplicating " << numCopies << " times: \n";
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = i * numCopies; j < (i+1)*numCopies; j++)
		{
			*(newArr + j) = arr[i];
		}
	}

	return newArr;
}
