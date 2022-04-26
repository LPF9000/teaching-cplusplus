/*****************************************************************//**
 * \file   RL_M7A.cpp
 * \brief  Structures vs. Classes
 *
 * Write a structure called Person that contains two member variables,
 * one for age(integer), and one for weight(integer).
 * 
 * Write a function called getPerson that take in Person Struct
 * using pass by reference, and prompts the user for their age
 * and weight from within the function. 
 * 
 * Write a class called Date that contains three private member variables,
 * (integer) that correspond to the current day, month, and year. 
 * Create a public mutator to change the variables.
 * 
 * Write a public member function of Date called showDate() which
 * outputs the date according to the test cases.
 * 
 * In main(), prompt the user for the day, month, and year. 
 * Create a Date object, and use your mutator to set the
 * values. Create a structure variable, and call getPerson(), passing
 * in the person variable as an argument.
 * 
 * Call showDate() on the Person object to display the date.  
 *  
 * Print the age and weight in main() using the Person variable
 * as shown in the test case.
 * No print function necessary for this. 
 * 
 *
 * Psuedocode:
 * (1) Define/Declare getPerson struct, with members age and weight
 * (2) function getPerson(), prompt user for age and weight
 * (3) Class Date
 * (4) mutator to set the day month and year
 * (5) function showData() to print the date
 * (6) function to access the person struct getPerson()
 * (7) Create object for Date class and struct variable in main
 * (8) Prompt user for month, day, and year
 * (9) call mutator function for Data class to set the date
 * (10) call getPerson to prompt user for age and weight
 * (11) call showDate to print date, and print person data from main
 *
 *
 * \author Ryan Laur
 * \date   March 2, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// Person structure has members age and weight
struct Person
{
    int age, weight;
};

// Date class
class Date
{
public:
    // mutator
    void setDate(int newDay, int newMonth, int newYear);

    // print
    void showDate();

private:
    int year, day, month;
};

// function prototype
void getPerson(Person& person1);

int main()
{
    // create Person struct variable
    Person p1;

    // create Date class object
    Date d1{};

    // variables for user input
    int day, month, year;

    // prompt user for day, month, and year
    cout << "Enter the month, day, and year, each separated by a space: ";
    cin >> month >> day >> year;

    // set the date variables using user values
    d1.setDate(day, month, year);

    // call function to prompt user for age and weight
    getPerson(p1);

    // display the date
    d1.showDate();

    // display the age and weight
    cout << "Age Entered: " << p1.age << endl << "Weight Entered: "
        << p1.weight << endl;

    return 0;
}

// getPerson function to prompt user for age and weight
void getPerson(Person& person1)
{
    cout << "Enter age: ";
    cin >> person1.age;
    cout << "Enter weight: ";
    cin >> person1.weight;
}

// mutator to set the date values
void Date::setDate(int newDay, int newMonth, int newYear)
{
    day = newDay;
    month = newMonth;
    year = newYear;
}

// function to print the date
void Date::showDate()
{
    cout << "\nDate Entered: " << month << "/" << day << "/" << year << endl;
}
