/*
 * IKHWArraysP2.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: raghav
 */

#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"

bool isPali(string s)
{
    if( s == string(s.rbegin(), s.rend()))
        return true;

    return false;
}

int IKSolution::nextPalindrome(int iInputNum)
{
    DEBUG_DEBUG(cout << "iInputNum = " << iInputNum << "\n");
    int nextPali = 0;

    /* Convert the number to a string */
    string s = to_string(iInputNum);

    int middle = (s.size() -1)/2 ;

    if(s[middle] != '9')
    {
        if(s.size() % 2)
        {
            string prefix = s.substr(0,middle);
            string suffix = s.substr(middle + 1);
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix << "\n");

            if((suffix > prefix) || (prefix.size() == 0))
            {
                s[middle] = s[middle] + 1;
            }
            suffix = string(prefix.rbegin(), prefix.rend());

            string ret = s.substr(0, middle + 1) + suffix;
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix <<  "\n");
            DEBUG_DEBUG(cout << "ret = " << ret << "\n");
            nextPali = stoi(ret);
            return nextPali;
        }
        else
        {

            string prefix = s.substr(0,middle + 1);
            string suffix = s.substr(middle + 1);
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix << "\n");

            if(suffix > prefix)
            {
                prefix = to_string(stoi(prefix) + 1);
            }
            suffix = string(prefix.rbegin(), prefix.rend());

            string ret = prefix + suffix;
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix <<  "\n");
            DEBUG_DEBUG(cout << "ret = " << ret << "\n");
            nextPali = stoi(ret);
            return nextPali;


        }
    }
    else
    {

        if(s.size() % 2)
        {
            string prefix = s.substr(0,middle);
            string suffix = s.substr(middle + 1);
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix << "\n");

            if((suffix > prefix))
            {
                prefix = to_string(stoi(prefix) + 1);
            }
            suffix = string(prefix.rbegin(), prefix.rend());

            string ret = prefix + "0" + suffix;
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix <<  "\n");
            DEBUG_DEBUG(cout << "ret = " << ret << "\n");
            nextPali = stoi(ret);
            return nextPali;
        }
        else
        {
            string prefix = s.substr(0,middle + 1);
            string suffix = s.substr(middle + 1);
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix << "\n");

            if(suffix >= prefix)
            {
                int oldsize = prefix.size();
                prefix = to_string(stoi(prefix) + 1);
                if(prefix.size() > oldsize)
                {
                    suffix = string(prefix.rbegin() + 1, prefix.rend());
                }
                else
                {
                    suffix = string(prefix.rbegin(), prefix.rend());
                }
            }
            else
            {
                suffix = string(prefix.rbegin(), prefix.rend());
            }

            string ret = prefix + suffix;
            DEBUG_DEBUG(cout << "prefix = " << prefix << " suffix = " << suffix <<  "\n");
            DEBUG_DEBUG(cout << "ret = " << ret << "\n");
            nextPali = stoi(ret);
            return nextPali;

        }

    }

    return nextPali;
}

void printVector(vector<int> v)
{
    for(auto it : v)
    {
        DEBUG_DEBUG(cout << it << " ");
    }
    DEBUG_DEBUG(cout << "\n");
}


vector<int> IKSolution::AlternatePosNegative(vector<int> vec)
{

    int lastPosindex = 0;
    int lastNegindex = 0;
    printVector(vec);
    DEBUG_DEBUG(cout << " \n");

    for(int index = 1; index < vec.size(); index++)
    {
        DEBUG_DEBUG(cout << "value processed =  " << vec[index] << "  ");
        if(vec[index] < 0 && (vec[lastPosindex + 1] > 0)  )
        {
            int temp = vec[lastPosindex + 1];
            vec[lastPosindex + 1] = vec[index];
            for(int j = index; j > (lastPosindex + 2); j--)
            {
                vec[j] = vec[j-1];
            }
            vec[lastPosindex + 2] = temp;
            lastPosindex = lastPosindex + 2;
            printVector(vec);
            lastNegindex = index;
        }
        else if(vec[index] > 0 && (vec[lastNegindex + 1] < 0))
        {

            int temp = vec[lastNegindex + 1];
                        vec[lastNegindex + 1] = vec[index];
                        for(int j = index; j > (lastNegindex + 2); j--)
                        {
                            vec[j] = vec[j-1];
                        }
                        vec[lastNegindex + 2] = temp;
                        lastNegindex = lastNegindex + 2;
                        printVector(vec);
                        lastPosindex = index;
        }
    }
    return vec;
}


