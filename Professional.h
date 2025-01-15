#pragma once
#include "Contact.h"
#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

class Professional: public Contact
{
	private:
		string company;
		string position;
		string workNumber;
	public:
		Professional();
		Professional(string first, string last, string cell, string workNumber, string company, string position);

		//getters
		string getCompany();
		string getPosition();
		string getWorkNumber();

		//setters
		void setCompany(string company);
		void setPosition(string position);
		void setWorkNumber(string workNumber);
};
#endif

