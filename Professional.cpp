#include "Professional.h"

Professional::Professional()
{
	company = "";
	position = "";
	workNumber = "";
}
Professional::Professional(string first, string last, string cell, string workNumber, string company, string position)
{
	this->first = first;
	this->last = last;
	this->cell = cell;
	this->workNumber = workNumber;
	this->company = company;
	this->position = position;
}

//getters
string Professional::getCompany()
{
	return company;
}
string Professional::getPosition()
{
	return position;
}
string Professional::getWorkNumber()
{
	return workNumber;
}

//setters
void Professional::setCompany(string company)
{
	this->company = company;
}
void Professional::setPosition(string position)
{
	this->position = position;
}
void Professional::setWorkNumber(string workNumber)
{
	this->workNumber = workNumber;
}