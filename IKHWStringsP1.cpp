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
 * Problem: Try tp find
 * Approach:

   Brute force if O(n * n * k)
   O(n * k * k) solution: If the part of a string is palindrome, then you have to reverse the non palindrome part and find a match.
   If the no part of the string is a palindrome, then you have to reverse the entire string and see if there is a match.

   If a string is palindrome, then if you add strings as its wings(left & right), then there is a chance
   that you will generate a new palindrome again.
   If a string is NOT a palindrome, then if you add strings as its wings(left and rigth), then there is NO chance that you
   will generate a new palindrome again.

   TBD: Try solving using Trie.
   1. Create a try of reverse of all strings
   2. Now walk in tandem one pointer pointing to the original string and the other pointer pointing to the trie.
   3. Now when you find a match in trie, you have confirm whether rest of the original string is a palindrome.
   4. Complexity is O(n * k * k)
   5. Now if you use Mancher's algorithm after this, you will be able to reduce it to O(n * k)

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
/***************************************************************************************************************************************************/

bool regExMatcherUtil(string strText, string strPattern, int ti, int pi,  map<pair<int,int>,bool>& memo)
{
    DEBUG_TRACE(cout << "text length " << strText.size() << " text index = " << ti << " Pattern size " << strPattern.size()  << " patterIndex = " << pi << " \n");
    bool result = false;

    auto res = memo.find(make_pair(ti, pi));
    if(res != memo.end())
    {
        return res->second;
    }


    if(strPattern.size() == pi) //Process all chars in pattern
    {
        if(strText.size() == ti)
            return true;
        else
            return false;
    }

    /* If the next character of pattern is ‘*’, then we do a brute force exhaustive matching of 0, 1, or more
     * repeats of current character of pattern until we could not match any more characters. */
    if(strPattern[pi + 1] == '*') //If the second char in the pattern is equal to *
    {
        DEBUG_TRACE(cout << "About to process * \n");
        while(
               (ti < strText.size()) &&
               ((strPattern[pi] == strText[ti]) || (strPattern[pi] == '.'))
             )
        {
            DEBUG_TRACE(cout << "skipping char " <<  strPattern[pi] << " \n");

            if(regExMatcherUtil(strText, strPattern, ti, pi + 2, memo) == true)
            {
                result = true;
                break;
            }
            ti++;
        }
        result = regExMatcherUtil(strText, strPattern, ti, pi + 2, memo);
    }
    else
    {
        /* If the next character of pattern is NOT ‘*’, then it must match the current character of text.
         * Continue pattern matching with the next character of both text and pattern */
        DEBUG_TRACE(cout << "Non * char \n");
        if(
             (ti < strText.size()) &&
             ((strPattern[pi] == strText[ti]) || (strPattern[pi] == '.'))
          )
        {
            assert(ti < strText.size());
            result = regExMatcherUtil(strText, strPattern, ti + 1, pi + 1, memo);
        }
    }

    DEBUG_DEBUG(cout << " text index = " << ti  << " patterIndex = " << pi << " result = " << result <<  " \n");
    memo.insert(make_pair(make_pair(ti, pi),result));
    return memo[make_pair(ti, pi)];


    return result;
}

