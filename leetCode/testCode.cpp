#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include<iostream>
#include<string>
#include<algorithm>
#include"Solution.h"
#include<map>
#include "parseServerLog.hpp"
#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "../IKSolution.hpp"

#include "../Catch.hpp"
using namespace std;


using namespace std;


struct linkedList
{
    int data;  
    char c;
    linkedList *next;
}; 

extern linkedList *detectLoop(linkedList * headOfList);
int addAnEdge(int from, int to);
int printAllGraphEdges();  
int printTheLinkedList(linkedList *head);
linkedList *reverseMyNext(linkedList *prevNode,linkedList *currNode);

linkedList *head;

int addValueToMatrx(unsigned int row,unsigned int column,int value);
map<pair <int, int> , int> myMatrix;

#define NO_OF_VERTEX 6
//linkedList *ptr[NO_OF_VERTEX]; 

int findKthLargestFromTwoVec(vector<int> &v1, vector<int> &v2, int k,int& val);
int getMiddleValue(vector<int> &v,int low,int high);
int findKthLargestRecursive(vector<int> &v1, int low1, int high1, vector<int> &v2, int low2, int high2, int k);
Solution mySolution;


int testZigZagConversion();
int testAddTwoNos();
int understandStringFuncs();
void reverseWordsInAString(string &s);
int findKthLargest(vector<int> vec, int k);
int giveMeNearestMultiple(int x, int y);
LinkedListNode* refactorIntoOddEven(LinkedListNode **head);
vector<int> detectShortestPath(vvi g, int src, int dest);
bool searchUsingDFS(vvi g, int src, int dest);
string findLeastCommonManager(MultiChildTreeNode *root, string name1, string name2);


TEST_CASE( "Find Kth largest using quick select", "Find Kth largest using quick select")
{
    cout << "Find Kth largest using quick select \n";

    vector<int> ip;

    ip = {1, 2, 3, 4, 5};
    REQUIRE(findKthLargest(ip, 1) == 5);
    REQUIRE(findKthLargest(ip, 2) == 4);
    REQUIRE(findKthLargest(ip, 3) == 3);
    REQUIRE(findKthLargest(ip, 4) == 2);
    REQUIRE(findKthLargest(ip, 5) == 1);
    REQUIRE(findKthLargest(ip, 6) == 0);


    ip = {5, 4, 3, 2, 1};
    REQUIRE(findKthLargest(ip, 1) == 5);
    REQUIRE(findKthLargest(ip, 2) == 4);
    REQUIRE(findKthLargest(ip, 3) == 3);
    REQUIRE(findKthLargest(ip, 4) == 2);
    REQUIRE(findKthLargest(ip, 5) == 1);
    REQUIRE(findKthLargest(ip, 6) == 0);


    ip = {1, 5, 3, 4, 2};
    REQUIRE(findKthLargest(ip, 1) == 5);
    REQUIRE(findKthLargest(ip, 2) == 4);
    REQUIRE(findKthLargest(ip, 3) == 3);
    REQUIRE(findKthLargest(ip, 4) == 2);
    REQUIRE(findKthLargest(ip, 5) == 1);
    REQUIRE(findKthLargest(ip, 6) == 0);

    ip = {1, 4, 3, 5, 2};
    REQUIRE(findKthLargest(ip, 1) == 5);
    REQUIRE(findKthLargest(ip, 2) == 4);
    REQUIRE(findKthLargest(ip, 3) == 3);
    REQUIRE(findKthLargest(ip, 4) == 2);
    REQUIRE(findKthLargest(ip, 5) == 1);
    REQUIRE(findKthLargest(ip, 6) == 0);

    ip = {5, 3, 4, 1, 2};
    REQUIRE(findKthLargest(ip, 1) == 5);
    REQUIRE(findKthLargest(ip, 2) == 4);
    REQUIRE(findKthLargest(ip, 3) == 3);
    REQUIRE(findKthLargest(ip, 4) == 2);
    REQUIRE(findKthLargest(ip, 5) == 1);
    REQUIRE(findKthLargest(ip, 6) == 0);

    ip = {1, 3, 4, 5, 2};
    REQUIRE(findKthLargest(ip, 1) == 5);
    REQUIRE(findKthLargest(ip, 2) == 4);
    REQUIRE(findKthLargest(ip, 3) == 3);
    REQUIRE(findKthLargest(ip, 4) == 2);
    REQUIRE(findKthLargest(ip, 5) == 1);
    REQUIRE(findKthLargest(ip, 6) == 0);
    REQUIRE(findKthLargest(ip, 0) == 0);
    REQUIRE(findKthLargest(ip, 7) == 0);

}


TEST_CASE( "Find the nearest multiple: Uber question", "Find the nearest multiple: Uber question")
{
    cout << "Find the nearest multiple: Uber question \n";

    REQUIRE(giveMeNearestMultiple(19, 4) == 20);
    REQUIRE(giveMeNearestMultiple(22, 4) == 24);
    REQUIRE(giveMeNearestMultiple(5, 3) == 6);
    REQUIRE(giveMeNearestMultiple(7, 3) == 6);
    REQUIRE(giveMeNearestMultiple(24, 4) == 24);
    REQUIRE(giveMeNearestMultiple(24, 0) == 0);


}

template <typename T>
const bool Contains( std::vector<T>& Vec, const T& Element )
{
    if (std::find(Vec.begin(), Vec.end(), Element) != Vec.end())
        return true;

    return false;
}

