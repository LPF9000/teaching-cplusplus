/*****************************************************************//**
 * \file   RL_M10A.cpp
 * \brief  This program will prompt the user for a review for a 
 * business, and display the remaining character count. 
 * 
 * Pseudocode:
 * (1) Prompt for user input (review)
 *		(i) only allow user to enter 50-500 characters, repeat (1)
 *		
 * (2) Display user's review
 * (3) Display number of characters used
 * 
 * 
 * \author Ryan Laur
 * \date   March, 26 2021
 *********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	const int MAX_CHAR = 500;
	char review[MAX_CHAR + 1];

	cout << "Write a review (Min. 50 Characters): " << endl;
	cin.getline(review, 501);

	while (strlen(review) < 50 || strlen(review) > 500)
	{
		cout << strlen(review) << "/" << MAX_CHAR << " characters used.\n";
		cout << "\nPlease enter a 50-500 characters. \n";
		cout << "Write a review (Min. 50 Characters): \n";
		cin.getline(review, 501);
	}
	cout << "\nThe review you entered is: \n";
	cout << review << endl;
	cout << strlen(review) << "/" << MAX_CHAR << " characters used.\n";

	return 0;
}