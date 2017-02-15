#include<iostream>
#include<string>
#include<algorithm>
#include"Solution.h"
#include<map>
#include "IKSolution.hpp"

#define CATCH_CONFIG_MAIN
#include "Catch.hpp"

int testZigZagConversion();
int testAddTwoNos();

Solution mySolution;
int understandStringFuncs();
void reverseWordsInAString(string &s);


using namespace std;



int testIKWork();

#if 0
int main()
{
    cout << "Hello World!!!\n";

    //testAddTwoNos();

    //testZigZagConversion();

    //understandStringFuncs();

    testIKWork();

    cout << "End of Main";

    return 0;
}
#endif


IKSolution soln;

#if 0
TEST_CASE( "Count the number of islands", "[Islands]" ) {


    vvi a = {
                   {1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1},
                   {1, 0, 0, 1, 1},
                   {0, 0, 0, 0, 0},
                   {1, 0, 1, 0, 1}
               };

    vvi b = {
                       {1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1},
               };

    vvi c = {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
            };

    REQUIRE( soln.countNoOfIslands(a) == 5 );
    REQUIRE( soln.countNoOfIslands(b) == 1 );
    REQUIRE( soln.countNoOfIslands(c) == 0 );
}
#endif

#if 0
TEST_CASE( "Convert a string from src to dest", "[Convert a string]" ) {


    ls dict = {"bit", "bal", "hal", "hit", "had", "cad", "bat", "hat", "bil", "kit"};
    string s1 = "hit";
    string s2 = "kit";
    vector<string> dest = {"hit","kit"};

    cout << "src = " << s1;
    cout << " dest = " <<  s2 << "\n";

    REQUIRE( soln.convertAString(dict, s1, s2) == dest);

    ls dict1 = {"cat", "bat", "hat", "bad", "had"};
    string s11 = "bat";
    string s12 = "had";
    vector<string> dest1 = {"bat","hat","had"};

    REQUIRE( soln.convertAString(dict1, s11, s12) == dest1);

}
#endif

#if 0
TEST_CASE( "Bloom filter tests", "[Bloom]" ) {

   BloomFilter bf(100,2); //size = 5, hash function 2;
   uint8_t data[] = {1,2,3,4,5};
   string str1("raghav");
   string str2("shivani");
   string str3("shourya");
   string str4("lakshmi");

   bf.add((const uint8_t *)str1.c_str(),str1.size());
   bf.add((const uint8_t *)str2.c_str(),str2.size());

   REQUIRE(bf.possiblyContains((const uint8_t *)str1.c_str(),str1.size()) == true);
   REQUIRE(bf.possiblyContains((const uint8_t *)str2.c_str(),str2.size()) == true);
   REQUIRE(bf.possiblyContains((const uint8_t *)str3.c_str(),str3.size()) == false);
   REQUIRE(bf.possiblyContains((const uint8_t *)str4.c_str(),str4.size()) == false);

   bf.add((const uint8_t *)str3.c_str(),str3.size());
   REQUIRE(bf.possiblyContains((const uint8_t *)str3.c_str(),str3.size()) == true);


}
#endif
#if 0
TEST_CASE( "Print all subsets", "subsets" ) {

   vector<int> value0 = {1,2,3};
   ssi res0 = {{1,2,3},{1,2},{1,3},{1},{2,3},{2},{3},{}};
   REQUIRE(soln.provideSubSets(value0) == res0);

   vector<int> value1 = {1,2,3,4};
   ssi res1 = {{1 , 2 , 3 , 4},{1 , 2 , 3},{1 , 2 , 4},{1 , 2},
               {1 , 3 , 4}, {1 , 3}, {1 , 4},{1}, {2 , 3 , 4},
               {2 , 3}, {2 , 4}, {2}, {3 , 4}, {3}, {4},{}
              };
   REQUIRE(soln.provideSubSets(value1) == res1);
}
#endif

