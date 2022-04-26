/*****************************************************************//**
 * \file   RL_M7B.cpp
 * \brief  Bank and Client Classes
 *
 * Write a class called Client that contains two private variables,
 * for the amount of money in checking, and in savings. Create a
 * public accessor and mutator for the member variables. 
 * 
 * Write a class called Bank that contains three private member variables,
 * one for an array of clients (Client), the number
 * of clients in the array, and the maximum size of the array. We will
 * assume the maximum size to be 3. 
 *
 * Write a public member function called addClient() which takes in 
 * a BankAccount object and puts it into the array.
 *
 * Write a public member function of Bank called showData() that
 * prints all of the clients data. 
 *
 * Test your Client and Bank classes with the member functions with
 * hardcoded values as shown in the test case. 
 *
 *
 * Psuedocode:
 * (1) Client class
 *      setAccount() mutator
 *      showData() public member function to print
 *      private members for checking and savings
 * (2) Bank class
 *      addClient() member function to add Client object
 *      showData() member function to print all client data
 *      Client array, size, and capacity private variables
 * (3) Create objects for bank class and client in main
 * (4) Set checking and savings amounts using mutator
 * (5) Set Precision
 * (6) Add a Client and print the results
 *      
 *
 *
 * \author Ryan Laur
 * \date   March 2, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// Client class
class Client
{
public:

    // mutators
    void setAccount(double newChecking, double newSavings);

    // print
    void showData();

private:
    double checking, savings;
};

// Bank class
class Bank
{
public:
    //accessors
    void addClient(Client newClient);

    // print
    void showData();

private:
    const int MAX_SIZE = 3;
    Client clientArray[3] = {};
    int numClients = 0;
};

int main()
{
    Bank b1;
    Client c1{}, c2{}, c3{};

    // set checking and savings
    c1.setAccount(2010.71, 9876.33);
    c2.setAccount(13.71, 0.00);
    c3.setAccount(500.00, 600.00);

    // set precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // add clients
    cout << "After adding client 1: " << endl;
    b1.addClient(c1);
    b1.showData();

    cout << "After adding client 2: " << endl;
    b1.addClient(c2);
    b1.showData();

    cout << "After adding client 3: " << endl;
    b1.addClient(c3);
    b1.showData();

    cout << "After adding client 4: " << endl;
    b1.addClient(c3);

    return 0;
}

// mutator for checking and savings
void Client::setAccount(double newChecking, double newSavings)
{
    checking = newChecking;
    savings = newSavings;
}

// function to print checking and savings balance for a client
void Client::showData()
{
    cout << "Checking Balance: " << checking << endl;
    cout << "Savings Balance: " << savings << endl;
    cout << endl;
}

// function to add client
void Bank::addClient(Client newClient)
{
    // only assign into arrive if there is room in the array
    if (numClients < MAX_SIZE)
    {
        clientArray[numClients] = newClient;
        numClients++;
    }
    else
        cout << "Not enough space to add client!\n" << endl;
}

// function to print all of the clients data
void Bank::showData()
{
    for (int i = 0; i < numClients; i++)
    {
        cout << "Client " << i + 1 << ": " << endl;
        clientArray[i].showData();
        
    }
}
