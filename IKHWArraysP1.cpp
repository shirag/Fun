/*

 * HomeWork1P1.cpp
 *
 *  Created on: Jan 10, 2017
 *      Author: Raghav Navada
 */


#include "IKSolution.hpp"



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


/*************************************************************************************************/
/* Problem: Pascal's Triangle
 * Example:
 * Approach:
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 */
// A O(n^2) time and O(1) extra space function for Pascal's Triangle
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
        //cout << "value = " << intArr[i] << "\n";
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
             cout << "CumS = " << cumS << "\n";
             m.insert(make_pair(cumS,i));
        }
        else
        {
            if((cumS == 0) && (intArr[it->second] != 0))   //Case where there are zeroes in the beginning.
                continue;

            cout << "found cumS " << cumS << "\n";
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


/* Problem:
 * Example:
 * Approach: all nearest smaller values problem.
 *           Push an index to the stack if its value is higher than the previous value in the stack. This determines LEFT of a value.
 *           Pop it out when you find something smaller than this value. Idea is we have found how far to the RIGHT this element can extend.
 *           After popping out, calculate the area and update the max value if its needed.
 *           area = h * (currnetIndex - st.top() - 1)
 *           https://www.quora.com/What-is-the-algorithmic-approach-to-find-the-maximum-rectangular-area-in-a-histogram
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 */

int IKSolution::findLargestRectangle()
{

    stack<int> s1;
    int maxVal = 0;
    int val = 0;

   // v v1 = {1,2,4,0,4,6,4,2,1};
	//v v1 = {6, 2, 5, 4, 5, 1, 6};
    vi v1 = {10,20,30};
	int index = 0;

	/* Iterate over all elements of the array */
	for(vi::iterator it = v1.begin(); it != v1.end(); )
	{
		/* if stack is empty or if the value is higher  */
        if((s1.empty()) || (v1[s1.top()] <= (*it) ))
        {
        	/* Beginning of a new value */
        	cout << "pushing " << *it << "\n";
        	s1.push(index);
        	it++, index++;
        }
        else /*End of a value. Time to determine the area */
        {
        	int beginIn = s1.top();
        	s1.pop();

        	cout << "popping " << v1[beginIn] << "\n";

        	/* If the value is lower, then end of the last value. */
        	//val = (v1[beginIn]) * (index-beginIn);
        	if (s1.empty())
        		val = (v1[beginIn]) * (index);
        	else
        	    val = (v1[beginIn]) * (index-s1.top()-1); //element begins after s1.top()-1 and ends one before index.

        	cout << "val = " << val << "\n";

           if(maxVal < val)
        		maxVal = val;
        }
	}

	cout << "Done with processing all elements of array. Now its time to pop rest of the stack \n";
	while(!s1.empty())
	{
		int beginIn = s1.top();
		s1.pop();

		if (s1.empty())
		    val = (v1[beginIn]) * (index);
		else
		    val = (v1[beginIn]) * (index-s1.top()-1);

		if(maxVal < val)
		    maxVal = val;

	}

    cout << "Found Max val = " << maxVal << "\n" ;

	return 0;
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
 *         Use a stack store the new merged intervals. You always compare with top of the stack.
 *         If there is no merge at all then push a new interval to the stack.
 * Complexity: (n)(logn)
 * Space Complexity: O(n) //for stack
 * Any other better approach:
 * */
int IKSolution::mergeIntervals()
{

	vpii v1;
	vpii vf;

	//v1.push_back(make_pair(100,2));
	//v1.push_back(make_pair(1,2));
	//v1.push_back(make_pair(6,9));
	//v1.push_back(make_pair(5,7));
	//v1.push_back(make_pair(6,8));

	v1.push_back(make_pair(1,3));
	v1.push_back(make_pair(2,4));
	v1.push_back(make_pair(5,7));
	v1.push_back(make_pair(6,8));

	sort(v1.begin(), v1.end(),myComparefunc);

	cout << "\n";


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
    	cout << "pair->first = " << it->first << " pair->second = " << it->second << "\n";
    }

	return 0;
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

	cout << "\n";

	for(int i = 0; i < size; i++)
	{
    	p2[i] = p1[i] * p2[i];
        cout << p2[i] << " \n" ;
	}

    return 0;
}


