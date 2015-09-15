#include "student.h"

#include<string> //for std::string
using std::string;

string Student::getName() const
{
	return _name;
}

int Student::getID() const
{
	return _id;
}

void Student::setName(string name)
{
	_name=name;
}

void Student::setID(int id)
{
	_id=id;
}

string Student::toString() const
{
	//Dummy return 
	return "toString called"; 
}

bool operator== (const Student &lhs, const Student &rhs)
{
	//Dummy return
	return false;
}

bool operator!= (const Student &lhs, const Student &rhs)
{
	return !(lhs==rhs);
}

ostream &operator << (ostream &str, const Student &s)
{
	str << s.toString();
	return str;
}