#if 0
TEST_CASE( "Expression Evaluator", "EV" ) {


   string s0("2"); int res0 = 2;
   vector<string> ress0 = {"2=2"};
   REQUIRE(soln.expressionEvaluator(s0, res0) == ress0);


   string s1("22"); int res1 = 4;
   vector<string> ress1 = {"2+2=4","2*2=4"};
   REQUIRE(soln.expressionEvaluator(s1, res1) == ress1);


   string s2("222");int res2 = 6;
   vector<string> ress2 = {"2+2+2=6","2+2*2=6","2*2+2=6"};
   REQUIRE(soln.expressionEvaluator(s2, res2) == ress2);


   string s3("222");int res3 = 8;
   vector<string> ress3 = {"2*2*2=8"};
   REQUIRE(soln.expressionEvaluator(s3, res3) == ress3);

   string s4("222");int res4 = 24;
   vector<string> ress4 = {"2+22=24","22+2=24"};
   REQUIRE(soln.expressionEvaluator(s4, res4) == ress4);

   string s5("222");int res5 = 222;
   vector<string> ress5 = {"222=222"};
   REQUIRE(soln.expressionEvaluator(s5, res5) == ress5);

}
#endif

TEST_CASE( "Palindromic Decomposition", "PV" )
{
    vector<string> is;
    vector<string> t;
    vector < vector<string> > res;


    /* 0 */
    is.push_back("");
    t =  {""};
    res.push_back(t);
    t.clear();

    /* 1 */
    is.push_back("abba");
    t =  { "a|b|b|a|", "a|bb|a|", "abba|" };
    res.push_back(t);
    t.clear();

    /* 2 */
    is.push_back("aab");
    t =  {"a|a|b|","aa|b|"};
    res.push_back(t);
    t.clear();

    /* 3 */
    is.push_back("abracadabra");
    t = { "a|b|r|a|c|a|d|a|b|r|a|",
          "a|b|r|a|c|ada|b|r|a|",
          "a|b|r|aca|d|a|b|r|a|"};
    res.push_back(t);
    t.clear();

    /* 4 */
    is.push_back("raabbag");
    t = { "r|a|a|b|b|a|g|",
          "r|a|a|bb|a|g|",
          "r|a|abba|g|",
          "r|aa|b|b|a|g|",
          "r|aa|bb|a|g|" };

    res.push_back(t);
    t.clear();

    int size = is.size();
    int startIndex = 0;
    int endIndex = 0;

    for(int i = startIndex; i < endIndex; i++)
        REQUIRE(soln.palindromicDecomposition(is[i]) == res[i]);

}

TEST_CASE( "N Queens", "NQueens" )
{
    cout << "N Queens \n\n";

    vector<int> is;
    vector <long> res;

    /* http://www.jsomers.com/nqueen_demo/nqueens.html*/
    is = {4, 5, 6, 7, 8, 14, 19};
    res = {2, 10, 4, 40, 92, 365596, 4968057848};

    int size = is.size();
    int startIndex = 0;
    int endIndex = 0;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.NQueens(is[i]) == res[i]);
    }
}


TEST_CASE( "How many tree with N nodes", "NNodes" )
{
    cout << "How many tree with N nodes \n\n";

    vector<int> is;
    vector <long> res;

    is.push_back(1);
    res.push_back(1);

    is.push_back(2);
    res.push_back(2);

    is.push_back(3);
    res.push_back(5);

    is.push_back(4);
    res.push_back(14);

    is.push_back(5);
    res.push_back(42);


    int size = is.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.howManyTrees(is[i]) == res[i]);
    }
}

TEST_CASE( "How Many bits set", "bitsset" )
{
    cout << "How many bits \n\n";

    vector<int> is;
    vector <long> res;

    is = {0,1,2,3};
    res = {0,1,1,2};

    int size = is.size();
    int startIndex = 0;
    int endIndex = 0;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(countBitsUsingLookUp(is[i]) == res[i]);
    }
}


TEST_CASE( "sumOfIntegers", "soints" )
{
    cout << "Sum of Ints \n\n";

    vector< vector<int> > is;
    vector<int> is1;
    vector<bool> res;

    is =  {{2,4,8},{2,-4,8},{2,4,8},{2,4,8}};
    is1 = {6,1,14,9};
    res = {true,false,true,false};

    int size = is.size();
    int startIndex = 0;
    int endIndex = 0;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.sumOfIntegers(is[i],is1[i]) == res[i]);
    }
}


