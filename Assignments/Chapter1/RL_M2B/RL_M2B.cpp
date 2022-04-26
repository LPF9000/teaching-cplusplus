/*****************************************************************//**
 * \file   RL_M2B.cpp
 * \brief  Time Conversion Calculator
 * 
 * Write a program that reads an integer from the user for
 * a number of seconds (userSeconds), 
 * and converts to the equivalent weeks, days, hours, 
 * minutes, and seconds.
 * 
 * Hint: Try to use use modulo (%) to find the the days, 
 * hours, minutes, and seconds. In other words, use the % operator to 
 * calculate the remainder of the weeks, days, hours, and minutes.
 * 
 * The second part the program will prompt the user for the
 * number of seconds, and convert directly to years. 
 * Round the years to 5 decimal places. 
 * 
 * Psuedocode:
 * (1) INITIALIZE Variables
 * (2) READ number of seconds
 * (3) CALCULATE weeks, days, hours, minutes, seconds
 * (4) DISPLAY converted time 
 * (5) READ number of seconds
 * (5) CALCULATE years from user's seconds
 * (6) SET precision to 5 decimal places
 * (7) DISPLAY seconds converted to years
 * 
 * \author Ryan Laur
 * \date   January 15, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

int main()
{
	// INITIALIZE Variables
	int userSeconds(0), weeks(0), days(0), hours(0), minutes(0), seconds(0);
	double years = 0;

	// READ number of seconds
	cout << "Welcome to the Time Conversion Program!" << endl;
	cout << endl << "Enter the number of seconds: ";
	cin >> userSeconds;

	// CALCULATE weeks, days, hours, minutes, seconds
	weeks = userSeconds / (3600 * 24 * 7);
	days = (userSeconds / (3600 * 24)) % 7;
	hours = userSeconds / 3600 % 24;
	minutes = (userSeconds / 60) % 60;
	seconds = userSeconds % 60;
	
	// DISPLAY converted time
	cout << userSeconds << " seconds is: " << weeks << " weeks, "
		<< days << " days, " << hours << " hours, " << minutes << " "
		"minutes," << " and " << seconds << " seconds." << endl;

	// READ number of seconds
	cout << endl << "Enter the number of seconds: ";
	cin >> userSeconds;

	// CALCULATE years from user's seconds
	years = userSeconds / (3600.0 * 24.0 * 365.0);

	// SET precision to 5 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(5);

	// DISPLAY seconds converted to years
	cout << endl << userSeconds << " seconds converted to years is: "
		<< years << " years." << endl;

	return 0;
}