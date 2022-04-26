/*****************************************************************//**
 * \file   RL_M3D.cpp
 * \brief  Fibonacci Sequence Generator
 * 
 * Write a program that calculates a Fibonacci sequence. 
 * 
 * Then prompt the user for
 * an integer greater than 0, and print this number of Fibonacci 
 * values as shown in the test case.
 * 
 * ie. F(0) => n=0 (first number), F(1) => n=1 (second number)
 * 
 * Ask the user if they want to run the program again (y/n)?
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
 *      (a) READ integer userNum for number of values
 *      (b) CALCULATE Fibonacci Sequence from 0 to userNum-1
 *      (c) DISPLAY Fibonacci values
 *      (d) READ character to run again or quit y/n
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
    int userNum(0), num1, num2, num3(0), finished(0);
    char userChar;

    cout << "Welcome to the Fibonacci sequence Generator!" << endl;

    // DO-WHILE finished = false
    do
    {
        //READ integer userNum for number of values
        cout << "\nEnter the number of Fibonacci numbers you want to generate: ";
        cin >> userNum;

        cout << "The first " << userNum << " Fibonacci numbers are: "
            << endl;

        // INITIALIZE position 0 and 1 of sequence
        num1 = 0, num2 = 1;

        // CALCULATE Fibonacci Sequence
        for (int i = 1; i <= userNum; i++)
        {
            // Print default F(0) = 0
            if (i == 1)
            {
                cout << num1 << " ";
            }

            // Print default F(1) = 1
            else if (i == 2)
            {
                cout << num2 << " ";
            }

            // CALCULATE Fibonacci sequence F(n) for n>1
            else
            {
                num3 = num1 + num2;
                num1 = num2;
                num2 = num3;
                cout << num2 << " ";
            }
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

