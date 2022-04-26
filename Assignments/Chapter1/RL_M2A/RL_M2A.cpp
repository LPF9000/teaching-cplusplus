/*****************************************************************//**
 * \file   RL_M2A.cpp
 * \brief  Arithmetic using mixed data types
 * 
 * A. Write a program reads an integer and a double from the user, num1 
 * and num2 respectively, and then performs addition, subtraction, 
 * multiplication, and division of the two numbers. The output will
 * be of type double, rounded to 2 decimal places. 
 * 
 * B. Repeat part A but output to a new variable of type integer.
 * 
 * Extra practice (Not required for solution): 
 * Is part A different than part B? If so, why?
 * When you build the code, you may notice some warnings in the output
 * window specifying a possible loss of data. How could
 * you use type casting to avoid this warning without changing the
 * result? For more info, read Ch. 1.2 on type casting. 
 * 
 * Pseudocode:
 * (1) INITIALIZE variables
 * (2) READ num1 and num2
 * (3) CALCULATE and DISPLAY results using type double
 *		(a) addition, subtraction, multiplication, division
 * (4) READ num1 and num2
 * (5) CALCULATE and DISPLAY results using type integer
 *		(a) addition, subtraction, multiplication, division
 * 
 * \author Ryan Laur
 * \date   January 2021
 *********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	// INITIALIZE variables
	int num1 = 0;
	double num2 = 0.0;
	double result1 = 0.0;
	int result2 = 0;

	// READ num1 and num2
	cout << "Enter an integer and a double, seperated by a space: ";
	cin >> num1 >> num2;

	// SET precision to 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// CALCULATE and DISPLAY results using type double

	cout << endl << "Output to double type: " << endl;
	// addition
	result1 = num1 + num2;
	cout << num1 << " + " << num2 << " = " << result1 << endl;

	// subtraction
	result1 = num1 - num2;
	cout << num1 << " - " << num2 << " = " << result1 << endl;

	// multiplication
	result1 = num1 * num2;
	cout << num1 << " * " << num2 << " = " << result1 << endl;

	// division
	result1 = num1 / num2;
	cout << num1 << " / " << num2 << " = " << result1 << endl;

	// CALCULATE and DISPLAY results using type int

	cout << endl << "Output to integer type: " << endl;

	// addition
	result2 = static_cast<int>(num1 + num2); // typecasting
	cout << num1 << " + " << num2 << " = " << result2 << endl;

	// subtraction
	result2 = static_cast<int>(num1 - num2);
	cout << num1 << " - " << num2 << " = " << result2 << endl;

	// multiplication
	result2 = static_cast<int>(num1 * num2);;
	cout << num1 << " * " << num2 << " = " << result2 << endl;

	// division
	result2 = static_cast<int>(num1 / num2);;
	cout << num1 << " / " << num2 << " = " << result2 << endl;

	return 0;
}
