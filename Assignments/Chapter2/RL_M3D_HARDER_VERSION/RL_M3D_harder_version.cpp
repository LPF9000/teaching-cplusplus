/*****************************************************************//**
 * \file   RL_M3D.cpp
 * \brief  Fibonacci Sequence Generator
 * 
 * Write a program that calculates a Fibonacci sequence. The program
 * should display two options for the user: Option 1 will 
 * calculate a user-specified number of Fibonacci values, and option 2
 * will find the nth Fibonacci number specified by the user. 
 * Prompt the user for an integer to select an option.
 * 
 * If the user enters a 1 for option 1, then prompt the user for
 * an integer, and print this number of Fibonacci values as shown in
 * the test case.
 * 
 * If the user enters a 2 for option 2, then prompt the user for an
 * integer, and print the nth position of the Fibonacci sequence
 * given by the integer as shown in the test case. 
 * ie. F(0) => n=0 (first number), F(1) => n=1 (second number)
 * 
 * Ask the user if they want to run the program again (y/n)?
 * Repeat the prompts until they enter 'y' or 'n'.
 * 
 * Note: Fibonacci numbers, commonly denoted F(n), form a sequence
 * such that each number is the sum of the two preceding numbers, 
 * starting from 0 and 1. 
 * 
 * F(0) = 0, F(1) = 1
 * F(n) = F(n-1) + F(n-2) for n > 1
 * 
 * Hint:
 * F(0) = 0
 * F(1) = 1
 * F(2) = F(1) + F(0) = 1 + 0 = 1
 * F(3) = F(2) + F(1) = 1 + 1 = 2, etc. 
 * 
 * Pseudocode:
 * 
 * (1) INITIALIZE variables
 * (2) DO-WHILE finished = false
 *      (a) DISPLAY options for user
 *      (b) READ integer to select option
 *      (c) IF Option 1
 *          (i) READ integer userNum for number of values
 *          (ii) CALCULATE Fibonacci Sequence from 0 to userNum-1
 *          (iii) DISPLAY Fibonacci values
 *      (d) IF Option 2 
 *          (i) READ integer userNum for nth value to calculate
 *          (ii) CALCULATE Fibonacci Sequence from 0 to userNum
 *          (iii) DISPLAY nth value F(n)
 *      (e) READ character to run again or quit y/n
 *          (i) IF 'y' finished = false
 *          (ii) ELSE IF 'n' finished = true
 *          (iii) ELSE (not 'y' or 'n'), invalid entry *              
 *
 * \author Ryan Laur
 * \date   January 26, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

int main()
{
    // INITIALIZE variables
    int result = 0;
    int userNum(0), userOption(0), num1, num2, num3(0), finished(0);
    char userChar = ' ';

    cout << "Welcome to the Fibonacci sequence Generator!" << endl;

    // DO-WHILE finished = false
    do
    {
        // DISPLAY options for user
        cout << "(1) Generate Fibonacci sequence";
        cout << "\n(2) Find the nth Fibonacci number";

        // READ integer to select option
        cout << "\nChoose an option (Enter 1 or 2): ";
        cin >> userOption;

        // IF Option 1
        if (userOption == 1)
        {
            //READ integer userNum for number of values
            cout << "\nEnter the number of Fibonacci numbers you want to generate: ";
            cin >> userNum;

            // Used in For loop for i=0; i<userNum-1; i++
            --userNum;
        }

        // IF Option 2
        else
        {
            // READ integer userNum for nth value to calculate
            cout << "\nEnter the nth Fibonacci number you want to calculate F(n): ";
            cin >> userNum;
        }

        // INITIALIZE position 0 and 1 of sequence
        num1 = 0, num2 = 1;

        // CALCULATE Fibonacci Sequence
        for (int i = 0; i <= userNum; i++)
        {
            // IF current position is F(0)
            if (i == 0)
            {
                // IF option 1, display current value
                if (userOption == 1)
                    cout << num1 << " ";

                // EXIT for loop if only displaying F(0) for option 2
                if (userNum == 0)
                {
                    result = num1; 
                    continue;
                }
            }

            // ELSE IF current position is F(1)
            else if (i == 1)
            {
                // IF option 1, display current value
                if (userOption == 1)
                    cout << num2 << " ";

                // EXIT for loop if only displaying F(1) for option 2
                if (userNum == 1)
                {
                    result = num2;
                    continue;
                }
            }

            // CALCULATE Fibonacci sequence F(n) for n>1
            else
            {
                num3 = num1 + num2;
                num1 = num2;
                num2 = num3;
                result = num2;

                // IF option 1, display current value
                if (userOption == 1)
                {
                    cout << num2 << " ";
                }
            }
        }

        // IF option 2
        if (userOption == 2)
        {
            // DISPLAY nth fibonacci number F(n)
            cout << "The fibonacci number, F("
                << userNum << ") is: " << result << " ";
        }

        cout << endl;

        // READ character to run again or quit y / n
        do
        {
            cout << "Run again? (y/n): ";
            cin >> userChar;

            // IF y, finished = false; IF 'n', finished = true;
            switch (userChar)
            {
            case 'Y':
                finished = 0;
                cout << endl;
                break;
            case 'y':
                finished = 0;
                cout << endl;
                break;
            case 'N':
                finished = 1;
                break;
            case 'n':
                finished = 1;
                break;
            }
        } while ((userChar != 'Y' && userChar != 'y' && userChar != 'N' && userChar != 'n'));
    } while (finished == 0);

    cout << "\nThank you for using the Fibonacci Sequence Generator. Goodbye!" << endl;

    return 0;
}

