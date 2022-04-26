/*****************************************************************//**
 * \file   RL_M13A.cpp
 * \brief  Polymorphism (Pizza, DeepDishPizza, RegularPizza)
 * 
 * Define a class called Pizza with two protected member variables
 * for the size and number of toppings of a pizza. Define two
 * pure virtual functions called getTotal() and getInput(). Write a 
 * default constructor initializing the member variables to 0.
 * 
 * Define a class called DeepDishPizza that has a default
 * constructor initializing the member variables to 0, and 
 * two virtual functions for getTotal() and getInput(). getTotal()
 * will return the total price for a deep dish pizza. The total for 
 * a deepdish is 2.5 times the size, with 0.50 added for each topping.
 * getInput() will get the inputs from the user as shown in the test 
 * cases. 
 * 
 * Define a class called RegularPizza that has a default
 * constructor initializing the member variables to 0, two
 * virtual functions for getTotal() and getInput(). The total for
 * an original pizza will be 1.5 times the size, with 0.50 added
 * for each topping. getInput() will get the inputs from the user
 * as shown in the test cases.
 * 
 * In main, execute the different versions of getInput() and 
 * getTotal() after declaring a pointer of Pizza type and default
 * objects of the two classes (DeepDishPizza and RegularPizza),
 * polymorphically.
 * 
 * Psuedocode:
 * (1) Pizza class
 *		pure virtual function to get inputs from user
 *		pure virtual function to get total price
 *		member variables for size and number of toppings
 * (2) deepdishpizza class
 *		virtual function to get inputs from user
 *		virtual function to get total price
 *			2.5*size + 0.5* (number of toppings)
 * (3) regular class
 *		virtual function to get inputs from user
 *		virtual function to get total price
 *			1.5*size + 0.5* (number of toppings)
 *
 *
 * \author besta
 * \date   April  16, 2021
 *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// pizza class
class Pizza
{
public:
	Pizza();
	virtual double getTotal() const = 0;
	virtual void getInput() = 0;

protected:
	int size, numToppings;
};

// deepdish pizza class
class DeepDishPizza : public Pizza
{
public:
	DeepDishPizza();
	void getInput();
	double getTotal() const;

};

// regular pizza class
class RegularPizza : public Pizza
{
public:
	RegularPizza();
	void getInput();
	double getTotal() const;
};

// main
int main()
{
	DeepDishPizza d1;
	RegularPizza r1;

	Pizza* p1 = &d1;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	p1->getInput();
	cout << "Total: $" << p1->getTotal() << endl;

	p1 = &r1;

	p1->getInput();
	cout << "Total: $" << p1->getTotal() << endl;
	
}

// default constructor
DeepDishPizza::DeepDishPizza()
{
	size = 0;
	numToppings = 0;
}

// get inputs from user (deepdish)
void DeepDishPizza::getInput()
{
	cout << "Deep Dish Pizza: \n";
	cout << "Enter a size: (8 or 12 inches)" << endl;
	cin >> size;
	while (size != 8 && size != 12)
	{
		cout << "Invalid entry. \n";
		cout << "Enter a size: (8 or 12 inches)" << endl;
		cin >> size;
	}	
	cout << "How many toppings would you like? ";
	cin >> numToppings;
}

// return total price
double DeepDishPizza::getTotal() const
{
	return 2.5*(double)size + 0.5*(double)numToppings;
}

// default constructor for regular pizza
RegularPizza::RegularPizza()
{
	size = 0;
	numToppings = 0;
}

// get inputs from user
void RegularPizza::getInput()
{
	cout << "\nOriginal Pizza: \n";
	cout << "Enter a size: (8, 12, 14, or 16 inches)" << endl;
	cin >> size;
	while (size != 8 && size != 12 && size != 14 && size != 16)
	{
		cout << "Invalid entry. \n";
		cout << "Enter a size: (8, 12, 14, or 16 inches)" << endl;
		cin >> size;
	}
	cout << "Enter the number of Toppings: ";
	cin >> numToppings;
}

// return total price
double RegularPizza::getTotal() const
{
	return 1.5*(double)size + 0.5*(double)numToppings;
}

// default pizza constructor
Pizza::Pizza()
	:size(0), numToppings(0)
{}
