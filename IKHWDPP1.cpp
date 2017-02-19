/*
 * IKHWDPP1.cpp


 *
 *  Created on: Feb 18, 2017
 *      Author: raghav
 */
#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


/*
 * Contract:
 *
 *      Return the min no steps from a string's given index to dest.
 *
 *      I replace/delete/insert.
 *      I ask my right index to give the mini
 *
 *      Take the min returned by all my subordinates and return th
 *
 *
 * */
int editDistanceUtil(string& str1, int index, string& dest)
{
    /*
     * If leaf:
     *    Try matching the string with dest
     *    If the dest and src match, return depth.
     * At an index,
     * If it already has a character, try replacing it with all chars.
     *    Request the next index to perform the same.
     * Else
     *     for characters a to z:
     *         insert a character
     *         Request the next index to perform the same.
     *         delete a character.
     *         Request the next index to perform the same.
     *
     * Return the min of all values returned by all recursive cases.
     * Add one to the distance before returning.
     */
    if(index >= str1.size())
    {
        DEBUG_TRACE(cout << "Hit the base case \n";)
        return -1;
    }

    int d3 = 1;
    int dist = 1;
    int d = 1;
    int maxD = 1;

    DEBUG_DEBUG(cout << "Index = " << index << " After replace str = " << str1 << " \n";)

    char temp = str1[index];
    //Replace the char at index
    for(int i = 0; i < 26; i++)
    {

        //if( ('a' + i) != temp)
        //{
            str1[index] = 'a' + i;
            DEBUG_TRACE(cout << "Index = " << index << " After replace str = " << str1 << " \n";)
            if(str1 == dest)
            {
                DEBUG_DEBUG(cout << "Index = " << index << " After replace str = " << str1 << " \n";)
                DEBUG_DEBUG(cout << " SRC = DEST \n";)
                return 0;
            }
            else
            {
                dist = editDistanceUtil(str1, (index + 1), dest);
                if(dist != -1)
                {
                    cout << "incrementing distance \n";
                    dist = dist + 1;
                    cout << "dist = " << dist << " \n";
                    maxD = dist > maxD ? dist : maxD;
                }
            }

        //}

    }
    str1[index] = temp;

#if 0
    //Delete the char at index
    str1.erase(str1.begin() + index);
    dist = editDistanceUtil(str1, (index + 1), dest);
    str1.insert(str1.begin() + index, temp);
    maxD = dist > maxD ? dist : maxD;


    //Insert to a location next to the char
    for(int i = 0; i < 26; i++)
    {
        str1.insert(str1.begin() + index + 1, 'a' + i);
        if(str1 == dest)
            return d3;
        else
        {
            dist = editDistanceUtil(str1, (index + 2), dest);
            str1.erase(str1.begin() + index);
            maxD = dist > maxD ? dist : maxD;

        }
    }
#endif


    return maxD;

}

/* Problem:
 * Example:
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


/* Problem:
 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Take Away:
 */
vector<string>IKSolution::wordBreak(string strWord, vector < string > strDict)
{
    vector<string> vs;

    return vs;
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

