#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    Name: Joanna Lopez      NetID: jjl369
    Date: April 24, 2023    Due Date: May 1, 2023

    Description: This program will use a function that takes in a user inputed string and may recursively call itself to 
                 split or pick out the sub equations inside each parenthesis. Furthermore if the original equation has an
                 'a' then the function will ask user to input a number or if it is a 'b' then the program will ask the user
                 to input a variable other wise it will call itself until it has iterated through the entire string returning
                 the newly built equation.

*/



// function declaration
string buildEq(string eqTemplate, string tab);

int main()
{
    // vector of equation templates to test...
    vector<string> equations{
        "a + a",
        "((b - b)^2 + (b - b)^2)^1/2",
        "a + b",
        "ab + (b - b / a(a + a))",
        "(a ^ a) + (a - a + b)",
        "ab"
    };

    cout << "Welcome to the equation builder!" << endl << endl;

    // iterates through the vector
    // calls function on each vector item
    for (int i = 0; i < equations.size(); i++)
    {
        cout << "Starting equation: " << equations[i] << endl << endl;

        // builds equation
        string eq = buildEq(equations[i], "");

        cout << endl << "Equation built: " << eq << endl << endl;
    }

    return 0;
}

string buildEq(string eqTemplate, string tab)
{
    // creates string to store the built equation
    string newEq;
 
    // looping through the string 
   for (int i = 0; i < eqTemplate.size(); i++)
    {
        if (eqTemplate[i] == 'a')
        {
            string num;
            cout  << tab << "Enter in a number: ";
            cin >> num;
            newEq += num; 
        }
        else if (eqTemplate[i] == 'b')
        {
            string var;
            cout << tab << "Enter in a variable: ";
            cin >> var;
            newEq += var; 
        }

       else  if (eqTemplate[i] == '(')
        { 
            //creates temporary string to store sub equation
            // creates an int variable to count the number of parenthesis
            // creates a counter to continue iterating through string
            string sub;
            int parenthesis = 1;
            int count = i + 1;

            // while there are parenthesis
            while (parenthesis > 0) {

                // if the character after the current character is a paranthesis
                // add to the parenthesis counter
                if (eqTemplate[count] == '(')
                    parenthesis++;
                // else if the character is an end parenthesis decrease the number of parenthesis
                else if (eqTemplate[count] == ')')
                    parenthesis--;
                // if the number of parenthesis is not zero then add the character to the sub string
                if (parenthesis != 0)
                   sub += eqTemplate[count];
              
                // add one to counter each time
                count++;  
            }
            // displays the sub equation
            cout << tab << "Sub-equation: " << sub << endl;
            // this is the recursive case which uses the sub string to continue
            newEq += '(' + buildEq(sub, tab+"\t") + ')';
            i += sub.size() + 1;
        }
        else 
        {
            // adds to the final equation string
            newEq += eqTemplate[i];
        }
   }

    return newEq;
}