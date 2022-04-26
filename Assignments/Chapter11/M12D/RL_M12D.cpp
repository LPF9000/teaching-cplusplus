/*****************************************************************//**
 * \file   RL_M12D.cpp
 * \brief  Class called Admin that inherits from a class called User
 *
 * Create a base class called DynamicArray with protected member 
 * variables for the size of the array, the capacity, and a
 * pointer of type int for a dynamic array of integers. 
 *
 * Write a default constructor that initializes the size to 0,
 * the capacity to 1, and allocates the dynamic array with the
 * capacity. 
 * 
 * Write a custom constructor that takes in a capacity, and
 * initializes the size to 0, the capacity to its corresponding 
 * parameter, and allocates the dynamic array with the capacity.
 * 
 * Create a destructor that deletes the array and sets it equal
 * to nullptr. 
 * 
 * Write a member function called fillArray() that
 * fills a dynamic array based on inputs from the user, with the size
 * incrememnting each time a number is entered. 
 * 
 * Write a member function called emptyArray() that deletes the
 * array, sets it equal to nullptr, sets the capacity to 1, and the
 * size to 0. 
 * 
 * Write an accessor for the capacity and the size. 
 * 
 * Write a function called print() that will print the numbers
 * stores in the array.
 *
 * Create a derived classed called Backup that inherits from the
 * DynamicArray class (public), with private member variables for 
 * the backup size of the array, the backup capacity, and a
 * pointer of type int for a backup dynamic array of integers.  
 * 
 * Create a default constructor that initializes the member variables
 * with the member variables from the base class DynamicArray. Allocate
 * the dynamic backup array with the backupCapacity.
 * 
 * Create a custom constructor that takes in a capacity, and calls 
 * the custom DynamicArray constructor with the capacity as the argument.
 * It will initalize the member variable backupSize with 0, and 
 * the backupCapacity with the capacity from the derived class. 
 * Allocate the dynamic array backupArray with the capacity. 
 * 
 * Write a destructor that deletes the dynamic array and sets
 * it equal to nullptr. 
 * 
 * Write a member function called backup() that sets the backupSize equal
 * to the size of the base class, and the backupCapacity equal to the 
 * capacity of the base clase. It will then copy each
 * position of the array of the DynamicArray class into the backupArray
 * of the Backup class. 
 * 
 * Write a member function called restore() that sets the size equal
 * to the backupSize of the derived class, and the capacity equal to the 
 * backupCapacity of the derived clase. It will then copy each
 * position of the backupArray of the Backup class into the array
 * of the DynamicArray class. 
 * 
 * Write a function called print() that calls the print
 * function of the DynamicArray class. 
 * 
 *
 * In main, first create a 
 * default Backup object and call the accessors to display the capacity and 
 * size. Then, prompt the user for the number of integers they
 * would like to enter, and create a new custom object passing in
 * the user input for the capacity. Display the new capacity and 
 * the size using the accessors. Continue testing the functions
 * as shown in the test cases. 
 *
 *
 *
 * Pseudocode:
 *
 * (1) Class called DynamicArray
 *      default constructor
 *      custom constructor
 *      function to print
 *      destructor
 *      function to empty array
 *      function to fill array
 *      accessors for size and capacity
 *      member variables for size, capacity, and a pointer 
 *
 * (2) Class called Backup (inherits from DynamicArray)
 *      default constructor
 *      custom constructor
 *      function to print
 *      member variables for backupsize, backup capacity, and
 *          a backup pointer
 *      destructor
 *      function to backup array
 *      function to restore array
 *
 * (4) Main
 *      create default Backup object
 *      print results
 *      get user input for capacity
 *      create custom Backup object
 *      print results
 *      fill array with user input
 *      print results
 *      backup array
 *      empty array
 *      print results
 *      restore array
 *      print results
 *
 *
 * \author Ryan Laur
 * \date   April 9, 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// DynamicArray class
class DynamicArray {
public:
    DynamicArray();
    DynamicArray(int capacity);
    ~DynamicArray();
    void fillArray();
    void emptyArray();
    int getSize() const;
    int getCapacity() const;
    void print() const;

protected:
    int* arr;
    int size, capacity;
};

// Derived class inherits from DynamicArray
class Backup : public DynamicArray {
public:
    Backup();
    Backup(int _capacity);
    ~Backup();
    void backup();
    void restore();
    void print() const;

private:
    int* backupArr;
    int backupcapacity, backupSize;
};

// main
int main()
{
    int capacity;

    // default object
    cout << "Creating default object..." << endl;
    Backup b1;

    cout << "Capacity: " << b1.getCapacity() << endl;
    cout << "Size: " << b1.getSize() << endl;
    
    cout << "How many numbers would you like to enter? ";
    cin >> capacity;

    // custom object
    cout << "\nCreating a new custom object..." << endl;
    Backup b2(capacity);

    cout << "Capacity: " << b2.getCapacity() << endl;
    cout << "Size: " << b2.getSize() << endl;

    // fill array
    cout << "\nFilling Array..." << endl;
    cout << "Enter " << capacity << " numbers separated by a space: ";
    b2.fillArray();

    cout << "Array stored: " << endl;
    b2.print();
    cout << "Capacity: " << b2.getCapacity() << endl;
    cout << "Size: " << b2.getSize() << endl;

    // backup array
    cout << "\nBacking up array....\n";
    b2.backup();

    // empty array
    b2.emptyArray();
    b1.print();
    cout << "After emptying array: " << endl;
    cout << "Capacity: " << b2.getCapacity() << endl;
    cout << "Size: " << b2.getSize() << endl;

    // restore array
    cout << "\nRestoring Array...\n";
    b2.restore();
    cout << "\nArray after restoring: " << endl;
    b2.print();
    cout << "Capacity: " << b2.getCapacity() << endl;
    cout << "Size: " << b2.getSize() << endl;

    return 0;
}

// default constructor for DynamicArray class
DynamicArray::DynamicArray()
    : capacity(1), size(0)
{
    arr = new int[capacity];
}

// custom constructor for DynamicArray Class
DynamicArray::DynamicArray(int _capacity)
    : capacity(_capacity), size(0)
{
    arr = new int[capacity];
}

// destructor
DynamicArray::~DynamicArray()
{
    delete[] arr;
    arr = nullptr;
}

// function to fill dynamic array
void DynamicArray::fillArray()
{
    for (int i = 0; i < capacity; i++)
    {
        cin >> arr[i];
        size++;
    }
}

// function to empty an array
void DynamicArray::emptyArray()
{
    delete[] arr;
    arr = nullptr;
    size = 0;  
    capacity = 1;
}

// accessor for the size of base class
int DynamicArray::getSize() const
{
    return size;
}

// accessor for capacity of base class
int DynamicArray::getCapacity() const
{
    return capacity;
}

// function to print a DynamicArray
void DynamicArray::print() const
{    
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Backup class default constructor
Backup::Backup()
    : backupcapacity(capacity), backupSize(size)
{
    backupArr = new int[backupcapacity];
}

// Backup class custom constructor
Backup::Backup(int _capacity)
    : DynamicArray(_capacity), backupSize(0)
{
    backupcapacity = capacity;
    backupArr = new int[backupcapacity];
    
}

// backup class destructor
Backup::~Backup()
{
    delete[] backupArr;
    backupArr = nullptr;
}

// function to backup the array of the base class 
void Backup::backup()
{
    backupSize = size;
    backupcapacity = capacity;

    for (int i = 0; i < size; i++)
    {
        backupArr[i] = arr[i];
    }
}

// function to restore the array back to base class
void Backup::restore()
{
    size = backupSize;
    capacity = backupcapacity;

    arr = new int[size];

    for (int i = 0; i < backupSize; i++)
    {
        arr[i] = backupArr[i];
    }
}


// function to print
void Backup::print() const
{
    DynamicArray::print();
}