TEST_CASE( "Ip with most \"Not Found\" Error","Ip with most \"Not Found\" Error:")
{
    cout << "Test: Ip with most \"Not Found\" Error \n";

    {
        ifstream in;
        const char *fileName =  "./logFiles/u_ex170418.log";
        vector<string> expectedRes1 = {"10.16.4.10","10.16.4.12"};
        vector<string> expectedRes2 = {"10.16.4.12","10.16.4.10"};
        in.open(fileName);
        if (!in)
            cout << "ERROR: Can't open the file named " << fileName << " \n";

        LogTable log(in);
        vector<string> res = log.getMostNotFoundIPs();

        if(res != expectedRes1 && res != expectedRes2)
            assert(0);
        cout << "File: " << fileName << " \n";
        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";

    }

    {
        ifstream in;
        vector<string> expectedRes = {};
        LogTable log(in);

        vector<string> res = log.getMostNotFoundIPs();
        assert(res == expectedRes);

        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";
    }


    {
        ifstream in;
        const char *fileName =  "dummy.log";
        in.open(fileName);
        if (!in)
            cout << "ERROR: Can't open the file named " << fileName << " \n";

        LogTable log(in);
        vector<string> res = log.getMostNotFoundIPs();
        cout << "File: " << fileName << " \n";
        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";
    }

    {
        ifstream in;
        const char *fileName =  "./logFiles/u_ex1704181.log";
        vector<string> expectedRes = {"10.16.4.14","10.16.4.12","10.16.4.10"};
        in.open(fileName);
        if (!in)
            cout << "ERROR: Can't open the file named " << fileName << " \n";

        LogTable log(in);
        vector<string> res = log.getMostNotFoundIPs();

        if (!Contains(res,expectedRes[0]) || !Contains(res,expectedRes[1]) || !Contains(res,expectedRes[2]))
            assert(0);
        cout << "File: " << fileName << " \n";
        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";
    }


    {
        ifstream in;
        const char *fileName =  "./logFiles/dummy1.log";
        vector<string> expectedRes = {};
        in.open(fileName);
        if (!in)
            cout << "ERROR: Can't open the file named " << fileName << " \n";

        LogTable log(in);
        vector<string> res = log.getMostNotFoundIPs();

        assert(res == expectedRes);
        cout << "File: " << fileName << " \n";
        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";
    }

    {
        ifstream in;
        const char *fileName =  "./logFiles/emptyResult1.log";
        vector<string> expectedRes = {};
        in.open(fileName);
        if (!in)
            cout << "ERROR: Can't open the file named " << fileName << " \n";

        LogTable log(in);
        vector<string> res = log.getMostNotFoundIPs();

        assert(res == expectedRes);
        cout << "File: " << fileName << " \n";
        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";

    }

    {
        ifstream in;
        const char *fileName =  "./logFiles/emptyResult2.log";
        vector<string> expectedRes = {};
        in.open(fileName);
        if (!in)
            cout << "ERROR: Can't open the file named " << fileName << " \n";

        LogTable log(in);
        vector<string> res = log.getMostNotFoundIPs();

        assert(res == expectedRes);
        cout << "File: " << fileName << " \n";
        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";

    }

    {
        ifstream in;
        const char *fileName =  "./logFiles/oneMaxResult1.log";
        vector<string> expectedRes = {"127.0.0.1"};
        in.open(fileName);
        if (!in)
            cout << "ERROR: Can't open the file named " << fileName << " \n";

        LogTable log(in);
        vector<string> res = log.getMostNotFoundIPs();

        assert(res == expectedRes);
        cout << "File: " << fileName << " \n";
        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";

    }

    {
        ifstream in;
        const char *fileName =  "./logFiles/oneMaxResult2.log";
        vector<string> expectedRes = {"127.0.0.1"};
        in.open(fileName);
        if (!in)
            cout << "ERROR: Can't open the file named " << fileName << " \n";

        LogTable log(in);
        vector<string> res = log.getMostNotFoundIPs();

        assert(res == expectedRes);
        cout << "File: " << fileName << " \n";
        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";

    }


    {
        ifstream in;
        const char *fileName =  "./logFiles/threeMaxResults.log";
        vector<string> expectedRes = {"127.0.0.3", "127.0.0.2", "127.0.0.1"};
        in.open(fileName);
        if (!in)
            cout << "ERROR: Can't open the file named " << fileName << " \n";

        LogTable log(in);
        vector<string> res = log.getMostNotFoundIPs();

        if ( !(Contains(res,expectedRes[0]) && Contains(res,expectedRes[1]) &&
             Contains(res,expectedRes[2]) && (res.size() == 3)) )
            assert(0);
        cout << "File: " << fileName << " \n";
        for(auto val : res)
            cout << "Ip with most \"Not Found\" Error: " << val << " \n";
        cout << "*********************************************\n";

    }


}

TEST_CASE( "Refactor into Odd and Even")
{
    cout << "Refactor into Odd and Even \n";

    LinkedListNode node1; LinkedListNode node2; LinkedListNode node3; LinkedListNode node4;
    LinkedListNode node5; LinkedListNode node6; LinkedListNode node7; LinkedListNode node8;

    node1.next = &node2;node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = &node6; node6.next = &node7; node7.next = &node8; node8.next = nullptr;
    node1.val = 3; node2.val = 5; node3.val = 7; node4.val = 57;
    node5.val = 9; node6.val = 11; node7.val = 13; node8.val = 15;

    LinkedListNode *head = &node1;
    LinkedListNode *evenList = refactorIntoOddEven(&head);
    LinkedListNode *current = head;
    cout << "Odd List \n";
    while(current != nullptr)
    {
        cout << "val = " << current->val << " \n";
        current = current->next;
    }
    current = evenList;
    cout << "Even List \n";
    while(current != nullptr)
    {
        cout << "val = " << current->val << " \n";
        current = current->next;
    }


    node1.next = &node2;node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = &node6; node6.next = &node7; node7.next = &node8; node8.next = nullptr;
    node1.val = 2; node2.val = 4; node3.val = 6; node4.val = 8;
    node5.val = 10; node6.val = 12; node7.val = 14; node8.val = 16;

    head = &node1;
    evenList = refactorIntoOddEven(&head);
    current = head;
    cout << "Odd List \n";
    while(current != nullptr)
    {
        cout << "val = " << current->val << " \n";
        current = current->next;
    }
    current = evenList;
    cout << "Even List \n";
    while(current != nullptr)
    {
        cout << "val = " << current->val << " \n";
        current = current->next;
    }


}


