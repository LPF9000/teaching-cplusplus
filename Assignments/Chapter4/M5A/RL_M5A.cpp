/*****************************************************************//**
 * \file   RL_M5A.cpp
 * \brief  Call-by-Value vs. call-by-reference
 *
 * 1. Write a void function called getNumbers() that should use
 * call-by-reference parameters and read in an int and double from
 * the user.
 * 
 * 2. Write a void function called multiply that multiplies the two
 * numbers together. Use call-by-value parameters for the int and 
 * double, and a call-by-reference parameter for the result. 
 * 
 * 3. Write a void function called print() that uses call-by-value
 * parameters to print the int, double, and the result of the 
 * multiplication.
 * 
 * 4. Test getNumbers(), multiply(), and print() in main() as shown
 * in the test cases.
 * 
 * Hint:
 * The prototypes of the functions are as follows:
 * 
 * void getNumbers(int&, double&);
 * double multiply(int, double, double&);
 * void print(int, double, double);
 * 
 * Psuedocode:
 * (1) Prompt user input by calling function getNumbers() using
 * call-by-reference.
 * (2) Multiply the two numbers by calling function multiply(),
 * that takes in the user input using call-by-value, and the result
 * of multiplication using call-by-reference
 * (3) Print the result by calling function print() using 
 * call-by-value. 
 *
 *
 * \author Ryan Laur
 * \date   February 9, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// function prototypes
void getNumbers(int&, double&);
void multiply(int, double, double&);
void print(int, double, double);

//main
int main() 
{
	// initialize variables
	int userNum1 = 0;
	double userNum2 = 0.0, result = 0.0;

	// call function to get user input
	getNumbers(userNum1, userNum2);

	// call function to multiply numbers
	multiply(userNum1, userNum2, result);

	// call function to print results
	print(userNum1, userNum2, result);

	return 0;
}

// prompt user for numbers
void getNumbers(int& input1, double& input2)
{
	cout << "Enter an integer and floating point number: ";
	cin >> input1 >> input2;
}

// calculate product of two numbers
void multiply(int num1, double num2, double& product)
{
	product = num1 * num2;
}

// print results
void print(int number1, double number2, double answer)
{
	cout << number1 << " x " << number2 << " = " << answer << endl;
}
