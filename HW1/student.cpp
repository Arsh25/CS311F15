/*
 * student.cpp
 * Arsh Chauhan
 * 09/15/2015
 * Source for class Student
 */

#include "student.h"

#include<iostream>
using std::cout;

/* getName
 * Pre: None
 * Post: 
 * 	 Returns a C++ string representing the Student's name
*/
string Student::getName() const
{
	return _name;
}

/* getID
 * Pre: None
 * Post: 
 * 	 Returns an int which represents the student's ID number
*/
int Student::getID() const
{
	return _id;
}

/* setName
 * Pre: name is a valid C++ sting
 * Post: _name == name
*/
void Student::setName(string name)
{
	_name=name;
}

/* setID
 * Pre: id is an unsigned int (Max. 8 digits)
 * Post: _id == id, if id is positive and at most 8 digits 
*/
void Student::setID(int id)
{
	if(validID()) // Check if id is >0 and at most 8 digits 
	_id=id;
	else
	cout << "Invalid ID: Must be positive and at most 8 digits";
}

/* toString
 * Pre: None
 * Post:
 * 	  Return is a string giving the student information as _name (_id), _id is padded
 *    on the left with zeros
*/
string Student::toString() const
{ 
	 
	
	string idStr; // String representation of _id
	
	if(idLen() < 8) //Append zeros if _id < 8 digits 
	 {
		 int diff = 8 - idLen();
		 for(int i = 0; i < diff; i++)
		 {
			 idStr += '0'; //Append leading zeros
		 }
		 
	 }
	 idStr += std::to_string(_id);
	 
	return _name + " (" + idStr + ")"; 
}


/* op== for Student
 * Pre: None
 * Post: 
 * 		Returns true if lhs and rhs represent the same student
 */
bool operator== (const Student &lhs, const Student &rhs)
{
	string name1, name2;
	int id1,id2;
	
	name1 = lhs.getName();
	id1 = lhs.getID();
	
	name2 = rhs.getName();
	id2 = rhs.getID();
	
	return ((name1 == name2) && (id1 == id2)); // Student objects are equal if both _id and _name are identical 
}


/* op!= for Student
 * Pre: None
 * Post: 
 * 		Returns true if lhs and rhs do not represent the same student
 */
bool operator!= (const Student &lhs, const Student &rhs)
{
	return !(lhs == rhs);
}


/* Stream insertion op for Student
 * Pre: None
 * Post: 
 * 		Srting form of Student object ( as returned by .toString()) has
 * 		been printed to the given stream
 * 		Returns the given stream
 */
ostream &operator<< (ostream &str, const Student &s)
{
	str << s.toString();
	return str;
}

