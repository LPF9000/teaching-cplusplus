/*****************************************************************//**
 * \file   RL_M4B.cpp
 * \brief  Volume and Mass of a steel sphere
 * 
 * Write a user-defined function called getVolume() that takes in
 * the radius a sphere in cm, and returns the volume in cm^3.
 * 
 * Write a user-defined function called getMass() that takes in the
 * volume of a sphere in cm^3, and returns the mass in grams (g)
 * 
 * In the main function, prompt the user for the radius in cm, and
 * call the functions getVolume and getMass. Print the results
 * to two decimal places as shown in the test case.
 *
 * Pseudocode:
 * (1) FUNCTION prototypes
 * (2) INITIALIZE variables
 * (2) READ radius
 * (3) FUNCTION getVolume(), return volume
 * (4) FUNCTION getMass() , return mass
 * (5) PRINT volume and mass
 * 
 * mass = volume*density
 * density of steel = 8.05 g/cm^3
 * Volume = (4/3)*pi*r^3
 * r = radius
 * pi = 3.1459
 * 
 * Note: For exponents, you may use the function pow(base,exponent) 
 * defined in <cmath>.
 * 
 * \author Ryan Laur
 * \date   February, 2 2021
 *********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

// FUNCTION prototypes
double getVolume(double _radius);
double getMass(double _volume);

int main()
{
	double userRadius(0.0), volume(0.0);
	cout << "Calculate the radius of a steel sphere" << endl;
	cout << "\nEnter the radius of a steel sphere (cm): ";
	cin >> userRadius;

	while (cin.fail() || userRadius <= 0.0)
	{
		cout << "Invalid entry, only enter positive numbers." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter the radius of a steel sphere: ";
		cin >> userRadius;
	}

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	volume = getVolume(userRadius);
	cout << "\nThe volume of the steel sphere is: " << volume << " cm^3" << endl;
	cout << "The mass steel sphere is: " << getMass(volume) << " g" << endl;

	return 0;
}

double getVolume(double _radius)
{
	const double _pi = 3.1459;
	return ((4.0 / 3.0) * _pi * pow(_radius, 3));
}

double getMass(double _volume)
{
	const double density = 8.05;
	return _volume * density;
}
