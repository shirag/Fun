/*
 * IKHWDPP1.cpp


 *
 *  Created on: Feb 18, 2017
 *      Author: raghav
 */
#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"

int min(int a, int b)
{
    return (a < b ? a : b);
}


#if 0
bool giveMeAllCombinationStrings(string str, int index, vector<string>& vs, string& dest)
{


    if(index < str.size())
    {
        DEBUG_TRACE(cout << "Trying to replace at index : " << index << " \n");
        char temp = str[index];
        for(int i = 0; i < 26; i++)
        {
            str[index] = 'a' + i;
            if(str[index] != dest[index])
                continue;
            vs.push_back(str);
        }
        str[index] = temp;

        str.erase(str.begin() + index);
        if(str.size() == dest.size())
        {
            vs.push_back(str);
        }
        str.insert(str.begin() + index, temp);

    }

    DEBUG_TRACE(cout << "About to insert at index : " << index << " \n");
    for(int i = 0; i < 26; i++)
    {
        if(!((str.size() + 1) <= dest.size() ))
        {
            continue;

        }
        if(index < str.size())
        {
            str.insert(str.begin() + index + 1, ('a' + i));

            if(str[index + 1] != dest[index + 1])
            {
                str.erase(str.begin() + index + 1);
                continue;
            }

            vs.push_back(str);
            str.erase(str.begin() + index + 1);
        }
        else
        {
            str.push_back('a' + i);
            if(str[index + 1] != dest[index + 1])
            {
                str.erase(str.end()-1);
                continue;
            }
            vs.push_back(str);
            str.erase(str.end()-1);
        }
    }
    return true;
}

int editDistanceUtil(string& src, string& dest, int index, map<string,int>& memo)
{

    int minChanges = INT_MAX;
    vector<string> combos;

    if(src == dest)
    {
        DEBUG_TRACE(cout << "index = " << index << "Base case \n");
        return 0;
    }

    if(index > src.size() || (index > dest.size()))
    {
        return minChanges;
    }

    giveMeAllCombinationStrings(src, index, combos, dest);
    for(auto it : combos)
    {
        DEBUG_DEBUG(cout << "count " << countt << " index:" << index << " src is " << src << " next string = " << it << " \n");
        countt++;
        int changes = 0;
        int offset = 0;

        if(it.size() >= src.size())//replace/insert
            offset = 1;
        changes = editDistanceUtil(it, dest, index + offset, memo);
        if(changes != INT_MAX)
        {
            DEBUG_TRACE(cout << "index:" << index << " src is " << src << " next string = " << it << " \n");
            if(it != src)
                changes++;
            minChanges = changes < minChanges ? changes : minChanges;
        }
    }

    return minChanges;

}
#endif


int editDistanceUtil(string s1, string s2, map<pair<string,string>,int>& minDest)
{
    DEBUG_DEBUG(cout << "len1 = " << s1.size() << " len2  = " << s2.size() << " \n");

    auto it = minDest.find(make_pair(s1,s2));
    if(it != minDest.end())
        return it->second;

    if(s1.size()  == 0)
        return s2.size();

    if(s2.size()  == 0)
        return s1.size();

    if(s1[0] == s2[0])
    {
        string ns1 =  string(s1.begin() + 1, s1.end());
        string ns2 =  string(s2.begin() + 1, s2.end());
        return editDistanceUtil(ns1, ns2, minDest);
    }

    int insertChars = INT_MAX;
    int deleteChars = INT_MAX;
    int replaceChars = INT_MAX;

    {   //Insert a char at the src[0] beginning and assume it matches the content of the corresponding dest location.
        string ns1 =  string(s1.begin(), s1.end());
        string ns2 =  string(s2.begin() + 1, s2.end());
        insertChars = editDistanceUtil(ns1, ns2, minDest);
    }

    {
        //Assume that inserted char at dest[0] matches the current src index string and move on.
        string ns1 =  string(s1.begin() + 1, s1.end());
        string ns2 =  string(s2.begin(), s2.end());
        deleteChars = editDistanceUtil(ns1, ns2, minDest);
    }

    {
        string ns1 =  string(s1.begin() + 1, s1.end()); cout << " ns1 = " << ns1 << "\n";
        string ns2 =  string(s2.begin() + 1, s2.end()); cout << " ns2 = " << ns2 << "\n";

        replaceChars = editDistanceUtil(ns1, ns2, minDest);
        DEBUG_DEBUG(cout << " replaceChars = " << replaceChars << " \n");
    }

    int minVal = min(min(insertChars, deleteChars), replaceChars);
    DEBUG_TRACE(cout << " minVal = " << minVal << " \n");

    minDest.insert( make_pair(make_pair(s1,s2), (minVal + 1)) );
    return minDest[make_pair(s1,s2)];

}
/* Problem:
 *    Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of
 *    edits (operations) required to convert ‘str1’ into ‘str2’. YOu have following three operations allowed
      Insert, Remove, and Replace

 * Example:
      Input:   str1 = "sunday", str2 = "saturday"
      Output:  3

 * Approach:
 *    We have to find the distance between two srings.
 *    Memoization: For any source and destination string pair, give me the distance.
 *    https://en.wikipedia.org/wiki/Levenshtein_distance
 *
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 * 1. In my initial approach, I had tried to actually place strings at different locations and find out the
 *    distance. Actually, this is not needed. You can calculate it without actually generating combinations.
 * 2. I tried passing in the index instead of passing in the length. In this case also solution is
 *    very confusing.
 * 3. Key to the solution is to understand that we insert/delete at index 0 and not 1.
 *
 */