/*
 * Problem:
 *    Regular expression matching.
 * Approach:
 *    Greedy approach does not work - that is you process the character just in front of you.
 *    Non greedy approach is processing the char beyond the one in front of you. That would be the *
 *
 *    Check the second char. If its a * then you have to skip all chars in the source until you find a char that is not the preceding char of *
 *    These above are two tricky cases.
 *     http://articles.leetcode.com/regular-expression-matching/
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
       Why the regex pattern “.*” matches the string “ab”. “.*” means repeat the preceding element 0 or more times.
       Here, the “preceding” element is the dot character in the pattern, which can match any characters.
       Therefore, the regex pattern “.*” allows the dot to be repeated any number of times, which matches any string (even an empty string).

       ["ab"]
       [abc*]
       should return true

       [abc]
       [abcd]
       should return false

       ["abc"];
       ["a*abc"];
       should return true.
       Here we compare we compare text's first a with pattern's first a and then pass in the entire abc of text and abc of pattern to the recursive call.
       If returns true we return true. We return the overall result as true.

       ["aabc"];
       ["a*abc"];
       should return true.
       Here we compare we compare text's first a with pattern's first a and then pass in the entire aabc of text and abc of pattern to the recursive call.
       It returns false. Then we pass in abc of text and abc of pattern to the recursive call. That returns true. Then we return overall result as true.
       Using this example you can find out the repetitive sub problems.

       Basically if you see a preceding char and * in pattern, you cannot skip all the matching chars in text and continue the search. This is a greedy approach.
       You should first see at the index if the entire text matches the pattern(starting next to *). If it fails, then only you should try skipping chars in text.
       This is where memoization comes into picture. We use memoization here to store the results of repeated subproblems in the case of *.

       Memoization is useful in the case of non-greedy approaches.

 * Time Complexity: O(n * k * k)
 * Space Complexity:
 * Take Away:
 * Optimization:
 *     1. Start from the end and try greedy.
 *     2. Build a autometa.
 */
bool IKSolution::regExMatcher(string strText, string strPattern)
{
    map<pair<int,int>,bool> memo;

    cout << strText << "\n";
    cout << strPattern << "\n";
    return regExMatcherUtil(strText, strPattern, 0, 0, memo);
}
/************************************************************************************/

void LongestProperSuffixTable(string p, vector<int>& lps)
{

    lps.push_back(0);
    for(int i = 1; i < p.size(); i++)
    {
        string s = p.substr(0, (i + 1));
        DEBUG_TRACE(cout << " substring is " << s << "\n" );
        unsigned int maxLength = 0;
        for(int j = 0; j < s.size(); j++)
        {
            string prefix = s.substr(0, j + 1);
            string suffix = s.substr((s.size() - 1 - j), j + 1);
            if((prefix != s) && ((suffix != s)) && (prefix == suffix))
            {
                DEBUG_TRACE(cout << " prefix is " << prefix << "\n" );
                DEBUG_TRACE(cout << " suffix is " << suffix << "\n" );
                maxLength =  prefix.size() > maxLength ? prefix.size() : maxLength;
            }
            DEBUG_TRACE(cout << " maxLength is " << maxLength << "\n" );
        }
        lps.push_back(maxLength);
    }
}

bool KMPMain(string strText, string strPattern, vector<int> lps)
{

    int sindex = 0;
    int pindex = 0;

    while(sindex < strText.size())
    {
        if((pindex != strPattern.size()) && strText[sindex] == strPattern[pindex])
        {
            sindex++; pindex++;
            DEBUG_DEBUG(cout << "Match at " << sindex << " \n");
            continue;
        }

        if(pindex == strPattern.size())
        {
            DEBUG_DEBUG(cout << "Pattern found at index " << sindex << " \n");
            pindex = lps[pindex - 1];
            return true; //You dont do this if you want to continue looking for pattern match.
        }
        else
        {
            DEBUG_DEBUG(cout << "Mismatch at " << sindex << " \n");
            if(pindex != 0)
                pindex = lps[pindex - 1]; //For every mismatch after the first char in pattern lookup the table how much to skip in the next case.
            else //case where was no match at all
                sindex = sindex + 1;
        }
    }

    return false;
}

/*
 * http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
 * 1. Form the table for pattern that indicates the length of string where max prefix is equal to max suffix.
 * 2. Keep going over the string looking for pattern. When it does not match set the index pattern string from the table.
 * 3.
 */

bool IKSolution::KMP(string strText, string strPattern)
{
    vector<int> lps;

    DEBUG_DEBUG(cout << "strText is " << strText << " strPattern is " << strPattern << " \n");

    LongestProperSuffixTable(strPattern, lps);

    DEBUG_DEBUG(cout << "Table is: " );
    for(auto it : lps)
    {
        DEBUG_DEBUG(cout << it << " " );
    }
    DEBUG_DEBUG(cout << "\n");

    strText.push_back('$'); // Dummy val. This way in cases where the entire string itself matches the pattern we dont have to have additional
                             // logic below the main loop to process it.
    return KMPMain(strText, strPattern, lps);


}