TEST_CASE( "Search for a path and detect shortest Path")
{
    cout << "Find if a path exists using DFS";
    cout << "Print Shortest Path\n";


    vvi ip;
    vi temp;
    vector<int> expected;
    vector<int> res;

    temp = {1, 2};ip.push_back(temp); //0
    temp = {0, 3};ip.push_back(temp); //1
    temp = {0};   ip.push_back(temp); //2
    temp = {4, 1};ip.push_back(temp); //3
    temp = {3};   ip.push_back(temp); //4
    temp = {6};   ip.push_back(temp); //5
    temp = {5};   ip.push_back(temp); //6

    res = detectShortestPath(ip, 0, 4);
    expected = {0, 1, 3, 4};
    REQUIRE(res == expected);
    REQUIRE(searchUsingDFS(ip, 0, 4) == true);


    res = detectShortestPath(ip, 3, 0);
    expected = {3, 1, 0};
    REQUIRE(res == expected);
    REQUIRE(searchUsingDFS(ip, 0, 3) == true);

    res = detectShortestPath(ip, 0, 7); //node does not exist
    expected = {};
    REQUIRE(res == expected);
    REQUIRE(searchUsingDFS(ip, 0, 7) == false);

    res = detectShortestPath(ip, 0, 5); //path does not exist
    expected = {};
    REQUIRE(res == expected);
    REQUIRE(searchUsingDFS(ip, 0, 5) == false);

    res = detectShortestPath(ip, 0, 2); //direct path
    expected = {0, 2};
    REQUIRE(res == expected);
    REQUIRE(searchUsingDFS(ip, 0, 2) == true);

    res = detectShortestPath(ip, 0, 3); //direct path
    expected = {0, 1, 3};
    REQUIRE(res == expected);
    REQUIRE(searchUsingDFS(ip, 0, 3) == true);

    ip.clear();

    temp = {1, 2, 8};ip.push_back(temp); //0
    temp = {0, 3, 7};ip.push_back(temp); //1
    temp = {0};   ip.push_back(temp); //2
    temp = {4, 1};ip.push_back(temp); //3
    temp = {3};   ip.push_back(temp); //4
    temp = {6};   ip.push_back(temp); //5
    temp = {5};   ip.push_back(temp); //6
    temp = {1, 8};ip.push_back(temp); //7
    temp = {7};ip.push_back(temp);    //8

    res = detectShortestPath(ip, 0, 8); //direct path
    expected = {0, 8};
    REQUIRE(res == expected);
    REQUIRE(searchUsingDFS(ip, 0, 8) == true);

    res = detectShortestPath(ip, 1, 8); //direct path
    expected = {1, 0, 8};
    REQUIRE(res == expected);
    REQUIRE(searchUsingDFS(ip, 1, 8) == true);
}




TEST_CASE("Find closest manager")
{
    cout << "Find closest manager";



    MultiChildTreeNode root0;
    root0.name = "Steve Jobs";

    MultiChildTreeNode root1;
    root1.name = "Narain";

    MultiChildTreeNode root2;
    root2.name = "Gopal";

    MultiChildTreeNode root3;
    root3.name = "Subbarao";

    MultiChildTreeNode root4;
    root4.name = "Ramesh";
    root4.parent = &root1;

    MultiChildTreeNode root5;
    root5.name = "Naras";

    MultiChildTreeNode root6;
    root6.name = "Krish";

    MultiChildTreeNode root7;
    root7.name = "Raghav";

    MultiChildTreeNode root8;
    root8.name = "Shivani";

    MultiChildTreeNode root9;
    root9.name = "Vish";

    MultiChildTreeNode root10;
    root10.name = "Smi";


    root0.subOrds.push_back(&root1);
    root0.subOrds.push_back(&root2);
    root0.subOrds.push_back(&root3);

    root1.subOrds.push_back(&root4);
    root1.subOrds.push_back(&root5);
    root1.subOrds.push_back(&root6);

    root4.subOrds.push_back(&root7);
    root4.subOrds.push_back(&root8);

    root5.subOrds.push_back(&root9);
    root5.subOrds.push_back(&root10);


    REQUIRE(findLeastCommonManager(&root0, "Narain", "Subbarao") == "Steve Jobs");
    REQUIRE(findLeastCommonManager(&root0, "Hui", "Sameer") == "");
    REQUIRE(findLeastCommonManager(&root0, "Ramesh", "Krish") == "Narain");
    REQUIRE(findLeastCommonManager(&root0, "Raghav", "Krish") == "Narain");
    REQUIRE(findLeastCommonManager(&root0, "Shivani", "Smi") == "Narain");
    REQUIRE(findLeastCommonManager(&root0, "Shi", "Smi") == "");
    REQUIRE(findLeastCommonManager(&root0, "Raghav", "Ramesh") == "Narain");
}

/****************************************************************************************************************************/

/*  Quick select, variation of quick sort.
 *  Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array.
 *  It is given that ll array elements are distinct.
 *  T(n) = T(n-) + O(n)
 *  The worst case time complexity of this method is O(n2), but it works in O(n) on average.
 *  */
