/*
 * Solution.hpp
 *
 *  Created on: Jan 9, 2017
 *      Author: GouriShivani
 */

#ifndef IK_SOLUTION_HPP_
#define IK_SOLUTION_HPP_

//#include<string>
//#include<string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>    // std::sort
#include <stack>
#include <limits.h>
#include <queue>
#include <set>
#include <list>

using namespace std;

struct Node
{
	int val;
	struct Node *left, *right;
};

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector< pair<int,int> > vpii;

typedef pair<int, int> pii;
typedef queue<pii> qpii;
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef queue<vpii> qvpii;

typedef list<pii> lpii;
typedef queue<lpii> qlpii;


typedef list<string> ls;
typedef queue<ls> qls;
typedef set<string> ss;




Node *createTreeNode(int key);
//int *mergeArray(int arr1[], int arr2[], int m, int n);
vector<int> mergeVector(vector<int> v1, vector<int> v2);
int depthFirstSearchUtil(vvi& W, int node, vector<bool>& flag);
int countComponents(int n, vector< pair<int, int> >& edges);

class IKSolution
{
    public:

	    int getValue(string s);
	    int setVal(string str, int val);
	    int deleteVal(string s);
	    int getRandomVal();

	    /* HomeWork1/Arrays and Ad hoc */
	    int prLR();
	    int mergeIntervals();
	    int twoDArraySearch();
	    int findLargestRectangle();
	    vector<string> sumZero(vector<int> intArr);
	    void printPascal(int n);

	    /* Trees: Class problems */
	    void treeBFS(Node *root);
	    Node* bSTTreeInsert(Node *root, int key);
	    int deleteANode(Node *root, int key); /* 3:20 at Gayathri vid */
	    int findSuccessor(Node*, int key); //Recursive DFS irder soln. when you hit a value lesser print the last one.

	    int checkIfPalindromeRotate(string&); //time test problem

	    /* Homework2 - Trees */
	    bool isBST(Node*);
	    Node* mergeTwoBSTs(Node* node1, Node* node2);
	    int printAllPathsInATee(Node *node);
	    int countUniValSubtrees(Node *node);
	    Node* treeToDoubleLL(Node*);
	    Node* findLCA(Node* root, int n1, int n2);
	    void postorderTraversal(Node* root);
	    /* Tree time test problem */
	    void createBalancedBST(vector<int> iArray);
	    int findKThSmallestUtil(Node* root, unsigned int& k, unsigned int& counter);

	    /* Graph/Homework3 */
        int printAllPathsInAGraph(vvi& g, int src, int dest);
	    int cloneAGraph(); /* You have to ensure cycles are taken care of properly */
	                       /* Not just a set. You have to use a hash map */
        int findTheBasin(); /* Rainfal problem. Find the basin to which the water flows. */
        int convertAString(ls&, string& begin, string& end); /* Convert string a to b using a dictionary of words*/
	    int knightsTourOnChessBoard(int rows, int columns, int sx, int sy, int ex, int ey);
	    string topologicalSort(vector<string>);
	    int countNoOfIslands(vvi matrix); /* Basically a connected components problem */

        /* Graph/Homework3 */
	    vector<string> expressionCreator(string strDigits, int iK);


	    /*Count the no of islands */
};



#endif /* SOLUTION_HPP_ */
