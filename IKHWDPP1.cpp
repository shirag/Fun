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

bool dictLookUp(vector<string>&res, set<string>& strDict, vector<string>& fr)
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

bool dictLookUpStr(string str, set<string>& strDict)
{
    if(strDict.find(str) == strDict.end())
    {
        DEBUG_TRACE(cout << "Match Not Found " << " \n");
        return false;
    }

    DEBUG_TRACE(cout << "Match Found " << str << " \n");
    return true;
}

/* For the given index and present set of strings, give me all strings that makes a set in which all words end up being a part of
 * dictionary  */
vector<string> giveMeAllSStringsfromIndex(string strWord, set<string>& strDict, int sindex, map<int,vector<string>>& memo)
{

    DEBUG_TRACE(cout << "sindex = " << sindex <<  " \n");
    vector<string> fr;

    auto it = memo.find(sindex);
    if(it != memo.end())
    {
        DEBUG_DEBUG(cout << "cache Read:sindex: " << sindex << " \n");
        return it->second;
    }

    if(sindex == strWord.size())
    {
        DEBUG_TRACE(cout << "Base case " << " \n");
        fr.push_back(strWord); //Hack here to differentiate between base case and a case where strings from an index don't return valid words.
        return fr;
    }

    for(int i = 0; i < (strWord.size()); i++)
    {
        if((sindex + i) < (strWord.size()))
        {
            string s(strWord.c_str() + sindex, i + 1);
            fr = giveMeAllSStringsfromIndex(strWord, strDict, (sindex + i + 1), memo);
            if((fr.size() != 0) && (dictLookUpStr(s, strDict) == true))
            {
                DEBUG_DEBUG(cout << "i = " << sindex << " pushing " << s << " to stack \n");
                fr.push_back(s);
                break;
            }
            else
                fr.clear();
        }
    }

    memo.insert(make_pair(sindex,fr));
    return memo[sindex];

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
    int index = 0;
    set<string> dict;
    map<int, vector<string>> memo;

    for(auto it : strDict)
        dict.insert(it);

    /* Form the string */
    vector<string>fr = giveMeAllSStringsfromIndex(strWord, dict, index, memo);
    if(fr.size())
        fr.erase(fr.begin()); //I have written a dummy in the beginning. Get rid of that.

    return fr;
}