int IKSolution::editDistance(string strWord1, string strWord2)
{
    map<pair<string,string>, int> minDest;
    return editDistanceUtil(strWord1, strWord2, minDest);
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
        DEBUG_TRACE(cout << "cache Read:sindex: " << sindex << " \n");
        return it->second;
    }

    if(sindex == strWord.size())
    {
        DEBUG_TRACE(cout << "Base case " << " \n");
        fr.push_back(strWord); //Trick here to differentiate between base case and a case where strings from an index
                               //don't return valid words. Somewhat similar to stairs problem.
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
int count1 = 0; // Just to see how many times the recursive function is called.
vector<int> makeChangeUtil(int C, vector <int>& intDenominations, int& currSum, map<int, vector<int>>& cache)
{
    vector<int> minBt;
    bool minBtInit = false;

    auto it = cache.find(currSum);
    if(it != cache.end())
    {
        return it->second;;
    }
    if(currSum == C)
    {
        minBt.push_back(0); // dummy value to differentiate between valid and invalid results
        return minBt;
    }

    DEBUG_DEBUG(cout << "count = " << count1++ << " \n");

    vector<int> bt;
    for(auto it : intDenominations)
    {
        DEBUG_TRACE(cout << " currSum = " << currSum << " Added denomination: " << it << " \n");
        currSum += it;

        if(currSum <= C)
        {
            bt = makeChangeUtil(C, intDenominations, currSum, cache);
            DEBUG_TRACE(cout << "currSum = " << currSum << " Added denomination: " << it << " returned true \n");
            if( (bt.size() >= 1) &&  (minBtInit == false) )
            {
                bt.push_back(it);
                minBt = bt;
                minBtInit = true;
            }
            else if( (bt.size() >= 1) && (((bt.size() + 1) < minBt.size())))
            {
                bt.push_back(it);
                minBt = bt;
            }
        }

        currSum -= it;

    }

    cache.insert(make_pair(currSum,minBt));
    return cache[currSum];
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
    count1 = 0;
    int currSum = 0;
    vector<int> minDenom;
    map<int,vector<int>> cache;
    minDenom = makeChangeUtil(C, intDenominations, currSum,  cache);
    if(minDenom.size())
        minDenom.erase(minDenom.begin());
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

int maxWinUtil(vector<int>& intCoins, int startIndex, int endIndex, map<pair<int, int>, int>& memo)
{

    auto it = memo.find(make_pair(startIndex, endIndex));
    if(it != memo.end())
    {
        return it->second;
    }


    if(endIndex == startIndex + 1)
    {
        return (intCoins[endIndex] > intCoins[startIndex] ? intCoins[endIndex] : intCoins[startIndex]);
    }

    if(endIndex == startIndex)
    {
        return intCoins[startIndex];
    }

    int a = maxWinUtil(intCoins, startIndex + 2, endIndex, memo); // player 2's first choice
    int b = maxWinUtil(intCoins, startIndex + 1, endIndex - 1, memo); //// player 2's second choice
    int myMaxIfIselectFirstIndex = intCoins[startIndex] + min(a, b);

    a = maxWinUtil(intCoins, startIndex + 1, endIndex - 1, memo);
    b = maxWinUtil(intCoins, startIndex, endIndex -2, memo);
    int myMaxIfIselectLastIndex = intCoins[endIndex] + min(a, b);

    int myMaxForSure =  (myMaxIfIselectFirstIndex > myMaxIfIselectLastIndex ? myMaxIfIselectFirstIndex : myMaxIfIselectLastIndex);

    memo.insert(make_pair(make_pair(startIndex, endIndex), myMaxForSure));
    return memo[make_pair(startIndex, endIndex)];

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
    map<pair<int, int>, int> memo;

    return maxWinUtil(intCoins, beginIndex,  endIndex, memo);

#if 0
    int val1 = maxWinUtil(intCoins, 0, beginIndex + 1, endIndex);
    val1 = val1 + intCoins[0];

    int val2 = maxWinUtil(intCoins, endIndex, beginIndex, endIndex - 1);
    val2 = val2 + intCoins[endIndex];

    cout << "val1 = " << val1 << " \n";
    cout << "val2 = " << val2 << " \n";


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
                maxForAllNeighbours = val;
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
 *     After all the computaton I return the max value.
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

/***************************************************************************************/

int maxProductFromCutPiecesUtil(int ropelength, int currentLength, map<int,int>& memo)
{

    auto it = memo.find(currentLength);
    if( it != memo.end())
        return it->second;

    int maxProduct = INT_MIN;
    if((ropelength == currentLength) || (ropelength == 2)) //Please note: Additional exit condition(min rope length).
        return 1;


    for(int i = 1; i <= ropelength; i++)
    {
        if((currentLength + i) > ropelength)
            break;
        int currProduct = maxProductFromCutPiecesUtil(ropelength, currentLength + i, memo);
        if(currProduct > INT_MIN)
            if((currProduct * i) > maxProduct)
                maxProduct = currProduct * i;

    }

    memo.insert(make_pair(currentLength, maxProduct));
    return memo[currentLength];

}

/* Problem:
 *     Rope cutting problem. Get the max product you can get from various lengths.
 *
 * Example:
 *
 * Approach:
 *
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
int IKSolution::maxProductFromCutPieces(int ropelength)
{
    map<int,int> memo;
    int currentLen = 0;
    return maxProductFromCutPiecesUtil(ropelength, currentLen, memo);
}


/******************************************************************************************************************************/

int totalNoOfRows = 0;
int totalNoOfColumns = 0;

vector<pair<int,int>> numberOfPathsFromHere(vector<vector<int>> a,  int currRow, int currCol)
{
    vector<pair<int,int>> res;

    int nextRow = currRow + 1;
    int nextCol = currCol + 1;

    if((nextRow < totalNoOfRows) && (nextCol < totalNoOfColumns))
    {
        if(a[nextRow][nextCol])
        {
            res.push_back(make_pair(nextRow, nextCol));
        }
    }
    return res;
}

int numberOfPathsUtil(vector<vector<int>>& a, int currRow, int currCol)
{

    DEBUG_TRACE(cout << "currentStair = " << currentStair << "\n");
    if( (currRow == (totalNoOfRows - 1)) && (currCol == (totalNoOfColumns - 1)))
        return 1;

    int numOfPaths = 0;
    auto choices = numberOfPathsFromHere(a, currRow, currCol);
    for(auto it : choices)
    {
        int paths = numberOfPathsUtil(a, it.first, it.second);
        if(paths != 0)
            numOfPaths++;
    }

    return numOfPaths;
}

//This is totally untested code.
//DP timed test problem. No of paths in a matrix, Please look at snap shots for explanation of the probelm
int IKSolution::numberOfPaths(vector<vector<int>> a)
{
    int currRow = 0;
    int currColumn = 0;
    totalNoOfRows = 2;
    totalNoOfColumns = 3;
    return numberOfPathsUtil(a, currRow, currColumn);
}
/******************************************************************************************************************************/