int findKthLargestUtil(vector<int>& vec, int low, int high, int k)
{
    if(low > high)
    {
        cout << "Error";
        return 0;
    }

    int pivot = partition(vec, low, high);
    int pvt_distance_from_end = high - pivot;

    if((pvt_distance_from_end + 1) == k)
        return vec[pivot];

    if((pvt_distance_from_end + 1) >  k )
        return findKthLargestUtil(vec, pivot + 1, high, k); //right side of pivot
    else
        return findKthLargestUtil(vec, low, pivot - 1, k - (pvt_distance_from_end + 1));

}


int findKthLargest(vector<int> vec, int k)
{
    if(vec.size() < k)
    {
        cout << "Error: Not enough elements in the array \n";
        return 0;
    }

    //k  = vec.size() - 1 - k + 1;
    return findKthLargestUtil(vec, 0, vec.size() - 1, k);
}

/**********************************************************************************************************/
/*
  Write a function to round x to the nearest multiple of y.
  Examples:
     x = 5, y = 3, answer = 6
     x = 7, y = 3, answer = 6
     TODO: Should handle float, double and should use templates
           Upaload it onto Stackoverlfow sight.
     Approach: Find the distance between last multiplier and x, and x and next multiplier.
               Use the minimum of the two.
  */
int giveMeNearestMultiple(int x,  int y)
{


#if 0
    //This also works great!!!
    int result = 0;
    int i = 1;

    i = x/y;

    int diff1 = abs(x - (i + 1 * y));
    int diff2 = x - (i) * y;

    i = diff1 < diff2 ? i + 1 : i;
    result = (i * y);
#endif

    if (y == 0) return 0;

    int distance_from_last_multiplier = x % y;
    int distance_to_next_multiplier = y - distance_from_last_multiplier;

    return distance_from_last_multiplier < distance_to_next_multiplier ? x - distance_from_last_multiplier : x + distance_to_next_multiplier;
}
/********************************************************************************************************
   Nelson FB: Two sorted arrays and merge one with another. First one has enough space to handle the second one.
   Peter question: The problem was "derive a list of diagonals of an nxm matrix", not too bad
*********************************************************************************************************/
//Take a linked list and refactor into 2 lists, one Even and one Odd, based on values.
//Input: Pointer to pointer to head. Points to the head of the odd list when the function returns.
//Return value: Pointer to new even list.
LinkedListNode* refactorIntoOddEven(LinkedListNode **head)
{
    LinkedListNode *dummyHead = new LinkedListNode;
    dummyHead->next = *head;
    LinkedListNode *prev = dummyHead; //Points to the last odd value or Dummy Head;

    LinkedListNode *newEvenListHead = nullptr;
    LinkedListNode *newEvenListTail = nullptr;

    LinkedListNode *current = *head;

    while(current != nullptr)
    {
        if(!(current->val % 2)) //even
        {
            prev->next = current->next;
            if(newEvenListHead == nullptr)
                newEvenListHead = current;
            else
                newEvenListTail->next = current;

            newEvenListTail = current;
        }
        else
            prev = current;

        current = current->next;
    }

    *head = dummyHead->next;
    if(newEvenListTail != nullptr)
        newEvenListTail->next = nullptr;

    return newEvenListHead;
}

/*******************************************************************************************************************/
vector<int> detectShortestPath(vvi g, int src, int dest)
{
    set<int> vis;
    map<int, int> paths;
    int level = 0;
    vector<int> res;

    cout << "Find shortest path from " << src << " to " << dest << " \n";

    if(dest >= g.size())
    {
        cout << "Error \n";
        return res;
    }
    if(src == dest)
        return res;

    queue<int> mQ;

    mQ.push(src);
    vis.insert(src);
    paths[src] = -1;

    while(!mQ.empty())
    {
        int item = mQ.front();
        mQ.pop();


        if(item == dest)
            break;

        for(auto val : g[item])
        {
            if(vis.find(val) != vis.end())
                continue;
            mQ.push(val);
            vis.insert(val);
            paths[val] = item;
        }
    }


    int temp = dest;
    while(paths.count(temp))
    {
        res.push_back(temp);
        temp = paths[temp];
    }
    res = vector<int>(res.rbegin(), res.rend());

    return res;
}

/*******************************************************************************************************************/
bool searchUsingDFSUtil(vvi g, int src, int dest, set<int>& visited)
{
    if(src == dest)
    {
        cout << "Node found \n";
        return true;
    }

    for(auto val : g[src])
    {
        if(!visited.count(val))
        {
            visited.insert(val);
            bool retVal = searchUsingDFSUtil(g, val, dest,visited);
            if(retVal == true)
                return retVal;

        }

    }
    return false;

}
/*
 * Problem: Using DFS search for the presence of a key node.
 * */
bool searchUsingDFS(vvi g, int src, int dest)
{
    set<int> visited;
    visited.insert(src);
    return searchUsingDFSUtil(g, src, dest, visited);
}

/*********************************************************************************************************/

/*
 * Problem: Detect the common manager. Variation of the LCA problem.
 * Approach: Post order DFS.
 * Complexity: O(n). You have to simple traverse the entire tree.
 * If your child finds the common manager, then simply propagate it up.
 * Otherwise, find if you are the common one.
 * Otherwise, find if child found one and you are the second employee.
 * Otherwise, find if you are one of the employee.
 *
 *
 * */


string findLeastCommonManagerUtil(MultiChildTreeNode *root, string emp1, string emp2, bool& found)
{
    string manager;
    bool found1 = false;
    bool found2 = false;

    if(root == nullptr)
    {
        found = false;
        return manager;
    }

    for(auto val : root->subOrds)
    {
        manager = findLeastCommonManagerUtil(val,emp1, emp2, found);

        if(manager.size() != 0)
            return manager; //If some child finds it simple propagate it up.

        if(found == true){
            if(found1 == false){
                found1 = true;
                continue;
            }
            if(found2 == false)
                found2 = true;
        }
    }
    if(found1 == true && found2 == true) //One child found one and the other found another
        return root->name;

    if(found1 == true || found2 == true){ //One child found one
        found = true;
        if(root->name == emp1 || root->name == emp2) //Other is myself
            return root->parent->name;
        else
            return manager;
    }
    if(root->name == emp1 || root->name == emp2) //Im one of the employees
    {
        found = true;
        return manager;
    }

    found = false;
    return manager;


}