//Utility function for sorting before mergin intervals.
/* Iterator points to a pair. So, use the pair to compare. */
bool myComparefunc(vector<int> p1, vector<int> p2)
{
    if(p1[0] < p2[0])
        return 1;
    else if (p1[0] == p2[0])
    {
        if(p1[1] > p2[1])
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

vector<pair<int,int>> IKSolution::skyLine(vvi buildings)
{
    vector<pair<int,int>> res;
    priority_queue<pair<int,int>> mypq;
    int omh = 0;
    int index = 0;
    int i = 0;
    int height;
    int xb;
    int xe;

    //Sort by the first element. if all first elements are equal then sort by second element. But, the max one comes first.
    sort(buildings.begin(), buildings.end(),myComparefunc);

    while(1)
    {
        if(index == buildings.size())
        {
            if(mypq.empty())
                break;
        }

        if(index < buildings.size())
        {
            height = buildings[index][1];
            xb = buildings[index][0];
            xe = buildings[index][2];
        }

        /* Check if there is a beginning */
        if( (index < buildings.size()) && (i == xb) )
        {
            DEBUG_TRACE(cout << i << " Before Insert: next x = " << xb << height  << xe << " \n");
            pair<int,int> p;

            if(!mypq.empty())
            {
                p = mypq.top();
                omh = p.first;
            }
            else
                omh = 0;

            mypq.push(make_pair(height,xe));
            p = mypq.top();
            if(p.first > omh)
            {
                DEBUG_DEBUG(cout << " New lining after Add " << i << " " << height << " \n");
                res.push_back(make_pair(i,height) );
            }
            index++;
        }
        else
        {
            if(index < buildings.size())
                DEBUG_TRACE(cout << "Before delete: next x = " << xb <<  height  << xe << " \n");

            /* If there is an end to the top, pop all the one;s that are not valid anymore */
            if(!mypq.empty())
            {
                pair<int,int> p = mypq.top();
                bool popped = false;
                int lastpopval = p.first;
                while(p.second <= i)
                {
                    popped = true;
                    mypq.pop();
                    if(!mypq.empty())
                    {
                        p = mypq.top();
                        lastpopval = p.first;
                    }
                    else
                    {
                       lastpopval = 0;
                       break;
                    }
                }
                if(popped == true)
                {
                    DEBUG_DEBUG(cout << " New lining after Remove " << i << " " << lastpopval << " \n");
                    res.push_back(make_pair(i,lastpopval));
                }
            }
        }


        {
            //Skip to the next x coordinate
            int nextEnd = INT_MAX;
            int nextX = INT_MAX;
            if(!mypq.empty())
            {
                pair<int,int> p = mypq.top();
                nextEnd = p.second;
            }

            if(index < buildings.size())
                nextX = buildings[index][0];

            i = nextX < nextEnd ? nextX : nextEnd;

        }
    }
    return res;
}
/***************************************************************************************************************************/


/* Problem: Run Length Encoding.
 *
 *
 */
string IKSolution::RLE(string strInput)
{


    char firstChar;
    string res;

#if 1
    for(int i = 0; i < strInput.size(); i++)
    {
        int count = 1;
        firstChar = strInput[i];

        while(firstChar == (strInput[i + count]))
        {
            count++;
        }

        if(count > 2)
        {
            res = res + to_string(count);
            res.push_back(firstChar);
        }
        else if(count == 2)
        {
            res.push_back(firstChar);
            res.push_back(firstChar);
        }
        else
            res.push_back(firstChar);

        i += (count - 1);

    }
#endif
    return res;

#if 0
    //Encode a string that has char and numbers in it. Basically compress a string.

               // B       5      129  A    5     129     5      C         to "BAAAAA55555C"

    //Assuming * does not appear in the string,
    // B*5A*55C

    char *s;
    string ress;

    int size = 8;
    int index = 0;

    while(index != size)
    {
        while((index != size) && s[index] != '*')
        {
            index++;
            res.push_back(s[index]);

            //push all those chars into the vector
        }

        if((index != size) && s[index] == '*')
        {

            index++;
            int beginIndex = index;

            while((index != size) && ((s[index] <= ) && (s[index] <= ) ))
            {
                index++;
            }

            if(index != size)
            {
                //Get the integer value from the string
                //Push those many chars into a vector
                char charToInsert;


                if(s[index - 1] == ) //a number
                {
                    charToInsert = s[index - 1];
                }
                else
                {
                }

                for(int i = 0; i < (beginIndex - index); i++)
                {
                    res.push_back(s[index]);
                }
            }
        }
    }

    return res;
#endif

}

/*********************************************************************************************************************/
int findMinimumUtil(vector<int>& arr, int low, int high)
{
    DEBUG_DEBUG(cout << "low = " << low << " high = " << high << "\n");
    if(low >= high)
    {
        if(low > high)
            DEBUG_DEBUG(cout << "low > high \n"); //Non rotated case
        else
            DEBUG_DEBUG(cout <<  "low == high \n");

        return arr[low];
    }


    int mid = (low + high)/2;

    if(((arr[mid - 1] > arr[mid])  &&  (arr[mid] < arr[mid + 1])))
    {
        DEBUG_DEBUG(cout << "Tipping point middle is less than left and right \n");
        return arr[mid];
    }

    if(arr[mid] < arr[high])
        return findMinimumUtil(arr, low, (mid - 1));

    if(arr[mid] >= arr[low])
        return findMinimumUtil(arr, mid + 1, high);

    assert(0);

}


/* Problem: find the minimum in a rotated sorted array
 *
 * Approach:
 *          Base case: When there is one element in the array, its the min value[1,2 is a case that makes low > high].
 *                     If the middle value is less than both right and left that is the min value.
 *
 *          Regular case:
 *                    1. If the middle value is less than high index val then search onto left of middle.
 *                    2. If the middle value is greater than or equal to** low index val then search onto right of middle.
 *
 *                    **  Note that 2,1 is a case that makes equal to important.
 *          Standard binary search: Search the middle, if not search left or right depending upon certain criterion.
 *
 * Time Complexity: logn
 */
int IKSolution::findMinimum(vector<int> arr)
{
    int minVal;


    minVal = findMinimumUtil(arr, 0, arr.size()-1);

    return minVal;
}

/*********************************************************************************************************************/

/* Problem: Given a large array of 4-byte integers. Find out how many total bits are turned ON in such an array?
 *
 *
 */
int IKSolution::printCountOfBitsSet(vector<int> intArr)
{

    int result = 0;
    int count = 0;
    map<int,int> table;

    if(table.empty())
    {
        for(int i = 0; (i < 256); i++)
        {
            int mask = 0x01; count = 0;
            for(int j = 0; j < 8; j++)
            {
                if(i & mask)
                    count++;
                mask <<= 1;
            }
            DEBUG_DEBUG(cout << "for val i = "<< i << " no of bits set " << count << "\n");
            table.insert(make_pair(i,count));
        }
     }


     for(auto it : intArr)
     {
         int mask = 0x000000FF;
         for(int i = 0; i < 4; i++)
         {
             int temp = (it) & mask;
             temp >>= (i * 8); //very important
             auto it1 = table.find(temp);
             result += (it1->second);
             mask <<= 8;

         }
         DEBUG_DEBUG(cout << "returning " << result << "\n");
     }
     DEBUG_DEBUG(cout << "returning " << result << "\n");

     return result;

}



