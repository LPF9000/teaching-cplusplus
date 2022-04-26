/*****************************************************************//**
 * \file   RL_M5C.cpp
 * \brief  Simple Sort
 *
 * Revisit the code for swapping two numbers using user-defined 
 * functions. Swap the numbers' positions as follows:
 * 
 * 1. Write input1 void functioned called swapNumbers() that takes 
 * in two integers
 *  and swaps their positions. 
 * 
 * 2. Write input1 void function called simpleSort() that takes in four
 *  integers and sort them from smallest to largest, by calling
 *	swap() inside of simpleSort().
 * 
 * 3. Write input1 void function called printNumbers() that takes in
 *  four integers and prints the sorted numbers.. 
 * 
 * 4. Test simpleSort() and printNumbers() in your main() as shown
 *  in the test case.
 *
 * Note: Hardcode the integer values in variables
 *  to test your program to match the test cases.
 * 
 * Do not use any pre-defined sorting or swap functions, or arrays.
 * 
 * Psuedocode:
 * (1) CALL function printNumbers() that takes in 4 numbers and prints
 *	them.
 * (2) CALL function simpleSort() that takes in 4 numbers and
 *	sorts them in increasing order
 *		(a) CALL swapNumbers() to swap numbers if num1 is greater than num2
 *		(b) repeat (a) for num3 and num4, num1 and num3, num2 and num4
 *			and num2 and num3
 * (3) CALL function printNumbers() to sorted numbers
 *
 *
 * \author Ryan Laur
 * \date   February 9, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// function declarations
void swapNumbers(int&, int&);
void simpleSort(int&, int&, int&, int&);
void printNumbers(int, int, int, int);

// main
int main()
{
	// initialize variables
	int var1 = 9, var2 = 3, var3 = 5, var4 = 1;

	// print numbers before sorting
	cout << "The numbers before sorting: " << endl;
	printNumbers(var1, var2, var3, var4);

	// sort numbers in increasing order
	cout << "The numbers after sorting: \n";
	simpleSort(var1, var2, var3, var4);

	// print sorted numbers
	printNumbers(var1, var2, var3, var4);

	// set new values for variables
	var1 = 20, var2 = 19, var3 = 18, var4 = 17;

	// print numbers before sorting
	cout << "\nThe numbers before sorting: " << endl;
	printNumbers(var1, var2, var3, var4);

	// sort numbers in increasing order
	cout << "The numbers after sorting: \n";
	simpleSort(var1, var2, var3, var4);

	// print sorted numbers
	printNumbers(var1, var2, var3, var4);

	return 0;
}

// function to sort numbers in increasing order
void simpleSort(int& input1, int& input2, int& input3, int& input4)
{
	// call swapNumbers() if not in increasing order
	if (input1 > input2) {
		swapNumbers(input1, input2); 
	}
	if (input3 > input4) {
		swapNumbers(input3, input4);
	}
	if (input1 > input3) {
		swapNumbers(input1, input3);
	}
	if (input2 > input4) {
		swapNumbers(input2, input4);
	}
	if (input2 > input3) {
		swapNumbers(input2, input3);
	}
}

// function to swap two numbers
void swapNumbers(int& num1, int& num2)
{
	int temp = 0;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

// function to print numbers
void printNumbers(int output1, int output2, int output3, int output4)
{
	cout << "[ " << output1 << ", " << output2 << ", " << output3 
		<< ", " << output4 << " ]\n";
}
