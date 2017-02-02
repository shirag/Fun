/*
Monkei miles * Utility.cpp
 *
 *  Created on: Jan 6, 2017
 *      Author: GouriShivani
 */


#include <string>
#include <string.h>
#include <vector>
#include <map>
#include "IKSolution.hpp"
#include <cstdlib>
#include <iostream>
#include <queue>


using namespace std;

void StairCase(int n)
{
	if(n > 100 || n < 1)
	    return;

	for(int i = 1; i <= n; i++)
	{
	    for(int j = 1; j <= n-i; j++)
	        cout << " ";

		for(int j = 1; j <= i; j++)
		    cout << "#";

		cout <<"\n";
	}

	return;
}


int toRoman(string strRoman)
{
    unsigned index = 0;
	unsigned int size = strRoman.size();
	int curr = 0;
	int prev = -1;

	map<char,int> tbl;

	tbl['I'] = 1;
	tbl['V'] = 5;
	tbl['X'] = 10;
	tbl['L'] = 50;
	tbl['C'] = 100;
	tbl['D'] = 500;
	tbl['M'] = 1000;

    while(index < size)
    {
    	curr = tbl[strRoman[index]];

	    index++;
	    if(prev == -1)
	    {
	        prev = curr;
	        continue;
	    }

	    if(curr > prev)
	        prev = curr - prev;
	    else
	        prev = curr + prev;

	    cout << "prev = " << "prev";

	}

	if(prev > 4999)
	    return 4999;

	return prev;

}

#define  PRE_ORDER   1
#define   IN_OPDER   2
#define POST_ORDER   3

#define ORDER_OF_TRAVERSAL PRE_ORDER
/*
 * A tree BFS implementation using Queue
 */
void IKSolution::treeBFS(Node *root)
{
	queue<Node *> mQ;
	Node* tn;

	if(root == NULL)
		return;

	mQ.push(root);

	while(!mQ.empty())
	{
		tn = mQ.front();
        mQ.pop();

        if(ORDER_OF_TRAVERSAL == PRE_ORDER)
            cout << "Value of the node = " <<  tn->val << "\n";

        if(tn->left)
            mQ.push(tn->left);

        if(ORDER_OF_TRAVERSAL == IN_OPDER)
                   cout << "Value of the node = " <<  tn->val << "\n";

        if(tn->right)
            mQ.push(tn->right);

        if(ORDER_OF_TRAVERSAL == POST_ORDER)
                           cout << "Value of the node = " <<  tn->val << "\n";

	}

}



bool isP(string str)
{

    int l = 0;
    int h = str.length() - 1;

    while (h > l)
        if (str[l++] != str[h--])
           return false;

    return true;
}

/* Problem: Check if the string is rotated it will generate a Palindrome
 * Example:  bbaa
 * Approach: Generate a pointer that splits the strings into two substrings. Concatenate the first substring
 *           to the end of the second and see if its a Palindrome. Repeat the process until you move the pointer
 *           till end of the string.
 * Complexity: O(n^2)
 * Space Complexity: O(n)
 * Any other better approach:
 *           Constant space solution can be produced by doing everything in place
 *           and by two utility functions getLeft() and getRight()
 */
int IKSolution::checkIfPalindromeRotate(string& str)
{

    if(isP(str))
        return true;

    int n = str.length();
    for (int i = 0; i < n-1; i++)
    {
        string str1 = str.substr(i+1, n-i-1);
        string str2 = str.substr(0, i+1);

        if (isP(str1.append(str2)))
            return true;
    }

    return false;

}




#if 0
int readK(char* output);

int readN(char* output, int N)
{
    char *readB;

    int tReadBytes = 0;
    int readBytes = 0;
    static int leftB = 0;

    if(leftB > 0)
        tReadBytes = leftB;

    while(tReadBytes < N)
    {
        readBytes = readK(readB);
        tReadBytes += readBytes;
    }

    if(tReadBytes > N)
    {
        leftB = tReadBytes - N;
        return N;
    }
    else
    {
        return tReadBytes;

    }

    return 0;


}