TEST_CASE( "Well Formed Brackets", "Well Formed Brackets" )
{
    cout << "Well Formed Brackets \n\n";

    vector<int> is;
    vector<int> res;

    is = {1,2,3,4,6};
    res = {1,2,5,14,42};

    int size = is.size();
    int startIndex = 0;
    int endIndex = 0;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.wellFormedBrackComb(is[i]) == res[i]);
    }
}


TEST_CASE( "Find the head of the loop in a LL", "Linked List" )
{
    cout << "Head of the loop \n\n";

    vector<List*> is;
    vector<List*> res;

    List *ptr1 = nullptr;
    List *ptr2 = nullptr;
    is.push_back(ptr1);
    res.push_back(ptr2);

    //no cycle test.
    List node3; node3.next = nullptr;
    List node4; node4.next = &node3;
    List node5; node5.next = &node4;
    List node6; node6.next = &node5;
    List node7; node7.next = &node6;
    List node8; node8.next = &node7;
    List node9; node9.next = &node8;
    List node10; node10.next = &node9;
    List node11; node11.next = &node10;
    List node12; node12.next = &node11;
    List node13; node13.next = &node12;
    List node14; node14.next = &node13;
    List node15; node15.next = &node14;
    is.push_back(&node15);
    res.push_back(ptr2);

    //create a loop
    List nodea3; nodea3.next = nullptr; nodea3.val = 3;
    List nodea4; nodea4.next = &nodea3; nodea4.val = 4;
    List nodea5; nodea5.next = &nodea4; nodea5.val = 5;
    List nodea6; nodea6.next = &nodea5; nodea6.val = 6;
    List nodea7; nodea7.next = &nodea6; nodea7.val = 7;
    List nodea8; nodea8.next = &nodea7; nodea8.val = 8;
    List nodea9; nodea9.next = &nodea8; nodea9.val = 9;
    List nodea10; nodea10.next = &nodea9; nodea10.val = 10;
    List nodea11; nodea11.next = &nodea10; nodea11.val = 11;
    List nodea12; nodea12.next = &nodea11; nodea12.val = 12;
    List nodea13; nodea13.next = &nodea12; nodea13.val = 13;
    List nodea14; nodea14.next = &nodea13; nodea14.val = 14;
    List nodea15; nodea15.next = &nodea14; nodea15.val = 15;

    nodea5.next = &nodea14; //Loop
    is.push_back(&nodea15);
    res.push_back(&nodea14);

    int size = is.size();
    int startIndex = 0;
    int endIndex = 0;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.pointerToCycle(is[i]) == res[i]);
    }


}

TEST_CASE( "Longest substring with matching parentheses", "Longest substring" )
{
    cout << "Longest substring with matching parentheses \n\n";

    vector<string> is;
    vector<int> res;

    is.push_back("((())((()");
    res.push_back(4);

    int size = is.size();
    int startIndex = 0;
    int endIndex = 0;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.maxLenMatchingParen(is[i]) == res[i]);
    }

}

TEST_CASE( "Find the middle of a Linked List", "Middle List" )
{
    cout << "Find the middle of a Linked List \n\n";

    vector<List*> is;
    vector<int> res;

    List *ptr1 = nullptr;

    is.push_back(ptr1);
    res.push_back(0);

    List node3; node3.next = nullptr;   node3.val = 3;
    List node4; node4.next = &node3;    node4.val = 4;
    List node5; node5.next = &node4;    node5.val = 5;
    List node6; node6.next = &node5;    node6.val = 6;
    List node7; node7.next = &node6;    node7.val = 7;
    List node8; node8.next = &node7;    node8.val = 8;
    List node9; node9.next = &node8;    node9.val = 9;//middle
    List node10; node10.next = &node9;  node10.val = 10;
    List node11; node11.next = &node10; node11.val = 11;
    List node12; node12.next = &node11; node12.val = 12;
    List node13; node13.next = &node12; node13.val = 13;
    List node14; node14.next = &node13; node14.val = 14;
    List node15; node15.next = &node14; node15.val = 15;

    is.push_back(&node15);
    res.push_back(9);

    List nod3; nod3.next = nullptr;  nod3.val = 3;
    List nod4; nod4.next = &nod3;    nod4.val = 4;
    List nod5; nod5.next = &nod4;    nod5.val = 5;
    List nod6; nod6.next = &nod5;    nod6.val = 6;
    List nod7; nod7.next = &nod6;    nod7.val = 7;
    List nod8; nod8.next = &nod7;    nod8.val = 8;
    List nod9; nod9.next = &nod8;    nod9.val = 9; //middle
    List nod10; nod10.next = &nod9;  nod10.val = 10;
    List nod11; nod11.next = &nod10; nod11.val = 11;
    List nod12; nod12.next = &nod11; nod12.val = 12;
    List nod13; nod13.next = &nod12; nod13.val = 13;
    List nod14; nod14.next = &nod13; nod14.val = 14;
    List nod15; nod15.next = &nod14; nod15.val = 15;
    List nod16; nod16.next = &nod15; nod16.val = 16;


    is.push_back(&nod16);
    res.push_back(9);

    int size = is.size();
    int startIndex = 0;
    int endIndex = 0;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.findMiddleNode(is[i]) == res[i]);
    }
}