/****************************************************************************************************************/

/*
 *    Problem:
 *    For "nailed" you have to generate following strings:
 *    "n4d" "n3ed" "na3d" "n2led" "na2ed" "nai2d"
 *
 *    Approach:
 *    At each level, you have to generate all prefixes.
 */

void NeuronymsUtil(string s, int count)
{
    if(count <= 1)
       return;

    for(int i = 0; i <= (s.size() - 2 - count); i++)
    {
        string preFix = s.substr(0,1) + s.substr(1, i);
        string suffix = s.substr(i + count + 1);
        string neur = preFix + to_string(count) + suffix;
        DEBUG_DEBUG(cout << "Next Neuronym is " << neur << " \n");
    }

    NeuronymsUtil(s, count - 1);

}

void IKSolution::Neuronyms(string s)
{

    int count = s.size() - 2;
    NeuronymsUtil(s, count);

}
/****************************************************************************************************************/

/*
 *    Problem: Print matrix in a spiral order.
 *    Approach: Its a pure index manipulation problem.
 *
 */
string IKSolution::printSpirally(vector<vector<char>> matrix)
{
    string ret;

    int no_of_rows = matrix.size();
    cout << "no_of_rows " << no_of_rows << " \n";

    int no_of_columns = matrix[0].size();
    cout << "no_of_columns " << no_of_columns << " \n";

    int current_first_row = 0;
    int current_first_column = 0;
    int current_last_column = no_of_columns - 1;
    int current_last_row = no_of_rows - 1;

    while((current_first_column <= current_last_column) && (current_first_row <= current_last_row))
    {
        DEBUG_DEBUG(cout << "Next main iteration \n");
        for(int i = current_first_column; i <= current_last_column; i++)
        {
            DEBUG_TRACE(cout << "Next main iteration1 \n");
            ret.push_back(matrix[current_first_row][i]);
        }

        for(int i = (current_first_row + 1); i <= current_last_row; i++)
        {
            DEBUG_TRACE(cout << "Next main iteration2 \n");
            ret.push_back(matrix[i][current_last_column]);
        }

        for(int i = (current_last_column - 1); i >= current_first_column; i--)
        {
            DEBUG_TRACE(cout << "Next main iteration3 \n");
            if(current_last_row != current_first_row) //First for loop takes care of this.
            {
                ret.push_back(matrix[current_last_row][i]);
            }
        }

        for(int i = (current_last_row - 1); i > current_first_row; i--)
        {
            DEBUG_TRACE(cout << "Next main iteration4 \n");
            if(current_last_column != current_first_column) //Second for loop takes care of this.
            {
                ret.push_back(matrix[i][current_first_column]);
            }

        }

        current_first_row++;
        current_first_column++;
        current_last_column--;
        current_last_row--;

    }

    return ret;
}

/* Problem:
*  Move all letters to one side of the string and all numbers should be on other side of the string.
*  Approach:
*  Have two pointers. 1. To current processing char(index1).
*                     2. To the last alphabet value(index2).
*  Every time you come across a alphabet(index1) swap the alphabet with contents of index2.
 */

string IKSolution::moveAllLettersToLeftSide(string s)
{

    int lastAlpaIndex = -1;
    int currIndex = 0;
    char *ptr = (char *)s.c_str();
    cout << s << "\n";

    for(int i = 0 ; i < s.size(); i++)
    {
        if( (ptr[currIndex] >= 97) && (ptr[currIndex] <= 122) ) //alpha
        {
            char temp = ptr[currIndex];
            ptr[currIndex] = ptr[lastAlpaIndex + 1];
            ptr[lastAlpaIndex + 1] = temp;;
            lastAlpaIndex = lastAlpaIndex + 1;
        }

        currIndex++;
    }

    cout << s << "\n";
    return s;

}
