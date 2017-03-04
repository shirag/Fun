/* * IKHWStringsP1.cpp

 *
 *  Created on: Feb 23, 2017
 *      Author: raghav
 */


#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"

/* Problem: Longest substring with at most 2 distinct characters.
 * Approach:
 * Time Complexity:O(n)
 * Space Complexity: O(1)
 * Take Away:
 * */

string IKSolution::longestSub(string strText)
{
    string ret;
    if(strText.size() == 1)
    {
        return ret;
    }

    map<char,pair<int,int>> hist;
    int maxLength = INT_MIN;
    int maxStartIndex = 0;
    int maxEndIndex = 0;

    hist.insert(make_pair(strText[0], make_pair(0,0)));
    if(strText[1] != strText[0])
        hist.insert(make_pair(strText[1], make_pair(1,1)));

    int currIndex = 2;
    char lastChar = strText[1];
    strText.push_back(0);
    cout << "size of new string = " << strText.size() << "\n";

    for(auto it = strText.begin() + 2; it != (strText.end()); it++)
    {
        auto it1 = hist.find(*it);
        if(it1 != hist.end())
            it1->second.second = currIndex;
        else if(hist.size() == 1)
        {
            hist.insert(make_pair(strText[currIndex], make_pair(currIndex,currIndex)));
        }
        else
        {
            /* Find the char that was seen first and then measure the length */
            int minFirst = INT_MAX;
            int deleteLastS = 0;
            char charToDelete = 0;

            for(auto it : hist)
            {
                if(it.second.first < minFirst)
                    minFirst = it.second.first;
                if(it.first != lastChar)
                {
                    deleteLastS = it.second.second; //Find when it was seen last
                    charToDelete = it.first;
                }
            }

            if((currIndex - minFirst) > maxLength)
            {
                maxLength = currIndex - minFirst;
                maxStartIndex = minFirst;
                maxEndIndex = currIndex;

            }

            if(charToDelete != 0)
                hist.erase(hist.find(charToDelete));

            hist[lastChar] = make_pair(deleteLastS + 1, currIndex - 1 );
            hist.insert(make_pair(strText[currIndex], make_pair(currIndex,currIndex)));
        }
        lastChar = strText[currIndex];
        currIndex++;
    }

    string s(strText.begin() + maxStartIndex, strText.begin() + maxEndIndex);
    DEBUG_DEBUG(cout << "The max length string is " << s  << "  and length is " << maxLength << " \n" );
    return s;
}



bool isPalindrome(string s)
{
    if(s.empty())
        return true;

    if(s == string(s.rbegin(), s.rend()))
        return true;
    else
        return false;
}

/*
 * Problem:
 * Approach:

   Brute force if O(n * n * k)
   O(n * k * k) solution: If the part of a string is palindrome, then you have to reverse the non palindrome part and find a match.
   If the no part of the string is a palindrome, then you have to reverse the entire string and see if there is a match.

   If a string is palindrome, then if you add strings as its wings(left & right), then there is a chance
   that you will generate a new palindrome again.
   If a string is NOT a palindrome, then if you add strings as its wings(left and rigth), then there is NO chance that you
   will generate a new palindrome again.

   TBD: TRy solving using Trie.

   For O(n * k) solution where k is the length of string refer,
   https://www.quora.com/Given-a-list-of-words-can-two-words-be-joined-together-to-form-a-palindrome
   Using Mancher's algorithm.



 * Time Complexity: O(n * k * k)
 * Space Complexity:
 * Take Away:
 */

vector<pair<string,string>> IKSolution::joinWordToMakePali(vector<string> s)
{
    /* Populate the set with strings */
    map<string,int> ips;
    vector<pair<string,string>> res;

    for(int i = 0; i < s.size(); i++)
        ips.insert(make_pair(s[i], i));

    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < s[i].size(); j++)
        {
            string prefix = s[i].substr(0, j);
            string suffix = s[i].substr(j);
            DEBUG_TRACE(cout << "prefix = " << prefix << " suffix = " << suffix << " \n" );
            if(isPalindrome(prefix) == true)
            {
                string tmp = string(suffix.rbegin(), suffix.rend());
                if(ips.count(tmp) >= 1 )
                {
                    res.push_back(make_pair(s[i],tmp));
                    DEBUG_DEBUG(cout << "Good Pair: " << s[i] << " : " << tmp << " \n" );
                }
            }
            if(isPalindrome(suffix) == true)
            {
                string tmp = string(prefix.rbegin(), prefix.rend());
                if(ips.count(tmp) >= 1 )
                {
                    res.push_back(make_pair(s[i],tmp));
                    DEBUG_DEBUG(cout << "Good Pair: " << s[i] << " : " << tmp << " \n" );

                }
            }
        }
    }
    return res;
}

