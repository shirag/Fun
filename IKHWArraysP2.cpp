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

/*
 * Problem:
 *     Given a number, find the next smallest palindrome
 *
 * Approach:
 *     http://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
 *
 */

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

            if((suffix >= prefix))
            {
                int oldsize = prefix.size();
                prefix = to_string(stoi(prefix) + 1);
                cout << "aprefix = " << prefix   << " \n";

                if(prefix.size() > oldsize)
                {
                    cout << "size greater \n";
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

/*
 * Problem:
 *     Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive
 *     number is followed by negative and vice-versa maintaining the order of appearance.
       Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the
       end of the array. If there are more negative numbers, they too appear in the end of the array.
   Approach:
       The idea is to process array from left to right. While processing, find the first out of place element in the
       remaining unprocessed array. An element is out of place if it is negative and at odd index, or it is positive
       and at even index. Once we find an out of place element, we find the first element after it with opposite sign.
       We right rotate the subarray between these two elements (including these two).
 * */

vector<int> IKSolution::AlternatePosNegative(vector<int> vec)
{

    int lastPosindex = 0;
    int lastNegindex = 0;
    int count = 0;

    for(int index = 0; index < vec.size(); index++)
    {
        if(index % 2) //negative
        {
            if(vec[index] < 0)
                continue;
            while((index + count < vec.size()) && (vec[index + count] > 0))
                count++;
        }
        else //positive
        {
            if(vec[index] > 0)
                continue;
            while((index + count < vec.size()) && (vec[index + count] < 0))
                count++;
        }

        if(index + count < vec.size())
        {
            int temp = vec[index];
            vec[index] = vec[index + count];
            for(int j = index + count; j > index + 1; j--)
            {
                vec[j] = vec[j-1];
            }
            vec[index + 1] = temp;
        }
        count = 0;

    }

    return vec;
}
/**********************************************************************************************/


/* Utility function for sorting before mergin intervals.
   Iterator points to a pair. So, use the pair to compare.*/
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


/*
 * Problem:
 *     The skyline problem.
 *     https://leetcode.com/problems/the-skyline-problem/#/description
 *     http://www.geeksforgeeks.org/divide-and-conquer-set-7-the-skyline-problem/
 *     https://briangordon.github.io/2014/08/the-skyline-problem.html
 *     A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance.
 *     Now suppose you are given the locations and height of all the buildings, write a program to output the skyline formed by
 *     these buildings collectively.
 * Approach:
 *     We use a heap to store all the processed buildings(height and end x coordinate). So, at any point the top of the heap represents the tallest building.
 *     Use this information to produce the output array.
 *     1. Sort by the first element(x). For equal start positions sort then by their height. But, the higher one's come first.
 *     2. In a loop, process one of the following:
 *        * Next beginning of a building. OR
 *        * End of the building on the top of a heap.
 *        whichever comes first.
 *     3. If its the next beginning of a building, push it to heap and then see if the addition makes a difference.
 *     4. If its the end of an existing building on the top of heap, then pop the building and all buildings that are
 *        not relevant anymore from the the heap.
 *
 * Time Complexity:
 *     O(n log n)
 * Alternate approach:
 *     There is a merge sort based approach in GeeksforGeeks.
 *
 *
 */
vector<pair<int,int>> IKSolution::skyLine(vvi buildings)
{
    vector<pair<int,int>> res;
    priority_queue<pair<int,int>> mypq;
    int heightOfTallest = 0;
    int nextBuildToProcess = 0;
    int nextXCordToProc = 0;
    int height;
    int xe;
    pair<int,int> p;
    bool pushToHeap = false;

    sort(buildings.begin(), buildings.end(), myComparefunc);

    while(1)
    {
        if(nextBuildToProcess == buildings.size())
        {
            if(mypq.empty())
                break;
        }

        {
            /* Generate the next nextXCordToProc to be processed.  */
            int endXOfTallest = INT_MAX;
            int startXOfNextBuilding = INT_MAX;
            if(!mypq.empty())
            {
                p = mypq.top();
                heightOfTallest = p.first;
                endXOfTallest = p.second;
            }
            else
                heightOfTallest = 0;

            if(nextBuildToProcess < buildings.size())
            {
                startXOfNextBuilding = buildings[nextBuildToProcess][0];
                height = buildings[nextBuildToProcess][1];
                xe = buildings[nextBuildToProcess][2];
            }

            if(startXOfNextBuilding < endXOfTallest)
            {
                nextXCordToProc = startXOfNextBuilding;
                pushToHeap = true;
            }
            else
                nextXCordToProc = endXOfTallest;

        }

        /* if the beginning X of the next building to be processed equal to nextX to be processed */
        if( pushToHeap == true)
        {
            pushToHeap = false;
            mypq.push(make_pair(height,xe));
            p = mypq.top();
            if(p.first > heightOfTallest) // If the newly added height is greater than the top height, time to insert a new pair to results
            {
                DEBUG_DEBUG(cout << " New lining after Add " << nextXCordToProc << " " << height << " \n");
                res.push_back(make_pair(nextXCordToProc,height) );
            }
            nextBuildToProcess++;
        }
        else
        {
            /* If there is an end to the top, pop all the one;s that are not valid anymore */
            while(p.second <= nextXCordToProc)
            {
                mypq.pop();
                if(!mypq.empty())
                {
                    p = mypq.top();
                    heightOfTallest = p.first;
                }
                else
                {
                    heightOfTallest = 0;
                    break;
                }
            }
            DEBUG_DEBUG(cout << " New lining after Remove " << nextXCordToProc << " " << heightOfTallest << " \n");
            res.push_back(make_pair(nextXCordToProc,heightOfTallest));
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

/*
 * Problem:
 *     Given a large array of 4-byte integers. Find out how many total bits are turned ON in such an array?
 * Approach:
 *     Populate the hashmap for all values between 0 and 255(1 byte). Then use this lookup table to find the values for
 *     all 4 bytes values by right shifting.
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





