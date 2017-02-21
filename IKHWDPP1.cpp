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

    if(str1 == dest)
    {
        //DEBUG_DEBUG(cout << "Index = " << index << " str = " << str1 << " \n";)
        return 0;
    }

    if( (abs(dest.size() - str1.size()) != 1) ||  (dest.size() == str1.size()) )
    {
    }
    else
    {
        return -1;
    }

    ////if(index >= str1.size())
    //if((index >= str1.size()) && (index >= dest.size()))
    //{

      //  else
       // {
            //DEBUG_DEBUG(cout << "Base case: Index = " << index << " str = " << str1 << " \n";)
          //  return -1;
        //}
    //}

    //DEBUG_DEBUG(cout << "Index = " << index << " str = " << str1 << " \n";)

    //Replace the char at index
    if(index < str1.size())
    {
        char temp = str1[index];
        for(int i = 0; i < 26; i++)
        {
            str1[index] = 'a' + i;
            if(str1[index] != dest[index])
            {
                continue;

            }
            DEBUG_DEBUG(cout << "Replace: Index = " << index << " str1  " << str1 << "  \n";);
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
            DEBUG_DEBUG(cout << "Delete: Index = " << index << " str1  " << str1  << " \n";);
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
    }

#if 1
    if(index < str1.size())
    {
        cout << "About to insert AT " << (index + 1)  << " \n";
        //Insert to a location next to the char
        for(int i = 0; i < 26; i++)
        {
            str1.insert(str1.begin() + index + 1, ('a' + i));
            if(str1[index + 1] != dest[index + 1])
            {
                str1.erase(str1.begin() + index + 1);
                continue;
            }
            DEBUG_DEBUG(cout << "Insert: Index = " << index + 1 << " str1  " << str1  << " \n";);
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
    }
#endif


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

/*********************************************************************************************************************************/
/* Give me a vector of all mins */
bool makeChangeUtil(int C, vector <int>& intDenominations, int& currSum, vector<int>& minDenom, map<int, vector<int>>& cache)
{
    int minChange = -1;
    vector<int> minBt;

#if ENABLE_DP
    auto it = cache.find(currSum);
    if(it != cache.end())
    {
        minDenom = it->second;
        return true;
    }
#endif

    if(currSum == C)
        return true;

    if(currSum > C)
        return false;


    vector<int> bt;
    for(auto it : intDenominations)
    {
        DEBUG_TRACE(cout << "currSum = " << currSum << " Added denomination: " << it << " \n");
        currSum += it;

        if(makeChangeUtil(C, intDenominations, currSum, bt, cache) == true)
        {
            DEBUG_TRACE(cout << "currSum = " << currSum << " Added denomination: " << it << " returned true \n");
            if(minChange == -1 || (bt.size() < minChange))
            {
                minChange = bt.size();
                bt.push_back(it);
                minBt = bt;
            }
        }

        bt.clear();
        currSum -= it;
    }
    if(minChange == -1)
        return false;

#if ENABLE_DP
    cache.insert(make_pair(currSum,minBt));
    minDenom = cache[currSum];
    return true;
#endif

    minDenom = minBt;
    return true;

}


/* Problem:
 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
vector<int> IKSolution::makeChange(int C, vector <int> intDenominations)
{
    int currSum = 0;
    vector<int> minDenom;
    map<int,vector<int>> cache;
    makeChangeUtil(C, intDenominations, currSum, minDenom, cache);
    return minDenom;
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
/***********************************************************************************************************/

vector<vector<int>> lupt = {
                        {4, 6},    //0
                        {6, 8},    //1
                        {9, 7},    //2
                        {4, 8},    //3
                        {3, 9, 0}, //4
                        {},        //5
                        {1,7,0},   //6
                        {6, 2},    //7
                        {1, 3},    //8
                        {2, 4},    //9
                      };

vector<int> getNextKnightLocation(int startdigit)
{
    return lupt[startdigit];
}

#define ENABLE_DP 1


int numPhoneNumbersUtil(int startdigit, int& phonenumberlength, int currCount, map< pair<int,int>,int>& memT)
{
    int noOfCombs = 0;
    if(startdigit == 1 && currCount == 7)
    DEBUG_DEBUG(cout << "Starting digit: " << startdigit << " currCount " << currCount << " \n");

#if ENABLE_DP
    auto it = memT.find(make_pair(startdigit,currCount));
    if(it != memT.end())
    {
        DEBUG_DEBUG(cout << "cache Read: Starting digit: " << startdigit << " currCount " << currCount << " \n");
        noOfCombs = it->second;
        return noOfCombs;
    }
#endif

    vector<int> enddigits;
    if(currCount == phonenumberlength)
    {
        DEBUG_TRACE(cout << "Base Case: \n");
        return 1;
    }

    enddigits = getNextKnightLocation(startdigit);
    for(auto it : enddigits)
    {
        noOfCombs += numPhoneNumbersUtil(it, phonenumberlength, currCount + 1, memT);
        DEBUG_TRACE(cout << " noOfCombos = " << noOfCombs <<  " \n");
    }

#if ENABLE_DP
    DEBUG_TRACE(cout << "Cache Write: Starting digit: " << startdigit << " currCount " << currCount << " \n");
    memT.insert(make_pair(make_pair(startdigit,currCount), noOfCombs));
    return memT[make_pair(startdigit,currCount)];
#endif

    return noOfCombs;

}


/* Problem: Knight's tour
 * Example:
 * Approach:
 *     Recursive call contract:
 *     Starting at startdigit, tell me how may ways phonenumberlength no can be formed? I have already collect currCount digits  until now.
       startdigit: Starting digit
       phonenumberlength: No of digits in a valid no.
       currCount: No of collected numbers until now.
       I go over all my neighbours, ank ask the same question. Add all their answers. Report it to my manager.

 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int IKSolution::numPhoneNumbers(int startdigit, int phonenumberlength)
{
    map<pair<int,int>,int> memT;
    int currentCount = 1; //the first digit has already been added
    return  numPhoneNumbersUtil(startdigit, phonenumberlength, currentCount, memT);
}
/******************************************************************************************************************************/

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
/******************************************************************************************************************************/

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

