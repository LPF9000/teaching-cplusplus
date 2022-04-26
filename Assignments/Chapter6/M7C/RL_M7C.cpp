/*****************************************************************//**
 * \file   RL_M7C.cpp
 * \brief  Fraction Class
 *
 * Write a class called Fraction that contains two private member variables
 * for the numerator and denominator (integers).
 * -Create a public acccessor and a mutator for each private member 
 * variable. 
 * 
 * Write a public member function getDecimal() that returns the
 * decimal form of the fraction.
 * 
 * Write a public member function called getFraction() that returns
 * the gcd, or common-factor of the numerator and denominator.
 * 
 * In main(), create a Fraction object, and hardcode the numerator
 * and denominator as shown in the test case using the mutators. 
 * Display the entered fraction using the accessors. Call getDecimal()
 * to display the decimal form of the fraction. Call getFraction(), and
 * use the returned gcd to simplify the fraction into its simplest form
 * and print the output as shown in the test case. 
 *
 * Psuedocode:
 * (1) Class Fraction() with members variables for numerator and denominator
 * (2) Public accessors and mutators for numerator and denominator
 * (3) Member function getDecimal() that returns the decimal of fraction
 * (4) Member function that returns the gcd
 * (5) In main, create a fraction object
 * (6) Assign numerator and denominator using utators
 * (7) Call getDecimal() to display decimal
 * (8) Call getFraction() to get gcd
 * (9) Divide numerator and denominator by gcd to get a simplified 
 *		fraction
 * (10) Print the output
 *
 * \author Ryan Laur
 * \date   March 2, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

//class declaration
class Fraction {
public:
	//mutators
	void setNumer(int newNumer);
	void setDenom(int newDenom);

	//accessors
	int getNumer();
	int getDenom();

	// decimal and simplified fraction
	double getDecimal();
	int getFraction();

private:
	int numerator, denominator;
};

// main
int main() 
{
	// create Fraction object
	Fraction f1{};

	// set numerator and denominator with mutators
	f1.setNumer(192);
	f1.setDenom(12);

	// display the fraction entered and the decimal form
	cout << "Fraction Entered: " << f1.getNumer() << "/" << f1.getDenom() << endl;
	cout << "Decimal Form: " << f1.getDecimal() << endl;

	// simplify praction and print the result
	int cf = f1.getFraction();
	int newDenom = f1.getDenom() / cf;

	if (newDenom == 1)
	{
		cout << "Simplified fraction: " << f1.getNumer() / cf;
	}
	else
	{
		cout << "Simplified fraction: " << f1.getNumer() / cf << "/"
			<< f1.getDenom() / cf;
	}
	
	
	return 0;
}

// mutator function to set the numerator
void Fraction::setNumer(int newNumer)
{
	numerator = newNumer;
}

// mutator function to set the denominator
void Fraction::setDenom(int newDenom)
{
	denominator = newDenom;
}

// accessor function to return the numerator
int Fraction::getNumer()
{
	return numerator;
}

// accessor function to return the denominator
int Fraction::getDenom()
{
	return denominator;
}

// member function to return result of division
double Fraction::getDecimal()
{
	return static_cast<double>(numerator)/static_cast<double>(denominator);
}

// member functiont to return the gcd
int Fraction::getFraction()
{
	int num1 = numerator;
	int num2 = denominator;

	while (num1 != num2)
	{
		if (num1 > num2)
			num1 -= num2;
		else
			num2 -= num1;
	}

	return num1;
}
