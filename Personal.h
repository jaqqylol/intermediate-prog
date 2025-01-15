#pragma once

#ifndef PERSONAL_H
#define PERSONAL_H
#include "Contact.h"

class Personal: public Contact
{
	private:
		string birthday;
		string address;
		string city;
		string state;
		string zip;
	
	public:
		Personal();
		Personal(string first, string last, string cell, string birthday, string address, string city, string state, string zip);

	//getters
		string getBirthday();
		string getAddress();
		string getCity();
		string getState();
		string getZip();

	//setters
		void setBirthday(string birthday);
		void setFullAddress(string address, string city, string state, string zip);

};
#endif 