TEST_CASE( "Implement the min stack", "Min Stack" )
{
    cout << "Implement the min stack \n\n";

    soln.pushMS(1); soln.pushMS(2);   soln.pushMS(3);
    soln.pushMS(4); soln.pushMS(5);
    if(!soln.emptyMS())
        REQUIRE(soln.getMinMS() == 1);
    soln.popMS(); soln.popMS(); soln.popMS(); soln.popMS(); soln.popMS(); soln.popMS(); soln.popMS();

    soln.pushMS(1); soln.pushMS(5);
    soln.pushMS(3); soln.pushMS(0);
    if(!soln.emptyMS())
        REQUIRE(soln.getMinMS() == 0);
    soln.popMS(); soln.popMS(); soln.popMS(); soln.popMS(); soln.popMS(); soln.popMS(); soln.popMS();
    if(!soln.emptyMS())
        REQUIRE(soln.getMinMS() == 0);

    soln.pushMS(1); soln.pushMS(5);
    soln.pushMS(3); soln.pushMS(0);
    soln.pushMS(10); soln.pushMS(20);
    if(!soln.emptyMS())
        REQUIRE(soln.getMinMS() == 0);

    soln.popMS(); soln.popMS(); soln.popMS();
    if(!soln.emptyMS())
        REQUIRE(soln.getMinMS() == 1);
}

#if 1
TEST_CASE( "Swap Kth Node", "Swap Nodes" )
{
    cout << "Swap Kth Node \n\n";
    List node1; List node2; List node3; List node4; List node5; List node6;

    //TEST CASE: Nullptr case
    List *ptr1 = nullptr;
    REQUIRE(soln.swapKthNodes(ptr1,5) == nullptr);


    //TEST CASE: Regular case
    node1.next = &node2;  node1.val = 1;
    node2.next = &node3;  node2.val = 2;
    node3.next = &node4;  node3.val = 3;
    node4.next = &node5;  node4.val = 4;
    node5.next = &node6;  node5.val = 5;
    node6.next = nullptr; node6.val = 6;
    List *temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    List *res = soln.swapKthNodes(&node1,2);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";

    //TEST CASE: Where elements to be swapped are sitting next to each other
    node1.next = &node2;  node1.val = 1;
    node2.next = &node3;  node2.val = 2;
    node3.next = &node4;  node3.val = 3;
    node4.next = nullptr;  node4.val = 4;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.swapKthNodes(&node1,2);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";

    //TEST CASE: Swap first and last elements
    node1.next = &node2;  node1.val = 1;
    node2.next = &node3;  node2.val = 2;
    node3.next = &node4;  node3.val = 3;
    node4.next = nullptr;  node4.val = 4;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.swapKthNodes(&node1,1);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";


    //TEST CASE: Where k does not exist. List is shorter
    node1.next = &node2;  node1.val = 1;
    node2.next = &node3;  node2.val = 2;
    node3.next = &node4;  node3.val = 3;
    node4.next = nullptr;  node4.val = 4;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.swapKthNodes(&node1,6);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";


    //TEST CASE: where y is before x
    node1.next = &node2;  node1.val = 1;
    node2.next = nullptr;  node2.val = 2;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.swapKthNodes(&node1,2);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";

    node1.next = nullptr;  node1.val = 1;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.swapKthNodes(&node1,1);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";
}
#endif

