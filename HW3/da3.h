/*
 * Arsh Chauhan
 * 09/29/2015
 * Edited: 10/01/2015
 * da3.h
 * Header file for Assignment 3 Functions
 */ 

#ifndef FILE_DA3_H_INCLUDED
#define FILE_DA3_H_INCLUDED

#include <cstddef>
using std::size_t;
#include <stdexcept>
using std::out_of_range;
#include <algorithm>
using std::sort;
using std::unique;
#include <vector>
using std::vector;

// **************************************************************** // *
// Begin DO-NOT-CHANGE section                                      // *
// Do not alter the lines below                                     // *
// **************************************************************** // *
                                                                    // *
                                                                    // *
// struct LLNode                                                    // *
// Linked List node, with client-specified value type               // *
// Invariants:                                                      // *
//     Either _next is nullptr, or _next points to an LLNode,       // *
//      allocated with new, owned by *this.                         // *
// Requirements on Types:                                           // *
//     ValueType must have a copy ctor and a dctor.                 // *
template <typename ValueType>                                       // *
struct LLNode {                                                     // *
    ValueType _data;  // Data for this node                         // *
    LLNode * _next;   // Ptr to next node, or nullptr if none       // *
                                                                    // *
    // The following simplify creation & destruction                // *
                                                                    // *
    // 1- & 2-param ctor                                            // *
    // Pre:                                                         // *
    //     theNext, if passed, is either nullptr, or else it        // *
    //      points to an LLNode, allocated with new, with           // *
    //      ownership transferred to *this.                         // *
    // Post:                                                        // *
    //     _data == theData.                                        // *
    //     If _next passed, then _next == theNext. Otherwise,       // *
    //      _next is nullptr.                                       // *
    explicit LLNode(const ValueType & theData,                      // *
                    LLNode * theNext = nullptr)                     // *
        :_data(theData), _next(theNext)                             // *
    {}                                                              // *
                                                                    // *
    // dctor                                                        // *
    // Pre: None.                                                   // *
    // Post: None. (_next delete'd)                                 // *
    ~LLNode()                                                       // *
    { delete _next; }                                               // *
};                                                                  // *
                                                                    // *
                                                                    // *
// **************************************************************** // *
// End DO-NOT-CHANGE section                                        // *
// Do not alter the lines above                                     // *
// **************************************************************** // *


/*listItem: Function takes an LLNode and index.
 * Pre: index must be a valid std::size_t
 * Post: If index is valid, then returns the data in that node
 * Requirement on Types: None 
 */ 
template <typename ValueType>
ValueType listItem(const LLNode<ValueType> * head,
                   size_t index)
{
    size_t counter = 0;
    
    if(head == 0) //Check for empty list
		{
			throw out_of_range ("Passed index is out of range");
		}
    while(head != 0)
    {
		if(counter == index )
		{
			return (head->_data);
		}
		else
		{
			counter++;
			head = head->_next;
		}
	}
	if(counter >= index)
	{
		throw out_of_range ("Passed index is out of range");
	}
}

/*
 * didItThrow: Takes a function or function pointer and checks if it throws
 * Pre: f must be valid function / function ptr
 * 		threw must be a valid boolean
 * Post: Runs function f if no exception is thrown.
 *       Sets threw=true and rethrows, if any exception is thrown by f
 * Requirement on types: None
 */ 
template <typename Func>
void didItThrow(Func f,
                bool & threw)
{
	threw = false;
	
	try
	{
		f();
	}
    
    catch(...)
    {
		threw = true;
		throw;
	}
}

/*countUnique: Counts the number of unique elements in a range 
 * Pre: Parameters first and last specify a valid range
 * Post: Returns the number of unique elements in the passed range
 * Requirements on types:
 * 		RAITer must have operator-,operator=,operator==,operator<
 */ 
template <typename RAITer>
size_t countUnique(RAITer first,
                   RAITer last)
{
    sort(first,last);
    auto it = unique(first,last);
	return (it-first);
}


int gcd(int a,
        int b);


#endif  //#ifndef FILE_DA3_H_INCLUDED

