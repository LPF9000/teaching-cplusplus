/*****************************************************************//**
 * \file   RL_M10B.cpp
 * \brief  This program will display a list of video games, and allow
 * the user to search for a game based on a keyword, displaying a list
 * of search results. 
 * 
 * Write a function called findGame that takes in an array of 
 * string objects, the size, and an array of integers, and returns 
 * a the number of search results found (integer). 
 * 
 * findGame() will prompt the user for a keyword, using 
 * a local variable of type c-string and the cin.getline() function.
 * You can assume the maximum size of the c-string is 20 characters. 
*  Then, the function will search the entire array for the user's
 * keyword. If the characters match, save the index of the game
 * into the integer array. Each time there is a match, increment
 * a local variable called count. The function will return this 
 * count of how many search results were found. 
 * 
 * Write a function called print that takes in an array of games
 * and the size and displays the results.
 * 
 * In main, create an array of string objects with the names
 * shown in the test case, with a maximum size of 4. Then, Create an
 * array of type integer called indexArr, also with a size of 4. 
 * 
 * Print the list of games as shown in the test case.
 * 
 * Call findGame(), passing in the array of string objects, the size,
 * and indexArr.
 * 
 * Print the search results using the values stored in indexArr as the
 * indices of your array of string objects. 
 * 
 * Ask the user if they would like to perform another search (y/n)
 * 
 * Note: Though there are many ways to accomplish this, 
 * in your findGame() function, you may use strlen() to find the
 * length of a c-string, strncmp(str1, str2) to compare n characters 
 * between two c-strings, and c_str() to convert and string object
 * to a c-string.
 *
 * Pseudocode:
 * (1) findGame function
 * (2) print function
 * (3) array of string objects
 * (4) print list of games
 * (5) find game, prompt user for name of game to search for
 *
 *
 * \author Ryan Laur
 * \date   March, 26 2021
 *********************************************************************/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int findGame(string games[], int size, int indexArr[]);
void print(string games[], int size);

int main()
{
	const int size = 4;
	char repeat = 'y';

	// array of string objects
	string games[size] = { {"ghost of tsushima"}, {"assasin's creed"}, {"call of duty"}, {"cyberpunk 2077"} };

	// loop to repeat program
	while (repeat == 'y')
	{
		// initialize array of indices
		int indexArr[size]{};
		int newSize = 0;

		// print list of games
		cout << "List of PS5 games: " << endl;
		print(games, size);

		// call findGame() to prompt user for game and search for it
		newSize = findGame(games, size, indexArr);

		// display search results
		cout << "The search results are: " << endl;
		for (int i = 0; i < newSize; i++)
		{
			cout << i + 1 << ". " << games[indexArr[i]] << endl;
		}

		// prompt user for repeat
		cout << "\nWould like to make another search? (y/n) ";
		cin >> repeat;

		// ignore for >> and getline used in the same program
		cin.ignore(1000, '\n');
		cout << endl;
	}

	return 0;
}

// function to print list of games
void print(string games[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << ". " << games[i] << endl;
	}
}

// function to search array for a game
int findGame(string games[], int size, int indexArr[])
{
	// prompt for user input
	char userGame[20];
	cout << "\nType in a search keyword: ";
	cin.getline(userGame, 20);
	
	// start the number of search results at 0
	int count = 0;

	// check array for user input
	for (int i = 0; i < size; i++)
	{
		// compare strings with a char limit based on the length of user input
		// (strncmp(str1, str2, n) n = length of userGame
		if (!strncmp(games[i].c_str(), userGame, strlen(userGame)))
		{
			// set index array equal to current game index
			indexArr[count] = i;

			// increment count, the new size of indexArr
			count++;
		}
	}

	return count;

}
