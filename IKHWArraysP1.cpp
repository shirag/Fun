/*

 * HomeWork1P1.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: Raghav Navada
 */



#define DEBUG_LEVEL DEBUG_LEVEL_MAINSTATUS
#include "IKSolution.hpp"


/* Problem:
 *     Implement a magic hash map. All following 4 has to ne O(1)
        int getValue(string s);
        void setVal(string str, int val);
        void deleteVal(string s);
        int getRandomVal(); //uniformly returns a random value from the map
 *
 * Example:
 * Approach:
 *      1. Have a map and an auxially array.
 *      2. key in the map is the key you want to search and the value is the index to an array.
 *      3. When you delete a key, its not deleted, but just swapped with the one at the end of the array.
 *         The idea here is deleting the end of the array may not be always O(1). Then you insert at a
           particular location in the array.
        4. In the array you store both the key and the value.
 *
 * */

typedef unordered_map<string, unsigned int> msv;
vector<pair<string,int>> refTable;
msv mMap;

unsigned int size = 0;


int IKSolution::getValue(string s)
{
    int val = 0;

    if(mMap.count(s) != 0)
    {
        int index = mMap[s];
        return refTable[index].second;
        assert(refTable[index].first == s);
    }

    return val;
}

void IKSolution::setVal(string str, int val)
{

    if(mMap.count(str) == 0)
    {
        cout << "Field not found.. \n" ;
        if(size == refTable.size())
        {
            cout << "push_back \n";
            refTable.push_back({str,val});
            mMap[str] = size;
            size++;
        }
        else
        {
            cout << "insert \n";
            refTable.insert(refTable.begin() + size, {str, val});
            mMap[str] = size;
            size++;
        }
    }
    else
    {
        //Overwrite to an existing field
        cout << "Field found .. \n" ;
        int index = mMap[str];
        refTable[index].second = val;
        assert(refTable[index].first == str);
    }

    return;
}

void IKSolution::deleteVal(string str)
{

    if(mMap.count(str) != 0)
    {
        int index = mMap[str];

        refTable[index].first = refTable[size-1].first;
        refTable[index].second = refTable[size-1].second;

        size--;

        mMap.erase(str);
        mMap[refTable[index].first] = index;
    }

    return;
}

int IKSolution::getRandomVal()
{
    int val = 0;

    int rv = rand() % size;


    val = refTable[rv].second;

    cout << "Random person " << refTable[rv].first << " Age " << refTable[rv].second << "\n";

    return val;
}

/*  Problem:
 *      Find a duplicate in an array of size n with elements equal to 1 to n-1.
 *      [1,2,3,3] n = 4,elements = 1 to 3
 *      IMPORTANT: There can be more than one repeating elements.
 *
 *  Approach 1:
 *      Create a boolean auxiliary array. Mark the field in the array.
 *  Approach 2:
 *      Add a constant value to the corresponding field to indicate the number has been found.
 *  Approach 3:
 *      Instead of adding a no to the field, place all elements at their exact location.
 *      Use the first location in the array as the placeholder.
 *  Approach 4:
 *
 */

