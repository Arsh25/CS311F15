/* Arsh Chauhan
 * 09/24/2015
 * ssarray.h
 * Header for Class SSArray
*/ 

#ifndef SSARRAY_H
#define SSARRAY_H

#include <cstdlib> //For size_t
using std::size_t;
#include <algorithm> //For std::copy
using std::copy;


/* class SSArray
 * Simple RAII class hodlding a dynamically allocated templated array
 * A const SSArray does not allow modification os its array items
 * There is no assocaited source file 
 * Invariant:
 * 	     _ptr points to memory allocated with new[], owned by *this
 * 	Requirement on types:
 *       T must have: ==, !=, <,<=,>,>=,[] operators
 *       T must have copy ctor, copy=, begin,end, size and dtor 
 *              
*/         
template <typename T>
class SSArray
{
public:
	using size_type = size_t;
	using value_type = T;
	
private:
	size_type _size;
	value_type *_ptr;
	
public:
	
	/*Default ctor
	 * Pre: None
	 * Post: Creates new array of 10 elemment of type "value_type", all elements are default constructed
	 */ 
	SSArray():_size(10),_ptr(new value_type[10])
	{}
	/*1 parameter ctor
	 * Pre: size must be of type size_type. 
	 * Post: Allocates new array with type "value_type" of size with new[]. All elements are deafult constructed
	 */ 
	explicit SSArray(size_type size):_size(size),_ptr(new value_type[size])
	{}
	
	/*2 parameter ctor
	 * Pre: size must be of type size_type. val must be of value_type 
	 * Post: Allocates new array with type "value_type" of size with new[]. All elements are set to val
	 */ 
	SSArray(size_type size,const value_type &val ):_size(size),_ptr(new value_type[size])
	{
		for (int i=0;i<_size;i++)
		{
			_ptr[i] = val;
		}
	}
	
	/*Copy ctor, performs deep copy
	 *Pre: begin and end must be defined
	 *Post: Deallocates rhs, creates new SSArray object equal to rhs  
	 */ 
	SSArray(const SSArray &rhs):_size(rhs.size()),_ptr(new value_type[rhs.size()]) //Copy ctor, performs deep copy
	{
		copy(rhs.begin(), rhs.end(), _ptr);
	}
	
	/*dtor for SSArray
	 * Pre: None
	 * Post: Memory pointed to by _ptr is deallcated
	 */ 
	~SSArray()
	{ 
		delete [] _ptr;
	}
	
	
	// Operators
	
	/* non const [] operator
	 * Pre: Calling object must be non const SSArray object
	 * Post: Returns address of passed index 
	 */ 
	value_type &operator[](const size_type &index)
	{
		return _ptr[index];
	}
	
	/* const [] operator
	 * Pre: Calling object must be a const SSArray object
	 * Post: Returns address of passed index 
	 */ 
	const value_type &operator[](const size_type& index) const
	{
		return _ptr[index];
	}
	
	/* Copy= for SSArray
	 * Pre: = operator, begin , end and size must be defined. rhs must be a valid SSArray object
	 * Post: Assigns rhs to *this
	 */ 
	SSArray &operator=(const SSArray &rhs)
	{
		if(this != &rhs)
		{
			delete[] _ptr;
			_ptr = new value_type[rhs.size()];
			_size = rhs.size();
			copy(rhs.begin(), rhs.end(), _ptr);
		}
		return *this;
	}
	
	
	
	//Member functions
	
	/*Member function size(). No parameters
	 * Pre: None
	 * Post: Returns a size_type representing the size of the SSArray 
	 */ 
	size_type size() const
	{
		return _size;
	}
	
	/*Member function begin(). No parameters
	 * Pre: Calling object must be a non const SSArray
	 * Post: Returns address of first element  
	 */ 
	value_type *begin()
	{
		return _ptr;
	}
	
	/*Member function end(). No parameters
	 * Pre: Calling object must be a non const SSArray
	 * Post: Returns address just past the end of SSArray  
	 */ 
	value_type *end()
	{
		return (begin()+_size); //Canonical
	}
	
	/*Member function begin(). No parameters
	 * Pre: Calling object must be a const SSArray
	 * Post: Returns address of first element  
	 */ 
	const value_type *begin()const
	{
		return _ptr;
	}
	
	/*Member function end(). No parameters
	 * Pre: Calling object must be a const SSArray
	 * Post: Returns address just past the end of SSArray  
	 */ 
	const value_type *end() const
	{
		return (begin()+_size); //Canonical
	}
};

/* operator == for SSArray. Takes two SSArray objects
 * Pre: Operator != must be defined for value_type
 * Post: Returns true if lhs==rhs 
 */  
template <class T>
bool operator == (const SSArray<T> &lhs, const SSArray<T> &rhs) 
{
	if(lhs.size()!=rhs.size())
		return false;
	else
	{
		for (int i=0; i<lhs.size(); i++)
		{
			if(lhs[i]!=rhs[i])
				return false;
		}
	}
	return true;
}

/* operator != for SSArray. Takes two SSArray objects
 * Pre: Operator == must be defined for T
 * Post: Returns true if lhs!=rhs 
 */  
template <class T>
bool operator != (const SSArray<T> &lhs, const SSArray<T> &rhs)
{
	return !(lhs==rhs); 
}

/* operator < for SSArray. Takes two SSArray objects
 * Pre: Operators ==,[],<,> and member function size must be defined for value_type
 * Post: Returns true if lhs<rhs 
 */
template <class T>
bool operator< (const SSArray<T> &lhs, const SSArray<T> & rhs)
{
	if(lhs==rhs)
	{
		return false;
	}
	
	for (int i=0; i<lhs.size(); ++i)
	{
		if(i==rhs.size())
		{
			return false;
		}
	
		if(lhs[i]<rhs[i])
		{
			return true;
		}
		else if(lhs[i]>rhs[i])	
		{
			return false;
		}
	}	
	if(lhs.size()<rhs.size())
	{
		return true;
	}
	return false;
}

/* operator > for SSArray. Takes two SSArray objects
 * Pre: Operator <= must be defined for value_type
 * Post: Returns true if lhs>rhs 
 */
template <class T>
bool operator> (const SSArray<T> &lhs, const SSArray<T> & rhs)
{
	return !(lhs<=rhs); 
}

/* operator <= for SSArray. Takes two SSArray objects
 * Pre: Operator < and == must be defined for value_type
 * Post: Returns true if lhs<=rhs 
 */
template <class T>
bool operator<= (const SSArray<T> &lhs, const SSArray<T> & rhs)
{
	return ((lhs<rhs) || (lhs==rhs)); //canonical  
}

/* operator <= for SSArray. Takes two SSArray objects
 * Pre: Operator > and == must be defined for value_type
 * Post: Returns true if lhs>=rhs 
 */
template <class T>
bool operator>= (const SSArray<T> &lhs, const SSArray<T> & rhs)
{
	return ((lhs>rhs) || (lhs==rhs)); //canonical
}
#endif