#endif



/* Merge two arrays*/
// A utility function to merge two sorted arrays into one
vector<int> mergeVector(vector<int> v1, vector<int> v2)
{
    // mergedArr[] is going to contain result
    //int *mergedArr = new int[m + n];
    int i = 0, j = 0;
    int m = v1.size();
    int n = v2.size();
    vector<int> mergedVec;

    // Traverse through both arrays
    while (i < m && j < n)
    {
        // Pick the smaler element and put it in mergedArr
        if (v1[i] < v2[j])
        {
            mergedVec.push_back(v1[i]);
            i++;
        }
        else
        {
            mergedVec.push_back(v2[j]);
            j++;
        }

    }

    // If there are more elements in first array
    while (i < m)
    {
        mergedVec.push_back(v1[i]);
        i++;
    }

    // If there are more elements in second array
    while (j < n)
    {
        mergedVec.push_back(v2[j]);
        j++;
    }

    return mergedVec;
}


Node* createTreeNode(int key)
{
    Node* node = new(Node);
    node->val = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/************************************************************************************************************************************/
/* Its OK to make the tree unbalanced during the process.
 * Function that creates a new and returns its pointer.
 * Each node returns its pointer.
 *  */
Node* IKSolution::bSTTreeInsert(Node *root, int key)
{
    if (root == NULL)
        return createTreeNode(key);

    if(key == root->val)
        return root;

    if(key < root->val)
        root->left = bSTTreeInsert(root->left, key);
    else
        root->right = bSTTreeInsert(root->right, key);

    return root;


}

#if 0
// What is latch in here?
long time()
{
    int count;
    CountDownLatch c;


    c.CountdownLatch(count); //reference


    //Ask master threads to start;
    /* for all threads start threads. t.execute(countDown)*/

    time t1 = time();
    c.await(); //wait for all of then to complete

    //all participants say they are done
    returnTime = currentTime() - t1;


}
#endif


/*
 *
 * Suppose we abstract our file system by a string in the following manner:

 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext

 * The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

 * The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext

* The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty
* second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

* We are interested in finding the longest (number of characters) absolute path to a file within our file system.
* For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length
* is 32 (not including the double quotes).

 */
int longestStringFunction(string& s);



/* Implementation shows how we can use the C++ vector to achieve the functionality of a Stack */
int longestStringFunction(string &input)
{
    int lengthOfPath = 0, currMaxLen = 0;
    unsigned int index = 0;
    unsigned int len = input.length();
    int currLevel = 0, lastLevel = 0;
    unsigned int oldIndex = 0;
    vector<int> vs;

    while(index < len)
    {
        if(input[index] != 0x0A)
        {
            index++;
            continue;
        }

        /*Convert the read char set to C++ string object */
        string readString = string(input.begin() + oldIndex, input.begin() + index);

        //Find if the read string is a file name?
        if(readString.find(".") != string::npos)
        {
            lengthOfPath = (index - oldIndex);
            for( vector<int>::iterator it = vs.begin(); it != vs.end(); it++ )
                lengthOfPath += *it + 1;

            if(lengthOfPath > currMaxLen)
                currMaxLen = lengthOfPath;
        }
        else
            vs.push_back(index - oldIndex); //store the

        currLevel = 0;
        while((input[++index] == 0x09) && (index < len))
            currLevel++;

        if((currLevel <= lastLevel))
            vs.erase(vs.begin() + currLevel,vs.end());

        oldIndex = index; lastLevel = currLevel;

    }

    //This is just a repetition of the above code. I have to find a optimal way of doing this.
    if(index - oldIndex)
    {
        string readString = string(input.begin() + oldIndex, input.begin() + index);
        if(readString.find(".") != string::npos)
        {
            lengthOfPath = index - oldIndex;
            for( vector<int>::iterator it = vs.begin(); it != vs.end(); it++ )
                lengthOfPath += *it + 1;

            if(lengthOfPath > currMaxLen)
                currMaxLen = lengthOfPath;
        }
    }

    return currMaxLen;

}






