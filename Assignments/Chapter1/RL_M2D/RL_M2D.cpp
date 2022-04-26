/*****************************************************************//**
 * \file   M2D.cpp
 * \brief  Calculate your Mercurian Age
 *
 * Write a program that reads two integers from the user, their age
 * in years and days. 
 * ie. If their birthday is on Jan.1 1989, and the current date is 
 * Jan. 2, 2021, the user will enter 32 years and 1 day. 
 * 
 * Calculate their Mercurian age, that is, their age on Mercury based
 * on its revolution around the sun.
 * Output the Mercurian age in terms of how many times Mercury revolves
 * around the sun.
 * The final answer should be displayed as years, rounded to 2 
 * decimal places.
 *
 * The time it takes Mercury to revolve around the sun is 
 * 87 days, 23 hours, and 17 minutes. (One year on Mercury)
 * 
 * 
 * Psuedocode:
 * (1) INITIALIZE Mercurian Age as const int
 * (2) READ userYears, userDays
 * (3) DISPLAY userYears, userDays
 * (4) CALCULATE Mercurian Age
 * (5) SET precision to 5 decimal places
 * (6) DISPLAY Mercurian Age
 * 
 * \author Ryan Laur
 * \date   January 15, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	// INITIALIZE variables
	int userYears(0), userDays(0);
	double years = 0.0;
	double days = 0.0;
	const int mercDays(87), mercHours(23), mercMinutes(17);

	// READ user age
	cout << "Welcome to the Mercurian Age Calculator!" << endl << endl;
	cout << "Enter your age in years and days, respectively: ";
	cin >> userYears >> userDays;

	// DISPLAY user age on Earth
	cout << "Your age on Earth is: " << userYears << " years and "
		<< userDays << " days." << endl;

	// CALCULATE Mercurian Age
	days = mercDays + (mercHours / 24.0) + ((mercMinutes / 60.0) / 24.0);
	years = (365.0 / days) * (userYears + (userDays / 365.0));

	// SET precision to 5 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// DISPLAY Mercurian Age
	cout << "Your age  is: " << years << " Mercurian years." << endl;

	return 0;
}