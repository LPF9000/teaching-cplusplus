/*****************************************************************//**
 * \file   RL_M4A.cpp
 * \brief  Is Prime?
 *
 * Write a user-defined function calls isPrime that takes in a 
 * positive integer and returns bool, true or false. 
 * 
 * In main, prompt the user for an integer, call isPrime() after
 * input validation, and display if the number is prime or not
 * based on the test case. Ask the user if they would like to 
 * run the program again (y/n)
 *
 * Pseudocode:
 * (1) FUNCTION prototype
 * (2) MAIN
 * (3) INITIALIZE variables
 * (4) READ integer from user
 * (5) CALL function isPrime()
 * (6) FUNCTION that returns true if a prime number, false otherwise
 * (7) PRINT if number is prime or not
 *
 * \author Ryan Laur
 * \date   February, 2 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// FUNCTION prototype
bool isPrime(int num);

// MAIN
int main() 
{
    // INITIALIZE variables
    int userNum(0), finished(0);
    char userChar = 'y';
    do
    {
        // READ integer from user
        cout << "Enter a number: ";
        cin >> userNum;

        // VALIDATE input
        while (cin.fail() || userNum < 0 )
        {
            cout << "Invalid entry, only enter numbers greater or equal to zero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a positive integer: ";
            cin >> userNum;

        }
    
        // CALL function isPrime(), and PRINT results
        if (!(isPrime(userNum)))
            cout << userNum << " is a not prime number" << endl;
        else
            cout << userNum << " is a prime number" << endl;
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
        } while ((cin.fail() || userChar != 'Y' && userChar != 'y' && userChar != 'N' && userChar != 'n'));
    } while (finished == 0);

    return 0;
}

// FUNCTION that returns true if prime, false otherwise
bool isPrime(int num)
{
    // special case, 0 and 1 are not prime
    if (num == 0 || num == 1) 
    {
        return false;
    }
    else 
    {
        for (int i = 2; i <= num / 2; ++i) 
        {
            if (num % i == 0) 
            {
                return false;
            }
        }

        return true;
    }
    
}
