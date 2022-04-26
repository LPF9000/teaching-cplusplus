/*****************************************************************//**
 * \file   RL_M5D.cpp
 * \brief  Temperature Conversion
 *
 * Write a program that converts degrees celcius to farenheit,
 * and degrees farenheit to celcius. Overload a function called
 * convertTemp, where one instance converts celcius to farenheit, 
 * and the other instance converts farenheit to celcius. Test your
 * functions in main() as shown in the test cases, displaying results
 * to 1 decial place.
 * 
 * The prototypes of your functions should be as follows:
 * void inputTemp(double&);
 * void convertTemp(double&);
 * void convertTemp(double&, double&);
 * 
 * Note:
 * 
 * F = (9/5 * C) + 32
 * C = (F - 32) * 5/9
 *
 * Psuedocode:
 * (1) CALL function to prompt user for degrees celcius
 * (2) CALL overloaded function to convert celcius to farenheit
 * (3) DISPLAY results
 * (4) CALL function to prompt user for degrees farenheit
 * (5) CALL overloaded fucntion to convert farenheit to celcius
 * (6) DISPLAY results
 *
 *
 * \author Ryan Laur
 * \date   February 9, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// function prototypes
void inputTemp(double&);
void convertTemp(double&);
void convertTemp(double&, double&);

int main()
{
    // initialize variables
    double degC = 0.0, degF = 0.0;

    cout << "Temperature Conversion Program\n" << endl;

    // call function to get user input for degC
    cout << "Enter a temperature in Celcius: ";
    inputTemp(degC);

    // call overloaded function to convert temperature to F
    degF = degC;
    convertTemp(degF);

    // set precision to 1 decimal place
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    // display results
    cout << degC << "C in farenheit is: " << degF << "F \n" << endl;

    // call function to get user input for degF
    cout << "Enter a temperature in Farenheit: ";
    inputTemp(degF);

    // call overloaded function to convert temperature to C 
    convertTemp(degC, degF);

    // display results
    cout << degF << "F in celcius is: " << degC << "C " << endl;

    return 0;
}

// function to get farenheight or celcius inputs
void inputTemp(double& userTemp)
{
    cin >> userTemp;
}

void convertTemp(double& degrees)
{
    degrees = (9.0 / 5.0) * degrees + 32.0;
}

// convert celcius to farenheit
void convertTemp(double& cTemp, double& fTemp)
{
    cTemp = (fTemp - 32.0) * (5.0 / 9.0);
}