int IKSolution::findDuplicateThatOccursOnce(vector<int> v)
{
    int duplicate = 0;

#if 0
    //Time: O(n)
    //Space: O(n)
    vector<bool> w(v.size());

    for(int i = 0; i < v.size(); i++)
    {
        int tmp = v[i];

        if(w[tmp-1] == true)
            return tmp;

        w[tmp-1] = true;
    }

    return duplicate;
#endif

#if 0
    // If the element at the index where it belongs is greater than n then that is the duplicate.
    //Time: O(n)
    //Space: O(1). But, there is a chance of overflow. Modifying the array. So,not possible on read-only array.

    for(int i = 0; i < v.size(); i++)
    {
        int tmp = v[i];
        if(tmp > v.size())
            tmp = tmp - v.size();

        if(v[tmp-1] > v.size())
            return tmp;

        v[tmp-1] += v.size();
    }

    return duplicate;
#endif

#if 0
    //Time: O(n)
    //Space O(1). Modifying the array. So, not possible on read-only array.
    //Insert the element at the right location. Make array[0] as the place holder.
    for(int i = 0; i < v.size(); i++)
    {
        int tmp = v[0];

        if(v[0] == v[tmp])
            return tmp;
        else
            swap(v[0],v[tmp]);
    }

    return duplicate;
#endif

#if 1

    //Find the median of the given range.
    //Count how many numbers(in the array) are in the range beginning and median.
    //If count is greater than what it is supposed to be, then duplicate is on left of the median.

    //Time: O(n log n)
    //Space O(1). Possible on read only arrays.
    printVector(v);

    int rb = 1;
    int re = v.size() - 1;

    while(rb != re)
    {
        float median = (rb + re)/2.0;
        int count = 0;

        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] <= median && v[i] >= rb)
                count++;
        }
        DEBUG_ERROR(cout << "rb = " << rb << " re = " << re << " median = " << median << " count = " << count << " \n");
        if(count > median - rb + 1)
            re = median; //its on left of median
        else
            rb = median + 0.5; //its on right of median
    }

    DEBUG_ERROR(cout << "rb = " << rb << " re = " << re << " \n");
    return rb;
#endif

}

/*************************************************************************************************/
/* Problem: Pascal's Triangle
 * Example:
 * Approach:
 * Complexity:
 *     A O(n^2) time and O(1) extra space function for Pascal's Triangle
 * Space Complexity:
 * Any other better approach:
 */

void IKSolution::printPascal(int n)
{
    for (int line = 1; line <= n; line++)
    {
        int C = 1;
        for (int i = 1; i <= line; i++)
        {
            cout <<  C;
            C = C * (line - i) / i;
        }
        cout << "\n";
    }

}

/* Problem: Sum of zero problem
 * Example:
 * Approach: Iterate over elements of array and calculate the cumulative sum. Store the sum and the index in a map.
 *           Every time you calculate the sum you lookup the map to see if the sum already exists. If the value exists
 *           then we have found the subarry whose sum is zero.
 *
             |----------------Array---------------------------------------|
 *           |--------------|---------------------------|-----------------|
 *           |-------X(x)---|---------------------------|-----------------|
 *           |---------------------Y(y)-----------------|-----------------|
 *           In the above pic is the X is cumulative sum of x elements. Y is the cumulative sum of y elements.
 *           If X == Y, then the array with 0 sum spans from index x to index y-1.
 *
 * Time Complexity:O(n)
 * Space Complexity:O(n). Since we use a map.
 * Any other better approach:
 */
vector<string> IKSolution::sumZero(vector < int > intArr)
{

    int cumS = 0;
	int sz = intArr.size();
	map<int,int> m;
	vector<string> vs;

	m.insert(make_pair(0,0));

    for(int i = 0; i < sz; i++)
    {
        string s;
        cumS += intArr[i];

        if(cumS == 0)
        {
            for(int j = 0; j <= i; j++)
            {
                s.append(to_string(intArr[j]));
                if(j != i)
                    s.append(",");
                else
                {
                    vs.push_back(s);
                    s.clear();
                }
            }
        }

        map<int,int>::iterator it = m.find(cumS);

        if(it == m.end())
        {
             //cout << "CumS = " << cumS << "\n";
             m.insert(make_pair(cumS,i));
        }
        else
        {
            if((cumS == 0) && (intArr[it->second] != 0))   //Case where there are zeroes in the beginning.
                continue;

            string s;
            for(int j = (it->second)+1; (j <= i) && (j != 0); j++)
            {
                s.append(to_string(intArr[j]));
                if(j != i)
                    s.append(",");
                else
                {
                    vs.push_back(s);
                    s.clear();
                }

            }

       }
    }

    return vs;
}


