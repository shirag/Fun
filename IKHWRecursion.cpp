/*
 *


 * IKHWRecursion.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: Raghav Navada
 */
#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"



vector<string> permuteUtil(string& arr, unsigned int index)
{
    vector<string> res;

    if(index == arr.size())
    {
        DEBUG_DEBUG(cout << "We have a new permutation to print: ");
        string s(arr.begin(),arr.end());
        DEBUG_DEBUG(cout << s << "\n");
        res.push_back(arr);
        return res;
    }

    for(unsigned int i = index; i < arr.size(); i++)
    {
        swap(arr[index],arr[i]);
        vector<string> res1 = permuteUtil(arr, (index + 1));
        res.insert(res.end(),res1.begin(), res1.end());
        swap(arr[index],arr[i]);
    }

    return res;

}
/* Problem: Generate all permutations.
 * Approach: This is a very simple in-place place algorithm
 *          // Generate an array with values 1, 2, 3, 4 and then swap all values.
 *          // Every time swap the contents of a particular index with another index value.
            // After you are done generating all permutation, you swap back
            // i.e you swap 0 index value with 0th index value, then 0 index value with 1st index value and so on.
            // Contract: Ill give you an index and then an input string. You give all permutations.
            // My job: If its base case,return. Else Ill place all values in that index.
            // Delegation: Ill request my subordinate to do the same for the next index.
 * Time Complexity:
 *          T(n) = n*T(n-1) + O(n) [This is ignoring the print and each swap operation takes O(1)
            If G(n) = T(n)/n! we get
            G(n) = G(n-1) + O(1/(n-1)!)
            which gives G(n) = Theta(1).
            Thus T(n) = O(n!).
            Assuming that the print happens exactly n! times, we get the time complexity as
            O(n * n!)
 * Space Complexity: O(1)

 *
 * */
vector<string> IKSolution::generateAllPermutations(string s)
{
    return permuteUtil(s, 0);
}

/****************************************************************************************************/

bool canIKeepAQueenAtThisLocation(char mycR, int myC, char newcR, int newC)
{
    int myR = mycR - '0';
    int newR = newcR - '0';

    DEBUG_DEBUG(cout<< "myR = " << myR << " myC = " << myC << " newR = " << newR << " newC = " << newC << "\n");


    if((newR == myR) && (newC == myC))
        return true;

    if((newR == (myR + 1)) && (newC == (myC + 1)))
        return false;

    if((newR == (myR + 1)) && (newC == myC))
        return false;

    if((newR == myR) && (newC == (myC + 1)))
        return false;


    if((newR == (myR - 1)) && (newC == (myC - 1)))
        return false;

    if((newR == (myR - 1)) && (newC == myC))
        return false;

    if((newR == myR) && (newC == (myC - 1)))
        return false;

    if((newR == (myR + 1)) && (newC == (myC - 1)))
        return false;

    if((newR == (myR - 1)) && (newC == myC + 1))
        return false;

    if(abs(newR - myR) == abs(newC - myC))
        return false;

    if(abs(myR - newR) == abs(myC - newC))
        return false;

    return true;

}
/*Ill give you an index. You tell me if its OK to place queen */
void NQueensUtil(vector<char>& arr, unsigned int index, long& count)
{
    if(index == arr.size())
    {
        for(unsigned int i = 0; i < (arr.size()-1); i++)
            for(unsigned int j = i + 1; j < (arr.size()); j++)
                if(canIKeepAQueenAtThisLocation(arr[i],i,arr[j],j) == false)
                    return;
        count++;
        DEBUG_DEBUG(cout << "We have a new permutation to print: ");
        string s(arr.begin(),arr.end());
        DEBUG_DEBUG(cout << s << "\n");
        return;
    }

    //Every time swap the contents of a particular index with another index value.
    for(unsigned int i = index; i < arr.size(); i++)
    {
        DEBUG_DEBUG(cout << "column = " << index << " row = " << arr[index] << " ");
        swap(arr[index],arr[i]); //array[index] --> rows , index --> column
        NQueensUtil(arr, (index + 1), count);
        swap(arr[index], arr[i]);
    }

    return;

}