#if 0
TEST_CASE( "Reverse a linked list in groups", "Reverse in groups" )
{
    cout << "Reverse a linked list in groups \n\n";
    List node1; List node2; List node3; List node4;
    List node5; List node6; List node7; List node8;

    node1.val = 1; node2.val = 2; node3.val = 3;
    node1.next = &node2; node2.next = &node3; node3.next = nullptr;

    List* temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    List *res = soln.myListreverseAListInGroupsOfGivenSize(&node1,3);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";

    //Test Case: more than one loop
    node1.val = 1; node2.val = 2; node3.val = 3; node4.val = 4;
    node5.val = 5; node6.val = 6; node7.val = 7; node8.val = 8;
    node1.next = &node2; node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = &node6; node6.next = &node7; node7.next = &node8; node8.next = nullptr;

    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.myListreverseAListInGroupsOfGivenSize(&node1,3);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";


    //Test Case: more than one loop
    node1.val = 1; node2.val = 2; node3.val = 3; node4.val = 4;
    node5.val = 5; node6.val = 6; node7.val = 7; node8.val = 8;
    node1.next = &node2; node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = &node6; node6.next = &node7; node7.next = &node8;  node8.next = nullptr;

    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.myListreverseAListInGroupsOfGivenSize(&node1,5);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";


    //Test Case: more than one loop
    node1.val = 1; node2.val = 2; node3.val = 3; node4.val = 4;
    node5.val = 5; node6.val = 6; node7.val = 7; node8.val = 8;
    node1.next = &node2; node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = &node6; node6.next = &node7; node7.next = &node8;  node8.next = nullptr;

    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.myListreverseAListInGroupsOfGivenSize(&node1,0);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";

    //Test Case: more than one loop
    node1.val = 1; node2.val = 2; node3.val = 3; node4.val = 4;
    node5.val = 5; node6.val = 6; node7.val = 7; node8.val = 8;
    node1.next = &node2; node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = &node6; node6.next = &node7; node7.next = &node8;  node8.next = nullptr;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.myListreverseAListInGroupsOfGivenSize(&node1,1);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";


    //Test Case: more than one loop
    node1.val = 1; node2.val = 2; node3.val = 3; node4.val = 4;
    node5.val = 5; node6.val = 6; node7.val = 7; node8.val = 8;
    node1.next = &node2; node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = &node6; node6.next = &node7; node7.next = &node8;  node8.next = nullptr;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.myListreverseAListInGroupsOfGivenSize(&node1,10);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";


}
#endif

#if 0
TEST_CASE( "Zip A Linked List from its two ends", "Zip List" )
{
    cout << "Zip list from its two ends  \n\n";
    List node1; List node2; List node3; List node4; List node5; List node6;


    //Basic test case:
    node1.val = 1; node2.val = 2; node3.val = 3; node4.val = 4; node5.val = 5; node6.val = 6;
    node1.next = &node2; node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = &node6; node6.next = nullptr;
    List* temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    List * res = soln.zipAList(&node1);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";

    //Basic test case:
    node1.val = 1; node2.val = 2; node3.val = 3; node4.val = 4; node5.val = 5;
    node1.next = &node2; node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = nullptr;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.zipAList(&node1);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";

    //One node case
    node1.val = 1; node1.next = nullptr;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.zipAList(&node1);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";

    //Two node test case:
    node1.val = 1; node2.val = 2;
    node1.next = &node2; node2.next = nullptr;
    temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    res = soln.zipAList(&node1);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";

    //Three node test case:
    node1.val = 1; node2.val = 2; node3.val =3;
    node1.next = &node2; node2.next = &node3; node3.next = nullptr;
    temp = &node1;
    while(temp)
    {
            cout << " val = " << temp->val;
            temp = temp->next;
    }
    cout << "\n";
    res = soln.zipAList(&node1);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";
}
#endif


