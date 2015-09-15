#include "student.h"

#include<string> //for std::string
using std::string;
#include<sstream> //for std::ostringstream
using std::ostringstream;

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
	 int length=1;
	 int id=_id;
	 while(id /= 10)
		length++;
	
	string idStr;
	
	
	 if(length <8)
	 {
		 int diff=8-length;
		 for(int i=0; i<diff; i++)
		 {
			 idStr += '0';
		 }
		 
	 }
	 idStr += std::to_string(_id);
	 
	return _name + " (" + idStr + ")"; 
}

bool operator== (const Student &lhs, const Student &rhs)
{
	string name1, name2;
	int id1,id2;
	
	name1=lhs.getName();
	id1=lhs.getID();
	
	name2=rhs.getName();
	id2=rhs.getID();
	
	return ((name1==name2)&&(id1==id2));
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

