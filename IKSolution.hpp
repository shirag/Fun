/*
 * Solution.hpp
 *
 *  Created on: Jan 9, 2017
 *      Author: Raghav Navada
 */

#ifndef IK_SOLUTION_HPP_
#define IK_SOLUTION_HPP_

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>
#include <cassert>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <functional>
#include <memory>
#include <fstream>
#include <bitset>
#include <math.h>


using namespace std;

class Node
{
    public:
	    int val;
	    struct Node *left, *right;
	    struct Node *nextRight; //Pointer to the right sibling
};

class Tree
{
    public:
        stack<Node *> nextlowestStack;
        void init(Node *root);
        Node* next();
        bool hasNext();
};

struct LinkedListNode
{
    int val;
    int key;
    struct LinkedListNode *next;
    struct LinkedListNode *prev;
    struct LinkedListNode *rand;
};

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef pair<char,int> pci;

typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef queue<pii> qpii;
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef queue<vpii> qvpii;
typedef list<pii> lpii;
typedef queue<lpii> qlpii;
typedef list<string> ls;
typedef queue<ls> qls;
typedef set<string> ss;
typedef set<si> ssi;
typedef queue<list<Node*>> qln;
typedef list<Node*> ln;



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
void printVector(vector<int> v);
bool identicalLinkedListNodes(LinkedListNode *l1, LinkedListNode *l2);
int partition(vector<int>& a, int low, int high);

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
        LRUCache();
        void set(int key, int val);
        int get(int key);
        void remove(int key);
        ~LRUCache();

    private:
        unordered_map<int, LinkedListNode*> lrum;
        LinkedListNode *head = nullptr;
        LinkedListNode *tail = nullptr;
        const unsigned int lRUMaxSizeCache = 2;

        LinkedListNode* push_front(int key, int val);
        void move_front(LinkedListNode* node);
        void pop_back();
        void evict(int key);
};


class superStack
{
    private:
        LinkedListNode *head = nullptr;
        int size;

    public:
        superStack();
        void push(int x);
        void pop();
        int top();
        void inc(int e, int k);


};


class LinkedList
{
    public:
        void addValue(int);
        void deleteValue(int);
        bool find(int);
        void printList();
        LinkedList();
        ~LinkedList();

    private:
        LinkedListNode *head = nullptr;


};

struct Point
{
    int x;
    int y;
    int z;
};

class IKSolution
{
    private:
        stack<int> csS;
        stack<int> minS;

    public:

        //Magic Map
        int getValue(string s);
        void setVal(string str, int val);
        void deleteVal(string s);
        int getRandomVal(); //uniformly returns a random value from the map

	   	/* Arrays and Ad hoc; HomeWork1 Part */
        int prLR();
	    vpii mergeIntervals(vpii v1);
	    int twoDArraySearch();
	    int findLargestRectangle(vi);
	    vector<string> sumZero(vector<int> intArr);
	    void printPascal(int n);
	    int nextPalindrome(int iInputNum);
	    vector<int> AlternatePosNegative(vector<int> vec);
	    vector<pair<int,int>> skyLine(vvi vec);
	    string RLE(string strInput);
	    int findMinimum(vector<int> arr);
	    int printCountOfBitsSet(vector<int> intArr);
	    int findMaxSumSubArray(vector<int> arr); //Kadane's algorithm


	    int findDuplicateThatOccursOnce(vector<int> v); //Prudhvi
	    int findADuplicate(); /*Geeta*//* Array of n integers values between 0 and n-1 and there are duplicate. Find a duplicate
	                                    * 1. Bucket method. - Add a value and then subtract when you want to check.
	                                    * 2. Swapping method - As you iterate over the array keep swapping.
	                                    */


	    /* Trees: Class problems */
	    void treeBFS(Node *root);
	    Node* bSTTreeInsert(Node *root, int key);
	    int deleteANode(Node *root, int key); /* 3:20 at Gayathri vid */
	    int findSuccessor(Node*, int key); //Recursive DFS inrder soln. when you hit a value lesser print the last one.
	    int checkIfPalindromeRotate(string&); //time test problem

	    /* Homework2 - Trees */
	    bool isBST(Node*);
	    Node* mergeTwoBSTs(Node* node1, Node* node2);
	    void printAllPathsInATee(Node *node);
	    vvi printAllPathsInATeeToASum(Node* root, int k);
	    int countUniValSubtrees(Node *node);
	    Node* treeToDoubleLL(Node*);
	    Node* findLCA(Node* root, int n1, int n2);
	    void postorderTraversal(Node* root);
	    /* Tree time test problem */
	    void createBalancedBST(vector<int> iArray);
	    int findKThSmallest(Node* root, unsigned int k);
	    /* K' successor problem */
	    /* Interval trees? */
	    /* Segment trees? */
	    vvi treeLevelOrderPrint(Node *root);
	    vvi treeLevelOrderPrintUsingList(Node *root);
	    Node* cloneATree(Node *root);
	    Node* flipATree(Node *root);
	    int largestBST(Node *root);
	    vvi constrctTree(vector<int> iInOrderArray, vector<int> iPreOrderArray);
	    void PopulateSiblingPointers(Node *root);

	    /* Graph/Homework3 */
	    void bfsTemplete();
        int printAllPathsInAGraph(vvi& g, int src, int dest);
        int cloneAGraph(); /* You have to ensure cycles are taken care of properly */
	                       /* Not just a set. You have to use a hash map */
        int findTheBasin(); /* Rainfal problem. Find the basin to which the water flows. */
        vector<string> convertAString(ls&, string& begin, string& end); /* Convert string a to b using a dictionary of words*/
	    int knightsTourOnChessBoard(int rows, int columns, int sx, int sy, int ex, int ey);
	    string topologicalSort(vector<string>);
	    int countNoOfIslands(vvi matrix); /* Basically a connected components problem */
	    int snakeNLadder(int m, int n, unordered_map<int,int> locations, map<int,int>& prevMap);

