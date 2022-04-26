/*****************************************************************//**
 * \file   RL_M12B.cpp
 * \brief  Class called Admin that inherits from a class called User
 *
 * Define a class called User with two protected member variables,
 * one for the number of users, as well as a pointer to a variable
 * of type string for the dynamic array of user names. Write
 * a member function to display the list the users, and another
 * member function to display a menu of options. A normal user
 * can only display the list of Users, or exit. 
 * 
 * The function menuOptions() will display a list of options,
 * a prompt the user for an option, and call the corresponding
 * member funtion. 
 * 
 * Create a default constructor for the User class 
 * that initializes the number of users to 1, 
 * and allocates the dynamic array of user names with a 
 * size of 1. 
 *
 * Define a class called Admin that inherits (public) from the
 * class User with an extra protected variable for
 * an email (string). Write a member function to add a user, delete
 * a user, display the users, and display a menu of options. An
 * admin can add, delete, display, or View as User.
 * 
 * Create a default constructor for the Admin class that 
 * initializes the email as shown in the test case, and
 * initializes the first user in the array as "Admin". You should call
 * the User() default constructor in the initialization list to
 * allocate your array. 
 * 
 * The addUser() function will prompt
 * a user for a userName, and add it into the array. You may use
 * a temporary dynamic array to assist you here. 
 * 
 * The deleteUser() function will prompt the user
 * for a number number to delete, and remove that user. You can use 
 * a temporary dynamic array to assist you here. 
 * 
 * The function menuOptions() of the Admin class will display a list of options,
 * a prompt the user for an option, and call the corresponding
 * member funtion. If they select View As User, you should use
 * an non-class User object to call the menuOptions function
 * of the User class. 
 *
 * In main, create a default admin object, and call menuOptions()
 * to display the options. Each choice selected within menuOptions 
 * will call the corresponding function, and return to menuOptions()
 * as shown in the test case. 
 *
 * Pseudocode:
 *
 * (1) Class called User
 *      default constructor
 *      function to print users
 *      function to print menu options
 *      member variables for number of users and usernames
 *
 * (2) Class called Admin (inherits from User)
 *      default constructor
 *      function to add user
 *      function to delete user
 *      function to print users
 *      function to print menu options
 *      member variable for email
 *
 * (4) Main
 *      create Admin object
 *      display menuoptions and get user input
 *          call appropriate function based on user input
 * 
 *      View As User Option
 *          Call menuOptions() using non-class User object
 *          only can display users or exit
 *
 * \author Ryan Laur
 * \date   April 9, 2021
 *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// Admin class
class User {
public:
    User();
    ~User();
    void showUsers() const;
    void menuOptions() const;
protected:
    string* users;
    int numUsers;
};

// Derived class inherits from User
class Admin : public User {
public:
    Admin();
    ~Admin();
    void addUser();
    void deleteUser();
    void showUsers();
    void menuOptions();

private:
    string email;
};

// main
int main()
{  
    Admin a;
    a.menuOptions();

    return 0;
}

// default constructor for the User class
User::User()
    : numUsers(1)
{
    users = new string[1];
}

// desctructor for user class
User::~User()
{
    delete[] users;
    users = nullptr;
}

// function to print the list of users as a user
void User::showUsers() const
{
    cout << "Users: " << endl;
    for (int i = 0; i < numUsers; i++)
    {
        cout << i + 1 << ". " << users[i] << endl;
    }

    cout << endl;

    menuOptions();
}

// function to display the menu options as a User
void User::menuOptions() const
{
    cout << "User Menu: " << endl;
    cout << "1. Display Users" << endl;
    cout << "2. Exit Menu\n";

    cout << "\nChoose an option (1-2): ";

    int option;
    cin >> option;

    switch (option) {
    case 1:
        showUsers();
        break;
    case 2:
        break;
    }
}

// default constructor for Admin Class
Admin::Admin()
    : email("sam.bridges@ufl.edu"), User()
{
    users[0] = "Admin";
}

// destructore
Admin::~Admin()
{
}

// function to add a user
void Admin::addUser()
{
    string userName;
    cout << "Please enter a userName: " << endl;
    cin >> userName;
   
    // increment the number of users
    numUsers++;

    // create temporary array 
    string* temp = new string[numUsers];

    // copy old array into temporary array
    for (int i = 0; i < numUsers - 1; i++)
    {
        temp[i] = users[i];
    }

    // add in the new userName to the last index in temp
    temp[numUsers - 1] = userName;

    // reallocate member dynamic array
    users = new string[numUsers];

    // set member array
    users = temp;
    cout << endl;

    // return to menuOptions
    menuOptions();
}

// function to delete a user
void Admin::deleteUser()
{
    int index;
    cout << "Which user would you like to delete? " << endl;

    cin >> index;
    while (index - 1 == 0)
    {
        cout << "Cannot delete Admin! " << endl;
        cout << "which user would you like to delete? ";
        cin >> index;
    }

    // temporary dynamic array
    string* temp = new string[numUsers];
    for (int i = 0; i < numUsers; i++)
    {
        // index of old array will equal index of new array
        int j = i;
        if (i == index - 1)
        {
            // skip index of old array if it matches user input
            j = i + 1;
            // if the last position is the one to delete, then 
            // j will be == to numUsers
            if (j == numUsers)
                break;
        }
        // copy the array into the temp array    
        temp[i] = users[j];
    }

    // decrement numUsers
    numUsers--;

    // reallocate array with new size
    users = new string[numUsers];

    // set userarray to temp array
    users = temp;

    cout << endl;

    // return to menu options
    menuOptions();
}

// function to print the list of users as an Admin
void Admin::showUsers()
{
    cout << "List of Users: " << endl;
    cout << "1. " << users[0] << endl;
    cout << "Email: " << email << endl;
    for (int i = 1; i < numUsers; i++)
    {
        cout << i + 1 << ". " << users[i] << endl;
    }
    cout << endl;

    // return back to menu options
    menuOptions();
}

// function to print the menu options as an Admin
void Admin::menuOptions()
{
    // display menu options
    cout << "Admin Menu: \n";
    cout << "1. Display Users\n";
    cout << "2. Add User\n";
    cout << "3. Delete User\n";
    cout << "4. View as User\n";

    // get user input 
    cout << "\nChoose an option (1-4): ";
    int option;
    cin >> option;

    // call function based on option
    switch (option) {
    case 1:
        showUsers();
        break;
    case 2:
        addUser();
        break;
    case 3:
        deleteUser();
        break;
    case 4:
        // display menuoptions as a user
        User::menuOptions();
        break;
    }
}
