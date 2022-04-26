/*****************************************************************//**
 * \file   RL_M3A.cpp
 * \brief  Aligned Square Matrix
 *
 * Write a program that will prompt the user for an integer, and
 * create a square matrix with dimensions of that integer. Print the
 * matrix with the following parameters:
 *
 * M(i,j) is a number with row position i, and column position
 * j.
 * 1. M(i,j) = i x 10^(i-1) + (j-1)
 *
 * 2. Align each number left based on the number of digits in the
 * number as shown in the test case.
 * 
 * Psuedocode:
 * (1) INITIALIZE variables
 * (2) READ integer for dimension of matrix
 * (3) CALCULATE max number of digits for padding, maxDigits
 * (4) LOOP i from 1 to number of rows
 *      (a) LOOP j from 1 to number of columns
 *          (i) CALCULATE number using formula => i x 10^(i-1) + (j-1)
 *          (ii) PRINT number
 *          (iii) PRINT spaces after number for padding maxDigits-num
 *
 * \author Ryan Laur
 * \date   January 26, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

int main()
{
    // INITIALIZE variables
    int num1(1), pow1(1), userNum(0), numDigits(0), maxDigits(0);

    // READ integer for dimension of matrix
    cout << "Matrix Generator" << endl;
    cout << "Enter an integer for the dimension of your square matrix: ";
    cin >> userNum;

    // find maximum power of 10
    for (int i = 1; i <= userNum; i++)
    {
        pow1 *= 10;
    }

    // CALCULATE max number of digits

    // CALCULATE largest number in matrix
    num1 = (userNum * pow1) + (userNum - 1);

    // CALCULATE number of digits in largest number
    while (num1 != 0)
    {
        num1 = num1 / 10;
        ++maxDigits;
    }

    // reset num1 and power of 10 back to 1
    num1 = 1;
    pow1 = 1;

    // LOOP i from 1 to number of rows
    for (int i = 1; i <= userNum; i++)
    {

        // LOOP j from 1 to number of columns
        for (int j = 1; j <= userNum; j++)
        {

            // CALCULATE number using formula => i x 10^(i-1) + (j-1)
            num1 = (i * pow1) + (j - 1);

            // PRINT number
            cout << num1;

            // calculate number of digits in number
            numDigits = 0;
            while (num1 != 0)
            {
                num1 = num1 / 10;
                ++numDigits;
            }

            // PRINT spaces after number for padding maxDigits-num
            for (int k = 0; k < (maxDigits - numDigits); k++)
            {
                cout << " ";
            }
        }

        // increment power of 10 before new row
        pow1 *= 10;

        // move to new line for new row
        cout << endl;
    }

    return 0;
}