/* Problem:  All nearest smaller values problem.
 * Example:
 * Approach:
 *           Top of the stack represents a higher value that has begun and has not ended.
 *           The one below it represents the starting index of the top of the stack.
 *           val = (v1[beginIn]) * (index-s1.top()-1);
 *
 *           Push an index to the stack if its value is higher than or EQUAL to the previous value in the stack. This determines LEFT of a value.
 *           Pop it out when you find something smaller than this value. Idea is we have found how far to the RIGHT this element can extend.
 *           * After popping out, calculate the area and update the max value if its needed.
 *             * Look at the equation closely.
 *             * DONT UPDATE the index for the loop. Because of this you will process the current index against the top of the stack again.
 *
 *           area = h * (currnetIndex - st.top() - 1)
 *           https://www.quora.com/What-is-the-algorithmic-approach-to-find-the-maximum-rectangular-area-in-a-histogram
 * Complexity: O(n)
 * Space Complexity:
 * Any other better approach:
 */

int IKSolution::findLargestRectangle(vi v1)
{

    stack<int> s1;
    int maxVal = 0;
    int val = 0;


	int index = 0;

	/* Iterate over all elements of the array */
	for(vi::iterator it = v1.begin(); it != v1.end(); )
	{
		/* if stack is empty or if the value is higher  */
        if((s1.empty()) || (v1[s1.top()] <= (*it) ))
        {
        	/* Beginning of a new value */
        	DEBUG_DEBUG(cout << "pushing " << *it << "\n");
        	s1.push(index);
        	it++, index++;
        }
        else /*End of a value. Time to determine the area */
        {
        	int beginIn = s1.top();
        	s1.pop();

        	DEBUG_DEBUG(cout << "popping " << v1[beginIn] << "\n");

        	/* If the value is lower, then end of the last value. */
        	if (s1.empty())
        		val = (v1[beginIn]) * (index);
        	else
        	    val = (v1[beginIn]) * (index-s1.top()-1); //element begins after s1.top()-1 and ends one before index.
        	DEBUG_DEBUG(cout << "val = " << val << "\n");

           if(maxVal < val)
        		maxVal = val;
        }
	}

	DEBUG_DEBUG(cout << "Done with processing all elements of array. Now its time to pop rest of the stack \n");
	while(!s1.empty())
	{
		int beginIn = s1.top();
		s1.pop();

		if (s1.empty())
		    val = (v1[beginIn]) * (index);
		else
		    val = (v1[beginIn]) * (index-s1.top()-1);
		DEBUG_DEBUG(cout << "val = " << val << "\n");

		if(maxVal < val)
		    maxVal = val;

	}

    DEBUG_DEBUG(cout << "Found Max val = " << maxVal << "\n");

	return maxVal;
}




/*
 * Problem:
 *     Given an n x n matrix, where every row and column is sorted in increasing order. Given a number x, how to decide whether this x is in the matrix.
 *     The designed algorithm should have linear time complexity.
 *
 * Example:
 *      int mat[4][4] = { {10, 20, 30, 40},
                          {15, 25, 35, 45},
                          {27, 29, 37, 48},
                          {32, 33, 39, 50},
                  };
         search(mat, 4, 29);
 * Approach:
 *     Compare x with top row right most element. Keep going left. When you come across an element whose value is
 *     less than x, go down that column and search for x.
 *     In the above example when you hit 20 start going down.
 * Complexity:
 *     O(n)
 *     O(M+N) for a MxN matrix.
 * Space Complexity:
 *     O(1)
 * Any other better approach:
 */
int IKSolution::twoDArraySearch()
{
   int n = 5;
   int x = 10; /* The element we are looking for */
   vvi arr(n, vector<int>(n));


   int j = 0;
   for(int i = n-1; i >= 0; i--)
   {
	   if (arr[j][i] == x)
	   {
		   return 1;
		   break;
	   }
	   else if(arr[j][i] < x)
	   {
           for(;j < n; j++)
           {
        	   if(arr[i][j] == x)
        	       return 1;
           }
	   }
   }

   return 0;
}