/* Problem: N-Queens
        Solve the N-Queens problem using recursion. (There may be other ways of solving this
            problem, but for the purpose of this exercise, please use recursion only).
        Problem statement: Place N queens on a NxN chessboard, such that no two queens are in
        line of attack of each other.

        Input N:
        Output: All possible arrangements of N queens on the board. Each arrangement can be
        represented by a matrix. Print the entire matrix, one per valid arrangement.
        For example,
        There exist two distinct solutions to the 4-queens puzzle:
        [
         [".Q..",  // Solution 1
          "...Q",
          "Q...",
          "..Q."],

         ["..Q.",  // Solution 2
          "Q...",
          "...Q",
          ".Q.."]
        ]
    Approach:
        We have location/index --> columns and
                        values --> rows
        Approach is at all locations you have to place all values and find out if there is a valid permutation.
    Time Complexity:
    Space Complexity:
*/
long IKSolution::NQueens(int n)
{
    vector<char> arr;
    long count = 0;

    for(int i = 0; i < n; i++)
    {
        arr.push_back(i + '0');
    }

    NQueensUtil(arr, 0, count);
    DEBUG_DEBUG(cout << "count = " << count << "\n");
    return count;

}
/****************************************************************************************/
void giveMeAllSubStringsfromIndex(int sindex, string& strInput, vector<string>&res, vector<string>& fr)
{

    if(sindex == strInput.size())
    {
        int j;
        //Check if all strings in the decomposition are palindromes.
        for(j = 0; j < res.size(); j++)
        {
            if (res[j] != string(res[j].rbegin(), res[j].rend()))
                break;
        }
        //Format return values.
        if( j == res.size())
        {
            string s;
            DEBUG_DEBUG(cout << "\n All string in the following decomposition are palindromes \n");
            for(int k = 0; k < res.size(); k++)
            {
                s.append(res[k]);
                s.append("|");
                DEBUG_DEBUG(cout << " " << res[k]);
            }
            fr.push_back(s);
            DEBUG_DEBUG(cout << "\n");

        }
        return;
    }

    for(int i = 0; i < (strInput.size()); i++ )
    {
        if((sindex + i) < (strInput.size()))
        {
            string s(strInput.c_str() + sindex, i + 1 );
            res.push_back(s);
            giveMeAllSubStringsfromIndex(sindex + i + 1, strInput, res, fr); //request the next guy to provide with all palindrome.
            res.pop_back();
        }
        if(sindex == 0)
        {
            res.clear();
        }
     }

     return;
}

/*
 * Problem:
     * Palindromic Decomposition
       A "Palindrome Decomposition" of string S, is a decomposition of the string into
       substrings, such that all those substrings are valid palindromes. A single character is
       considered a valid palindrome for this problem. Print out all possible palindromic
       decompositions of a given string.

       e.g.
       Input: abracadabra

       Ouput:
        "a|b|r|a|c|a|d|a|b|r|a|",
        "a|b|r|a|c|ada|b|r|a|",
        "a|b|r|aca|d|a|b|r|a|"
   Approach:
       Im going to create two substrings. One with one chars, Another with all chars onto the right of that one char.
 *     Ask my subordinate to repeat the same process.
 *     Im going to create two substrings. One with two chars, Another with all chars onto the right of those two chars.
 *     Ask my subordinate to repeat the same process.
 *     Repeat the above process for all chars in the string.
   Time Complexity:
   Space Complexity:

*/
vector<string> IKSolution::palindromicDecomposition(string strInput)
{
    vector<string> res;
    int index = 0;
    vector <string> fr;

    /* Form the string */
    giveMeAllSubStringsfromIndex(index, strInput, res, fr);

    return fr;
}

/***************************************************************************************************************/

