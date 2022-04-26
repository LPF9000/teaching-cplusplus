/*****************************************************************//**
 * \file   RL_M3B.cpp
 * \brief  Greatest Common Diviser (GCD) Calculator
 *
 * Write a program that will calculate the greatest common divisor
 * between two integers.
 * Prompt the user for two integers, and calculate the largest possible
 * integer that divides each of the integers evenly, with no remainder. 
 * Display the result as shown in the test cases. Ask the user if they 
 * want to run the program again (y/n)? 
 * 
 * The Euclidean Algorithm for finding GCD(A,B) is as follows:
 * 
 * If A = 0 then GCD(A,B) = B, because the GCD(0,B) = B
 * If B = 0 then GCD(A,B) = A, because the GCD(A,0) = A
 * 
 * A = B*Q + R
 * GCD(A,B) = GCD(B,R)
 * 
 * Then, divide A/B = Q + R
 * A becomes B, B becomes R
 * Divide A/B = Q + R . . .
 * 
 * repeat until B = 0, then GCD(A,0) = A
 * 
 * Example:
 * A=270 B = 192
 * Note: Works for A > B. If A < B, then swap the numbers.
 * 1. GCD(270,192) => 270/192 = 1 , Remainder=78 
 * 2. B = 192, R = 78
 * 3. GCD(192,78) => 192/78 = 2, Remainder = 36
 * 4. B = 78, R = 36
 * 5. GCD(78,36) => 78/36 = 2, Remainder = 6
 * 6. B = 36, R = 6
 * 7. GCD(36,6) => 36/6 = 6, Remainder = 0
 * 8. B = 6, R = 0
 * 9. GCD(6,0) = 6 => Final Answer
 * 
 * Psuedocode:
 * (1) INITIALIZE variables
 * (2) READ integers, A and B
 * (3) SWAP integers if A < b
 * (4) LOOP while A && B are not 0
 *      (a) CALCULATE remainder of A/B
 *      (b) SWAP A=B, B=R
 * (5) DISPLAY GCD, A
 * (6) READ char to run again (y/n)
 *
 * \author Ryan Laur
 * \date   January 26, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

int main()
{
    // INITIALIZE variables
    int A, B, GCD(1), temp, finished(0), R;
    char userChar;

    cout << "Greatest Common Diviser Calculator" << endl;
    do
    {
        // READ integers, A and B
        cout << "\nEnter 2 positive integers, separated by a space: ";
        cin >> A >> B;

        cout << "The GCD of " << A << " and " << B << " is: ";

        // SWAP integers if A < b
        if (A < B)
        {
            temp = A;
            A = B;
            B = temp;
        }

        // LOOP while B is not 0
        while (B != 0)
        {
            // CALCULATE remainder of A/B
            R = A % B;

            // SWAP A = B, B = R
            A = B;
            B = R;
        }
        
        // GCD will always be A 
        GCD = A;

        // DISPLAY GCD, A
        cout << GCD << endl;

        // Ask if run again, repeat if y/n is not entered
        do
        {
            cout << "Run again? (y/n): ";
            cin >> userChar;

            // IF y, finished = false; IF 'n', finished = true;
            switch (userChar)
            {
            case 'Y':
                finished = 0;
                break;
            case 'y':
                finished = 0;
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
    
    return 0;
}