//Utility function for sorting before mergin intervals.
/* Iterator points to a pair. So, use the pair to compare. */
bool myComparefunc(pair<int,int> p1, pair<int,int> p2)
{
	if(p1.first < p2.first)
	    return 1;
	else if (p1.first == p2.first)
		if(p1.second < p2.second)
			return 1;
		else
			return 0;
	else
		return 0;
}

/*
 * Problem: Given a set of time intervals in any order, merge all overlapping intervals into one and output the
 *         result which should have only mutually exclusive intervals.
 * Example:{1,3}, {2,4}, {5,7}, {6,8} }. should return {1, 4} and {5, 8}
 * Approach: is to first sort the intervals according to starting time.
 *         Once we have the sorted intervals, we can combine all intervals in a linear traversal.
 *         Use a vector store the new merged intervals. You always compare with top of the stack.
 *         If there is no merge at all then push a new interval to the vector.
 *         Three type of the cases for the second step:
 *         1. Second one's begin and end is within the first one.
 *         2. Second one's begin is within the second but not the end.
 *         3. Second one;s begin and end both are not inside the first one.
 *
 * Complexity: (n)(logn)
 * Space Complexity: O(n) //for stack
 * Any other better approach:
 * */
vpii IKSolution::mergeIntervals(vpii v1)
{
	vpii vf;

	sort(v1.begin(), v1.end(),myComparefunc);

    vf.push_back(make_pair(v1.begin()->first,v1.begin()->second));
    vpii::iterator itf = vf.end()-1;

    for(vpii::iterator its = (v1.begin()) + 1; its != v1.end(); its++)
    {
    	if(its->first <= itf->second) //overlap
    	{
    	    if(its->second > itf->second)
    	    	itf->second = its->second;
    	}
    	else //disconnect. Push it into stack.
    	{
    		vf.push_back(make_pair(its->first,its->second)) ;
            itf = vf.end()-1;
    	}
    }

    cout << "\n" ;
    for(vpii::iterator it = (vf.begin()); it != vf.end(); it++)
    {
    	DEBUG_DEBUG(cout << "pair->first = " << it->first << " pair->second = " << it->second << "\n");
    }

	return vf;
}

/* Problem:
 *     Given an array of numbers, return array of products of all other numbers (no division)
 * Example:
 *     Input : [1, 2, 3, 4, 5]
       Output: [(2*3*4*5), (1*3*4*5), (1*2*4*5), (1*2*3*5), (1*2*3*4)]
             = [120, 60, 40, 30, 24]
 * Approach:
 *
 *
 *     The trick is to construct the arrays (in the case for 4 elements)
       {              1,         a[0],    a[0]*a[1],    a[0]*a[1]*a[2],  }
       { a[1]*a[2]*a[3],    a[2]*a[3],         a[3],                 1,  }
       First one has the product of all elements that are towards your left.
       Second array has product of all elements are to your right.
       Then multiplying the two arrays element by element gives the required result

 * Complexity: O(n)
 * Space Complexity: O(n)
 * Any other better approach:
 *     This can be done in O(1) space too(excluding the o/p array).
 */

int IKSolution::prLR()
{
	vector<int> arr;

	arr.push_back(1);arr.push_back(2);arr.push_back(3);arr.push_back(4);arr.push_back(5);

	int size = arr.size();

	if(size == 0)
	{
		cout << "Array is empty \n" ;
		return 0;
	}

	vector<int> p1(size,0);
	vector<int> p2(size,0);

	p1[0] = 1;
	p2[size - 1] = 1;

	int pr1 = arr[0];
	int pr2 = arr[size - 1];

	for(int i = 1; i < size; i++)
	{
		p1[i] = pr1;
		pr1 *= arr[i];

		p2[size-i-1] = pr2;
		pr2 *= arr[size-i-1];
	}

	DEBUG_DEBUG(cout << "\n");

	for(int i = 0; i < size; i++)
	{
    	p2[i] = p1[i] * p2[i];
        DEBUG_DEBUG(cout << p2[i] << " \n");
	}

    return 0;
}