int provideSubSetsRec(vector<int>& ip, int index, int size, si& tempset, ssi& subs)
{
    if(index == size)
    {
        for(auto it = tempset.begin(); it != tempset.end(); it++)
        {
            DEBUG_DEBUG(cout << *it << ", ");
        }

        DEBUG_DEBUG(cout << "\n");
        subs.insert(tempset);
        return 0;
    }

    tempset.insert(ip[index]);
    provideSubSetsRec(ip, (index + 1), size, tempset, subs);
    tempset.erase(ip[index]);
    provideSubSetsRec(ip, (index + 1), size, tempset, subs);

    return 0;
}

/* Problem:
 *      Print out all the subsets of a set.
 * Example:
       {x,y} => {{}, {x},{y}, {x,y}}
       [Remember, that we are working with sets, so {y,x} is not different from {x,y}, and {x,x} is not a valid subset,
       unless the input also has two x's]
       {1,2,3} => {{}, {1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}}

       Input: Set, as an array
       Output: Subsets in any order.
 *
 * Approach:
 *
 *
 *         In the below shown pic nodes represent the index values passed to the recursive function
 *         and edges represent the action performed inside the recursive function. This is a execution tree.
 *         For every index, we add a value corresponding to the index to the set, generate all combinations, and then
 *         remove it from the set and generate all combinations again.
 *
 *
                                  4 Base case(1234)
                                  /
                           Add 4 /
 *                              / Remove 4
 *                             3-----------4 Base case(123)
 *                            /
 *                           /                  4 Base case(124)
                      Add 3 /            Add 4 /
 *                         /  Remove 3        / Remove 4
 *                        2------------------3 -----------4(12)Base case
                         /
                        /                 4 Base case(134)
                       /          Add 4 /
                      /                / Remove 4              Base case(14)
                     /                3------4 Base case(13)  4
              Add 2 /                /                       /
                   /           Add 3/                Add 4  /
                  / Remove 2       /  Remove 3             /  Remove 4
                 1----------------2 ----------------------3-----------(1)  Base case print
                /
               /                4 Base(234)
              /          Add 4 /
             /                /  Remove 4                                     4 Base(34)
     Add 1  /                3------- 4 Base(23)       4 Base(24)            /
           /          Add 3 /                   Add 4 /               Add 4 /
          /                /      Remove 3           / Remove 4            / Remove 4
         /                2-------------------------3-------- Base(2)     3-----------4 Base(3)      4 Base(4)
        /         Add 2  /                                         Add 3 /                    Add 4 /
       /                /                                               /                          /
      /    Remove 1    /               Remove 2                        /              Remove 3    /   Remove 4
      0 ---------------1----------------------------------------------2--------------------------3--------------4Base()
 *
 *
 * Complexity: O(2 pow n) ==> look at recurence solutions.
 * Space Complexity: O(n)
 * Any other better approach:
 *     * si& tempset can be replaced with bit array which is more compact.
 *     * Inside a for loop generate all combinations.
 *
 * Corner case:
 * Take away:
 */

ssi IKSolution::provideSubSets(vector<int> ip)
{
    ssi subs;
    si tempset;

    int index = 0;
    provideSubSetsRec(ip, index, ip.size(), tempset, subs);

    return subs;

}


/*******************************************************************************************************/

