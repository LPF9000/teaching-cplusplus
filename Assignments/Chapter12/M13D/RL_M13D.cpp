/*****************************************************************//**
 * \file   RL_M13D.cpp
 * \brief  Polymorphism (Client, PersonalClient, BusinessClient)
 * You may use the Client class from M11C to
 * help you answer this question.
 *
 * Write a class called Client that contains a public static member
 * variable called numClients. The Bank class is an abstract class,
 * a class with at least one pure virtual function. Declare
 * a pure virtual function called showData(). Also, create an accessor
 * for the static variable numClients. Create four protected member 
 * variables (firstname, lastname, checking, and savings) for 
 * the Client class. Create a default constructor to initialze
 * the checking and savings to 0.0, the first name to "Jane", and the
 * last name to "Doe". 
 *
 * Define a class called BusinessClient that inherits (public) from the class
 * Client with an extra private member variable: investments. Define
 * a constructor with five paramaeters, (firstname, lastname, checking,
 * savings, and investments) for the BusinessClient class. Define the virtual
 * function print() to display the firstname, lastname, checking balance,
 * savings balance, and investment balance of a BusinessClient object as shown
 * in the test cases. Increment numClients inside your constructor, so
 * the number of clients increases when the object is created. 
 * 
 * Define a class called PersonalClient that inherits (public) from the class
 * Client with an extra private member variable: limit. Define
 * a constructor with five paramaeters, (firstname, lastname, checking,
 * savings, and limit) for the PersonalClient class. Define the virtual
 * function print() to display the firstname, lastname, checking balance,
 * savings balance, and daily withdrawl limit balance of a PersonalClient object as shown
 * in the test cases. Increment numClients inside your constructor, so
 * the number of clients increases when the object is created. 
 *
 * In main, execute different versions of the function print() after
 * declaring an array of pointers of Client type and objects of the two classes
 * (PersonalClient and BusinessClient) polymorphically with hardcoding values. You can 
 * allocate the size of the array of pointers using the accessor
 * for numClients. 
 * 
 * Hint: 
 * You can create an array of pointers that point to your objects like so:
 * Client** clientArray = new Client*[numClients]{ &p1, &p2, &b1, &b2 };
 * 
 * you can then print using clientArray[i]->showData(); 
 * 
 *
 * Psuedocode:

 * (1) Class called Bank
 *      static variable for number of clients
 *      pure virtual function showData() to print data
 *      static accessor for number of clients
 * (2) Class called client
 *      default constructor
 *      pure virtual showData function to print data
 *      member variables for checking and savings , first name and
 *      last name
 * (3) Class called BusinessClient
 *      member variables
 *          first name, last name, checking, savings, and investments
 *      custom constructor to initialize member variables
 *      virtual showData() function to print
 * (4) Class called PersonalClient
 *      member variables
 *          first name, last name, checking, savings, and withdrawl limit
 *      custom constructor to initialize member variables
 *      virtual showData() function to print
 *
 * (3) Main
 *      create PersonalClient and BusinessClient objects
 *      create array of Clients
 *      add clients and print after each time adding
 *
 * \author besta
 * \date   April  16, 2021
 *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Client class
class Client
{
public:
    virtual void showData() const = 0;
    Client();
    static int getNumClients();
    static int numClients;

protected:
    double checking, savings;
    string firstname, lastname;
};

int Client::numClients = 0;

class BusinessClient : public Client
{
public:
    BusinessClient(string _firstname, string _lastname, double _checking, double _savings, double _investments);

    // member function
    void showData() const;

private:
    double investments;
};

class PersonalClient : public Client
{
public:
    PersonalClient(string _firstname, string _lastname, double _checking, double _savings, double _limit);

    // member function
    void showData() const;

private:
    double limit;
};


// main
int main()
{
    // create PersonalClient and BusinessClient objects
    PersonalClient p1("Sam", "Bridges", 2010.71, 9876.33, 1000), p2("Joe", "Exotic", 13.71, 0.00, 1000);
    BusinessClient b1("Hans", "Zimmer", 9622.00, 20000.00, 762333.87), b2("John", "Williams", 22222.00, 33333.00, 123222.00);

    // set precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    int num = Client::getNumClients();
    // allocate an array of pointers and initialize with object references
    Client** clientArray = new Client*[num]{ &p1, &p2, &b1, &b2 };

    // for loop to call showData() using the array of pointers
    for (int i = 0; i < num; i++)
    {
        clientArray[i]->showData();
    }

    delete[] clientArray;
    clientArray = nullptr;

    return 0;
}

// Client default constructor
Client::Client()
    : checking(0.0), savings(0.0), firstname("Jane"), lastname("Doe")
{}

// accessor for number of clients
int Client::getNumClients()
{
    return numClients;
}

// BusinessClient custom constructor
BusinessClient::BusinessClient(string _firstname, string _lastname, double _checking, double _savings, double _investments)
    : investments(_investments)
{
    numClients++;
    checking = _checking;
    savings = _savings;
    firstname = _firstname;
    lastname = _lastname;
}

// Display data for BusinessClient
void BusinessClient::showData() const
{
    cout << "BusinessClient Account: " << endl;
    cout << firstname << " " << lastname << " " << endl;
    cout << "Checking Balance: " << checking << endl;
    cout << "Savings Balance: " << savings << endl;
    cout << "Investmentsment Balance: " << investments << endl;
    cout << endl;
}

// custom constructor for PersonalClient
PersonalClient::PersonalClient(string _firstname, string _lastname, double _checking, double _savings, double _limit)
    : limit(_limit)
{
    numClients++;
    checking = _checking;
    savings = _savings;
    firstname = _firstname;
    lastname = _lastname;
}

// Display data for PersonalClient
void PersonalClient::showData() const
{
    cout << "PersonalClient Account: " << endl;
    cout << firstname << " " << lastname << " " << endl;
    cout << "Checking Balance: " << checking << endl;
    cout << "Savings Balance: " << savings << endl;
    cout << "Daily Withdrawl Limit: " << limit << endl;
    cout << endl;
}
