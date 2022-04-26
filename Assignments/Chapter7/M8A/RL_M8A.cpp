/*****************************************************************//**
 * \file   RL_M8A.cpp
 * \brief  Class called ProduceBox
 * 
 * Write a class called ProduceBox with private member variables for the
 * number of apples, bananas, kiwi, carrots, and broccoli. 
 * 
 * Write a default constructor that initializes all of the member
 * variables to 0. 
 * 
 * Write a custom constructor with five paramaeters that initializes 
 * each member variable with its parameter.
 * 
 * Write a public member function called print() to print the 
 * quantities of produce in the box. 
 * 
 * In main(), declare a ProduceBox object that is initialized
 * by the default constructor, and call print() on the object. Then,
 * declare another ProduceBox object that is initialized by the 
 * custom constructor with the values shown in the test case, 
 * and call print() on the object. 
 * 
 * Psuedocode:
 * 
 * (1) Class ProduceBox
 *		(a) apples, bananas, kiwi, carrots, brocolli member variables
 *		(b) print()
 *		(c) default constructor
 *		(d) custom constructor
 * (2) Main
 *		(a) ProduceBox object 1
 *		(b) initialize with default constructor
 *		(c) print member variables
 *		(d) ProduceBox object 2
 *		(e) initialize with custom constructor
 *		(f) print member variables
 * 
 *
 * \author Ryan Laur
 * \date   March 5, 2021
 *********************************************************************/
#include <iostream>
using namespace std;

// ProduceBox class
class ProduceBox
{
public:
    // default constructor
    ProduceBox();

    // custom constructor
    ProduceBox(int apples, int bananas, int kiwi, int carrots, int broccoli);

    // print member function
    void print();

private:
    int apples, bananas, kiwi, carrots, broccoli;
};

// main
int main()
{
    // Produce box object delcared with default constructor
    ProduceBox p1;

    // print object values
    p1.print();

    // Produce box object delcared with custom constructor
    ProduceBox p2(6, 7, 2, 8, 1);

    // print object values
    p2.print();

	return 0;
}

// default constructor initializing to 0
ProduceBox::ProduceBox()
    : ProduceBox(0,0,0,0,0) // constructor delegation to invoke custom constructor to initialize
{}

// custom constructor
ProduceBox::ProduceBox(int numApples, int numBananas, int numKiwi, int numCarrots, int numBroccoli)
    : apples(numApples), bananas(numBananas), kiwi(numKiwi), carrots(numCarrots), broccoli(numBroccoli)
{}

// member function to print amount of produce
void ProduceBox::print()
{
    cout << "Box of Produce" << endl;
    cout << "---------------" << endl;
    cout << "Apples: " << apples << endl;
    cout << "Bananas: " << bananas << endl;
    cout << "Kiwi: " << kiwi << endl;
    cout << "Carrots: " << carrots << endl;
    cout << "Broccoli: " << broccoli << endl << endl;
}
