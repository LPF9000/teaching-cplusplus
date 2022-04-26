/*****************************************************************//**
 * \file   RL_M8D.cpp
 * \brief  Class called Employee
 *
 * Write a class called Employee that contains two private member
 * variables, a static integer called count to store the total number of 
 * employees, and an integer called number to store the employee number. 
 * This program will count the number of Employee objects created. 
 *
 * Write a default constructor that initializes each of the member variables. 
 * Every time an employee object is created, the count will increment.
 * The current employee number will be initialized in the order the 
 * object was created, ie the first object will be empNumber = 1;
 * Define the default constructor with an initialization
 * section.
 *
 * Write a custom constructor that takes in a constant call-by-reference
 * employee object, and initializes the member variables in the same
 * manner as the default constructor. This is so if an object
 * is initialized by another object of the same class,
 * the counter will increment. 
 * 
 * 
 * Write an accessor for the number member variable, making it a 
 * constant function. Write a static accessor function for the
 * count member variable. 
 * 
 * Initialize your static variable to 0 outside of the class definition.
 * See page 310-311 for more details. 
 *
 * In main(), declare an Employee object that is initialized
 * by the default constructor. Print the results by calling the accessor 
 * for the number member variable using the Employee object, and call 
 * the accessor for the count variable from a non-class object. Then, 
 * declare a new Employee object that is initialized by the previous 
 * object, passing the first object as an argument. Print the results by 
 * calling the accessors in the same manner as before. 
 * Then, create two employee objects that are 
 * initialized by the default constructor, and print the results by 
 * calling the accessors in the same manner as before.  
 * 
 * Hint: Constant call-by-reference 
 * myClass(const myClass&)
 *
 * Psuedocode:
 *
 * (1) Class Employee
 *      (a) member variable number and static variable count
 *		(b) default constructor to increment count and number
 *		(c) custom constructor to increment count and number
 *      (d) accessors for number and count, count is static function
 * (2) Main
 *		(a) Declare Employee object with default constructor
 *		(b) print num using object, print count using non-class object
 *      (c) Declaree new employee object initializing with first object
 *		(d) print results
 *		(e) Declare two Employee Objects
 *		(f) print results
 *
 * \author Ryan Laur
 * \date   March 5, 2021
 *********************************************************************/
#include <iostream> 
using namespace std;

// Employee class
class Employee {
public:
	// default constructor
	Employee();

	// custom constructor
	Employee(const Employee&);

	// accessors
	int getNumber() const;
	static int getCount();

private:
	static int count;
	int number;
};

// initialize static variable outside of class
int Employee::count = 0;

// main
int main()
{
	// create first employee object
	Employee g1;

	// print using accessors
	cout << "After creating one object: " << endl;
	cout << "Accessing Object " << g1.getNumber() << ": " << endl;
	cout << "Total Employee Count: " << Employee::getCount() << endl;

	// create second employee object, intializing with first object
	Employee g2(g1);
	cout << "\nAfter creating one more object: " << endl;
	cout << "Accessing Object " << g2.getNumber() << ": " << endl;
	cout << "Total Employee Count: " << Employee::getCount() << endl;

	// create third and fourth employee objects using default constructor
	Employee g3, g4;

	// print using accessors
	cout << "\nAfter creating two more objects: " << endl;
	cout << "Accessing Object " << g3.getNumber() << ": " << endl;
	cout << "Total Employee Count: " << Employee::getCount() << endl;
	cout << "Accessing Object " << g4.getNumber() << ": " << endl;
	cout << "Total Employee Count: " << Employee::getCount() << endl;

	return 0;
}

// default constructor 
Employee::Employee()
	: number(++count)
{}

// custom constructor
Employee::Employee(const Employee&)
	: Employee()
{}

// employee number accessor
int Employee::getNumber() const
{
	return number;
}

// count accessor
int Employee::getCount()
{
	return count;
}
