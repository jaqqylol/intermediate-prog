#pragma once
#include <string>
using namespace std;

#ifndef Contact_H
#define Contact_H

class Contact
{
	protected:
		string first;
		string last;
		string cell;
	public:
		Contact();

		//getters
		string getFirst();
		string getLast();
		string getCell();

		//setters
		void setFirst(string first);
		void setLast(string last);
		void setCell(string cell);
};

#endif 

