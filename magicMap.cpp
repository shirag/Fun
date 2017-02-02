/*
 * magicMap.cpp
 *
 *  Created on: Jan 9, 2017
 *      Author: GouriShivani
 *
 *  Provide interfaces.
 */
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<map>
#include"IKSolution.hpp"
#include<cstdlib>

using namespace std;

/* Implement a magic hash map */
typedef vector< pair<string, int> > vp;
typedef map<string, unsigned int> msv;

vp auxillarDs;
msv mMap;
unsigned int cS = 0;


int IKSolution::getValue(string s)
{
	int val = 0;

	msv::iterator it = mMap.find(s);
	if(it != mMap.end())
	{
		//Retrieve the value from a vector that has a pair of string and int
        vp::iterator it1 = auxillarDs.begin() + it->second;
        val = it1->second;
	}

    return val;
}

int IKSolution::setVal(string str, int val)
{
	unsigned int sA;

	msv::iterator it = mMap.find(str);
	if(it == mMap.end())
	{
		cout << "Field not found .. \n" ;
		auxillarDs.push_back(make_pair(str,val));
		sA = auxillarDs.size();

		//mMap.insert(make_pair(str,sA-1));
		mMap[str] = sA-1;
		cS++;
	}
	else
	{
		//Overwrite to an existing field in a vector of <string,int>
		cout << "Field found .. \n" ;
		auxillarDs[it->second] = make_pair(str,val);
	}

    return 0;
}

int IKSolution::deleteVal(string str)
{

	msv::iterator it = mMap.find(str);
	if(it != mMap.end())
	{
		auxillarDs[it->second] = auxillarDs[cS-1];
		mMap[str] = it->second;
		mMap.erase(it);
		cS--;
	}

	cout<< "cs = " << cS << " \n";
	cout<< "length of vector = " << auxillarDs.size() << "\n";

	return 0;
}

int IKSolution::getRandomVal()
{
	int val = 0;

	int rv = rand()%cS;
	cout << "rv  = " << rv << "\n";

	vp::iterator it1 = auxillarDs.begin() + rv;
	val = it1->second;

	//cout << "val = " << val << "\n";

	return val;
}