TEST_CASE( "LRU Cache", "LRU" )
{
    cout << "Implement all the basic functionality provided by LRU Cache \n\n";

    LRUCache cache;
    cache.set(1, 1);
    cache.set(2, 2);
    REQUIRE(cache.get(1) == 1);
    cache.set(3, 3);            // evicts key 2
    REQUIRE(cache.get(2) == -1);//not found
    cache.set(4, 4);            // evicts key 1
    REQUIRE(cache.get(1) == -1);//not found
    REQUIRE(cache.get(3) ==  3);
    REQUIRE(cache.get(4) ==  4);
}

int maxLenMatchingParen(string strParenExpression);


int testIKWork()
{

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

    //soln.prLR();
    //soln.mergeIntervals();
    //soln.findLargestRectangle();

#if 0
    //Sum Zero
    //vi intArr = {1,2,3,-10,8,-8,6,10};
    //vi intArr = {1,2,3,-10,8,6,10};
    //vi intArr = {};
    //vi intArr = {0,1,2,3,4,-10};
    //vi intArr = {0};
    vi intArr = {0,1,2,-3};
    //vi intArr = {1,2,3};
    //vi intArr = {1,2,5,-7,10};
    //vi intArr = {1,2,-3};

    vector<string> vs = soln.sumZero(intArr);
    cout << "final o/p is \n";
    for(unsigned int i = 0; i < vs.size(); i++)
    {
        cout << vs[i] << "\n";
    }

#endif

    //soln.printPascal(6);

    //checkIfPalindromeRotate

#if 0
    //Node node;
    vi v;

    Node node1; node1.val = 5; Node node2; node2.val = 5;
    Node node3; node3.val = 5; Node node4; node4.val = 5;
    Node node5; node5.val = 5; Node node6; node6.val = 5;
    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = NULL;   node3.right = &node6;
    node4.left = NULL;   node4.right = NULL;
    node5.left = NULL;   node5.right = NULL;
    node6.left = NULL;   node6.right = NULL;

    soln.countUniValSubtrees(&node1);
#endif

    //Node node1; node1.val = 100;
    //node1.left = NULL; node1.right = NULL;

    //Node node2; node2.val = 50; node2.left = NULL; node2.right = NULL;
    //Node node3; node3.val = 150;node3.left = NULL; node3.right = NULL;
    //Node node1; node1.val = 100;
    //node1.left = &node2; node1.right = &node3;
#if 1
    Node node4; node4.val = 25;node4.left = NULL; node4.right = NULL;
    Node node5; node5.val = 75;node5.left = NULL; node5.right = NULL;

    Node node6; node6.val = 125;node6.left = NULL; node6.right = NULL;
    Node node7; node7.val = 175;node7.left = NULL; node7.right = NULL;


    Node node2; node2.val = 50; node2.left = &node4; node2.right = &node5;
    Node node3; node3.val = 150;node3.left = &node6; node3.right = &node7;

    Node node1; node1.val = 100;


    node1.left = &node2; node1.right = &node3;
#endif
#if 0
    Node* ret = soln.treeToDoubleLL(&node1);

    Node* temp = ret;
    cout << "\n ";
    do
    {
        if(ret != temp)
            cout << " --> ";

        cout <<  temp->val;
        temp = temp->right;

    }while(temp && (temp != ret));

#endif

#if 0
    //unsigned int counter = 0;
    //unsigned int k = 3;
    //soln.findKThSmallestUtil(&node1, k, counter);
    //int rows = 8; int columns = 8; int sx = 0; int sy = 0; int ex = 7; int ey = 7;
    //int rows = 6; int columns = 6; int sx = 0; int sy = 0; int ex = 5; int ey = 5;
    //int rows = 3; int columns = 3; int sx = 0; int sy = 0; int ex = 2; int ey = 2;
    //soln.knightsTourOnChessBoard(rows, columns, sx, sy, ex, ey);
#endif

    //vector<string> strDict = {"caa", "aaa", "aab"};
    //vector<string> strDict = {"baa","abcd","abca","cab","cad"};
    //vector<string> strDict = {"aa", "bb", "cc", "dd", "ee"};
    //soln.topologicalSort(strDict); //m is the no of strings and n is the no of chars in string


    cout << "\n\n*********** End of IKMain *******************\n";

    return 0;
}



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