string findLeastCommonManager(MultiChildTreeNode *root, string name1, string name2)
{
   bool found;
   return findLeastCommonManagerUtil(root, name1, name2, found);

}
/*********************************************************************************************************************/
#if 0
int main()
{
    cout << "Hello World!!!\n";



    //testAddTwoNos();

    //testZigZagConversion();

    //understandStringFuncs();

    //int maxLen;

    //string s("rag\n\tflf.txt");
    //maxLen = longestStringFunction(s);

    vi W(10);


    //cout << "\n W.size() " << W.size() <<"\n";
    //cout << " W[0].size() " << W[0].size() <<"\n";
    //cout << " W[1].size() " << W[1].size() <<"\n";

    //cout << "Max lengthVal = " << maxLen;
    vector< pair<int, int> > edges;
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));
    edges.push_back(make_pair(3,4));

    //edges.push_back(make_pair(0,1));
    //edges.push_back(make_pair(0,2));
    //edges.push_back(make_pair(0,3));
    //edges.push_back(make_pair(1,4));
    //edges.push_back(make_pair(1,5));
    //edges.push_back(make_pair(1,6));
    //edges.push_back(make_pair(1,2));
    //edges.push_back(make_pair(2,7));
    //edges.push_back(make_pair(2,8));
    //edges.push_back(make_pair(2,9));
    //edges.push_back(make_pair(3,10));
    //edges.push_back(make_pair(3,11));
    //edges.push_back(make_pair(3,12));


    //int counter = countComponents(13,edges);
    //int counter = countComponents(5,edges);

    //cout << "counter " << counter << "\n";


#if  0
    soln.setVal("raghav", 100);
    soln.setVal("raghav", 200);

    int val = soln.getValue("raghav");
    cout << "Get val = " << val << "\n";

    soln.setVal("shivani", 1000);
    soln.setVal("shourya", 2000);

    val = soln.deleteVal("shivani");
    soln.setVal("lakshmi",5000);


    val = soln.getValue("raghav");
    cout << "Get val = " << val << "\n";

    val = soln.getValue("shourya");
    cout << "Get val = " << val << "\n";

    val = soln.getValue("lakshmi");
    cout << "Get val = " << val << "\n";

    val = soln.getValue("shivani");
    cout << "Get val = " << val << "\n";

    for (int j = 0; j < 1000; j++)
    {
        soln.getRandomVal();
    }
#endif


    cout << "\n\n*********** End of IKMain *******************\n";

    return 0;


    cout << "End of Main";

    return 0;
}
#endif


#if 0
int main (int argc, char *argv[])
{

    map<char, bool> hashtable;
    linkedList *link;

    string myString = "Hello World \n\n";
    cout << myString;

    //addValueToMatrx(2,5,25);
    //addValueToMatrx(2,6,26);
    //addValueToMatrx(2,5,25);
    //addValueToMatrx(2,55,255);
    //addValueToMatrx(25,5,255);
    //addValueToMatrx(25,5,0);
    //addValueToMatrx(0,0,1);

    //int k = 3;
    //vector<int> v2 = {998,999,1000};
    //vector<int> v1 = {97,98,99};

    int k = 8;
    vector<int> v1 = {1107,1108,1109,1110,1111};
    vector<int> v2 = {997,998,999,1000,1001};

    //int k = 7;
    //vector<int> v1 = {1,2,3,4,14,15,16};
    //vector<int> v2 = {11,12,13,16,17,18,19};

    //vector<int> v1 = {1,2,3,4,100};
    //vector<int> v2 = {5,7,8,9,10};

    int high1 = v1.size()-1; 
    int high2 = v2.size()-1; 

    cout <<  "high1 = " << high1;  cout <<  " high2 = " << high2 << "\n" ;

    int z;
    if(findKthLargest(v1,v2,k,z) != -1)
        cout << " " << k <<"th "  << "largest element " << z << "\n";
	else
		cout << "Something went wrong";


#if 0
    linkedList *link1 = new linkedList();
    link1->data = 1;

    linkedList *link2 = new linkedList();
    link1->next = link2;
    link2->data = 2;

    linkedList *link3 = new linkedList();
    link2->next = link3;
    link3->data = 3;

    linkedList *link4 = new linkedList();
    link3->next = link4;
    link4->data = 4;
    link4->next = NULL;

    head = link1;
    
    printTheLinkedList(head);
    head = reverseMyNext(NULL,head);
    printTheLinkedList(head);

    //link4->next = link1; //If we want to create a loop.

    cout << "Loop  " << link1 << " \n " ;
    cout << "Loop  " << link2 << " \n " ;
    cout << "Loop  " << link3 << " \n " ;
    cout << "Loop  " << link4 << " \n " ;

    if((link = detectLoop(link1)) == NULL)
    {
        cout << "Loop not found \n";
    }
    else
    {
        cout << "Loop found " << link << " \n " ;
    }  


    addAnEdge(0,1);
    addAnEdge(0,2);
    addAnEdge(0,3);
    addAnEdge(1,3);
    addAnEdge(0,1);
    addAnEdge(0,2);
    addAnEdge(0,3);

    printAllGraphEdges();  
#endif
    
 
    return(0);
}
#endif