/*********************************************************************************************************************************/
/* Give me a vector of all mins */
bool makeChangeUtil(int C, vector <int>& intDenominations, int& currSum, vector<int>& minDenom, map<int, vector<int>>& cache)
{
    int minChange = -1;
    vector<int> minBt;

#if 1
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

#if 1
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
/***********************************************************************************************************/

int maxWinUtil(vector<int>& intCoins, int p1Index, int beginIndex, int endIndex)
{
    DEBUG_DEBUG(cout << "p1 val = " << intCoins[p1Index] << " beginIndex  = " << beginIndex << " endIndex = " << endIndex << " \n");
    int maxVal = 0;

    if(endIndex <= beginIndex)
    {
        DEBUG_DEBUG(cout << "Base case \n");
        return maxVal;
    }

    int p2SelectIndex = 0;
    if(intCoins[beginIndex] > intCoins[endIndex])
    {
        p2SelectIndex = beginIndex;
        beginIndex = beginIndex + 1;
    }
    else
    {
        p2SelectIndex = endIndex;
        endIndex = endIndex - 1;
    }
    cout << "p2 select Val = " << intCoins[p2SelectIndex] << "\n";

    int p1SeletIndex;
    if(intCoins[beginIndex] > intCoins[endIndex])
    {
        p1SeletIndex = beginIndex;
        beginIndex = beginIndex + 1;
    }
    else
    {
        p1SeletIndex = endIndex;
        endIndex = endIndex - 1;
    }

    //int val = maxWinUtil(intCoins, p1SeletIndex, beginIndex + 1, endIndex - 1);
    int val = maxWinUtil(intCoins, p1SeletIndex, beginIndex, endIndex);
    val += intCoins[p1SeletIndex];

    DEBUG_DEBUG(cout << "Val = " << val << " \n");


    //
    //int val = maxWinUtil(intCoins, beginIndex + 1, endIndex - 1);
    //int valF = val + intCoins[beginIndex];
    //int valL = val + intCoins[endIndex];
    //maxVal = valF > valL ? valF : valL;

    //val = maxWinUtil(intCoins, beginIndex + 2, endIndex);
    //valF = val + intCoins[beginIndex];
    //valL = val + intCoins[endIndex];
    //maxVal = valF > valL ? valF : valL;

    return val;
}


/* Problem: Coin Play
 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int IKSolution::maxWin(vector<int> intCoins)
{

    int beginIndex = 0;
    int endIndex = intCoins.size() - 1;

    int val1 = maxWinUtil(intCoins, 0, beginIndex + 1, endIndex);
    val1 = val1 + intCoins[0];

    int val2 = maxWinUtil(intCoins, endIndex, beginIndex, endIndex - 1);
    val2 = val2 + intCoins[endIndex];

    cout << "val1 = " << val1 << " \n";
    cout << "val2 = " << val2 << " \n";

#if 1
    if(val1 > val2)
    {
        return val1;
    }
    else return val2;
#endif


}
/***********************************************************************************************************/

vector<vector<int>> lupt = { {4, 6}, {6, 8}, {9, 7}, {4, 8}, {3, 9, 0},
                             {},     {1,7,0}, {6, 2}, {1, 3}, {2, 4} };

int numPhoneNumbersUtil(int startdigit, int& phonenumberlength, int currCount, map< pair<int,int>,int>& memT)
{
    int noOfCombs = 0;
    vector<int> enddigits;

    auto it = memT.find(make_pair(startdigit,currCount));
    if(it != memT.end())
    {
        DEBUG_DEBUG(cout << "cache Read: Starting digit: " << startdigit << " currCount " << currCount << " \n");
        noOfCombs = it->second;
        return noOfCombs;
    }


    if(currCount == phonenumberlength)
    {
        DEBUG_TRACE(cout << "Base Case: \n");
        return 1;
    }

    enddigits = lupt[startdigit];
    for(auto it : enddigits)
    {
        noOfCombs += numPhoneNumbersUtil(it, phonenumberlength, currCount + 1, memT);
        DEBUG_TRACE(cout << " noOfCombos = " << noOfCombs <<  " \n");
    }

    DEBUG_TRACE(cout << "Cache Write: Starting digit: " << startdigit << " currCount " << currCount << " \n");
    memT.insert(make_pair(make_pair(startdigit,currCount), noOfCombs));
    return memT[make_pair(startdigit,currCount)];

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

vector<int> getAllStairsFromHere(vector<int>& numSteps,  int& numStairs, int currentStair)
{
    vector<int> res;

    for(auto it : numSteps)
        if(it + currentStair <= numStairs)
            res.push_back(it + currentStair);

    return res;
}

// You ask the stair how many ways you can reach the top if I select you?
// If its the top, then its going to say there is one way to do it.
int numWaysToClimbUtil(vector<int>& numSteps, int& numStairs, int currentStair, map<int,int>& memT)
{

    DEBUG_TRACE(cout << "currentStair = " << currentStair << "\n");

    auto it = memT.find(currentStair);
    if(it != memT.end())
    {
        DEBUG_DEBUG(cout << "cache Read: current stair: " << currentStair << " \n");
        return it->second;
    }

    if(currentStair >= numStairs)
    {
        DEBUG_TRACE(cout << "Base Case: We have reached the last stair \n");
        return 1;
    }

    int numWaysToClimb = 0;
    auto choices = getAllStairsFromHere(numSteps,  numStairs, currentStair);
    for(auto it : choices)
        numWaysToClimb += numWaysToClimbUtil(numSteps, numStairs, it, memT);

    DEBUG_DEBUG(cout << "Cache Write: currentStair " << currentStair << " numWaysToClimb "<< numWaysToClimb << "\n");

    memT.insert(make_pair(currentStair, numWaysToClimb));
    return memT[currentStair];
}


/* Problem:
 * Example:
 * Approach:
 *     You ask a stair how many ways we can go to top?
 *     a. If its not the topmost stair, its going to ask all its neighbors and sum it up and return you the result.
 *     b. If its the topmost  stair its going to say 1.
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int IKSolution::numWaysToClimb(vector<int>numSteps, int numStairs)
{
    map<int,int> memT;
    int currentStair = 0;
    return numWaysToClimbUtil(numSteps, numStairs, currentStair, memT);
}


/******************************************************************************************************************************/
vector<int> getAllHomesYouCanVisitFromHere(int index, vector<int>& arrHouseValues)
{
    vector<int> res;

    for(int i = index + 1; i < arrHouseValues.size(); i++)
    {
        if(i == index + 1)
            continue;
        res.push_back(i);
    }

    return res;
}

int maxStolenValueUtil(vector<int>& arrHouseValues, int index, map<int,int>& memo)
{
    DEBUG_TRACE(cout << "House Index = " << index << " House val = " << arrHouseValues[index] << "\n");
    int maxSum = 0;

    auto it = memo.find(index);
    if(it != memo.end())
    {
        DEBUG_DEBUG(cout << "cache Read: index: " << index << " \n");
        return it->second;
    }

    if(index >= arrHouseValues.size())
    {
        DEBUG_DEBUG(cout << "Base Case \n");
        return 0;
    }

    for(int i = index; i < arrHouseValues.size(); i++)
    {
        int maxForAllNeighbours = 0;
        vector<int> homes = getAllHomesYouCanVisitFromHere(i, arrHouseValues);
        for(auto it : homes)
        {
            int val = maxStolenValueUtil(arrHouseValues, it, memo);
            if(val > maxForAllNeighbours)
            {
                maxForAllNeighbours = val;
            }
        }

        if(maxForAllNeighbours + arrHouseValues[i] > maxSum)
            maxSum = maxForAllNeighbours + arrHouseValues[i];

    }

    DEBUG_DEBUG(cout << "Cache Write: index: " << index << " maxSum " << maxSum << " \n");
    memo.insert(make_pair(index, maxSum));
    return memo[index];

}

/* Problem:
 *     There are n houses built in a line, each of which contains some value in it. A thief is going to steal the
 *     maximal value in these houses, but he cannot steal in two adjacent houses because the owner of a stolen
 *     house will tell his two neighbors on the left and right side. What is the maximal stolen value?
 *
 * Example:
 *     if there are four houses with values {6, 1, 2, 7}, the maximal stolen value is 13 when the first and fourth houses are stolen.
 *
 * Approach:
 *     If I start at a particular house what would be the max return?
 *     for all homes
 *       for all the traversable neighbours
 *       Give me the value.
 *       Ill find the max value and store it.
 *
 *     After all the compuation I return the max value.
 *
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int IKSolution::maxStolenValue(vector<int> arrHouseValues)
{
    map<int,int> memo;
    return maxStolenValueUtil(arrHouseValues, 0, memo);
}






