/*
 * Arsh Chauhan
 * 09/29/2015
 * Edited: 10/01/2015 
 * da3.cpp
 * Source file for Assignment 3 Functions
 */ 

#include "da3.h"  // For Assignment 3 prototypes & templates

/*gcd: Calcuates the gcd of 2 integers 
 *Pre: a,b >= 0, a and b are not both 0
 *Post: Returns the gcd of 2 integers
 *Does not throw
 */ 
int gcd(int a,
        int b)
{
    if( a == 0 ) //BASE CASE 
   {
	   return b;
   }
   if(a > b)
   {
	   return gcd(b,a);
   }
   return gcd((b%a),a);
}