/*
 * Problem:
 *    Regular expression matching.
 * Approach:
 *    Check the second char. If its a * then you have to skip all chars in the source until you find a char that is not the preceding char of *
 *    These above are two tricky cases.
 *
 *
 *    "aab"
      "c*a*b"
      should return true
      In this case there is zero match(c) of element preceding *.

      "caab"
      "c*a*b"
      should return true
      In this case there is one match(c) of element preceding *.

      ("abc");
      (".*c");
       should return true
       In this case there is no preceding element. So, we dont have to match b?
       I dont have  a stary for this part yet.

 * Time Complexity: O(n * k * k)
 * Space Complexity:
 * Take Away:
 */

bool regExMatcherUtil(string strText, string strPattern, int si, int pi)
{
    DEBUG_DEBUG(cout << "start index = " << si << " patterIndex = " << pi << " \n");


    if(strText.size() == si)
        return true;

    if( (strText.size() > (si + 1))  && (strPattern[si + 1] == '*'))
    {
        char skipChar;

        if(strPattern[si] == '.')
            skipChar = strPattern[si + 1];
        else
            skipChar = strText[si];

        while(skipChar != strPattern[pi - 1])
        {
            si++;
            if(strText.size() == si)
                return true;
            skipChar = strText[si];
            continue;
        }
        return regExMatcherUtil(strText, strPattern, si, pi + 2);
    }
    else
    {
        if( ((strText[si] == strPattern[pi]) || (strPattern[pi] == '.')) )
        {
            if(((si + 1) == strText.size()) && ((pi + 1) != strPattern.size()))
                return false;
            if(((pi + 1) == strPattern.size()) && ((si + 1) != strText.size()))
                return false;
            return regExMatcherUtil(strText, strPattern, si + 1, pi + 1);
        }
    }

    return false;

}


bool IKSolution::regExMatcher(string strText, string strPattern)
{

    cout << strText << "\n";
    cout << strPattern << "\n";
    return regExMatcherUtil(strText, strPattern, 0, 0);
}


bool IKSolution::KMP(string strText, string strPattern)
{


}



#if 0

//Find the closest pair from two sorted arrays
//Given two sorted arrays and a number x, find the pair whose sum is closest to x and the
//pair has an element from each array.

mergeTwoSortedArrays(vector<int> arr1, vector<int> arr2)
{
    vector<int> finalArray;

    if(arr1[index1] < arr2[index2])
    {
        final[finalIndex] = arra1[index1]
        index1++;
    }
    else
    {
        final[finalIndex] = arra1[index1]
        index2++;

    }
    finalIndex++;

}

findTheRankOfTheElement(aray a, int k)
{
    for(int i = 0)
    {

    }

    index = i;
    val = a[index];

    for(i = 0; i < size; i++)
    {

       if(a[i] < val)
       {
          swap(a[i], a[index]);
          i++;
       }
       else
       {
          swap(a[size-1],a[index]);
       }

    }




}

/* Build the pivot logic*/
int functionToPlace(vector<int> a)
{
    index = 0;
    val = a[index];

    for(i = 0; i < size; i++)
    {

         if(a[i] < val)
         {
             swap(a[i], a[index]);
             i++;
         }
         else
         {
             swap(a[size-1],a[index]);
         }

    }
}

void quickSort(vector<int> a)
{



}


void quickSort(vector<int> a)
{
    int elementToPick = 0;
    quickSort(a, elementToPick);
}






























Longest Palindrome
Start from middle and then keep expanding onto left and right.
Substrings in descending order of length.

int index = 0;
for(auto it : str)
{
    index++;
    cout << it;
    length = str.size() - index;
}

//Expanding frm middle
int m = (low + high)/2
nl = middle;
nh = middle + 1;

while(low < high)
{

}

for(int i = 0; )
{
    //Check if the string is a palindrome
}



set<char> table
string str;

//Substring that controls the set
for(int i = 0; i < str.size(); i++)
{
    for(int j = i; j < str.size() -1 ; j++
    {
        string s((str.begin + i), (str.end() + j));
        for(auto it : s)
        {
            table.insert(it)

        }

        /*if new set == controlled set then true*/
        else
           return false;
    }

}


#endif
