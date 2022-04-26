/*****************************************************************//**
 * \file   RL_M4C.cpp
 * \brief  Dice rolling game
 *
 * Write a programmer-defined function called roll() that simulates
 * the roll of a die. Each time the function is called, it will randomly
 * return the number rolled.
 * 
 * Write a programmer-defined function called startGame() that takes 
 * in a double for the amount of money a user has, and returns the 
 * amount of money they have after playing the game. Each game costs
 * $0.50 to play. 
 * 
 * 1. Prompt the user to guess an integer between 1-6.
 * 2. Call roll(), and print the number that was rolled.
 * 3. If the user guesses the correct number, they win $1.00.
 * 4. return the amount of money the user has
 * 
 * In your main function: 
 * 
 * 1. The user will start the game with $5.00. Print how much money
 * they have at the start of the program.
 * 2. Ask the user if they would like to play for $0.50 (y/n)?
 * 3. If they would like to play, call the function startGame, that
 * takes in the amount of money they currently have, and returns the 
 * new amount after playing the game. 
 * 4. Ask if they would like to play again? (y/n)
 * 5. If they run out of money, end the program with a goodbye message. 
 * 
 * 
 * Make use of <cstdlib> and <ctime> for access to rand(), srand(), 
 * and time(). Seed the random number generator at the very
 * beginning of the program using: srand((unsigned int)time(0)).
 *
 * Pseudocode:
 * (1) FUNCTION prototype for rolling dice
 * (2) MAIN 
 * (3) INITIALIZE variables
 * (4) SET srand seed
 * (5) DISPLAY total user money
 *		(i) END program if user has $0.00
 * (6) READ (y/n) if user would like to play
 * (7) IF yes, CALL startGame()
 * (8) FUNCTION startGame()
 * (8) READ an integer for the user's guess
 * (9) CALL function roll()
 * (10) FUNCTION roll()
 *		(i) RETURN random number between 1 and 6
 * (11) IF roll()=guess, add $1.00 to total user money
 * (12) REPEAT back to (5)
 *
 * \author Ryan Laur
 * \date   February, 2 2021
 *********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

 // FUNCTION prototype for rolling dice
int roll(int num);
double startGame(double userMoney);

int main()
{
	// INITIALIZE variables
	int finished(1);
	double totalMoney = 5.00;
	char userChar = 'n';

	srand((unsigned int)time(0));
	// SET precision
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Welcome to the dice rolling guessing game!" << endl;

	// REPEAT while user has money or wants to play
	while (finished == 1)
	{

		// DISPLAY total user money
		cout << "\nYou currently have: $" << totalMoney << endl;

		// END program if user has $0.00
		if (totalMoney == 0.0)
		{
			cout << "Sorry, you are out of money!" << endl;
			break;
		}

		// READ (y/n) if user would like to play
		cout << "Would you like to play for $0.50? (y/n): ";
		cin >> userChar;

		while (cin.fail() || (userChar != 'Y' && userChar != 'y' && userChar != 'N' && userChar != 'n'))
		{
			// CLEARS cin on invalid input
			cin.clear();

			// IGNORES the max number of char from input on invalid entry
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid entry" << endl;
			cout << "Would you like to play for $0.50? (y/n): ";
			cin >> userChar;
		}

		// IF yes, subract $0.50, if no, end program
		switch (userChar)
		{
		case 'Y':
			finished = 1;
			cout << endl;
			totalMoney = startGame(totalMoney);
			break;
		case 'y':
			finished = 1;
			cout << endl;
			totalMoney = startGame(totalMoney);
			break;
		case 'N':
			finished = 0;
			break;
		case 'n':
			finished = 0;
			break;
		}

		// IF user entered an 'n', break the while loop
		if (finished == 0)
			break;
	}

	cout << "Thank you for playing, Goodbye! " << endl << endl;

	return 0;
}

// FUNCTION roll() returns random number between 1 and 6
int roll(int num)
{
	return ((rand() % 6) + 1);
}

double startGame(double userMoney)
{
	int userInt(0), rollTotal(0);

	// subract $0.50 if they play the game
	userMoney -= 0.50;

	//READ an integer for the user's guess
	cout << "Guess a positive number (1-6): ";
	cin >> userInt;

	while (cin.fail() || userInt < 1 || userInt > 6)
	{
		// this CLEARS cin on invalid input
		cin.clear();

		// this IGNORES the maximum number of char from input on invalid entry
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid entry" << endl;
		cout << "Guess a positive number (1-6): ";
		cin >> userInt;
	}

	// CALL function roll()
	rollTotal = roll(userInt);
	cout << "\nYou rolled a: " << rollTotal << endl;

	// IF roll()=guess, add $1.00 to total user money
	if (rollTotal == userInt)
	{
		cout << "Your guess was correct! You win $1.00" << endl;
		return userMoney += 1.00;
	}
	else
	{
		cout << "Your guess was incorrect! You lose." << endl;
		return userMoney;
	}
}
