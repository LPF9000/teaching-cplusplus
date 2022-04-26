/*****************************************************************//**
 * \file   RL_M3C.cpp
 * \brief  Binary-Decimal Converter
 *
 * Write a program that will convert a positive decimal number to 
 * binary. Prompt the user for a positive integer as a decimal number, 
 * convert to binary and print the result. 
 * 
 * Decimal (base 10) to Binary (base 2):
 * 
 * For example, take the decimal number 23. Divide by 2 and save 
 * the remainder until the number is 0. 
 * 
 * 1.) 23/2 = 11    Remainder = 1   1x10^0 = 1
 * 2.) 11/2 = 5     Remainder = 1   1x10^1 = 10
 * 3.) 5/2  = 2     Remainder = 1   1x10^2 = 100
 * 4.) 2/2  = 1     Remainder = 0   1x10^3 = 0
 * 5.) 1/2  = 0     Remainder = 1   1x10^4 = 10000
 * 
 * The binary equivalent is 10111, using the remainders starting
 * from step 5 to step 1, multiplying by decreasing powers of 10,
 * down to 0:
 * 1x10^4 + 1x10^3 + 1x10^2 + 1x10^1 1x10^0 =>
 * 10000 + 0 + 100 + 10 + 1 = 10111
 * 
 * Psuedocode:
 * (1) INITIALIZE variables
 * (2) READ positive integer for decimal number
 * (3) WHILE num != 0
 *      (a) CALCULATE remainder
 *      (b) DIVIDE by 2
 *      (c) RESULT = RESULT + remainder * 10^n;
 * (4) DISPLAY result
 * 
 * \author Ryan Laur
 * \date   January 26, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

int main()
{
    // INITIALIZE variables
    int userNum(0), rem(0), result(0), num(1);
    cout << "Welcome to the Binary-Decimal Converter!" << endl;

    // READ integer for positive decimal number
    cout << "Enter a positive decimal number: ";
    cin >> userNum;
    cout << userNum << " converted to binary is: ";

    // LOOP while userNum is not equal to 0
    while (userNum != 0)
    {
        // CALCULATE remainder
        rem = userNum % 2;

        // DIVIDE by 2
        userNum /= 2;

        // RESULT = RESULT + remainder * 10^n;
        result += rem * num;
        num *= 10;
    }

    // DISPLAY result
    cout << result << endl;

    return 0;
}
        


