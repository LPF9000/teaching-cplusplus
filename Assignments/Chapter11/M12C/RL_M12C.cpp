/*****************************************************************//**
 * \file   RL_M12C.cpp
 * \brief  Class called Billing that inherits from a class called Person
 *
 * Create a base class called Person with protected member variable
 * for the name (string). Write a default constructor that 
 * initializes the name to "Jane Doe". Write a custom constructor that
 * initializes the member variable with its parameter.
 * 
 * Write a member function called print() that prints the
 * name of the person.
 * 
 * Create a derived classed called Billing that inherits from the
 * Person class (public), with a private member variable for
 * the balance (double). Create a default constructor
 * that initializes the balance to 0, and calls the 
 * default constructor for the person class to initialize the name.
 * Create a custom constructor that takes in a Person object and 
 * the balance, and initializes the inherited variales by
 * invoking the copy constructor. Person(object)
 * 
 * Create a member function called print() that calls the print
 * function from the Person class, and prints the balance. 
 * 
 * Test your defualt and custom objects in main as shown in the test 
 * cases. 
 *
 *
 *
 * Pseudocode:
 *
 * (1) Class called Person
 *      default constructor
 *      custom constructor
 *      function to print
 *      member variable for name
 *
 * (2) Class called Billing (inherits from User)
 *      default constructor
 *      custom constructor
 *      function to print name and balance
 *      member variable for balance
 *
 * (4) Main
 *      create default person object
 *      print results
 *      create default billing object
 *      print results
 *      create custom person object
 *      print results
 *      create custom billing object using the custom person object
 *      print results
 *
 *
 * \author Ryan Laur
 * \date   April 9, 2021
 *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Person class
class Person {
public:
    Person();
    Person(string _name);
    void print() const;
protected:
    string name;
};

// Derived class inherits from Person
class Billing : public Person {
public:
    Billing();
    Billing(const Person& p1, double _balance);
    void print() const;

private:
    double balance;
};

// main
int main()
{
    Person p1, p2("Sam Bridges");
    Billing b1, b2(p2, 4678.96);
    cout << "Testing default Person Object... " << endl;
    p1.print();

    cout << "\nTesting custom Person Object... " << endl;
    p2.print();

    cout << "\nTesting default Billing Object... " << endl;
    b1.print();

    cout << "\nTesting custom Billing Object... " << endl;
    b2.print();

    return 0;
}

// default constructor for Person class
Person::Person()
    : name("Jane Doe")
{}

// custom constructor for Person Class
Person::Person(string _name)
    : name(_name)
{}

// function to print the name of a person
void Person::print() const
{
    cout << "Name: " << name << endl;
}

// default Billing constructor
Billing::Billing()
    : Person(), balance(0.0)
{}

// custom constructor, invokes copy constructor of Person class
Billing::Billing(const Person& p1, double _balance)
    : balance(_balance), Person(p1)
{}

// function to print name and balance
void Billing::print() const
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    Person::print();
    cout << "Balance: $" << balance << endl;
}
