/*****************************************************************//**
 * \file   RL_M12A.cpp
 * \brief  Class called CourseGrade that inherits from a 
 * class called Percentage that inherits from a class called
 * Assignmments. 
 * 
 * Define a class called Assignments with two protected member variables,
 * one for the number of Assignents, as well as a pointer to a variable
 * of type double for the dynamic array of assignment scores. Write
 * a member function to get the scores from the user, by allocating
 * the dynamic array with size based on the number of assignments
 * from the user, as well
 * as a print function to print the list of scores as shown in the
 * test cases.
 * 
 * Define a classe called Percentage that inherits (public) from the
 * class Assignments with an extra protected variable for
 * the percentage. Write a member function to calculate the 
 * percentage (average), as well as a print function to print
 * the percentage as shown in the test cases.
 * 
 * Define a class called Grade that inherits (public) from the class
 * Percentage with an extra private variable for the grade (string).
 * Write a member function to calculate the grade based on the 
 * percentage, as well as a print function to print the final
 * Grade as shown in the test cases.
 * 
 * In main, create a default grade object, and call your functions
 * to get the number of assignments and scores from the user, 
 * calculate the percentage, calculate the final grade, and print
 * the results. 
 * 
 * Note: You may use the values below to calculate the letter grade
 * 
 * A = 90.0-100
 * A- = 87.0-89.9
 * B+ = 84-86.9
 * B = 80-83.9
 * B- = 77-79.9
 * C+ = 74-76.9
 * C = 70-73.9
 * C- = 67-69.9
 * D+ = 64-66.9
 * D = 60-73.9
 * D- = 57.0-59.9
 * E = 0-59.9
 * 
 * Hint: To round the percentage to 1 decimal place to calculate the
 * grade, you may include the library header <cmath> and use: 
 * 
 * percentage = round(percentage * 10.0) / 10.0;
 * 
 * 
 * Pseudocode:
 * 
 * (1) Class called Assignments
 *      function to get scores from user
 *      function to print results
 *      member variables for scores and number of assignments
 * 
 * (2) Class called Percentage (inherits from assignments)
 *      function to calculate percentage
 *      function to print results (calls print from Assignments)
 *      member variable for percentage
 * 
 * (3) Class called Grade
 *      function to calculate grade
 *      function to print results (calls print from Percentage)
 *      member variable for Grade
 * 
 * (4) Main
 *      create Grade object
 *      get user input for number of assignments and scores
 *      calculate percentage
 *      calculate grade
 *      print results
 * 
 * \author Ryan Laur
 * \date   April 9, 2021
 *********************************************************************/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Assignments class
class Assignments {
public:
    void getScores();
    void print() const;

protected:
    double* scores;
    int numScores;

};

// Derived class inherits from Assignments
class Percentage : public Assignments {
public:
    void calcPercentage();
    void print() const;

protected:
    double percentage;
   
};

// Derived class inherits from Percentage
class CourseGrade : public Percentage {

public:
    void calcGrade();
    void print() const;

private:
    string grade;

};

// main
int main()
{
    // create object
    CourseGrade g;

    // get scores from user
    g.getScores();

    // calculate the percentage
    g.calcPercentage();

    // calculate the letter grade
    g.calcGrade();

    // print results
    g.print();

    return 0;
}

// this function gets scores from the user 
void Assignments::getScores()
{
    // get number of assignments from user
    cout << "How many scores would you like to enter? ";
    cin >> numScores;

    // allocate dynamic array
    scores = new double[numScores];

    // get scores from user
    cout << "Enter " << numScores << " scores separated by a space: ";
    for (int i = 0; i < numScores; i++)
    {
        cin >> scores[i];
        scores[i] = round(scores[i] * 10.0) / 10.0;
    }
    
}

// function to print the assignment scores
void Assignments::print() const
{
    cout << "\nAssignments Scores: " << endl;
    for (int i = 0; i < numScores; i++)
    {
        cout << "Assignment " << i + 1 << ": " << scores[i] << endl;
    }
    cout << endl;
}

// function to calculate the total score percentage
void Percentage::calcPercentage()
{
    for (int i = 0; i < numScores; i++)
    {
        percentage += scores[i];
    }
    percentage /= numScores;
    percentage = round(percentage * 10.0) / 10.0;
}

// function to print total percentage and the scores
void Percentage::print() const
{
    Assignments::print();

    cout << "Total Percentage: " << percentage << "% \n";
}

// function to calculate the letter grade 
void CourseGrade::calcGrade()
{
    if (percentage >= 90.0)
        grade = "A";
    else if(percentage >= 87.0 && percentage <= 89.9)
        grade = "A-";
    else if (percentage >= 84.0 && percentage <= 86.9)
        grade = "B+";
    else if (percentage >= 80.0 && percentage <= 83.9)
        grade = "B";
    else if (percentage >= 77.0 && percentage <= 79.9)
        grade = "B-";
    else if (percentage >= 74.0 && percentage <= 76.9)
        grade = "C+";
    else if (percentage >= 70.0 && percentage <= 73.9)
        grade = "C";
    else if (percentage >= 67.0 && percentage <= 69.9)
        grade = "C-";
    else if (percentage >= 64.0 && percentage <= 66.9)
        grade = "D+";
    else if (percentage >= 60.0 && percentage <= 63.9)
        grade = "D";
    else if (percentage >= 57.0 && percentage <= 59.9)
        grade = "D-";
    else
        grade = "E";
}

// function to print all results
void CourseGrade::print() const
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    Percentage::print();
    cout << "Final Grade: " << grade << endl;
}
