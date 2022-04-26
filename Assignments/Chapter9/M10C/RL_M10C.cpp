/*****************************************************************//**
 * \file   RL_M10C.cpp
 * \brief  C-strings and Strings
 * 
 * This program will prompt the user for a first and last name, abbreviate
 * the first name, and concatenate the two strings. 
 * 
 * In Main:
 * 
 * Create two C-strings with a capacity of 20, and two string objects.
 * 
 * Prompt the user for a first and last name, storing into 
 * each C-string, respectively.
 * 
 * Prompt the user for a second first and last name, storing into
 * each string object, respectively. 
 * 
 * Make the first letter of each first and last name uppercase, as
 * shown in the test case.
 * 
 * Format the first name of the C-string and the string object to 
 * include only the first letter. 
 * 
 * Concanenate the first and last names of the C-string, and
 * concatenate the first and last names of the string. 
 * 
 * Display results as shown in the test case. 
 * 
 * Note: You may use the function toupper() to convert a single
 * character to uppercase. 
 *
 * Pseudocode:
 * (1) Prompt user for first and last names
 * (2) Make first letter of each name upppercase
 * (3) Store only the first letter into the first name
 * (4) Concatenate the first and last names
 *
 *
 * \author Ryan Laur
 * \date   March, 26 2021
 *********************************************************************/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	char cName1[20], cName2[20];
	string s1, s2;

	// prompt for user input
	cout << "Enter a first and last name: ";
	cin >> cName1 >> cName2;

	cout << "Enter a second first and last name: ";
	cin >> s1 >> s2;
	
	// Make first letter of each name uppercase
	cName1[0] = toupper(cName1[0]);
	cName2[0] = toupper(cName2[0]);
	s1[0] = toupper(s1[0]);
	s2[0] = toupper(s2[0]);

	// copy only the first position into cName1
	strncpy_s(cName1, cName1, 1);

	// Concatenate the first and last name
	strcat_s(cName1, ". ");
	strcat_s(cName1, cName2);

	// initialize s1 with only the first letter
	s1 = s1[0];

	// concatenate the first and last name
	s1 += ". " + s2;

	// You may also use substr, which is a more elegant solution
	//s1 = s1.substr(0, 1) + ". " + s2;

	cout << "Formatted C-String Name: " << cName1 << endl;
	cout << "Formatted String Name: " << s1 << endl;

	return 0;
}


