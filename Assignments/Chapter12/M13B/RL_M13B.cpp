/*****************************************************************//**
 * \file   RL_M13B.cpp
 * \brief  Polymorphism (Multiplier, Tripler, Doubler)
 *
 * Define a class called Multiplier with two protected member variables
 * for the size and a pointer of type int. Define a default constructor
 * that initializes the size to 0, and the pointer to nullptr. 
 * Write pure virtual function called print().
 *
 * Define a class called Tripler that inherits from Multiplier (public) that has a custom
 * constructor that takes in a whole array and a size. The custom 
 * constructor will dynamically allocate the member pointer
 * variable to an array using the passed in array and the size. 
 * The custom constructor will multiply the values in the array
 * by 3 as shown in the test cases. 
 *
 * Define a class called Doubler that inherits from Multiplier (public) that has a custom
 * constructor that takes in a whole array and a size. The custom
 * constructor will dynamically allocate the member pointer
 * variable to an array using the passed in array and the size.
 * The custom constructor will multiply the values in the array
 * by 2 as shown in the test cases.
 * 
 * Define virtual print functions for both the Doubler and Tripler classes,
 * as shown in the test cases. 
 *
 * In main, execute the different versions of print() after 
 * declaring a pointer of Multiplier type and custom
 * objects of the two classes (Tripler and Doubler),
 * polymorphically. You can get the size and inputs for the array
 * from the user to pass into the constructors. 
 *
 * Psuedocode:
 * (1) Multiplier class
 *		pure virtual function to print
 *		member variables for size and array 
 * (2) tripler class
 *		virtual function to print
 * (3) doubler class
 *		virtual function print
 *
 * \author besta
 * \date   April  16, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// multiplier class
class Multiplier
{
public:
	Multiplier();
	virtual void print() const = 0;

protected:
	int size;
	int* numArray;
};

// tripler class
class Tripler : public Multiplier
{
public:
	Tripler(int arr[], int _size);
	void print() const;

};

// doubler class
class Doubler : public Multiplier
{
public:
	Doubler(int arr[], int _size);
	void print() const;
};

// main
int main()
{
	int size;
	cout << "How many numbers would you like to enter? ";
	cin >> size;
	cout << "Enter " << size << " numbers separated by a space:\n";
	int* numArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> numArray[i];
	}
	
	Doubler d1(numArray, size);
	Multiplier* m1 = &d1;

	m1->print();

	Tripler t1(numArray, size);
	m1 = &t1;

	m1->print();

	delete[] numArray;
	numArray = nullptr;

	return 0;
}

// default constructor
Tripler::Tripler(int arr[], int _size)
{
	size = _size;
	numArray = new int[_size];
	numArray = arr;
	for (int i = 0; i < size; i++)
	{
		numArray[i] *= 3;
	}

}

// print function for tripler
void Tripler::print() const
{
	cout << "Tripled Array: \n";
	for (int i = 0; i < size; i++)
	{
		cout << numArray[i] << " ";
	}
	cout << endl;
}

// default constructor for doubler class
Doubler::Doubler(int arr[], int _size)
{
	
	size = _size;
	numArray = new int[_size];
	numArray = arr;
	for (int i = 0; i < size; i++)
	{
		numArray[i] *= 2;
	}
}

// print function
void Doubler::print() const
{
	cout << "Doubled Array: \n";
	for (int i = 0; i < size; i++)
	{
		cout << numArray[i] << " ";
	}
	cout << endl;
}

// default constructor
Multiplier::Multiplier()
	: size(0), numArray(nullptr)
{}