int getVal(int a, int b, char oper)
{
    int result;

    DEBUG_DEBUG(cout << "\n EXPR: " << a << oper << b << " \n") ;

    switch(oper)
    {
        case '+':
            result = a + b;
            break;
        case '*':
            result = a * b;
            break;
        case 'C':
            string s1 = to_string(a);
            string s2 = to_string(b);
            string s3(s1+s2);
            result = stoi(s3);
            break;
    }
    DEBUG_DEBUG(cout << "result = " << result << "\n");
    return result;
}
/* We have a complete expression. Time to calculate the value  */
int valueCalculator(vector<char>& tempS, map<char,int>& prec)
{
    stack<int> vs;
    stack<char> ops;
    int val = 0;
    int i = 0;
    int res;

    DEBUG_DEBUG(cout << "complete string is ready: " << " size = " << tempS.size() << " ");
    for(i = 0; i < tempS.size(); i++)
    {
        DEBUG_DEBUG(cout << i << " " << tempS[i]);
        if( (tempS[i] == '+') || (tempS[i] == '*') || (tempS[i] == 'C'))
        {
            //Equal precedence or lower precedence than the top of the operator stack, time to compute.
            while( (!ops.empty()) && (prec[tempS[i]] <= prec[ops.top()]) )
            {
                res = vs.top();
                vs.pop();
                res = getVal(res, vs.top(), ops.top());
                vs.pop();
                ops.pop();
                vs.push(res);
            }
            ops.push(tempS[i]);
        }
        else
        {
            string s;s.push_back(tempS[i]);
            int val = stoi(s);
            DEBUG_DEBUG(cout << "val = " << val << " ");
            vs.push(val);
        }
    }

    while( !ops.empty() )
    {
        DEBUG_DEBUG(cout << "\n done proc \n");
        res = vs.top();
        vs.pop();
        res = getVal(res, vs.top(), ops.top());
        vs.pop();
        ops.pop();
        vs.push(res);
    }

    if(!vs.empty())
        res = vs.top();

    return res;
}

void eERecur(string&strDigits, int iK, int index, vector<char>& tempS,vector<char>&ops, vector<string>&final, map<char,int>& prec)
{
    if(index >= ((strDigits.size() * 2) - 1)) //Base case. We are done placing operators in between all nos.
    {
        int res = valueCalculator(tempS,prec);
        if(res == iK)
        {
            DEBUG_DEBUG(cout << "result found \n");

            string s(tempS.begin(),tempS.end());
            auto it = s.find('C');
            while(it != string::npos) //Erase all Cs. I used C to indicate concatenation.
            {
                 s.erase(s.begin() + it);
                 it = s.find('C');
            }
            s.append("=");
            s.append(to_string(iK));
            DEBUG_DEBUG(cout << "\n About to push: "<< s << "\n");
            final.push_back(s);
        }
        return;
    }

    //Insert all operators at a particular index. Call the recursion on the next guy to do the same
    for(int i = 0; i < ops.size(); i++)
    {
        tempS[index] = ops[i];
        DEBUG_DEBUG(cout << "tempS[" << index << "] = "  << tempS[index] << " ") ;
        eERecur(strDigits, iK, (index + 2), tempS, ops,final,prec);
    }

    DEBUG_DEBUG(cout << "\n");

    return;

}

/*
 * Problem:
 *    Expression Evaluator
      Given a string of integers as input, put between each pair of digits, one of {"", "*",
      "+"} such that the expression you get will evaluate to K (a number also given as
      input). Putting an empty string ("") between two numbers means, that the numbers
      are joined to form a new number (e.g. 1""2=12)

      Order of integers given as input needs to remain the same.

      Input:
      1. String of positive integers
      2. Target K (given constant)

      Output:
      All possible strings that evaluate to K

      e.g.
      If the input string is "222", and your target (K) Is "24", two possible answers are:

      1. 22+2 (Here, we put the "" operator in between first two 2s and then put a plus
         between the last two)
      2. 2+22 (Here, we put the plus operator between two 2s and the put the "" operator
         between the last two)

      Realize that precedence of the operator matters. In higher to lower precedence:
      1. Join("")
      2. Multiplication(*)
      3. Addition(+)

               Print    Print  Print      Print   Print  Print         Print   Print   Print
              2        2      2           2      2       2            2       2        2
             /        /      /           /      /       /            /        /        /
           +/       x/    ""/          +/     x/     ""/           +/       x/      ""/
            \       /      /           /      /       /            /        /        /
              2---------------        2----------------           2-----------------
               \                     /                           /
              + \                  x/                         ""/
                 \                 /                           /
                  \               /                           /
                   \             /                           /
                    2----------------------------------------


*  Approach:
*  1. In the case of 222 - Create and array like this. 2 x 2 y 2 where field x and y are initially empty.
*  2. Generate all combination of operators in the position of x and y recursively.
*  3. Once you have the entire string, try to evaluate the expression and see if matches the dest value.
*  4. If it matches, append the string to the final vector which returns all results.
*  5. Very similar to the generate all subsets problem.
*
*  Complexity:
*  Space Complexity:
*  Any other better approach:
*     Can be solved using the bit array technique too. This will use a for loop and generate all permutations
*/

