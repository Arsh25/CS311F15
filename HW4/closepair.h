/*
 * Arsh Chauhan
 * 10/13/2015
 * Edited: 10/15/2015
 * closepair.h
 * Header file for Assignment 4 
 */ 
 
#ifndef CLOSEPAIR_H
#define CLOSEPAIR_H

#include <algorithm>
using std::sort;
#include <utility>
using std::pair;
using std::make_pair;
#include <cstddef>
using std::size_t;
#include <vector>
using std::vector;
#include <cmath> //for pow

//Debug includes
#include <iostream>
using std::cout;

using Pt2D = pair<double, double>;

/*
 * closepairRecurse: Recursive implementation of divide and conquer algorithm for closest pair problem
 * Pre: Parameters first and last specifiy a valid range. Range must be a vector<pair<double,double>>
 * Post: Returns a pair (pair<double,double>) representing the indices of the 2 closest points
 * 		Requirements on types:
 * 			first and last must be random access iterators 
 */ 
template<typename RAIter>
pair <size_t,size_t> closepairRecurse (RAIter first, RAIter last)
{
	size_t size=last-first;
	vector<Pt2D> points;
	double smallestDistance;
	Pt2D closestPair1;
	Pt2D closestPair2;
	
	for (size_t i = 0; i < size; ++i)
	{
		points.push_back(*(first+i));
	}
	
	if(size<=3) //BASE CASE
	/*NOTE: Find distance b/w all points and then return closest pair. This will be a max of 3 distances (n==3)*/
	{
		if(size ==2) // 2 points == 1 distance
		return make_pair(1,0);
		else 
		{
			double dist1 = pow((points[1].first-points[0].first),2) + pow((points[1].second-points[0].second),2);
			double dist2 = pow((points[2].first-points[1].first),2) + pow((points[2].second-points[1].second),2);
			double dist3 = pow((points[2].first-points[0].first),2) + pow((points[2].second-points[0].second),2);
			if(dist1 <= dist3 && dist1 <= dist2) //dist1 is smallest
			return make_pair(1,0);
			else if(dist2 <= dist3 && dist2 <= dist1) //dist2 is smallest
			return make_pair(2,1);
			else if(dist3 <= dist2 && dist3 <= dist1) //dist3 is smallest
			return make_pair(2,0);
			
		}
	}
	
	else //RECURSIVE CASE
	{	
		size_t middle;
		if(size%2 == 0)
		middle=size/2;
		else
		middle=(size/2)+1;
		
		double pivot = (points[middle+1].second+points[middle].second)/2; // y-coordinate of midpoint 
		RAIter pivotIter = first+middle;
		
		vector<Pt2D> LHL,RHL;
		vector<size_t> indicesLHL,indicesRHL;
		for(size_t i=0; i<size; ++i)
		{
			if(points[i].second<pivot)
			{
				LHL.push_back(*(first+i));
				indicesLHL.push_back(i);
			}
			else
			{
				RHL.push_back(*(first+i));
				indicesRHL.push_back(i);
			}
		}
		
		double index1,index2; //Indices returned by recursive calls 
		double dist1,dist2; 
		closestPair1 = closepairRecurse(LHL.begin(),LHL.end());
		index1=closestPair1.first;
		index2=closestPair1.second;
		dist1 = pow((points[index1].first-points[index2].first),2) + pow((points[index1].second-points[index2].second),2);
		closestPair2 = closepairRecurse(RHL.begin(),RHL.end());
		index1=middle+(closestPair2.first);
		index2=middle+(closestPair2.second);
		dist2 = pow((points[index1].first-points[index2].first),2) + pow((points[index1].second-points[index2].second),2);
		if(dist2 < dist1)
			{
				closestPair1 = closestPair2;
			} 
		else
			{
				index1=closestPair1.first;
				index2=closestPair1.second;
			}
		double closestDist = pow((points[index1].first-points[index2].first),2) + pow((points[index1].second-points[index2].second),2); //current min distance
		double split1 = pivot + closestDist; //Upper bound of strip
		double split2 = pivot - closestDist; //Lower bound of strip
		
		vector<Pt2D>L; //{All (x,y):split2<y<split1}
		vector<size_t>indicesL;
		
		for (size_t i = 0; i < (last-first); ++i)
		{
			if(points[i].second<split1 && points[i].second>split2)
			{
				//indicesL.push_back(i);
				L.push_back(*(first+i));
			}
		}
		sort(L.begin(),L.end(),
			[](const Pt2D & a, const Pt2D & b)  // Unnamed function
			{ return a.first < b.first; }
			);
		/*sort(indicesL.begin(),indicesL.end(),
			[=](const size_t & a, const size_t & b)  // Unnamed function
			{ return L[a].first < L[b].first; }
			);*/
			 
		
		
	//Iterate through list L and find distance between each point and the next 5
		for(size_t i=0; i!=(L.end()-L.begin());++i)
		{
			for(int j=1; j<=5;j++)
			{
				double dist = pow((L[i+j].first-L[i].first),2) + pow((L[i+j].second-L[i].second),2);
				if(dist<closestDist)
				closestPair1=make_pair(i+j,i);
			}
		}
		
		return closestPair1;
	}
}

/*
 * closePair: Wrapper around closepairRecurse
 * Pre: first and last must specify a valid range
 * 		last-first>=2
 * 		Range must be a vector of type pair<double,double> representing points in xy-plane
 * 		All points must have a unique y value
 * Post: Returns indices of closest pairs in the list. 
 * 		List may be reordered, indices returned are for the reordered list
 * 	 Requirements on types:
 * 		first and last must be random access iterators 
 */ 
template<typename RAIter>
pair <size_t, size_t> closePair(RAIter first, RAIter last)
{
	sort(first, last,
		[](const Pt2D & a, const Pt2D & b)  // Unnamed function
		{ return a.second < b.second; }
		);
	auto closest=closepairRecurse(first,last);
	cout<<"GOT:("<<closest.first<<","<<closest.second<<") ";
	return (make_pair(closest.first,closest.second));
	
}

#endif
