/*****************************************************************//**
 * \file   RL_M10D.cpp
 * \brief  String Object - Counting Characters
 * 
 * This program will read a phrase from the user, and display the number of 
 * times each letter was entered. 
 * 
 * Create a variable called letter that stores a single 
 * character. 
 * 
 * Create a string object called str to store an entire phrase. 
 * 
 * Create an array of integers called letterCount to store the counts
 * of letters in the phrase. 
 * 
 * Prompt the user for a phrase, using the cin.get() function to
 * store the character into str1, repeating until the user presses
 * enter ('\n'). For each iteration of the loop, concatenate the 
 * string object, str, with the character entered by the user to
 * store the entire phrase. 
 * 
 * Create an array called letterCount, of type integer, that will
 * count the number of times each letter is used. 
 * 
 * Check each character, and incremement at the index that corresponds to
 * the current character, 0 to 25. Assume each character entered
 * is lowercase. 
 * 
 * Print the results as shown in the test case, only display letters
 * for counts that are greater than 0. 
 * 
 * Hint: 
 * Use the Ascii table to determine the first index position.
 * ie. 'a' - 97 = 0, will be your first position. 
 * 
 * Note:
 * Assume the user will enter lowercase letters
 *
 * Pseudocode:
 * (1) Prompt user for input
 * (2) Loop for each character array position
 *		(i) concatenate string object with user input
 *		(ii) set index equal to the letter - 97
 *		(iii) increment at index corresponding to letter
 * (3) display results
 *
 *
 * \author Ryan Laur
 * \date   March, 26 2021
 *********************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	char letter{};
	int letterCount[26]{};
	string str;

	cout << "Enter a phrase: ";

	// loop to get each letter from the user
	do
	{
		// user input for letter
		cin.get(letter);

		// concatenate string object with letter
		str += letter;
		// do not count spaces	
		if (letter != ' ')
		{
			// set index starting position for 'a' => 0
			int index = int(letter) - 97;
			
			// increment at index only when a letter
			if (index >= 0 && index < 26)
			{
				letterCount[index]++;
			}	
		}
	} while (letter != '\n');

	// print user input
	cout << "\nYou entered the phrase: " << endl;
	cout << str << endl;

	cout << "Letter Counts: " << endl;

	// loop through array to print counts
	for (int i = 0; i < 26; i++)
	{
		if (letterCount[i] > 0)
			cout << char(i + 97) << ": " << letterCount[i] << endl;
	}

	return 0;
}