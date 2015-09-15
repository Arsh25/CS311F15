/*
 * student.h
 * Arsh Chauhan
 * 09/14/2015
 * Edited: 09/15/2015
 * Header for class Student
 */

#ifndef STUDENT_H
#define STUDENT_H

#include<string> // for std::string
using std::string;
#include<ostream> //for std::ostream
using std::ostream;


/* class Student
 * Student is uniquely represented by an  _id (ID number)
 * Invariants:
 * 		_name is a valid C++ string
 * 		_id is an unsigned int (Max 8 digits)
 */
 
class Student
{
	string _name;
	int _id;
	
	
	/* Helper function validID
	 * Pre: Non
	 * Post:
	 * 	  Returns true is _id is >=0 and max 8 digits long
	*/
	bool validID() const
	{
		return !(_id < 0 || idLen() > 8);
	}
	
	/* Helper function idLen
	 * Pre: Non
	 * Post:
	 * 	  Returns number of digits in _id
	*/
	unsigned int idLen() const
	{
		int length = 1;
		int id=_id;
		while(id /= 10) // Keep moving the decimal point until division by 10 returns 0
			length++;
		return length;
	}
	
	public:
	
	/* Default ctor
	 * Pre: None
	 * Post: 
	 * 		_name ==" "
	 * 		_id == 0
	*/
	Student():_name(""),_id(0) // Default ctor
	{}
	
	/* 2-parameter ctor
	 * Pre: None
	 * Post:
	 * 		_name == name
	 * 		_id == id
	*/
	Student(string name, unsigned int id):_name(name),_id(id) // 2 parameter ctor
	{}
	
	//Compiler generated  copy ctor, copy=, dctor used 
	
	//Get member functions 
	string getName() const; 
	int getID() const;
	
	//Set member functions 
	void setName(string);
	void setID(int);
	
	string toString() const; // Returns a string representation of the student information
	

};

bool operator== (const Student &lhs, const Student &rhs);
bool operator!= (const Student &lhs, const Student &rhs);

ostream &operator << (ostream &str, const Student &s);

#endif
