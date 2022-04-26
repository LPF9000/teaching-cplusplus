/*****************************************************************//**
 * \file   RL_M9A.cpp
 * \brief  Class called Money (Operating overloading)
 *
 * This program will test various types of operator overloading.
 *
 * Write a class called Money that contains 3 private member
 * variables, an integer called dollars, an integer called cents,
 * and a double called total. 
 *
 * Write a default constructor that initializes the member variables
 * to 0.
 *
 * Write a custom constructor that initializes the member variables
 * dollars and cents with their corresponding paramaters. Calculate
 * the total by adding together the dollars and cents in the body. 
 * 
 * Write another custom constructor that initializes the member
 * variable total with its parameter. You may initialize
 * the dollars and cents in the body by separating the dollars and cents
 * from the total. 
 *
 * Overload the binary + operator as a friend member function to 
 * add two totals together. The result
 * of the overloaded + operator must be a constant Money object. 
 * 
 * Overload the unary - operator as a member function,
 * to negate the dollars and cents. The result
 * of the overloaded - operator must be a constant Money object.
 * 
 * Overload the binary - operator as a non-member function,
 * to subtract two totals. The result
 * of the overloaded - operator must be a constant Money object.
 * 
 * Write an accessor for the total variable, making it a constant
 * function. 
 *
 * In main(), declare 3 custom Money objects, initializing with the dollars
 * and cents and displaying the total as shown in the test case. 
 * Add the first two money objects together, and call the accessor to display the total.
 * Negate the third object, calling the accessor to display the total.
 * Finally, subtract the second object from the first object, and
 * call the accessor to display the total as shown in the test case. 
 *
 * Psuedocode:
 *
 * (1) Money Class
 *      (a) member variables dollars, cents, and total
 *		(b) default constructor, set variables to 0
 *		(c) custom constructor, calculate total
 *      (d) accessor for total
 *		(e) overloaded unary - operator
 *		(f) overloaded friend, binary + operator
 * 
 * (2) Non-Member Function
 *		(a) overloaded binary - operator, non-member
 * 
 * (3) Main
 *		(a) Create 3 money objects
 *		(b) set precision
 *      (c) dispaly totals, the dollars and cents combined
 *		(d) add object 1 and object 2 using overloaded operator and display
 *		(e) negate object 3 and display  
 *		(f) subtract object 2 from object 1 and display
 *
 * \author Ryan Laur
 * \date   March 12, 2021
 *********************************************************************/
#include <iostream> 
using namespace std;

// Money class
class Money {
public:
	// default constructor
	Money();

	// custom constructor
	Money(int newDollars, int newCents);
	Money(double newtotal);

	// overloaded friend + operator
	friend const Money operator +(const Money& amount1, const Money& amount2);

	// overloaded unary - operator
	const Money operator -();

	// accessor for total
	double getTotal() const;

private:
	int dollars, cents;
	double total;
};

// overloaded non-member - operator
const Money operator -(const Money& total1, const Money& total2);

// main
int main()
{
	// create Money objects
	Money m1(5, 20), m2(4, 10), m3(1, 90);

	// set precision
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// Display totals
	cout << "Acc 1: $" << m1.getTotal() << endl;
	cout << "Acc 2: $" << m2.getTotal() << endl;
	cout << "Acc 3: $" << m3.getTotal() << endl;

	// the overloaded + returns an object, so you may use it in this form
	cout << "Acc1 + Acc2 = $" << (m1+m2).getTotal() << endl;

	// you may also reinitialize this way
	m3 = -m3;
	cout << "-Acc3 = $" << m3.getTotal() << endl;

	// you may also create a new object and initialize
	Money m4 = m1 - m2;
	cout << "Acc1 - Acc2 = $" << m4.getTotal() << endl;

	return 0;
}

// default constructor
Money::Money()
	: dollars(0), cents(0), total(0.0)
{}

// custom constructor to set dollars/sents and calculate total
Money::Money(int newDollars, int newCents)
	: dollars(newDollars), cents(newCents)
{
	total = static_cast<double>(dollars) + static_cast<double>(cents)/100.0;
}

// custom constructor to set the total
Money::Money(double newTotal)
	: total(newTotal), dollars((int)newTotal)
{
	cents = static_cast<int>((newTotal - (double)dollars)*100.0);
}

// unary overloaded (-) operator, member function
const Money Money::operator-()
{
	return Money(-dollars, -cents);
}

// member friend function for overloaded (+) operator
const Money operator+(const Money& amount1, const Money& amount2)
{
	return Money(amount1.total + amount2.total);
}

// non-member binary overloaded (-) operator
const Money operator-(const Money& amount1, const Money& amount2)
{
	return Money(amount1.getTotal() - amount2.getTotal());
}

// accessor for the total
double Money::getTotal() const
{
	return total;
}
