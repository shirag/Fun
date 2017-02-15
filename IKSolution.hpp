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
#include <unordered_map>


using namespace std;

struct Node
{
	int val;
	struct Node *left, *right;
};

struct List
{
    int val;
    int key;
    struct List *next;
    struct List *prev;
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

typedef set<int> si;
typedef set< si > ssi;

#define DEBUG_LEVEL_FATAL       5    //Somebody is going to die if this happens
#define DEBUG_LEVEL_ERROR       4    //Somebody is going to get very sick if this happens.
#define DEBUG_LEVEL_MAINSTATUS  3    //Something very important is going on. Not so usual.
#define DEBUG_LEVEL_DEBUG       2    //Print some debugging logic
#define DEBUG_LEVEL_TRACE       1    //Print function args
#define DEBUG_LEVEL_NONE        0    //nothing



#if (DEBUG_LEVEL == DEBUG_LEVEL_MAINSTATUS)
#define DEBUG_FATAL(x)       x
#define DEBUG_ERROR(x)       x
#define DEBUG_MAINSTATUS(x)  x
#define DEBUG_DEBUG(x)
#define DEBUG_TRACE(x)
#endif


#if (DEBUG_LEVEL == DEBUG_LEVEL_DEBUG)
#define DEBUG_FATAL(x)      x
#define DEBUG_ERROR(x)      x
#define DEBUG_MAINSTATUS(x) x
#define DEBUG_DEBUG(x)      x
#define DEBUG_TRACE(x)
#endif

#if (DEBUG_LEVEL == DEBUG_LEVEL_TRACE)
#define DEBUG_FATAL(x)      x
#define DEBUG_ERROR(x)      x
#define DEBUG_MAINSTATUS(x) x
#define DEBUG_DEBUG(x)      x
#define DEBUG_TRACE(x)      x
#endif

#if (DEBUG_LEVEL == DEBUG_LEVEL_NONE)
#define DEBUG_FATAL(x)
#define DEBUG_ERROR(x)
#define DEBUG_MAINSTATUS(x)
#define DEBUG_DEBUG(x)
#define DEBUG_TRACE(x)
#endif



Node *createTreeNode(int key);
vector<int> mergeVector(vector<int> v1, vector<int> v2);
int depthFirstSearchUtil(vvi& W, int node, vector<bool>& flag);
int countComponents(int n, vector< pair<int, int> >& edges);


struct BloomFilter {

  public:

      BloomFilter(uint64_t size, uint8_t numHashes): m_bits(size), m_numHashes(numHashes) {};
      void add(const uint8_t *data, std::size_t len);
      bool possiblyContains(const uint8_t *data, std::size_t len) const;

    private:
        uint8_t m_numHashes;
        std::vector<bool> m_bits;
};

/*
 * LRU cache. Its a key value store. Everything must be O(1) in time.
 */
class LRUCache
{
    public:
        void set(int key, int val);
        int get(int key);
        void remove(int key);

    private:
        List *createANewNode(int key,int val);
        void push_front(List *node);
        void move_front(List *node);
        void pop_back();
        void remove_node(List* node);
        int evict();

        struct LRUNode
        {
            int val;
            int key;
            int index;
        };

        unordered_map<int, List*> lrum;
        List *lrul;
        List *head = nullptr;
        List *tail = nullptr;
        const unsigned int lRUMaxSizeCache = 2;
        unsigned int lRUCachSize = 0;
};

class IKSolution
{
    private:
        stack<int> csS;
        stack<int> minS;

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
	    int findSuccessor(Node*, int key); //Recursive DFS inrder soln. when you hit a value lesser print the last one.

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
        vector<string> convertAString(ls&, string& begin, string& end); /* Convert string a to b using a dictionary of words*/
	    int knightsTourOnChessBoard(int rows, int columns, int sx, int sy, int ex, int ey);
	    string topologicalSort(vector<string>);
	    int countNoOfIslands(vvi matrix); /* Basically a connected components problem */

        /* Mock/Recursion/Homework4 */
	    int findADuplicate(); /* Array of n integers values between 0 and n-1 and there are duplicate. Find a duplicate
	                           * 1. Bucket method. - Add a value and then subtract when you want to check.
	                           * 2. Swapping method - As you iterate over the array keep swapping.
	                           */
	    int findMajority();  /* Array of n elements. Many duplicates. frequency greater than n/2. NOt within the range. */
	    int MaxPath(vvi); /* n x n matrix find the sum of max sum path */
	    void generateAllPermutation(int n); /* given an array of n integers generate and print all permutations */

	    set< set<int> > provideSubSets(vector<int> ip);
	    vector<string> expressionEvaluator(string strDigits, int iK); //Very similar to providesubsets(for all places plug in all operators).
	    vector<string> palindromicDecomposition(string strInput);
	    long NQueens(int n);
	    int howManyTrees(int n); //given you have n number of nodes.
	    bool sumOfIntegers(vector<int> IntArr, int iTarget); /*If there is a group of integers whose sum is K(may or may not be contigous)*/
	    int wellFormedBrackComb(int n);

        /* StackQueueLinkedList */
	    List *pointerToCycle(List *); /* Given  a pointer to the head of */
	    int maxLenMatchingParen(string strParenExpression);
	    int findMiddleNode(List *head);

	    void pushMS(int x);
	    int popMS();
	    int getMinMS();
	    bool emptyMS();

	    List* swapKthNodes(List*, int k);
	    List* myListreverseAListInGroupsOfGivenSize(List *myList, int k);
	    List* zipAList(List *myList);


        int dutchFlag(); /* Done during class. */

};



#endif /* SOLUTION_HPP_ */