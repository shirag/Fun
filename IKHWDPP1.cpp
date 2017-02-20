/*
 * IKHWDPP1.cpp


 *
 *  Created on: Feb 18, 2017
 *      Author: raghav
 */
#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


/*
 *
 * I replace/delete/insert at an index. I ask my right index to give the min.
 * Take the min returned by all my subordinates and return the val.
 *
 * At an index,
 *    If leaf:
 *       Try matching the string with dest. If the dest and src match, return 0.
 *       Else return -1, indicating we could not reach the dest after all combinations.
 *
      Replacing it with all chars(a to z).
 *    Request the subordinate to use the string provided and next index and provide the min no steps.
 *
 *    Delete the char at the index.
 *    Request the subordinate to use the string provided and next index and provide the min no steps.
 *
 *    Insert a char at the  next index.
 *    Request the subordinate to use the string provided and next index and provide the min no steps.
 *
 *    Return the min of all values returned by all recursive cases.
 *    Add one to the distance before returning.
 *
 */
int editDistanceUtil(string& str1, int index, string& dest)
{
    int dist = -1;
    int minD = -1;

    if(index >= str1.size())
    {
        if(str1 == dest)
        {
            DEBUG_DEBUG(cout << "Index = " << index << " After replace str = " << str1 << " \n";)
            return 0;
        }
        else
        {

            DEBUG_DEBUG(cout << "Base case: Index = " << index << " After replace str = " << str1 << " \n";)
            return -1;
        }
    }


    //Replace the char at index
    char temp = str1[index];
    for(int i = 0; i < 26; i++)
    {
        str1[index] = 'a' + i;
        if(str1[index] != dest[index])
        {
            continue;

        }
        dist = editDistanceUtil(str1, (index + 1), dest);
        if(dist != -1)
        {
            if( ('a' + i) != temp)
            {
                dist = dist + 1;
            }
            minD = dist;
        }
    }
    str1[index] = temp;

    //Delete the char at index
    str1.erase(str1.begin() + index);
    if(str1[index] == dest[index])
    {
        dist = editDistanceUtil(str1, (index + 1), dest);
        if(dist != -1)
        {
            DEBUG_TRACE(cout << "incrementing distance \n");
            dist = dist + 1;
            if(minD != -1)
                minD = dist < minD ? dist : minD;
            else
                minD = dist;

        }
    }
    str1.insert(str1.begin() + index, temp);

    //Insert to a location next to the char
    for(int i = 0; i < 26; i++)
    {
        str1.insert(str1.begin() + index + 1, ('a' + i));
        if(str1[index] != dest[index])
        {
           str1.erase(str1.begin() + index + 1);
           continue;
        }
        dist = editDistanceUtil(str1, (index + 2), dest);
        if(dist != -1)
        {
            dist = dist + 1;
            if(minD != -1)
                minD = dist < minD ? dist : minD;
            else
                minD = dist;
        }
        str1.erase(str1.begin() + index + 1);
    }


    return minD;

}

/* Problem:
 *    Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of
 *    edits (operations) required to convert ‘str1’ into ‘str2’. YOu have following three operations allowed
      Insert, Remove, and Replace

 * Example:
 *    Input:   str1 = "geek", str2 = "gesek"
      Output:  1
      We can convert str1 into str2 by inserting a 's'.
      Input:   str1 = "cat", str2 = "cut"
      Output:  1
      We can convert str1 into str2 by replacing 'a' with 'u'.
      Input:   str1 = "sunday", str2 = "saturday"
      Output:  3

 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int IKSolution::editDistance(string strWord1, string strWord2)
{

    int index = 0;
    return editDistanceUtil(strWord1, index, strWord2);
}

/**************************************************************************************************/

bool dictLookUp(vector<string>&res, vector<string>& fr, set<string>& strDict)
{

    int j;

    //Check if all strings in the decomposition are palindromes.
    for(j = 0; j < res.size(); j++)
    {
        if(strDict.find(res[j]) == strDict.end())
        {
            return false;
        }
    }

    //Format return values.
    if( j == res.size())
    {
        DEBUG_DEBUG(cout << "\n All string in the following decomposition are found in dictionary \n");
        for(int k = 0; k < res.size(); k++)
        {
            fr.push_back(res[k]);
            DEBUG_DEBUG(cout << " " << res[k]);
        }

        DEBUG_DEBUG(cout << "\n");

    }
    return true;
}

void giveMeAllSStringsfromIndex(int sindex, string& strInput, vector<string>&res, vector<string>& fr, set<string>& dict)
{

    if(sindex == strInput.size())
    {
        dictLookUp(res,fr,dict);
        return;
    }

    for(int i = 0; i < (strInput.size()); i++ )
    {
        if((sindex + i) < (strInput.size()))
        {
            string s(strInput.c_str() + sindex, i + 1 );
            res.push_back(s);
            giveMeAllSStringsfromIndex(sindex + i + 1, strInput, res, fr, dict);
            res.pop_back();
        }
        if(sindex == 0)
        {
            res.clear();
        }
     }

     return;
}

/* Problem:
 * Example:
 * Approach:
       Exactly similar to palindromic decomposition
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
vector<string>IKSolution::wordBreak(string strWord, vector<string> strDict)
{

    vector<string> res;
    int index = 0;
    vector <string> fr;
    set<string> dict;

    for(auto it : strDict)
    {
        dict.insert(it);
    }

    /* Form the string */
    giveMeAllSStringsfromIndex(index, strWord, res, fr, dict);


    return fr;
}

/* Problem:
 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
void IKSolution::makeChange(int C, vector < int > intDenominations)
{
    return;
}

/* Problem:
 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int IKSolution::maxWin(vector < int > intCoins)
{

    return 0;

}

/* Problem:
 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int IKSolution::numPhoneNumbers(int startdigit, int phonenumberlength)
{
    return 0;
}

/* Problem:
 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int IKSolution::numWaysToClimb(vector < int > numSteps, int numStairs)
{

    return 0;

}
/* Problem:
 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int maxStolenValue(vector<int> arrHouseValues)
{
    return 0;
}

