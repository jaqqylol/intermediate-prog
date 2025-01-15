/*
*   Name: Joanna Lopez      NetID: jjl369
*   Date: April 10, 2023    Due Date: April 14, 2023
*   
*   Description:    This program converts a binary number into a decimal. This is done
*                   with the help of a stack and uses its principles to do the calculations.
*                   There is also a loop in which the user is asked whether they want to continue
*                   converting other numbers and outputs accordingly.
*  
*/


#include <iostream>
#include <string>
#include <cmath>
#include "Stack.h"

// declare converting function
int convertBinary(string num);

int main()
{
    string num;
    string answer;

    cout << "Welcome to binary to decimal conversion." << endl << endl;

    // repeating loop
    while (1)
    {
        cout << "Enter in a binary number to convert: ";
        cin >> num;
        // call function to convert and display
        cout << "Your number converted is: " << convertBinary(num) << endl << endl;
        
        // ask user if they wish to keep converting
        cout << "Would you like to enter another binary number (yes/no)? ";
        cin >> answer;
        cout << endl;
        // loop according to answer
        if (answer == "no")
        {
            cout << "Good-bye!" << endl;
            return 0;
        }
        else if (answer == "yes")
        {
            cout << endl;
            continue;
        }
        else
        {
            cout << "That's not a valid response. Please try again." << endl;
            cout << "Would you like to enter another binary number (yes/no)? ";
            cin >> answer;
        }

    }

    return 0;
}

// defines function
int convertBinary(string num)
{
    // creates new stack object 
    Stack binaryNums;

    // for loop to iterate through string and add to stack
    // adding to stack converts it to a char
    for (int i = 0; i < num.length(); i++)
    {
        binaryNums.add(num[i]);
    }

    // for loop to iterate through stack using remove function
    // which returns the item removed (from the tail)
    // convert char item to int and store in int variable
    // use that to do calculations
    int sum = 0;
    char bin;
    for (int i = 0; i < num.length(); i++)
    {
        bin = binaryNums.remove();
        int deci = bin - '0';
        sum += deci * pow(2, i);
    }
   
    return sum;
}
