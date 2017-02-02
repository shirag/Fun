
 /*
  *
  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
   (you may want to display this pattern in a fixed font for better legibility)

  P   A   H   N
  A P L S I I G
  Y   I   R

  And then read line by line: "PAHNAPLSIIGYIR"

  Write the code that will take a string and make this conversion given a number of rows:

  string convert(string text, int nRows);

 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 *
 * For 2-row case. "ABCD", 2 --> "ACBD". The confusion most likely is from the character placement.
 * I would like to extend it a little bit to make ZigZag easy understood.

 The example can be written as follow:

    P.......A........H.......N
    ..A..P....L..S....I...I....G
    ....Y.........I........R

 Therefore, <ABCD, 2> can be arranged as:

    A....C
    ...B....D
*/

#include<iostream>
#include<string>
#include"Solution.h"
#include <new>

using namespace std;


string Solution :: zigZagConvert(string s, int numRows)
{
    //int index = 0;
    string retString;

    cout << " Input string is " << s;
    cout << " numRows = " << numRows << "\n";

    unsigned int index = 0;
    int rowIndex = 0;
    bool goingDown = 1;
    string *tempString;

    if(numRows <= 1)
    {
        return s;
    }

    try
    {
        tempString = new string[numRows];
    }
    catch(bad_alloc &ba)
    {
        cerr << "Bad allocation caught \n";
    }

    while(index < s.size())
    {
        tempString[rowIndex].push_back(s[index++]);

        if(rowIndex == (numRows-1))
        {
            rowIndex--;
            goingDown = 0;
        }
        else if(rowIndex == 0)
        {
            rowIndex++;
            goingDown = 1;
        }
        else
        {
           if(goingDown == 1)
           {
               rowIndex++;
           }
           else
               rowIndex--;
        }
    }


    for(int i = 0; i < numRows; i++)
    {
        unsigned int j = 0;
        while(j < tempString[i].size())
        {
            retString.push_back(tempString[i][j]);j++;
        }

    }

    //cout << "\n retString val is "<< retString << "\n";
    return retString;
}
