/*****************************************************************//**
 * \file   RL_M9B.cpp
 * \brief  Class called Point
 *
 * This program will display coordinates using overloaded << and >>
 * operators.
 *
 * Write a class called Point that contains 3 private member 
 * variables, integers, for x and y coordinates, and a variable 
 * called num to store the current object number. 
 * 
 * Write a static member variable called count that increments
 * when an object is created. (Refer to M8C)
 *
 * Write a default constructor that initialized the member variables
 * to 0, and incrementing count. Set num equal to count to 
 * set the current object number.
 *
 * Write a custom constructor that initializes the members
 * variables with their corresponding parameters. Define the 
 * custom constructor with an initialization section. Increment
 * count to set the total object number, and set num equal 
 * to count to get the current object number. 
 * 
 * Overload the << operator as a friend member function, which
 * returns the outputStream.
 * 
 * Hint: 
 * The function prototype is as follows:
 * friend ostream& operator <<(ostream& outputStream, const Point& point);
 * 
 * Overload the >> operator as a friend member function, which
 * returns the inputStream.
 * 
 * Hint: 
 * The function prototype is as follows:
 * friend istream& operator >>(istream& inputStream, Point& point);
 *
 * In main(), declare 2 default Point objects. Use cin >> object
 * to use the overloaded operator to read the data. Then, use
 * cout << object to use the overloaded operator to display the data. 
 * Use the coordinate formatting within the definition of your 
 * overloaded display operator as shown in the test case. 
 * All of the inputs and outputs should be displayed/obtained
 * by using the overloaded operators. 
 *
 * Psuedocode:
 *
 * (1) Point Class
 *      (a) member variables x, y, and num
 *		(b) default constructor, set variables to 0, increment count/num
 *		(c) custom constructor
 *		(d) overload << and >> operators
 *		(e) static variable count
 * (2) Main
 *		(a) Declare 2 coordinate objects
 *      (b) Use overloaded cin >> to get x,y of objects
 *		(c) Use overloaded out << to display x,y of objects
 *
 * \author Ryan Laur
 * \date   March 12, 2021
 *********************************************************************/
#include <iostream> 
using namespace std;

// Point class
class Point {
public:
	// default constructor
	Point();

	// custom constructor
	Point(int x, int y);

	// overloaded friend << operator
	friend ostream& operator <<(ostream& outputStream, const Point& point);

	// overloaded friend >> operator
	friend istream& operator >>(istream& inputStream, Point& point);

	// static variable to get the object count 
	static int count;

private:
	int x, y, num;
	
};

// initialize static variable
int Point::count = 0;

// main
int main()
{
	// create point objects
	Point p1, p2;

	// using overloaded inputstream operator >>
    cin >> p1;
	cin >> p2;

	// using overloaded output stream operator <<
	cout << "\nDisplaying Coordinates: " << endl;
	cout << p1 << p2 << endl;

	return 0;
}

// default constructor
Point::Point()
	: x(0), y(0)
{
	// increments count and saves current object number
	num = ++count;
}

// custom constructor to set dollars/sents and calculate total
Point::Point(int newX, int newY)
	: x(newX), y(newY)
{
	// increments count and saves current object number
	num = ++count;
}

// overloaded << operator
ostream& operator<<(ostream& outputStream, const Point& point)
{
	outputStream << "Point " << point.num << ": [ " << point.x << "," << point.y << " ]\n";

	return outputStream;
}

// overloaded >> operator
istream& operator >>(istream& inputStream, Point& point)
{
	cout << "Enter coordinates for point " << point.num << ": ";
	inputStream >> point.x >> point.y;
	return inputStream;
}
