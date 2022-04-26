/*****************************************************************//**
 * \file   RL_M9D.cpp
 * \brief  Class called PrimeNumber
 * 
 * This program will prompt the user for a prime number,
 * and return the next prime number. 
 *
 * Write a class called PrimeNumber that contains one private member
 * variable, an integer called number to store a primeNumber.
 *
 * Write a default constructor that initialized the member variable
 * to 2, the which is the first prime number. 
 * Define the default constructor with an initialization
 * section.
 *
 * Write a custom constructor that initializes the member variable 
 * with its corresponding paramater. Define the custom constructor with
 * and initalization section.
 *
 * Write an accessor for the number member variable, making it a
 * constant function. Write a static accessor function for the
 * count member variable.
 * 
 * Write a constant member function called isPrime(), that takes in
 * an integer, and returns true or false. 
 * 
 * Overload the postfix unary (++) operator as a member function, which
 * returns a constant PrimeNumber object. You may use isPrime() here, which
 * will increment the number until isPrime() returns true. You may use
 * post-increment or pre-increment here. 
 * 
 * In main(), first declare a PrimeNumber object that is initialized 
 * by the default constructor. Print the default prime number by
 * calling the accessor as shown in the test case. Then prompt
 * the user to enter a new prime number. Continue prompting the user
 * for a new number until the number they enter is prime, as shown in
 * test case. After the number is determined to be prime, reinitialize
 * the object using the anonymous object created by calling the 
 * custom constructor with the new prime number. Display the new
 * prime number as shown in the test case. Finally, create a new
 * PrimeNumber object that is initialized by post-incrementating 
 * the first object. Display your results as shown in the test case,
 * and prompt the user if they would like to enter another number (y/n).
 * 
 * Psuedocode:
 *
 * (1) PrimeNumber Class
 *      (a) member variable number
 *		(b) default constructor, set number to 2
 *		(c) custom constructor, initializing with new number
 *      (d) accessor getNumber() for number
 *		(e) isPrime() function
 *		(f) overload ++ operator 
 * (2) Main
 *		(a) Declare PrimeNumber object with default constructor
 *		(b) print num using object accessor
 *      (c) Prompt user for new number
 *		(d) Call isPrime(), repeat (c) until true
 *		(e) reinitialize object with custom constructor
 *		(f) print entered number using accessor
 *		(g) Delare new PrimeNumber object initialized with overloaded
 *			overloaded ++ operator on the first object
 *		(h) Print new number using accessor
 *		(i) Prompt user to run again (y/n)
 *
 * \author Ryan Laur
 * \date   March 12, 2021
 *********************************************************************/
#include <iostream> 
using namespace std;

// PrimeNumber class
class PrimeNumber {
public:
	// default constructor
	PrimeNumber();

	// custom constructord
	PrimeNumber(int newPrimeNum);

	// overloaded pre-increment operator
	const PrimeNumber operator ++();

	// accessor
	int getNumber() const;

	// function to check if prime
	bool isPrime(int) const;

private:
	int number;
};

// main
int main()
{
	int userNum = 0;
	char repeat = 'y';

	// PrimeNumber object intialized with default constructor
	PrimeNumber p1;

	// prompt user to under a prime number
	while (repeat == 'y')
	{
		cout << "Please enter a new prime number: ";
		cin >> userNum;
		while (!p1.isPrime(userNum))
		{
			cout << "The number entered is not prime! " << endl;
			cout << "Please enter a new prime number: ";
			cin >> userNum;
		}

		// object reinitialized with the user's input
		p1 = PrimeNumber(userNum);

		// print number entered by user
		cout << "The current prime number is: " << p1.getNumber() << endl;
		cout << "The next prime number is: ";

		// new object initialized with the first object incremented
		PrimeNumber p2 = ++p1;

		// print new number
		cout << p2.getNumber() << endl;

		// repeat 'y/n'
		cout << "Would you like to run again? (y/n) ";
		cin >> repeat;
		while (repeat != 'y' and repeat != 'n')
		{
			cout << "Invalid entry. " << endl;
			cout << "Would you like to run again? (y/n) ";
			cin >> repeat;
		}
		cout << endl;
	}

	cout << "Thank you for using this program. Goodbye!" << endl;

	return 0;
}

// default constructor 
PrimeNumber::PrimeNumber()
	: number(2)
{
	cout << "The default prime number is: " << number << endl;
}

// custom constructor
PrimeNumber::PrimeNumber(int newPrimeNum)
	: number(newPrimeNum)
{}

// overloaded ++ operator to return object using next prime number
const PrimeNumber PrimeNumber::operator++()
{
	number++;
	while (!isPrime(number))
	{
		number++;
	}
	return PrimeNumber(number);
}

// accessor for number variable
int PrimeNumber::getNumber() const
{
	return number;
}

// member function to determine if number if prime
bool PrimeNumber::isPrime(int num) const
{
	// anything less than 2 is not a prime number
	if (num < 2)
	{
		return false;
	}	
	// first prime number is 2
	else if (num == 2)
	{
		return true;
	}
	else
	{
		// start for loop after 2
		for (int i = 2; i <= num / 2; i++)
		{
			if (num % i == 0)
				return false;
		}
	}	
	return true;
}