        /* Mock/Recursion/Homework4 */

	    int findMajority();  /* Array of n elements. Many duplicates. frequency greater than n/2. NOt within the range. */
	    int MaxPath(vvi); /* n x n matrix find the sum of max sum path */
	    vector<string> generateAllPermutations(string s);

	    set< set<int> > provideSubSets(vector<int> ip);
	    vector<string> expressionEvaluator(string strDigits, int iK); //Very similar to providesubsets(for all places plug in all operators).
	    vector<string> palindromicDecomposition(string strInput);
	    long NQueens(int n);
	    int howManyTrees(int n); //given you have n number of nodes.
	    bool sumOfIntegers(vector<int> IntArr, int iTarget); /*If there is a group of integers whose sum is K(may or may not be contigous)*/
	    int wellFormedBrackComb(int n);
	    vector<int> diffWaysToCompute(string s);
	    void getSimilarMovies(int K);


        /* LinkedLinkedListNode */
	    LinkedListNode* AddTwoLinkedListNodes(LinkedListNode *LinkedListNode1, LinkedListNode *LinkedListNode2);
	    LinkedListNode* AddTwoLinkedListNodesLSDFirst(LinkedListNode *LinkedListNode1, LinkedListNode *LinkedListNode2);
	    LinkedListNode *pointerToCycle(LinkedListNode *); /* Given  a pointer to the head of */
	    list<int>::iterator interSectionOfTwoLists(list<int>& L1, list<int>& L2);
	    int Median(LinkedListNode *l1);
	    int findMiddleNode(LinkedListNode *head);
	    LinkedListNode* swapKthNodes(LinkedListNode*, int k);
	    LinkedListNode* myLinkedListNodereverseALinkedListNodeInGroupsOfGivenSize(LinkedListNode *myLinkedListNode, int k);
	    LinkedListNode* zipALinkedListNode(LinkedListNode *myLinkedListNode);
	    //Stack
	    void pushMS(int x);
	    int popMS();
	    int getMinMS();
	    bool emptyMS();
	    int maxLenMatchingParen(string strParenExpression);
        //Prio Queue
	    vector<int> slidingWindowMax(vector<int>, int w);
        /* Implement Queue using Stacks */ /* http://www.geeksforgeeks.org/queue-using-stacks/ */
	    list<int> MergeSortLists(list<int>);
	    LinkedListNode* MergeSortLinkedListNodePtr(LinkedListNode *l);
	    LinkedListNode* cloneASpecialLinkedList(LinkedListNode *l);
	    LinkedListNode* alternativeSplit(LinkedListNode* pLinkedListNode);
	    bool hasMatchingParantheses(string);

        /* Dynamic Programming */
        int editDistance(string, string);
        vector<string> wordBreak(string strWord, vector < string > strDict);
        vector<int> makeChange(int C, vector < int > intDenominations);
        int maxWin(vector < int > intCoins);
        int numPhoneNumbers(int startdigit, int phonenumberlength);
        int numWaysToClimb(vector < int > numSteps, int numStairs);
        int maxStolenValue(vector < int > arrHouseValues);
        int maxProductFromCutPieces(int ropelength);
        int numberOfPaths(vector<vector<int>> a);

        /* Strings */
        string longestSub(string strText);
        string minWindow(string strText, string strCharacters);
        vector<pair<string,string>> joinWordToMakePali(vector<string> s);
        bool regExMatcher(string strText, string strPattern);
        bool KMP(string strText, string strPattern);
        void Neuronyms(string s);
        string printSpirally(vector<vector<char>> matrix);
        string moveAllLettersToLeftSide(string s);
        //Class problem: Substring that controls the set

        /* Sorting */
        vector<int> groupNumbers(vector<int> intArr);
        vector<int> quickSort(vector<int>& a);
        vector<pair<pci,pci>> nutsNBolts(vector<pci>& nuts, vector<pci>& bolts);
        vector<int> mergeSortedArrays(vector<vector<int>> iarray);
        bool findMissingInteger(vector<int> v, int ragngeBegin, int rangeEnd, int memorySize, int& missingInt);
        vector<int> twitterTopK(vector<int>iStream, int iK);
        vector<string> printTriplets(vector<int> intArr);
        bool findIf4NumbersSumToK(vector<int> v, int k);
        vector<int> mergeFirstIntoAnother(vector<int> intArrShort, vector<int> intArrLong);
        string sortCharacters(string inString);
        vector<pair<int,int>> findClosestNeighbors(vector<Point>& vec, Point p, int k);
        /* ? Dutch National Flag timed test problem */
        /* ? Two sorted arrays. Find a duplicate. Use a Hash. Time 2n. Try the merging logic used for merge sort.*/


        /* Concurrency */
        void producerConsumerMain();
        void oddEvenMain();
        void synchrnousRequestDispatcher();

        /*
        Moving integer window, find the max. Use a double ended queue: Has properties of both Stack and Queue.
        *. find the missing number: Generate a lookup table and mark the no present.
            0-7: Generate a table and mark the bit that is present and finally scan.
            How do you do when you are given 4 bits. When space reduces think of a solution where time increases.*/

        int myMainDisp();

};





#endif /* SOLUTION_HPP_ */
