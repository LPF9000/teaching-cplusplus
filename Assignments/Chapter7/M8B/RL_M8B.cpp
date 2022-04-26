/*****************************************************************//**
 * \file   RL_M8B.cpp
 * \brief  Class called Grade
 *
 * Write a class called Grade that contains three private member
 * variables for an array of scores, the average score, and the total 
 * number of scores. You can initialize the array with a size of 3. 
 * 
 * Write a default constructor that initializes all of the member
 * variables to 0. Define the default constructor with an initialization 
 * section.
 *
 * Write a custom constructor that takes in the number of scores,
 * and an entire array of scores, and initializes each member
 * variable with its corresponding parameter. The third member variable,
 * the averageScore, will be calculated in the custom constructor. Define
 * the custom constructor with an initialization section for the number
 * of scores. Initializing the array and calculating the average
 * will take place in the body of the custom constructor. 
 * 
 * Write accessors for each of the member variables, making them
 * constant functions. The accessor for the array of scores will take
 * in an index, and return the value at that index. Make
 * the accessors constant functions. 
 * 
 * Write a **NON-MEMBER** function called print(), that takes in a
 * **Grade object**, and prints the list of 
 * scores stored in the array, the number of scores, and the average
 * score. 
 *
 * In main(), declare a Grade object that is initialized
 * by the default constructor, and call print() on the object. Declare 
 * an array of scores, hardcoded as shown in the test case. Then,
 * reinitialize the member variables of the Grade object by assigning 
 * an anonymous object with the custom constructor to the Grade object, 
 * using the value of the number of scores, and the array of scores
 * as arguments. 
 * Call print() to display the new values as shown in the 
 * test cases. 
 *
 * Psuedocode:
 *
 * (1) Class Grade
 *		(a) scoreArray, number of scores, average - member variables
 *		(b) default constructor
 *		(c) custom constructor
 *      (d) print function with const object call-by-reference parameter
 * (2) Main
 *		(a) Declare Grade object with default constructor
 *		(b) print member variables
 *      (c) Declare array of scores
 *		(d) Re-initialize object with anonymous object from custom constructor
 *		(e) print member variables
 *
 *
 * \author Ryan Laur
 * \date   March 5, 2021
 *********************************************************************/
#include <iostream>
using namespace std;

// Grade class
class Grade
{
public:
    // default constructor
    Grade();

    // custom constructor
    Grade(const int& numScores, const double newScores[]);

    // accessors
    double getAverage() const;
    int getNumScores() const;
    double getScores(const int& index) const;
    
private:
    double scores[3];
    int numScores;
    double average;
};

// non-member print function prototype
void print(const Grade& g1);

// main
int main()
{
    // set precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    // Grade object delcared with default constructor
    Grade g1;

    // call to non-member print function with object argument
    print(g1);

    // initialize array of scores
    double scores[3] = { 95.5, 94.2, 93.1 };

    // assigning anonymous object from custom constructor 
    cout << "\nAfter assigning anonymous object: " << endl;
    g1 = Grade(3, scores);
    print(g1);
    
    return 0;
}

// default constructor initializing to 0
Grade::Grade()
    : scores(), average(0.0), numScores(0)
{
}

// custom constructor that calculates an average
Grade::Grade(const int& numScores, const double newScores[])
    : numScores(numScores)
{
    average = 0;
    for (int i = 0; i < numScores; i++)
    {
        scores[i] = newScores[i];
        average += scores[i];
    }

    average /= static_cast<double>(numScores);
}

// accessor for the number of scores 
int Grade::getNumScores() const
{
    return numScores;
}

// accessor for the score array
double Grade::getScores(const int& index) const
{
    return scores[index];   
}

// accessor for the average
double Grade::getAverage() const
{
    return average;
}

// non-member print function
void print(const Grade& g1)
{
    // use accessors to retrieve member variables
    int num = g1.getNumScores();
    double avg = g1.getAverage();
    
    for (int i = 0; i < num; i++)
    {
        cout << "Score " << i + 1 << ": " << g1.getScores(i) << endl;
    }

    cout << "Number of Scores: " << num << endl;
    cout << "Average Score: " << g1.getAverage() << endl;

}