vector<string> IKSolution::expressionEvaluator(string strDigits, int iK)
{
    vector<string> final;
    int index = 0;
    vector<char> tempS((strDigits.size()*2)-1);
    vector<char> operators = {'+','*','C'};

    /* Map of precedences */
    map<char,int> prec;
    prec.insert(make_pair('+',10));
    prec.insert(make_pair('*',20));
    prec.insert(make_pair('C',30));

    /*Generate the string wit spaces in between numbers. We can insert operators in those spaces in between */
    for(int i = 0; i < strDigits.size(); i++)
    {
        char c = strDigits[i];
        tempS[i*2] = c;
        DEBUG_DEBUG(cout << "tempS[" << i*2 << "] = "  << tempS[i*2] << " ") ;
    }

    eERecur(strDigits, iK, index + 1, tempS, operators, final,prec);
    return final;
}
/****************************************************************************************************************/


/* Contract: You ask the function: How many trees you can form given N(eg 3) nodes
 * My work: I find what all ways this can be split?
 *          I  find that 2 can be on right OR
 *                       2 can be on left  OR
 *                       1 on right and one on left.
 *
 * Delegation: I ask my subordinate for all these combinations, how many tree you can form?
 * Post Processing: ?
 * */
/********************************************************************************************/
int howManyTreesUtil(int n)
{
    int result = 0;
    if(n == 1)
       return 1;

    for(int i = 0; i < n; i++)
    {
        int res1 = howManyTreesUtil(i); // no of nodes on my left
        int res2 = howManyTreesUtil(n-1-i); //no of nodes on my right

        if(res1 && res2)
            result += (res1 * res2);
        else if(res1)
            result += (res1);
        else if(res2)
            result += (res2);
     }

    return result;
}


/*
 *  Problem:
        5. How many trees with 'n' nodes
        Write a function that will return the number of binary trees that can be constructed, with 'n' nodes.

        e.g.
        for, n=1 => 1 possible tree (just root)
        for, n=2 => 2 possible trees (1. root->right 2. root->left)
        for, n=3 => 5 possible trees (1. root->right->right 2. root->right->left 3. root->left->left 4. root->left->right 5. root->left,right)

    Approach:
    Time Complexity:
    Space Complexity:
*/

//given you have n number of nodes.
int IKSolution::howManyTrees(int n)
{
    int result = howManyTreesUtil(n);
    DEBUG_DEBUG(cout << "For " << n << " nodes we have " << result << " no of trees\n");
    return result;
}

/********************************************************************************************/


bool sumOfIntegersUtil(vector<int>& iArr, int& iTarget, int index, set<int>& s)
{
    if(index == iArr.size())
    {
        int sum = 0;
        for(auto it = s.begin(); it != s.end(); it++)
        {
            sum += (*it);
            cout << "sum = " << sum << "\n";
            if(sum == iTarget)
            {
                return true;
            }
        }
        return false;
    }

    s.insert(iArr[index]);
    bool res = sumOfIntegersUtil(iArr, iTarget, (index + 1), s);

    if(res == false)
    {
        s.erase(iArr[index]);
        res = sumOfIntegersUtil(iArr, iTarget, (index + 1), s);
    }

    return res;

}

