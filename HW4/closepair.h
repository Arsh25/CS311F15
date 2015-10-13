/*
 * Arsh Chauhan
 * 10/13/2015
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

template<typename RAIter>
pair <size_t,size_t> closepairRecurse (RAIter first, RAIter last)
{
	size_t size=last-first;
	vector<Pt2D> points;
	double smallestDistance;
	Pt2D closestPair1;
	Pt2D closestPair2;
	size_t returnIndex;
	
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
		
		 
		/*Replace this with if statemensts for n==2 and n==3
		 * for (size_t i = 1; i <= size; ++i)
		{
			double distance = pow((points[i].first-points[i-1].first),2) + pow((points[i].second-points[i-1].second),2);
			
			if(i==1)
				{
					smallestDistance = distance;
					returnIndex = i;
				}
			else if(distance<smallestDistance)
				{
					smallestDistance = distance;
					returnIndex = i;
				}
		}*/
	}
	else //RECURSIVE CASE
	{
		size_t middle;
		if(size%2 == 0)
		middle=size/2;
		else
		middle=((int)(size/2)+1);
		
		double pivot = points[middle].second;
		RAIter pivotIter = first+middle;
		closestPair1 = closepairRecurse(first,pivotIter);
		closestPair2 = closepairRecurse(pivotIter,last);
		if(closestPair2 <= closestPair1)
			closestPair1 = closestPair2;
		double closestdist = pow((closestPair2.first-closestPair1.first),2) + pow((closestPair2.second-closestPair1.second),2);
		double split1 = pivot + closestdist;
		double split2 = pivot - closestdist;
		
		vector<Pt2D>L;
		vector<Pt2D> indicesL; //Indices of list L
		
		for(size_t i = 0; i < size; ++i)
		{
			if(points[i].second>split1 && points[i].second<split2)
			L.push_back(points[i]);
		}
		sort(L.begin(),L.end(),
			[](const Pt2D & a, const Pt2D & b)  // Unnamed function
			{ return a.first < b.first; }
			);
		
		for (size_t i = 0; i < L.size(); ++i)
		{
			indicesL.push_back(*(L.begin()+i));
		}
	
	//Iterate through list L and find distance between each point and the next 5
		/*for(auto i=L.begin(); i!=L.end()-5;++i)
		{
			Pt2D pt1 = *i;
			cout<<"######"<<pt1.first;
			for(int j=1; j<=5;j++)
			{
				//double x1 = pt1[1].first;
				//double dist = pow(,2) + pow(,2);
			}
		}
	}*/
	return make_pair(3,2); //Dummy return
	}
}

template<typename RAIter>
pair <size_t, size_t> closePair(RAIter first, RAIter last)
{
	sort(first, last,
		[](const Pt2D & a, const Pt2D & b)  // Unnamed function
		{ return a.second < b.second; }
		);
	auto closest=closepairRecurse(first,last);
	return (make_pair(closest.first,closest.second));
	
}

#endif