void myBitManipulations()
{
    // Clear the third bit;
    int a = 0xFF;
    printf("The original val is 0x%x \n", a);
    a &= ~(0x01 << 3);
    printf("The original val is 0x%x \n ", a);
}



int findKthLargest(vector<int> &v1, vector<int> &v2, int k,int& val)
{
    int size1 = v1.size();
    int size2 = v2.size();

    int low1 = 0;
    int high1 = size1-1 ; 
    int low2 = 0;
    int high2 = size2-1;

    if((size1 + size2) < k)
    {
        cout << "Combined array size is smaller than expected \n";
        return -1; 
    } 

    if(((size1 > k) && (size2 > k)))
    {
        val = findKthLargestRecursive(v1, low1, k-1, v2, low2, k-1, k);
        return 0; 
    }

    if(((size1 > k) && (size2 < k)) || (size1 > size2))
    {
        if(v1[size2-1] > v2[size2-1])
        {
            val = v1[k-1-size2];
            return 0;
        }
    }

    if(((size2 > k) &&  size1 < k) || (size2 > size1))
    {
        if(v2[size1-1] > v1[size1-1])
        {
            val = v2[k-1-size1];
            return 0;
        }
    }

    /* All cases where both have size less than k */ 
    val = findKthLargestRecursive(v1, low1, k-1, v2, low2, k-1, k);  
    return 0;
}

 
int getMiddleValue(vector<int> &v,int low,int high)
{
	if( ((low+high)/2) > (v.size()-1) )
        return v[v.size()-1];
	
	return v[(low+high)/2];
}

/*We always want to ensure that high1-low1+1 = high2-low2+1 = k*/
int findKthLargestRecursive(vector<int> &v1, int low1, int high1, vector<int> &v2, int low2, int high2, int k)
{
	printf("low1 = %d, high1 = %d, low2 = %d, high2 = %d, k = %d ", low1, high1, low2, high2, k);

    if(k == 1)
    {
        if(v1[low1] > v2[low2])
        {
            return v2[low2];   
        }
        else
            return v1[low1];

    }
	
	if(((low2 >= v2.size()) && high2 >= v2.size()))
	{
		return v1[low1+k-1];
		
	}
	
	if(((low1 >= v1.size()) && high1 >= v1.size()))
	{
		return v2[low2+k-1];
		
	}
	
	int m = getMiddleValue(v1,low1,high1);
	int n = getMiddleValue(v2,low2,high2);
	
	printf("m = %d, n = %d\n",m,n);
	
	if(m > n)
	{
		return findKthLargestRecursive(v1,low1,low1+(k/2-1),v2,low2+k/2,high2,k-(k/2));
	}
	else
		return findKthLargestRecursive(v1,low1+k/2,high1,v2,low2,low2+(k/2-1),k-(k/2));
	
}
/*********************************************************************************************************
/* Build with g++ -std=c++11 testCode.cpp */
int addValueToMatrx(unsigned int row,unsigned int column,int value)
{
    
    cout << "Enter " << __FUNCTION__ << " row value = " << row  << " column value = " << column << " value = "<< value << "\n";
 
    if((!value))
    {   
        cout << "trying to add zero!!!!"; 
        return 0;
    }     
 
    std::pair<int, int> p = std::make_pair(row, column);
    myMatrix[p] = value;  
	
    for(map<pair<int,int>,int>::iterator it = myMatrix.begin(); it != myMatrix.end(); it++)
    {
         cout << it->second << "\n";
    }

    return 0;
}


int isPalindrome(linkedList *headOfList)
{

    linkedList *currNode = headOfList;
    linkedList *newNode = NULL;
    linkedList *oldNode = NULL;
    bool isPalindrome = 1;

    while(currNode)
    {
        newNode = new linkedList();
        newNode->c = currNode->c;
        newNode->next = oldNode;
        oldNode = newNode;
    }

    currNode = headOfList;

}


linkedList *detectLoop(linkedList * headOfList)
{
    linkedList *slowRunner = headOfList;
    linkedList *fastRunner = headOfList;
    int count = 0; 

    while( ((slowRunner != fastRunner) || (count ==0) ) &&
            (slowRunner != NULL) &&
            (fastRunner != NULL)   
         ) 
    {
        fastRunner = fastRunner->next;
        if(count%2) 
            slowRunner = slowRunner->next;
        count++;
    }

     if(slowRunner == fastRunner)
     {
         return slowRunner; 
     }      
     else
         return NULL;
} 


#if 0
int addAnEdge(int from, int to)
{
    linkedList *currNode;
    linkedList *lastNode = NULL;
    linkedList *newNode;
      
 
    if( (from < 0 && (from >= NO_OF_VERTEX)) ||
        (to < 0 && (to >= NO_OF_VERTEX)) 
      )
    {
         cout << "Problem with vertex number"; 
         return 1;
    } 

    if(from == to)
    {
         cout << "From and To are the same. Cant do much"; 
    }
 

    if(ptr[from] == NULL)
    {
        ptr[from] = (linkedList*)new(linkedList); 
        ptr[from]->data = to;
        ptr[from]->next = NULL;

    }
    else
    {
        currNode = ptr[from];
        lastNode = NULL;
  
        while((currNode))
        {
            if(currNode->data == to)
            {
                cout << "Edge already exists from "<< from  << " to " << to << "\n";
                return 0;
            } 
            lastNode = currNode; 
            currNode = currNode->next;
        }

        newNode = (linkedList*)new(linkedList); 
        newNode->next = NULL;
        newNode->data = to;

        lastNode->next =  newNode;

    }
    return 0;

}


int printAllGraphEdges()  
{
    linkedList *currNode;
    int i = 0;

    while(i <= NO_OF_VERTEX)
    {
        currNode = ptr[i];
        while(currNode)
        {
            cout << "\nEdge from " << i <<  " to " << currNode->data << "\n"; 
            currNode = currNode->next;
        }
        i++;

    }

}
#endif

