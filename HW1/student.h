/*
 * student.h
 * Arsh Chauhan
 * 09/14/2015
 * Header for class Student
 */

#ifndef STUDENT_H
#define STUDENT_H

#include<string> // for std::string
using std::string;
#include<ostream> //for std::ostream
using std::ostream;

class Student
{
	string _name;
	int _id;
	
	public:
	Student():_name(""),_id(0) // Default ctor
	{}
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
