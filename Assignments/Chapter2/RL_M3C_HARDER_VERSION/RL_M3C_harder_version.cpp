/*****************************************************************//**
 * \file   RL_M3C.cpp
 * \brief  Binary-Decimal Converter
 *
 * Write a program that will convert a decimal number to binary, or
 * a binary number to decimal based on the user selection. Display
 * two options to the user, and prompt the user for a character, '1'
 * or '2' as shown in the test cases. Option 1 will prompt the user 
 * for an integer as a decimal number, convert to binary and print 
 * the result. Option 2 will prompt the user for a integer as a 
 * binary number, convert to decimal, and display the result. Use a 
 * switch statement to choose between the options. 
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
 * Binary (base 2) to Decimal (base 10):
 * 
 * Take the binary number 1011. Divide by 10 and save the remainder 
 * until the number is 0.
 * 
 * 1.) 1011/10 = 101 Remainder = 1  1x2^0   = 1
 * 2.) 101/10  = 10  Remainder = 1  1x2^1   = 2
 * 3.) 10/10   = 1   Remainder = 0  0x2^2   = 0
 * 4.) 1/10    = 0   Remainder = 1  1x2^3   = 8
 * 
 * The decimal equivalent is 11, using the remainders from step 1 to
 * step 5, multipying by increasing powers of 10:
 * 
 * 1x2^0 + 1x2^1 + 0x2^2 + 1x2^3 =>
 * 1 + 2 + 0 + 8 = 11
 * 
 * Psuedocode:
 * (1) INITIALIZE variables
 * (2) READ character for option
 * (3) SWITCH case 1; case 2
 *      (A) case '1'
 *          (i) READ integer for decimal number
 *          (ii) WHILE num != 0
 *              (a) CALCULATE remainder
 *              (b) DIVIDE by 2
 *              (c) RESULT = RESULT + remainder * 10^n;
 *      (B) case '2'
 *          (i) READ integer for binary number
 *          (ii) WHILE num != 0
 *              (a) CALCULATE remainder
 *              (b) DIVIDE by 10
 *              (c) RESULT = result + remainder * 2^n
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
    int userNum(0), rem(0), count(0), result(0), num(1), mult(1);
    char userOption;
    cout << "Welcome to the Binary-Decimal Converter!" << endl;

    // READ character for option
    cout << "(1) Convert Decimal to Binary" << endl;
    cout << "(2) Convert Binary to Decimal" << endl;
    cout << "Choose an option (Enter 1 or 2): ";
    cin >> userOption;

    // SWITCH case 1; case 2
    switch (userOption)
    {
    case '1':
        // READ integer for decimal number
        cout << "Enter a decimal number: ";
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
        break;
    case '2':
        // READ integer for binary number
        cout << "Enter a binary number: ";
        cin >> userNum;
        cout << userNum << " converted to decimal is: ";

        // LOOP while userNum is not equal to 0
        while (userNum != 0)
        {
            // CALCULATE remainder
            rem = userNum % 10;

            // 2^0 = 1
            if (count == 0)
                mult = 1;

            // 2^1 = 2
            else if (count == 1)
                mult = 2;

            // 2^n+1
            else            
                mult *= 2;                  
            
            // RESULT = result + remainder * 2^n
            result += rem * mult;

            // DIVIDE by 10
            userNum /= 10;
            count++;
        }
        break;
    }

    // DISPLAY result
    cout << result << endl;

    return 0;
}

