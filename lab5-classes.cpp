/*
*   Name: Joanna Lopez      NetID: jjl369
*   Date: March 1, 2023     Due Date: March 3, 2023
*   
*   Description: This program creates an address book to manage the user's
*                contacts. The user chooses an option from the ones displayed
*                in which the user could exit the program, display the address
*                book, add a contact, or delete a contact.
*/

#include "person.h" // include class header ONLY
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// declare functions
void readContacts(vector <Person>& contacts, ifstream& infile);
void addContacts(vector <Person>& contacts, string& filename);
void displayContacts(vector<Person>& contacts);


int main()
{
    //declare variables
    ifstream infile;
    vector<Person> contactVec;
    string filename;

    cout << "Welcome to your address book manager!" << endl;
    cout << "Please enter a file to read your contacts from (include extension): ";
    cin >> filename;
    
    // file validation and opening
    infile.open(filename);
    while (!infile.is_open())
    {
        cout << endl << "That file doesn't exist. Please try again." << endl;
        cout << "Please enter a file to read your contacts from (include extension): ";
        cin >> filename;
        infile.open(filename);
    }
    readContacts(contactVec, infile);
    while (1)
    {
        int option;

        //display menu
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display Address Book" << endl;
        cout << "2. Add Contact" << endl;
        cout << "What would you like to do? ";
        cin >> option;
        cout << endl;
        switch (option)
        {
            case 0:
            {
                cout << "Good-bye!" << endl;
                return 0;
            }
            case 1 :
            {
                displayContacts(contactVec);
                break;
            }
            case 2 :
            {
                addContacts(contactVec, filename);
                break;
            }
           
            default:
            {
                cout << "That's not a valid option. Please try again." << endl;
                break;
            }
        }

    }
    

    return 0;
}

void readContacts(vector <Person>& contacts, ifstream& infile)
{
    string contactInfo;
    Person contact;
    while (!infile.eof())
    {
        // read file content into class object
        infile >> contactInfo;
        contact.setFirstName(contactInfo);
        infile >> contactInfo;
        contact.setLastName(contactInfo);
        infile >> contactInfo;
        contact.setPhone(contactInfo);
        infile >> contactInfo;
        contact.setEmail(contactInfo);

        if (!infile.fail())
        {
            //add object to vector
            contacts.push_back(contact); 
        }   
    }
    infile.close(); //close file
}

void addContacts(vector <Person>& contacts, string& filename)
{
    string newfirstName;
    string newlastName;
    string newPhone;
    string newEmail;
    Person newContact;
    ofstream outfile;

    cout << "Here's where we'll gather the information." << endl;
    cout << "What is the first name? ";
    cin >> newfirstName;
    cout << "What is the last name? ";
    cin >> newlastName;
    cout << "What's the phone number? ";
    cin >> newPhone;
    cout << "What's the email address? ";
    cin >> newEmail;
    cout << endl;

    // add to vector and append to file
    newContact.setFirstName(newfirstName);
    newContact.setLastName(newlastName);
    newContact.setPhone(newPhone);
    newContact.setEmail(newEmail);
    contacts.push_back(newContact);

    outfile.open(filename, ios::app);
    outfile << newfirstName << " " << newlastName << " " << newPhone << " " << newEmail << endl;
    outfile.close();
    cout << "Contact added." << endl << endl;

}

void displayContacts(vector<Person>& contacts)
{
    for (int i = 0; i < contacts.size(); i++)
    {
        //prints out contacts in order from vector
        cout << "Contact " << i+1 << ": " << endl;
        cout << "Name: " << contacts[i].getFirstName() << " " << contacts[i].getLastName() << endl;
        cout << "Phone number: " << contacts[i].getPhone() << endl;
        cout << "Email address: " << contacts[i].getEmail() << endl;
        cout << endl;

    }
}
