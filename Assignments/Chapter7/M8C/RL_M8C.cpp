/*****************************************************************//**
 * \file   RL_M8C.cpp
 * \brief  Class called Whole
 *
 * Write a class called Whole that contains a private member
 * variable called num to store an integer, your class only will accept
 * whole numbers. 
 *
 * Write a default constructor that initializes the member
 * variable to 0. Define the default constructor with an initialization
 * section.
 *
 * Write a custom constructor that takes in a floating point number,
 * and initializes the member variable with its parameter. The 
 * custom constructor must check if the value of the parameter 
 * is a whole number. If it is a whole number, it will assign it to
 * the member variable normally. If it is not a whole number,
 * then it will output an error message and assign the variable with
 * 0. Define the custom constructor with an initialization section. 
 *
 * Write an accessor for the member variable, making it a 
 * constant function. 
 *
 * In main(), declare a Whole object that is initialized
 * by the default constructor, and call print() on the object. Declare
 * an array of scores, hardcoded as shown in the test case. Then,
 * reinitialize the member variables of the Whole object by assigning
 * an anonymous object with the custom constructor to the Whole object,
 * then call print() to display the new values as shown in the
 * test cases.
 *
 * Psuedocode:
 *
 * (1) Class Whole
 *      (a) member variable num
 *		(b) default constructor
 *		(c) custom constructor
 *      (d) accessor 
 * (2) Main
 *		(a) Declare Whole object with default constructor
 *		(b) print num
 *      (c) get user input for new number
 *		(d) Re-initialize object with anonymous object from custom constructor
 *		(e) print member variable
 *
 *
 * \author Ryan Laur
 * \date   March 5, 2021
 *********************************************************************/
#include <iostream>
using namespace std;

// Whole class
class Whole
{
public:
    // default constructor
    Whole();

    // custom constructor
    Whole(const double& num);

    // accessor
    int getNum() const;

private:
    int num;
};

// main
int main()
{
    // Whole object delcared with default constructor
    Whole w1;
    double userNum = 0;
    char repeat = 'y';

    // display using default constructor
    cout << "Default object value: " << w1.getNum() << endl;
    while (repeat == 'y')
    {
        // prompt user for input
        cout << "Enter a number: ";
        cin >> userNum;

        // use custom constructor to generate anonymous object
        w1 = Whole(userNum);
        cout << "Custom object value: " << w1.getNum() << endl;

        // prompt user to repeat program y/n
        cout << "Would you like to enter a new value? (y/n)" << endl;
        cin >> repeat;

        // only allow 'y' or 'n'
        while (repeat != 'y' && repeat != 'n')
        {
            cout << "Invalid Entry. " << endl;
            cin >> repeat;
        }
    }
    
    return 0;
}

// default constructor initializing to 0
Whole::Whole()
    : num(0)
{}

// custom constructor that only assigns num when input is whole
Whole::Whole(const double& numInput) // numInput is aliased by a double that is constant
    : Whole() // constructor delegation - invokes the default constructor
{
    // only set num if the input is a whole number
    if (numInput == static_cast<int>(numInput))
    {
        num = static_cast<int>(numInput);
    }     
    else
        cout << "Non-Whole number detected!" << endl;
}

// accessor for num member variable
int Whole::getNum() const
{
    return num;
}









