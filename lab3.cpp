/*
*	Name: Joanna Lopez		NetID: jjl369
*	Date: February 7, 2023	Due Date: February 10, 2023
*
*	Description: Program opens and reads file after user inputs a file which then a menu
*                is displayed to the user. User then chooses from menu options. These include
*                displaying the grades in the file, displaying the average of those grades, or
*                adding a new grade. In addition, before the program exits the letter grade is displayed
*                in accordance to their overall average grade.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using std::cout;
using std::cin;

int main()
{   // declaration of variables
    ifstream infile;
    string filename;
    vector<float> grades;
    int numberGrade;
    float averageGrade = {};
    float addedGrade;
    char letterGrade = {};

    cout << "Welcome to quiz grade averaging!" << endl << endl;

    // ***** file validation and file reading *****

    cout << "Enter the file name: ";
    cin >> filename;

    infile.open(filename);
    while (!infile.is_open())
    {
        cout << endl << "Error opening. Try again." << endl;
        cout << "Enter the file name: ";
        cin >> filename;

        infile.open(filename);
    }
    while (!infile.eof())
    {
        infile >> numberGrade;

        if (!infile.fail())
        {
            // use the push back function to add to vector
            grades.push_back(numberGrade);

        }
    }

    // menuing
    while (1)
    {
        string option;

        // displays menu
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display average" << endl;
        cout << "2. Display grades" << endl;
        cout << "3. Add new grade" << endl;
        cout << "Enter choice: ";
        cin >> option;

        cout << endl;

        // exit
        if (option == "0")
        {
            break;
        }

        // ***** add menu option handling *****
        else if (option == "1")
        {
            // compute average using for loop and display 
            averageGrade = 0;
            for (int i = 0; i < grades.size(); i++)
            {
                averageGrade += grades[i]; 
            }
            averageGrade /= grades.size();
            cout << "Your average quiz score is: " << averageGrade << endl;
        }
        
        else if (option == "2")
         {
            // display grades (cout)
            // using format [ Grade #: grade]
            for (int i = 0; i < grades.size(); i++)
            {
                cout << "Grade " << (i+1) << ": " << grades[i] << endl;
            }
         }

        else if (option == "3")
        {
            // use push back to insert new grade from input 
            // check if in range of 0.0-100.0 (loop)
            cout << "Enter a grade to add (0.0 - 100.0): ";
            cin >> addedGrade;

            while (!(addedGrade >= 0.0 && addedGrade <= 100.0))
            {
                cout << "Invalid grade. Please try again: ";
                cin >> addedGrade;
            }

            grades.push_back(addedGrade);
        }
        else
        {
            cout << "Invalid choice. Try again" << endl;
            cout << "Enter choice: ";
        }
        cout << endl;
    }

    // BONUS/Honors Requirement
    // ************************
    if (averageGrade >= 0.0 && averageGrade <= 59.9)
    {
        letterGrade = 'F';
    }
    else if (averageGrade >= 60.0 && averageGrade <= 69.9)
    {
        letterGrade = 'D';
    }
    else if (averageGrade >= 70.0 && averageGrade <= 79.9)
    {
        letterGrade = 'C';
    }
    else if (averageGrade >= 80.0 && averageGrade <= 89.9)
    {
        letterGrade = 'B';
    }
    else if (averageGrade >= 90.0 && averageGrade <= 100.0)
    {
        letterGrade = 'A';
    }
    
    cout << "With the average of " << averageGrade << " you'd have a grade of a " << letterGrade << "." << endl;
    cout << "Good-bye!" << endl;


    return 0;
}
