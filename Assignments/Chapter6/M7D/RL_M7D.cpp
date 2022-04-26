/*****************************************************************//**
 * \file   RL_M7D.cpp
 * \brief  Score Class
 *
 * Write a class called Game that contains four private member variables
 * for the scores of each team (integers), and the name of each team (strings).
 * -Create a public function called readScore() that prompts the user
 * for the scores of each team.
 * -Create a public function called readName() that prompts the user
 * for the names of each team.
 * -Create accessors for each of the 4 variables.
 *
 * In main(), create an array of Game objects with a maximum size of 5.
 * Prompt the user for the number of games they would like to enter,
 * and call your mutator functions to read the data. 
 * Then display the data using the accessor functions for each 
 * array position as shown in the test case. 
 *
 * Psuedocode:
 * (1) Class Game with member variables for scores and teams
 * (2) Accessor functions getScore() and getName()
 * (3) Mutator functions readScore() and readName()
 * (4) Create array of game objects, maximum size of 5
 * (5) prompt user for number of games to enter
 * (6) read data
 * (7) access and display data
 *
 *
 * \author Ryan Laur
 * \date   March 2, 2021
 *********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//class declaration
class Game {
public:
	//mutators
	void readScore();
	void readName();

	//accessors
	int getScore1();
	int getScore2();
	string getName1();
	string getName2();

private:
	int score1 = 0, score2 = 0;
	string team1, team2;
};

int main()
{
	// initialize variables
	const int MAX_SIZE = 5;
	Game gameArr[MAX_SIZE];
	string name1, name2;
	int score1(0), score2(0), size(0);

	// prompt user for number of games to enter into array
	cout << "How many games would you like to enter? ";
	cin >> size;

	// call functions to read the score and names from the user
	for (int i = 0; i < size; i++)
	{
		cout << "Game " << i + 1 << ": " << endl;
		gameArr[i].readScore();
		gameArr[i].readName();
	}

	// display the games entered using accessors
	cout << "Games Entered: " << endl;
	for (int i = 0; i < size; i++)
	{
		score1 = gameArr[i].getScore1();
		score2 = gameArr[i].getScore2();
		name1 = gameArr[i].getName1();
		name2 = gameArr[i].getName2();
		
		// Aligning the text
		cout << internal << setw(20) << "Game " << i+1 << endl;
		cout << "----------------------------------------" << endl;
		cout << name1 << setw(2) << " vs " << setw(2) << name2 << endl;
		cout << left << setw(9) << name1 << setw(2) << " : " << setw(6) << score1;
		cout << left << setw(9) << name2 << setw(2) << " : " << setw(6) << score2 << endl;
	}

	return 0;
}

// Mutator function to read the team scores from the user
void Game::readScore()
{
	cout << "Enter the scores for each team separated by a space: ";
	cin >> score1 >> score2;
}

// mutator function to read the team names from the user
void Game::readName()
{
	cout << "Enter the names of each team separated by a space: ";
	cin >> team1 >> team2;
}

// accessor function to return score 1
int Game::getScore1()
{
	return score1;
}

// accessor function to return score 2
int Game::getScore2()
{
	return score2;
}

// accessor function to return team name 1
string Game::getName1()
{
	return team1;
}

// accessor function to return team name 2
string Game::getName2()
{
	return team2;
}
