/*****************************************************************//**
 * \file   RL_M4D.cpp
 * \brief  Area or Perimeter
 *
 * Write a programmer-defined function called volume_or_surfaceArea
 * that takes in a length, width, and height, of a 3D rectangular 
 * prism. If the prism is a cube, the function will return the volume, 
 * (all sides equal length). Otherwise, it will return the surface area.
 * 
 * In your main, read the inputs from the user, and call 
 * volume_or_surfaceArea AFTER input validation, and the display
 * the output to 3 decimal places as shown in the test cases. 
 * 
 * The surface area of a rectangular prism is:
 * 
 * S = 2(l*w + l*h + w*h) where:
 * l = length, h = height, w = width
 * 
 *
 * Pseudocode:
 * 
 * (1) FUNCTION prototype
 * (2) MAIN
 *		(1) INITIALIZE variables
 *		(2) READ length, width, and height
 *		(3) REPEAT (2) if invalid entry
 *      (4) SET precision
 *		(5) CALL volume_or_surfaceArea(length,width,height)
 *      (6) FUNCTION returns volume if cube, surface area otherwise
 *		(6) PRINT result
 *      (7) READ run again, y/n
 *
 * \author Ryan Laur
 * \date   February, 2 2021
 *********************************************************************/

#include <iostream>
using namespace std;

// FUNCTION prototype
double volume_or_surfaceArea(double length, double width, double height);

int main()
{
    // INITIALIZE variables
	double userLength(0.0), userWidth(0.0), userHeight(0.0), result(0.0);
    int finished = 0;
    char userChar = 'y';

    do
    {
        // READ length, width, and height
        cout << "Enter the length, width, and height: ";
	    cin >> userLength >> userWidth >> userHeight;

        // VALIDATE input
        while (cin.fail() || userLength <= 0.0 || userWidth <= 0.0 || userHeight <= 0.0)
        {
            cout << "Invalid entry, only enter positive numbers." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEnter the length, width, and height: ";
            cin >> userLength >> userWidth >> userHeight;
        }

        // SET precision
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);

        // CALL function volume_or_surfaceArea(length,width,height)
	    result = volume_or_surfaceArea(userLength, userWidth, userHeight);

        // PRINT result
	    cout << result << endl;

        // READ character to run again or quit y / n
        do
        {
            cout << "Run again? (y/n): ";
            cin >> userChar;

            // IF y, finished = false; IF 'n', finished = true;
            switch (userChar)
            {
            case 'Y':
                finished = 0;
                cout << endl;
                break;
            case 'y':
                finished = 0;
                cout << endl;
                break;
            case 'N':
                finished = 1;
                break;
            case 'n':
                finished = 1;
                break;
            }
        } while ((cin.fail() || userChar != 'Y' && userChar != 'y' && userChar != 'N' && userChar != 'n'));
    } while (finished == 0);

	return 0;
}

double volume_or_surfaceArea(double length, double width, double height)
{
	if (length == width && length == height)
	{
		cout << "The shape is a cube!" << endl;
        cout << "The volume is: ";
		return (length * width * height);
	}
	else
		return (2 * ((width * length) + (height * length) + (height * width)));
}
