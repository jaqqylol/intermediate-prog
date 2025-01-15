#include "Personal.h"

Personal::Personal()
{
	birthday = "";
	address = "";
	city = "";
	state = "";
	zip = "";
}

Personal::Personal(string first, string last, string cell, string birthday, string address, string city, string state, string zip)
{
	this->first = first;
	this->last = last;
	this->cell = cell;
	this->birthday = birthday;
	this->address = address;
	this->city = city;
	this->state = state;
	this->zip = zip;
}

//getters
string Personal::getBirthday()
{
	return birthday;
}
string Personal::getAddress()
{
	return address;
}
string Personal::getCity()
{
	return city;
}
string Personal::getState()
{
	return state;
}
string Personal::getZip()
{
	return zip;
}

//setters
void Personal::setBirthday(string birthday)
{
	this->birthday = birthday;
}
void Personal::setFullAddress(string address, string city, string state, string zip)
{
	this->address = address;
	this->city = city;
	this->state = state;
	this->zip = zip;
}