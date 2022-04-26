/*****************************************************************//**
 * \file   RL_M11D.cpp
 * \brief  Class Called Bank
 * 
 * You may use the Bank and Client classes from M7B to 
 * help you answer this question.
 * 
 * Write a class called Client that contains two private variables,
 * for the amount of money in checking, and in savings. 
 * 
 * Write a default constructor that sets the member variables to 0.
 * 
 * Write a custom constructor that sets the initializes the member
 * variables with their corresponding parameter. 
 * 
 * Write a member function called showData() that prints the checking
 * and savings balances. 
 *
 * Write a class called Bank that contains two private member variables,
 * one for the number of clients for an array, and a pointer to a 
 * variable of type Client for the dynamic array. 
 * 
 * Write a default constructor that initializes the number of clients
 * to 0, and allocates the dynamic array with a capacity of 1. 
 * 
 * Write a destructor that frees the memory using delete[].
 *
 * Write a public member function called addClient() which takes in
 * a Client object and puts it into the array. Each time addClient is 
 * called, reallocate the array with the new size. The number of 
 * clients will increase each time the function is called. 
 * 
 * Hint: You can create another temporary array to assist in copying
 * the old array to the new array. 
 *
 * Write a public member function of Bank called showData() that
 * prints all of the clients data by calling the showData from Client.
 *
 * Test your Client and Bank classes with the member functions with
 * hardcoded values as shown in the test case.
 *
 * Psuedocode:
 * 
 * (1) Class called client
 *      default constructor
 *      custom constructor
 *      showData function to print data
 *      member variables for checking and savings
 * (2) Class called Bank
 *      member variables - pointer for array and number of clients
 *      default constructor
 *      destructor
 *      addClient function  
 *          increases size of array with each call
 *      showData function to print data
 * 
 * (3) Main
 *      create client objects
 *      create bank object
 *      add clients and print after each time adding
 *      
 *
 * \author besta
 * \date   April 2, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// Client class
class Client
{
public:
    Client();
    Client(double _checking, double _savings);

    // member function
    void showData() const;

private:
    double checking, savings;
};

// Bank class
class Bank
{
public:

    // default constructor
    Bank();

    // destructor
    ~Bank();

    void addClient(const Client& newClient);
    void showData() const;

private:
    Client* clientArray;
    int numClients;
};


// main
int main()
{
    // initialize client objects with custom constructor
    Client c1(2010.71, 9876.33), c2(13.71, 0.00), c3(500.00, 600.00) ,
        c4(9622.00, 20000.00);

    // intialize bank object with default constructor
    Bank b1;

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
    b1.addClient(c4);
    b1.showData();

    return 0;
}

// default constructor
Client::Client()
    : checking(0.0), savings(0.0)
{}

// custom constructor
Client::Client(double _checking, double _savings)
    : checking(_checking), savings(_savings)
{}

// function to print checking and savings balance for a client
void Client::showData() const
{
    cout << "Checking Balance: " << checking << endl;
    cout << "Savings Balance: " << savings << endl;
    cout << endl;
}

// default constructor
Bank::Bank()
    : numClients(0)
{
    // dynamically allocate array with capacity of 1
    clientArray = new Client[1];
}

// destructor
Bank::~Bank()
{
    delete[] clientArray;
    clientArray = nullptr;
}

// function to add client
void Bank::addClient(const Client& newClient)
{
    // increase number of clients
    numClients++;
    
    // if there is only 1 client, you do not need to change the size
    if (numClients-1 > 0)
    {
        // dynamically allocate a new array with new capacity
        Client* clientArray1 = new Client[numClients];

        // copy contents of old array into new array
        for (int i = 0; i < numClients-1; i++)
        {
           clientArray1[i] = clientArray[i];
        }
        // add the new client into the new array
        clientArray1[numClients-1] = newClient;

        // dynamically allocate our member array with the new capacity
        clientArray = new Client[numClients];

        // they are both the same size so we can copy the contents.
        clientArray = clientArray1;
    }
    else
    {
        clientArray[numClients-1] = newClient;
    }   
   
}

// function to print all of the clients data
void Bank::showData() const
{
    for (int i = 0; i < numClients; i++)
    {
        cout << "Client " << i + 1 << ": " << endl;
        clientArray[i].showData();
    }
}
