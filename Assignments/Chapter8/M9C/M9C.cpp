/*****************************************************************//**
 * \file   RL_M9C.cpp
 * \brief  Class called CreditCard (operator overloading)
 *
 * Write a class called CreditCard that contains 2 private member
 * variables, for the balance (double), and the interest rate (double)
 *
 * Write a default constructor that initializes the member variables
 * to 0.
 *
 * Write a custom constructor that initializes the members
 * variables with their corresponding parameter.
 *
 * Overload the + operator as a member function. The function 
 * must return a constant CreditCard object. 
 * 
 * Write a constant member function called print() that prints the information
 * according to the test case. 
 * 
 * Write a second class called BalanceTransfer, that contains 4
 * private member variables for the total limit, the balance, the interest
 * rate, and the remaining limit.
 * 
 * Write a default constructor that initializes variables to 0.
 * 
 * Write a custom constructor that initializes variables to their
 * corresponding parameter, with the exception of remaining limit which 
 * will be calculated by subtracting the balance from the total limit.
 * 
 * Overload the < operator as a member function, that takes in
 * a CreditCard object, and returns true or false by comparing the 
 * balance with the new CreditCard limit
 * 
 * Write a function called print() that will print the information
 * about the balance transfer as shown in the test case.
 *
 * In main(), declare 3 custom CreditCredit objects and print the information
 * as shown in the test case. Then, create a custom BalanceTransfer
 * object, that initializes the member variables using the 
 * balance and interest from the third credit card. The total limit
 * for the balance transfer is given in the test case. 
 * 
 * Then, determine if the remaining limit is less than the 
 * sum of the first two credit card balances. If so, print a message 
 * as shown in the test case. If the remaining limit is not less than
 * the sum of the first two credit card balances, then finish the
 * balance transfer by setting credit card 3 equal to the sum 
 * of credit card 1 and 2, and then set credit card 1 and 2 equal
 * to 0. Print the results as shown in the test case. 
 *
 * Psuedocode:
 *
 * (1) CreditCard Class
 *      (a) member variables balance and interest
 *		(b) default constructor, set variables to 0
 *		(c) custom constructor
 *		(d) overload +
 *		(e) print function
 *		(f) accessors
 * (2) BalanceTransfer Class
 *		(a) member variables balance, interest, limit, and remLimit
 *      (b) default constructor
 *		(c) custom constructor, calculate remaining Limit
 *		(d) Overloaded < operator
 *		(e) print function
 * (3) Main
 *		(a) create 3 credit card objects
 *		(b) print information
 *		(c) create balance transfer object
 *			(i) use balance and interest from Credit Card 3
 *		(d) use overloaded operators
 *			(i) the remaining limit is less than the sum of CC1 and CC2
 *		(e) if yes, print message
 *		(d) if no, print message, set C3 equal to C1 + C2, and set
 *			CC1 and CC2 to 0. 
 *		(e) print updated information. 
 *
 * \author Ryan Laur
 * \date   March 12, 2021
 *********************************************************************/
#include <iostream> 
using namespace std;

// CreditCard class
class CreditCard {
public:
	// default constructor
	CreditCard();

	// custom constructor
	CreditCard(double balance, double interest);

	// overloaded + operator
	const CreditCard operator +(const CreditCard&);

	// accessors
	double getBalance() const;
	double getInterest() const;

	// print function
	void print() const;	

private:
	double balance, interest;

};

// BalanceTransfer Class
class BalanceTransfer {
public:
	// default and custom constructor
	BalanceTransfer();
	BalanceTransfer(double newLimit, double newInterest, double newBalance);

	// overloaded operator
	const bool operator <(const CreditCard&);

	// print function
	void print() const;

private:
	double limit, balance, interest, remLimit;
};

// main
int main()
{
	// set precision
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);

	// credit card objects
	CreditCard c1(2657.23, 18.99), c2(6623.98, 13.99), c3(323.69,0.0);
	cout << "Credit Card 1: " << endl;
	c1.print();
	cout << "Credit Card 2: " << endl;
	c2.print();
	cout << "Credit Card 3: " << endl;
	c3.print();

	// balance transfer
	cout << "\nTransferring Card 1 + Card 2 ===> Card 3" << endl;
	cout << "\nAccount to transfer the balance to: " << endl;
	BalanceTransfer b1(9000.0, c3.getInterest(), c3.getBalance());
	b1.print();

	// using overloaded operators
	if (b1 < (c1 + c2))
	{
		cout << "You are able to transfer! " << endl;		
		c3 = (c1 + c2);
		c1 = CreditCard(0.0, 0.0);
		c2 = CreditCard(0.0, 0.0);		
	}
	else
	{
		cout << "You are not able to transfer! " << endl;
		cout << "Account balances will stay the same. \n" << endl;
	}

	// print updated account information
	cout << "Updated account information: " << endl;
	cout << "Credit Card 1: " << endl;
	c1.print();
	cout << "Credit Card 2: " << endl;
	c2.print();
	cout << "Credit Card 3: " << endl;
	c3.print();

	return 0;
}

// default constructor
CreditCard::CreditCard()
	: balance(0.0), interest(0.0)
{}

// custom constructor
CreditCard::CreditCard(double newBalance, double newInterest)
	: balance(newBalance), interest(newInterest)
{}

// overloaded + operator 
const CreditCard CreditCard::operator+(const CreditCard& c1)
{
	return CreditCard(balance + c1.balance, interest);
}

// accessor for the credit card balance
double CreditCard::getBalance() const
{
	return balance;
}

// accessor for the interest
double CreditCard::getInterest() const
{
	return interest;
}

// print for credit card information
void CreditCard::print() const
{
	cout << "Balance: " << balance << endl;
	cout << "Interest Rate: " << interest << endl;
}

// default constructor for BalanceTransfer
BalanceTransfer::BalanceTransfer()
	: limit(0.0), interest(0.0), balance(0.0), remLimit(0.0)
{}

// custom constructor for Balance Transfer
BalanceTransfer::BalanceTransfer(double newLimit, double newInterest, double newBalance)
	: limit(newLimit), interest(newInterest), balance(newBalance)
{
	remLimit = newLimit - newBalance;
}

// overloaded < operator
const bool BalanceTransfer::operator <(const CreditCard& c1)
{
	return limit > c1.getBalance();
}

// print function for balance transfer
void BalanceTransfer::print() const
{
	cout << "Total Limit: " << limit << endl;
	cout << "Remaining Limit: " << remLimit << endl;
	cout << "Interest Rate: " << interest << "%\n" << endl;
}


