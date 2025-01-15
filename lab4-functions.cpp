/*
    Name: Joanna Lopez         NetID: jjl369
    Date: February 12, 2023    Due Date: February 17, 2023

    Description: The Class Schedule Manager program will allow the user to
                 view and alter a class schedule according to the given
                 options and their input. This is done using various
                 functions and vectors.

*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

// declaring functions before main
void viewSchedule(vector<string>& codes, vector<string>& names);
bool addClass(vector<string>& codes, vector<string>& names);
bool removeClass(vector<string>& codes, vector<string>& names);
bool editClass(vector<string>& names);

int main()
{
    // declared vector
    vector<string> courseCodes;
    vector<string> courseNames;

    cout << "Welcome to the class schedule manager!" << endl;

    // displays menu
    while (1)
    {
        string option;

        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. View Schedule" << endl;
        cout << "2. Add Class" << endl;
        cout << "3. Remove Class" << endl;
        cout << "4. Edit Class" << endl;
        cout << "Which menu option would you like? ";
        cin >> option;
        cout << endl;

        if (option == "0")
        {
            break;
        }
        else if (option == "1")
        {
            // use empty() to check if vector is empty
            // call viewschedule function
            if (courseCodes.empty() && courseNames.empty())
            {
                cout << "You have to add classes first!" << endl;
            }
            else
            {
                viewSchedule(courseCodes, courseNames);
            }

        }
        else if (option == "2")
        {
            // call addclass function
            // tell whether it passed or failed
            if (addClass(courseCodes, courseNames) == true)
            {
                cout << endl << "Course added!" << endl;
            }
            else
            {
                cout << endl << "Error adding course. Please try again." << endl;
            }

        }
        else if (option == "3")
        {
            // use empty() again to check if vector is empty
            // if not use loop to display vector contents
            // check for failure
            // call removeClass function
            if (!(courseCodes.empty() && courseNames.empty()))
            {
                viewSchedule(courseCodes, courseNames);
                if (removeClass(courseCodes, courseNames) == true)
                {
                    cout << endl << "Removed course." << endl;
                }
                else
                {
                    cout << "Error removing course. Please try again." << endl;
                }
            }
            else
            {
                cout << "You have to add classes first!" << endl;
            }

        }
        else if (option == "4")
        {
            if (!courseNames.empty())
            {
                viewSchedule(courseCodes, courseNames);
                if (editClass(courseNames) == true)
                {
                    cout << endl << "Edited course." << endl;
                }
                else
                {
                    cout << "Error editing course. Please try again." << endl;
                }
            }
            else
            {
                cout << "You have to add classes first!" << endl;
            }
        }
        else
        {
            cout << "You entered an invalid menu option. Please try again." << endl;
            
        }
        cout << endl;
     
    }
    cout << "Good-bye!";

    return 0;
}

void viewSchedule(vector<string> &codes, vector<string> &names)
{
    for (int i = 0; i < codes.size(); i++)
    {
        cout << i + 1 << ": " << codes[i] << " " << names[i] << endl;
    }
}

bool addClass(vector<string>& codes, vector<string>& names)
{
    bool flag = false;
    string code;
    string name;

    cout << "What course code would you like to add? (4 characters long) ";
    cin >> code;
    
    switch(code.size())
    {
        // adding to vector
        // codes are checked for being exactly 4 characters long
        // using switch statement to check equality in size of code

        case 4:
            codes.push_back(code);
            cout << "What is the course name? ";
            cin.ignore();
            getline(cin, name);
            names.push_back(name);
            flag = true;
        break;
    }
    return flag;
}

bool removeClass(vector<string>& codes, vector<string>& names)
{
    bool flag = false;
    int coursenum;
    // use boolean variable to be able to return it

    cout << endl << "Which course would you like to remove? (Enter item number) ";
    cin >> coursenum;
    if (coursenum <= codes.size())
    {
        codes.erase(codes.begin() + (coursenum-1));
        names.erase(names.begin() + (coursenum-1));
        flag = true;
    }
    return flag;
}

bool editClass(vector<string>& names)
{
    bool flag = false;
    int num;
    string newName;

    cout << endl << "Which item would you like to edit? ";
    cin >> num;
    if (num <= names.size())
    {   
        cout << "What would you like the new name to be: ";
        cin.ignore();
        getline(cin, newName);
        names[(num-1)] = newName;
        flag = true;
    }
    return flag;
}