int printTheLinkedList(linkedList *head)
{
    linkedList *currNode = head;
 
    while(currNode)
    {
        printf("Node Data = %d \n",currNode->data);
        currNode = currNode->next;
    }
    return 0;
}

linkedList *reverseMyNext(linkedList *prevNode,linkedList *currNode)
{
    linkedList *tempPtr;

    if(currNode == NULL)
    {
        return prevNode; 
    }
    else
    {
       tempPtr = currNode->next;
       currNode->next = prevNode;
       return reverseMyNext(currNode,tempPtr);
    }
}



#if 0
int addNodeToList(linkedList *headOfList,int data)
{
    linkedList *currNode;
    linkedList *newNode; 

    newNode = NULL;

    newNode = new LinkedList;

    if(!newNode)
    {
        cout<< "Failure to allocate memory \n";
        return -1;
    }
    currNode = headOfList;   

    if(!currNode)
    {
    }   
    else
    {
        while(currNode->next)
        {
            currNode = currNode->next;
        }   
    }

    currNode = newNode;
    newNode->data = data;
    newNode->next = NULL; 
 
}
#endif


void reverseWordsInAString(string &s)
{
    reverse(s.begin(),s.end());

    string::iterator itB = s.begin();
    string::iterator itE = s.begin();

    while(itE != s.end())
    {
        if((*itB == 32) && (*itE == 32))
        {
            s.erase(itB);
            continue;
        }

        if((*itB != 32) && (*itE == 32))
        {
           reverse(itB,itE);
           itB = itE + 1;
        }

        itE++;

    }

    if((itB != s.end()) && (*itB != 32))
    {
        reverse(itB,itE);
    }

}


int understandStringFuncs()
{
    string myString;

    myString.assign("raghav");
    string::iterator itB = myString.begin();
    string::iterator itE = myString.end()-1;

    cout<< "First char before erase is = "<<*itB << "\n";
    cout<< "Last char before erase is = "<<*itE << "\n";

    //myString.erase(myString.begin());
    std::reverse(myString.begin(),myString.end());

    cout<< "First char after erase is = "<<*itB << "\n";
    cout<< "Last char after erase is = "<<*itE << "\n";

    return 0;

}

int testZigZagConversion()
{
    string resultString = mySolution.zigZagConvert("PAYPALISHIRING",3);
    cout << " \n The zigZagged string is " << resultString << "\n";

    return 0;
}


int testAddTwoNos()
{

    ListNode node1;
    ListNode node2;
    ListNode node3;
    ListNode node4;
    ListNode node5;
    ListNode node6;

    ListNode *resultNode;


    node1.val = 2;
    node1.next = &node2;

    node2.val = 4;
    node2.next = &node3;

    node3.val = 3;
    node3.next = 0x00;


    node4.val = 5;
    node4.next = &node5;

    node5.val = 6;
    node5.next = &node6;

    node6.val = 4;
    node6.next = 0x00;

    resultNode = mySolution.addTwoNumbers(&node1, &node4);

    while (resultNode != 0x00)
    {
        cout << "\n resultNode->val = " << resultNode->val;
        resultNode = resultNode->next;
    }

    cout << "\n End of program ..\n ";

    return 0;
}

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


ListNode* Solution :: addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* finalList = 0x00;
    ListNode* tempNode = 0x00;
    ListNode* lastNode = 0x00;

    int carry = 0;
    unsigned int val1;
    unsigned int val2;

    while(l1 || l2)
    {
        val1 = 0; val2 = 0;;

        if(l1)
        {
            val1 = l1->val;
            l1 = l1->next;
        }

        if(l2)
        {
            val2 = l2->val;
            l2 = l2->next;
        }

        tempNode = (ListNode*) new(ListNode);
        tempNode->val = (val1 + val2 + carry)%10;
        tempNode->next = 0x00;

        if(!finalList)
            finalList = tempNode;
        else
            lastNode->next = tempNode;

        lastNode = tempNode;
        if((val1 + val2 + carry)/10)
            carry = 1;
        else
            carry = 0;
    }

    if(carry == 1)
    {
        tempNode = (ListNode*) new(ListNode);
        tempNode->val = 1;
        tempNode->next = 0x00;
        lastNode->next = tempNode;
    }

    return finalList;
}


/************************************************************************************/
/* Program that shows RVO, copy constructors and assignment operators. */
class C
{
    public:
        C() {}
        C(const C& other) { std::cout << "A copy was made.\n"; }


        C& operator= (const C& other)
        {
            if (this != &other) // protect against invalid self-assignment
                cout << "A copy was made using assignment.\n";
            // by convention, always return *this
            return *this;
        }
};

C f()
{
    return C();
}

void myLittleFunctioUsingCopyConstructorAndAssigmentOperator()
{
    cout << "Hello World!\n";
    C obj = f();  //To disable RVO use -fno-elide-constructors
    C a;
    C b;
    a = b;
}




using namespace std;

map<int,int> table;


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





void getAllNodesImConnectedTo(vvi& mGraph, list<int>& pushL, int val)
{
    for(int index = 1; index < mGraph[val].size(); index++)
    {
        int val1 = mGraph[val][index];
        DEBUG_DEBUG(cout << "Processing Node " << val << " connected to " << val1 << " \n");
        pushL.push_back(val1);
    }
}

/*
 *
 * */

