/*****************************************************************//**
 * \file   RL_M13C.cpp
 * \brief  Polymorphism (Pet, Dog, Cat)
 *
 * Define a class called Pet with two protected member variables
 * for the breed the name. 
 * Write pure virtual function called print().
 *
 * Define a class called Dog that inherits from Pet (public) that has a custom
 * constructor that takes in the name and a breed to initialize
 * the member variables of the base class. 
 *
 * Define a class called Cat that inherits from Pet (public) that has a custom
 * constructor that takes in a name and a breed to initialize
 * the member variables of the base class. 
 *
 * Define virtual print functions for both the Cat and Dog classes,
 * as shown in the test cases.
 *
 * In main, execute the different versions of print() after
 * declaring a pointer of Pet type and custom
 * objects of the two classes (Dog and Cat),
 * polymorphically. Hardcode the values using the constructors. 
 *
 * Psuedocode:
 * (1) Pet class
 *		pure virtual function to print
 *		member variables for breed and name
 * (2) Dog class
 *		virtual function to print
 * (3) Cat class
 *		virtual function print
 *
 * \author besta
 * \date   April  16, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// Pet class
class Pet
{
public:
	virtual void print() const = 0;

protected:
	string breed;
	string name;
};

// Dog class
class Dog : public Pet
{
public:
	Dog(string _name, string _breed);
	void print() const;

};

// Cat class
class Cat : public Pet
{
public:
	Cat(string name, string _breed);
	void print() const;
};

// main
int main()
{
	Dog d1("Hazel", "Yorkie");
	Cat c1("Thom Yorke", "Bengal");

	Pet* p1 = &d1;
	p1->print();

	p1 = &c1;
	p1->print();

	return 0;
}

// default constructor
Dog::Dog(string _name, string _breed)
{
	breed = _breed;
	name = _name;
}

// print function for Dog
void Dog::print() const
{
	cout << "Printing Dog Object..." << endl;
	cout << "Name: " << name << endl;
	cout << "Breed: " << breed << endl;
	cout << endl;
}

// default constructor for Cat class
Cat::Cat(string _name, string _breed)
{
	name = _name;
	breed = _breed;
}

// print function
void Cat::print() const
{
	cout << "Printing Cat Object..." << endl;
	cout << "Name: " << name << endl;
	cout << "Breed: " << breed << endl;
}

