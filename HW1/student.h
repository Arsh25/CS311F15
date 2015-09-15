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
	Student():_name(""),_id(0) // Default C'tor
	{}
	Student(string name, unsigned int id):_name(name),_id(id) // 2 parameter C'tor
	{}
	
	Student(const Student &S):_name(S._name),_id(S._id) //Copy C'tor
	{}
	
	//Student & operator=(const Student &rhs); //Copy assignment
	
	//Compiler generated D'tor used 
	
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