void bfsTempleteUtil(vvi& mGraph, int initNode)
{
    queue<list<int>> mainQ;
    list<int> pushL;
    list<int> popL;
    set<int> visited;

    pushL.push_back(mGraph[initNode][0]);
    mainQ.push(pushL);
    pushL.clear();

    while(!mainQ.empty())
    {
        popL = mainQ.front();
        mainQ.pop();

        for(auto val : popL)
        {
            if(visited.count(val) != 0)
                continue;

            visited.insert(val);
            getAllNodesImConnectedTo(mGraph, pushL, val);

        }
        if(!pushL.empty())
        {
            mainQ.push(pushL);
            pushL.clear();
        }
    }

}


void bfsTemplete()
{
    vvi mGraph;
    vi tmp1;

    tmp1 = {0, 2, 3, 5};
    mGraph.push_back(tmp1);

    tmp1 = {1, 19, 31, 56};
    mGraph.push_back(tmp1);

    tmp1 = {2, 6, 7,  8};
    mGraph.push_back(tmp1);

    tmp1 = {3};
    mGraph.push_back(tmp1);

    tmp1 = {4};
    mGraph.push_back(tmp1);

    tmp1 = {5};
    mGraph.push_back(tmp1);

    tmp1 = {6, 2};
    mGraph.push_back(tmp1);

    tmp1 = {7};
    mGraph.push_back(tmp1);

    tmp1 = {8};
    mGraph.push_back(tmp1);

    bfsTempleteUtil(mGraph, 0);
    bfsTempleteUtil(mGraph, 2);
}
/*****************************************************************************************************/

#if 0
TEST_CASE( "Graph template BFS", "Graph template BFS" )
{

    cout << "Graph template BFS \n";

    soln.bfsTemplete();
}
TEST_CASE( "Similar movies", "Similar movies")
{
    cout << "Give me top K similar movies \n";
    soln.getSimilarMovies(2);
}

#endif

struct MovieInfo
{
    string title;
    int rating;
};

vector<MovieInfo> movieDB;

void populateList(int movieIndex, int K, priority_queue<int, vector<int>, greater<int>>& topRelatedMovies)
{
    if(topRelatedMovies.size() < K)
        topRelatedMovies.push(movieIndex);
    else
    {
        //cout <<  " movieDB[topRelatedMovies.top()].rating " << movieDB[topRelatedMovies.top()].rating << " \n";
        //  cout <<  " movieDB[movieIndex].rating "<< movieDB[movieIndex].rating << " \n";
        if(movieDB[topRelatedMovies.top()].rating < movieDB[movieIndex].rating)
        {
            topRelatedMovies.pop();
            topRelatedMovies.push(movieIndex);
        }
    }

}

void getAllMoviesImConnectedTo(const vvi& mGraph, list<int>& pushL, int selectMIndex, int K, priority_queue<int, vector<int>, greater<int>>& topRelatedMovies,
                               int original)
{
    for(int index = 1; index < mGraph[selectMIndex].size(); index++)
    {
        int simiMovieIndex = mGraph[selectMIndex][index];
        if(original != simiMovieIndex)
        {
            DEBUG_DEBUG(cout << "Processing Node " << selectMIndex << " connected to " << simiMovieIndex << " \n");
            populateList(simiMovieIndex, K, topRelatedMovies);
            pushL.push_back(simiMovieIndex);
        }
    }
}


void getSimilarMoviesUtil(const vvi& mGraph, int initNode, int K, priority_queue<int, vector<int>, greater<int>>& topRelatedMovies, int original)
{
    queue<list<int>> mainQ;
    list<int> pushL;
    list<int> popL;
    set<int> visited;

    pushL.push_back(mGraph[initNode][0]);
    mainQ.push(pushL);
    pushL.clear();

    while(!mainQ.empty())
    {
        popL = mainQ.front();
        mainQ.pop();

        for(auto val : popL)
        {
            if(visited.count(val) != 0)
                continue;

            visited.insert(val);
            getAllMoviesImConnectedTo(mGraph, pushL, val, K, topRelatedMovies, original);

        }
        if(!pushL.empty())
        {
            mainQ.push(pushL);
            pushL.clear();
        }
    }

}

void getSimilarMovies(int K)
{


    vvi mGraph;
    vi tmp1;
    priority_queue<int, vector<int>, greater<int>> topRelatedMovies;
    int inputMovie = 0;

    movieDB.push_back({"movie0",99}); //0
    movieDB.push_back({"movie1",21}); //1
    movieDB.push_back({"movie2",33}); //2
    movieDB.push_back({"movie3",42}); //3
    movieDB.push_back({"movie4",12}); //4
    movieDB.push_back({"movie5",01}); //5
    movieDB.push_back({"movie6",1000}); //6
    movieDB.push_back({"movie7",67}); //7
    movieDB.push_back({"movie8",99}); //8

    tmp1 = {0, 2, 3, 5}; //0
    mGraph.push_back(tmp1);

    tmp1 = {1, 19, 31, 56}; //1
    mGraph.push_back(tmp1);

    tmp1 = {2, 6, 7,  8}; //2
    mGraph.push_back(tmp1);

    tmp1 = {3}; //3
    mGraph.push_back(tmp1);

    tmp1 = {4}; //4
    mGraph.push_back(tmp1);

    tmp1 = {5}; //5
    mGraph.push_back(tmp1);

    tmp1 = {6, 2};//6
    mGraph.push_back(   tmp1);

    tmp1 = {7}; //7
    mGraph.push_back(tmp1);

    tmp1 = {8}; //8
    mGraph.push_back(tmp1);

    inputMovie = 0;
    K = 2;
    getSimilarMoviesUtil(mGraph, inputMovie, K, topRelatedMovies, inputMovie);

    cout << "All top " << K <<  " movies related to " << inputMovie <<  " are: \n";
    int size = topRelatedMovies.size();
    for(int i = 0; i < size; i++)
    {
        cout << "Related Movie is " << topRelatedMovies.top() << " \n";
        topRelatedMovies.pop();
    }



}

/*****************************************************************************************************/