/*
 * Problem: Find a subset where the sum matches to the specified value.
 *
 * Approach: Exactly similar the generate subset problem except that we come out when
 *           we encounter the target value.
 *           In the below shown pic nodes represent the index values passed to the recursive function
 *           and edges represent the action performed inside the recursive function. This is a execution tree.
 *           For every index, we add a value corresponding to the index to the set, generate all combinations, and then
 *           remove it from the set and generate all combinations again.
 *
 *
                                  4 Base case(1234)
                                  /
                           Add 4 /
 *                              / Remove 4
 *                             3-----------4 Base case(123)
 *                            /
 *                           /                  4 Base case(124)
                      Add 3 /            Add 4 /
 *                         /  Remove 3        / Remove 4
 *                        2------------------3 -----------4(12)Base case
                         /
                        /                 4 Base case(134)
                       /          Add 4 /
                      /                / Remove 4              Base case(14)
                     /                3------4 Base case(13)  4
              Add 2 /                /                       /
                   /           Add 3/                Add 4  /
                  / Remove 2       /  Remove 3             /  Remove 4
                 1----------------2 ----------------------3-----------(1)  Base case print
                /
               /                4 Base(234)
              /          Add 4 /
             /                /  Remove 4                                     4 Base(34)
     Add 1  /                3------- 4 Base(23)       4 Base(24)            /
           /          Add 3 /                   Add 4 /               Add 4 /
          /                /      Remove 3           / Remove 4            / Remove 4
         /                2-------------------------3-------- Base(2)     3-----------4 Base(3)      4 Base(4)
        /         Add 2  /                                         Add 3 /                    Add 4 /
       /                /                                               /                          /
      /    Remove 1    /               Remove 2                        /              Remove 3    /   Remove 4
      0 ---------------1----------------------------------------------2--------------------------3--------------4Base()
 *
 *  Complexity:
              O(2 pow n) ==> look at recurrence solutions.
              You cant improve on this as you have to generate all combinations
 * Space Complexity:
 * Any other better approach:
 *     * si& tempset can be replaced with bit array which is more compact.
 *     * Inside a for loop generate all combinations.
*  Space Complexity:
*  Any other better approach:
*/
bool IKSolution::sumOfIntegers(vector<int> IntArr, int iTarget)
{
    cout << "target is " <<  iTarget << "\n" ;
    int index = 0;
    set<int> sumS;
    return sumOfIntegersUtil(IntArr, iTarget, index, sumS);
}




/********************************************************************************************/
void wrapWithOneOutside(string &s)
{
    s.append(")");
    s.insert(0,"(");
}

void addOneNext(string& s)
{
    s.append("()");
}

void addOnePrev(string&  s)
{
    s.insert(0,"()");
}

/********************************************************************************************/
/* Problem:
 *
 * The task is to write a function Brackets(int n) that prints all combinations of well-formed brackets
 * from 1...n. For Brackets(3) the output would be

   ()
   (())  ()()
   ((()))  (()())  (())()  ()(())  ()()()

   Approach:

 *    Contract: Given the no of pairs, give me all combinations.
 *    Base case: When there is no more pairs left just return;
 *    Delegation: I ask the next pair to provide all its combinations. For all the combinations
      provided by the next pair, I add one outside, one next and one previous.

      Looks like this solution is not working properly. I would have to look into other solutions.

 */
vector<string> giveMeAllCombos(int pairNo, int& count)
{
    vector<string> ret;
    int count1 = 0;

    if(pairNo == 1)
    {
        string s;
        wrapWithOneOutside(s);
        ret.push_back(s);
        cout << s << "\n";
        count++;
        return ret;
    }



    vector<string> result = giveMeAllCombos((pairNo - 1), count);
    for(auto it : result)
    {
        string s = it;
        wrapWithOneOutside(s);
        ret.push_back(s);
        count1++;


        s = it;
        addOneNext(s);
        ret.push_back(s);
        string prev = s;
        count1++;

        s = it;
        addOnePrev(s);
        if(prev != s)
        {
            count1++;
            ret.push_back(s);
        }


    }
    count = count1;
    for(auto i : ret)
        cout << i << "\n";


    return ret;
}


/* print all combinations of well formed brackets*/
int IKSolution::wellFormedBrackComb(int n)
{
    vector<string> res;
    int count = 0;

    int m = n;

    giveMeAllCombos(m, count);
    cout << "overall count = " << count << "\n";
    return count;
}

/********************************************************************************************/
