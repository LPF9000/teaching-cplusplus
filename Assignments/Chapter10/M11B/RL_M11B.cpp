/*****************************************************************//**
 * \file   RL_M11B.cpp
 * \brief  Class called Pointer
 * 
 * Write a Class called Pointer with three private member
 * variables that stores two pointers of type int, and an integer. 
 * 
 * Write a default constructor that intializes the pointer
 * variables to NULL (nullptr), and the integer to 0. 
 * 
 * Write a custom constructor that takes in an integer, initializes
 * the private member integer variable with the passed integer value,
 * initializes the private member pointer variable to a newly
 * created dynamic variable with the passed value, and the second pointer
 * will be initialized with the reference of the **MEMBER* integer
 * value. 
 * 
 * Write an accessor and a mutator for each member variable. 
 * If a pointer is 0, its corresponding accessor will return 0, and
 * the mutator will use the pointer returned from a new created 
 * dynamic variable with the passed integer value. If it is not a 
 * null pointer, the accessor will return the dereferenced pointer,
 * and the mutator will set the deferenced pointer to the passed in
 * value.
 * 
 * Test your functions in main as shown in the test cases. 
 *
 * Psuedocode:
 * (1) class called Pointer
 *		default constructor
 *		custom constructor
 *		member variables
 *		accessors and mutators
 * (2) Test in Main
 *		create default and custom objects
 *		access default to print result
 *		call mutator on pointer 1 of default object
 *		access default to print results
 *		call mutator on integer variable for custom object
 *		access custom to print results
 *		call mutator on pointer 2 for custom object
 *		access custom to print results
 *	
 *
 * \author Ryan Laur
 * \date   April 2, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

class Pointer
{
public:
	// default constructor
	Pointer();
	
	// custom constructor
	Pointer(int num);

	// accessors
	int getPointer1() const;
	int getPointer2() const;
	int getNum() const;

	// mutators
	void setPointer1(int _num);
	void setPointer2(int _num);
	void setNum(int _num);
	
private:
	int* ptr1;
	int* ptr2;
	int num;
};

// main
int main()
{
	// create custom and default objects
	Pointer p1, p2(10);

	// accessing default
	cout << "Accessing variables using default object: \n";
	cout << "Integer: " << p1.getNum() << endl;
	cout << "Pointer1: " << p1.getPointer1() << endl;
	cout << "Pointer2: " << p1.getPointer2() << endl;

	// change pointer 1
	cout << "\nSetting pointer1 to value of 1234 in using the default object... \n";
	p1.setPointer1(1234);

	// accessing default 
	cout << "\nAccessing variables using default object: \n";
	cout << "Integer: " << p1.getNum() << endl;
	cout << "Pointer1: " << p1.getPointer1() << endl;
	cout << "Pointer2: " << p1.getPointer2() << endl;

	// accessing custom
	cout << "\nAccessing variables using custom object: \n";
	cout << "Integer: " << p2.getNum() << endl;
	cout << "Pointer1: " << p2.getPointer1() << endl;
	cout << "Pointer2: " << p2.getPointer2() << endl;

	// change integer variable
	cout << "\nSetting integer to value of 2 in using the custom object... \n";
	p2.setNum(2);

	// accessing custom
	cout << "\nAccessing variables using custom object: \n";
	cout << "Integer: " << p2.getNum() << endl;
	cout << "Pointer1: " << p2.getPointer1() << endl;
	cout << "Pointer2: " << p2.getPointer2() << endl;

	// change pointer 2
	cout << "\nSetting pointer2 to value of 1234 in using the custom object... \n";
	cout << "\nAccessing variables using custom object: \n";
	p2.setPointer2(1234);
	cout << "Integer: " << p2.getNum() << endl;
	cout << "Pointer1: " << p2.getPointer1() << endl;
	cout << "Pointer2: " << p2.getPointer2() << endl;

	return 0;
}

// default constructor
Pointer::Pointer()
	: ptr1(nullptr), ptr2(nullptr),num(0)
{}

// custom constructor
Pointer::Pointer(int _num)
	: num(_num), ptr2(&num)
{
	ptr1 = new int(_num);
}

// accessor for pointer1
int Pointer::getPointer1() const
{
	if (ptr1 == nullptr)
		return 0;
	else
	{
		return *ptr1;
	}
		
}

// accessor for pointer 2
int Pointer::getPointer2() const
{
	if (ptr2 == nullptr)
		return 0;
	else
		return *ptr2;
}

// mutator for pointer 1
void Pointer::setPointer1(int _num)
{
	if (ptr1 == nullptr)
		ptr1 = new int(_num);
	else
		*ptr1 = _num;
}

// mutator for pointer 2
void Pointer::setPointer2(int _num)
{
	if (ptr2 == nullptr)
		ptr2 = new int(_num);
	else
		*ptr2 = _num;

}

// mutator for integer variable
void Pointer::setNum(int num)
{
	this->num = num;
}

// accessor for integer variable
int Pointer::getNum() const
{
	return num;
}

