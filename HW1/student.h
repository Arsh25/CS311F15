/*
 * student.h
 * Arsh Chauhan
 * 09/14/2015
 * Edited: 09/16/2015
 * Header for class Student
 */

#ifndef STUDENT_H
#define STUDENT_H

#include<string> // for std::string
using std::string;
#include<ostream> //for std::ostream
using std::ostream;


/* class Student
 * Student is uniquely represented by _id (ID number)
 * Invariants:
 * 		_name is a valid C++ string
 * 		0 <= id <= 99,999,999
 */
 
class Student
{
	string _name;
	int _id;
	
	public:
	
	/* Default ctor
	 * Pre: None
	 * Post: 
	 * 		_name == " "
	 * 		_id == 0
	*/
	Student():_name(""),_id(0) // Default ctor
	{}
	
	/* 2-parameter ctor
	 * Pre: 0 <= id <= 99,999,999, name is a valid C++ string 
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
