/*
*	Name: Joanna Lopez		NetID: jjl369
*	Date: March 9, 2023		Due Date: March 13, 2023
* 
*	Description: This program outputs the contents in a certain format of professional
*				 or personal contacts using the contents of a given file and uses derived 
*				 classes and vectors to accomplish this.
*/

#include <iostream>
// include class headers
#include "Professional.h"
#include "Personal.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	// declares typeclass vector
	vector<Professional> profVec;
	vector<Personal> personalVec;

	// declares to use file
	ifstream infile;
	string filename;

	//variables to put data from file in
	string line;
	string fname;
	string lname;
	string phonecell;
	string workphone;
	string comp;
	string pos;
	string birth;
	string addy;
	string cit;
	string z;
	string sta;


	// inputs filename
	cout << "Enter the file name (include extension): ";
	cin >> filename;

	//opens file
	infile.open(filename);

	//check if file is opened/exists
	if (!infile.is_open())
	{
		cout << "Invalid file. Please try again." << endl;
		cout << endl << "Enter the file name (include extension): ";
		cin >> filename;
		infile.open(filename);
	
	}
	// loops through and reads file accordingly
	while (getline(infile, line))
	{
		if (line == "professional")
		{
			getline(infile, fname);
			getline(infile, lname);
			getline(infile, phonecell);
			getline(infile, workphone);
			getline(infile, comp);
			getline(infile, pos);

			//class object created
			Professional profContact(fname, lname, phonecell, workphone, comp, pos);

			profVec.push_back(profContact);
		}

		else
		{
			getline(infile, fname);
			getline(infile, lname);
			getline(infile, phonecell);
			getline(infile, birth);
			getline(infile, addy);
			getline(infile, cit);
			getline(infile, sta);
			getline(infile, z);

			//class object created
			Personal personalContact(fname, lname, phonecell, birth, addy, cit, sta, z);

			personalVec.push_back(personalContact);
		}
		
	}
	// closes file after reading file
	infile.close();

	cout << endl;

	// set up for printing personal contact vector
	cout << "Personal Contacts: " << endl << endl;
	for (int i = 0; i < personalVec.size(); i++)
	{
		cout << "Contact " << i + 1 << ": ";
		cout << personalVec[i].getFirst() << " " << personalVec[i].getLast() << endl;
		cout << "Cell: " << personalVec[i].getCell() << endl;
		cout << "Address: " << endl;
		cout << personalVec[i].getAddress() << endl;
		cout << personalVec[i].getCity() << ", " << personalVec[i].getState() << " " << personalVec[i].getZip() << endl;
		cout << "Birthday: " << personalVec[i].getBirthday() << endl << endl;
	}
			
	//set up for printing professional contact vector

	cout << "Business Contacts: " << endl << endl;
	for(int i = 0; i < profVec.size(); i++)
	{
		cout << "Contact " << i + 1 << ": ";
		cout << profVec[i].getFirst() << " " << profVec[i].getLast() << endl;
		cout << "Work: " << profVec[i].getWorkNumber() << endl;
		cout << "Cell: " << profVec[i].getCell() << endl;
		cout << profVec[i].getPosition() << " at " << profVec[i].getCompany() << endl << endl;
	}

	return 0;
}



