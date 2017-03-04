#include<iostream>
#include<string>
#include<algorithm>
//#include"Solution.h"
#include<map>
#include "IKSolution.hpp"

#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
using namespace std;


IKSolution soln;


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


TEST_CASE( "Bloom filter tests", "[Bloom]" )
{

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

TEST_CASE( "Print all subsets", "subsets" )
{

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
    int endIndex = size;

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

    is.push_back("((())(((())");
    res.push_back(4);

    is.push_back("((())(((())))");
    res.push_back(12);


    int size = is.size();
    int startIndex = 0;
    int endIndex = size;

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


    //Test Case: One element.
    List node1; node1.val = 100; node1.next = nullptr;
    is.push_back(&node1);
    res.push_back(100);

    //Test Case: Two elements.
    List node1a; node1a.val = 100;
    List node1b; node1b.val = 200;
    node1a.next = &node1b;
    node1b.next = nullptr;
    is.push_back(&node1a);
    res.push_back(200);

    int size = is.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.findMiddleNode(is[i]) == res[i]);
    }
}



TEST_CASE( "Find the median of a sorted circular linked list", "Median" )
{
    cout << "Find the median of a sorted circular linked list \n\n";

    vector<List*> is;
    vector<int> res;

    List *ptr1 = nullptr;
    is.push_back(ptr1);
    res.push_back(0);

    //Test Case: One element.
    List node1; node1.val = 100; node1.next = &node1;
    is.push_back(&node1);
    res.push_back(100);

    //Test Case: Two elements.
    List node1a; node1a.val = 100;
    List node1b; node1b.val = 200;
    node1a.next = &node1b;
    node1b.next = &node1a;
    is.push_back(&node1b);
    res.push_back(100);

    //Test Case: Odd no of elements.
    List n1; List n2; List n3; List n4; List n5; List n6;
    n1.val = 100; n1.next = &n2;
    n2.val = 200; n2.next = &n3;
    n3.val = 300; n3.next = &n4;
    n4.val = 400; n4.next = &n5;
    n5.val = 500; n5.next = &n1;
    is.push_back(&n3);
    res.push_back(300);

    //Test Case: Even no of elements.
    n1.val = 100; n1.next = &n2;
    n2.val = 200; n2.next = &n3;
    n3.val = 300; n3.next = &n4;
    n4.val = 400; n4.next = &n5;
    n5.val = 500; n5.next = &n6;
    n6.val = 600; n6.next = &n1;
    is.push_back(&n3);
    res.push_back(300);

    int size = is.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.Median(is[i]) == res[i]);
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
    REQUIRE(cache.get(4) ==  4);//4 is followed by 3
    cache.set(4, 5);            //evicts key 1
    REQUIRE(cache.get(4) ==  5);//4 is followed by 3
    cache.remove(4);
    REQUIRE(cache.get(4) ==  -1);
    REQUIRE(cache.get(3) ==  3);
    cache.remove(10);


}

TEST_CASE( "Sliding Window Problem", "Sliding Window" )
{
    cout << "Sliding Window Problem \n\n";
    vector<vector<int>> is;
    vector<unsigned int> window;
    vector<vector<int>> res;

    vector<int> temp = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> restemp = {3, 3, 5, 5, 6, 7};
    is.push_back(temp);
    res.push_back(restemp);

    vector<int> temp1(temp.rbegin(),temp.rend());
    vector<int> restemp1 =  {7, 6, 5, 5, 3, 3};
    is.push_back(temp1);
    res.push_back(restemp1);

    vector<int> temp2 = {1,2,3};
    vector<int> restemp2 = {3};
    is.push_back(temp2);
    res.push_back(restemp2);


    int size = is.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Next test \n\n";
        REQUIRE(soln.slidingWindowMax(is[i],3) == res[i]);
    }
}


TEST_CASE( "Intersection of two lists", "Intersection" )
{
    cout << "Intersection of two Lists \n\n";

    list<int> L1;
    list<int> L2;

    L1.push_back(1);
    L1.push_back(2);
    L1.push_back(3);

    L2.push_back(21);
    L2.push_back(22);
    L2.push_back(23);

    REQUIRE(soln.interSectionOfTwoLists(L1, L2) == L1.end());
    REQUIRE(soln.interSectionOfTwoLists(L1, L1) == L1.begin());
}

TEST_CASE( "Levenstein Problem", "editDistance" )
{
    cout << "Levenstein Problem for source string to destination string \n\n";

    vector<string> is1;
    vector<string> is2;
    vector<int> res;

    is1.push_back("k");
    is2.push_back("k");
    res.push_back(0);

    is1.push_back("k");
    is2.push_back("s");
    res.push_back(1);


    //Case 2:
    is1.push_back("ki");
    is2.push_back("si");
    res.push_back(1);

    //Case 3:
    is1.push_back("kit");
    is2.push_back("bat");
    res.push_back(2);

    //Case 4:
    is1.push_back("kit");
    is2.push_back("kat");
    res.push_back(1);

    //Case 5:Insert test
    is1.push_back("kith");
    is2.push_back("kaui");
    res.push_back(3);

    //Case 6: Delete tests
    is1.push_back("kit");
    is2.push_back("ka");
    res.push_back(2);

    //Case 7:
    is1.push_back("kith");
    is2.push_back("kui");
    res.push_back(3);

    //Case 8:
    is1.push_back("kit");
    is2.push_back("kjitt");
    res.push_back(2);

    //Case 9: Insert next to i
    is1.push_back("kit");
    is2.push_back("kijt");
    res.push_back(1);

    //Case 10:
    is1.push_back("geek");
    is2.push_back( "gesek");
    res.push_back(1);

    //Case 11:
    is1.push_back("cat");
    is2.push_back( "cut");
    res.push_back(1);


    //Case 12:
    is1.push_back("kitten");
    is2.push_back("sitting");
    res.push_back(3);

    //Case 13;
    is1.push_back("sunday");
    is2.push_back( "sunday");
    res.push_back(0);

    //Case 14;
    is1.push_back("sunday");
    is2.push_back( "saturday");
    res.push_back(3);



    int size = is1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "\n\n******************Test " << i <<": str1 = " << is1[i] << " str2 = " << is2[i] << "*****************\n";
        REQUIRE(soln.editDistance(is1[i],is2[i]) == res[i]);
        cout << "Test " << i <<": Pass \n";
    }


}


TEST_CASE( "Word Break", "Word Break" )
{
    cout << "Word break using DP problem \n\n";

    vector<string> is1;
    vector<vector<string>> is2;
    vector<vector<string>> res;

    is1.push_back("catbat");
    vector<string> is11 = {"cat", "bat"};
    is2.push_back(is11);
    vector<string> res1 = {"bat", "cat"};
    res.push_back(res1);

    is1.push_back("chocoapplepie");
    is11 = {"pie", "apple","raghav", "choco", "app"};
    is2.push_back(is11);
    res1 =  { "pie", "apple", "choco" };
    res.push_back(res1);


    is1.push_back("applepie");
    is11 = {"pie", "app","apple", "let", "pie"};
    is2.push_back(is11);
    res1 = {"pie", "apple"};
    res.push_back(res1);

    is1.push_back("interviewkickstart");
    is11 =  {"a", "e", "i", "int", "inter", "interview", "kick", "kicker", "kickstart", "star", "start", "view"};
    is2.push_back(is11);
    res1 = { "start", "kick", "view", "inter" };
    res.push_back(res1);

    is1.push_back("interviewkickstart");
    is11 =  {"interview", "kick", "kstart", "kicks"};
    is2.push_back(is11);
    res1 = {};
    res.push_back(res1);

    int size = is1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Test" << i <<": str1 = " << is1[i] << " \n";
        REQUIRE(soln.wordBreak(is1[i],is2[i]) == res[i]);
    }

}
/*
186, 119, 83, 408
6249
*/
TEST_CASE( "Make Change", "Make Change" )
{
    cout << "Make Change \n\n";

    vector<int> i1;
    vector<vector<int>> i2;
    vector<int> i2t;
    vector<vector<int>> res;
    vector<int> rest;

    //Case 0
    i1.push_back(0);
    i2t = {1,2,3};
    i2.push_back(i2t);
    rest = {};
    res.push_back(rest);

    i1.push_back(100);
    i2t = {};
    i2.push_back(i2t);
    rest = {};
    res.push_back(rest);


    i1.push_back(4);
    i2t = {1,2,3};
    i2.push_back(i2t);
    rest = {3, 1};
    res.push_back(rest);

    i1.push_back(10);
    i2t.clear();
    i2t = {2, 5, 3, 6};
    i2.push_back(i2t);
    rest = {5,5};
    res.push_back(rest);

    i1.push_back(4);
    i2t = {3,1,2,3};
    i2.push_back(i2t);
    rest = {1,3};
    res.push_back(rest);

    //5
    i1.push_back(67);
    i2t.clear();
    i2t = {2, 5, 3, 6};
    i2.push_back(i2t);
    rest = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 2 };
    res.push_back(rest);

    //6
    i1.push_back(151);
    i2t.clear();
    i2t = {2, 5, 3, 6, 100};
    i2.push_back(i2t);
    rest =  { 100, 6, 6, 6, 6, 6, 6, 5, 5, 5 };
    res.push_back(rest);

    i1.push_back(6249);
    i2t.clear();
    i2t = {186, 419, 83, 408};
    i2.push_back(i2t);
    rest =  { 408, 408, 408, 408, 408 , 408, 408 , 408, 83, 83, 83, 83, 419, 419,
      419, 419, 419, 186, 186, 186};
    res.push_back(rest);

    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Test" << i <<": C = " << i1[i] << " \n";
        REQUIRE(soln.makeChange(i1[i],i2[i]) == res[i]);
    }
}


TEST_CASE( "Number of phone no combinations", "Number of phone no combinations" )
{
    cout << "Test: Number of phone no combinations using Knight's tour \n\n";

    vector<int> i1;
    vector<int> i2;
    vector<int> res;

    //0
    i1.push_back(1);
    i2.push_back(10);
    res.push_back(1424);

    //1
    i1.push_back(1);
    i2.push_back(5);
    res.push_back(26);

    //2
    i1.push_back(6);
    i2.push_back(10);
    res.push_back(2304);

    //3
    i1.push_back(6);
    i2.push_back(20);
    res.push_back(9068032);

    //4
    i1.push_back(5);
    i2.push_back(20);
    res.push_back(0);

    //5
    i1.push_back(9);
    i2.push_back(13);
    res.push_back(19520);

    //6
    i1.push_back(6);
    i2.push_back(30);
    res.push_back(1329676288);

    i1.push_back(1);
    i2.push_back(30);
    res.push_back(582434816);

    i1.push_back(3);
    i2.push_back(25);
    res.push_back(402264064);


    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "Test" << i <<": Start digit = " << i1[i] << " no of digits " << i2[i] << " \n";
        REQUIRE(soln.numPhoneNumbers(i1[i],i2[i]) == res[i]);
    }
}

TEST_CASE( "Max Stolen Value", "Max Stolen Value")
{
    cout << "Test: Max Stolen Value \n\n";

    vector<vector<int>> i1;
    vector<int> res;
    vector<int> itemp;

    //0
    itemp = {6,1,2,7};
    i1.push_back(itemp);
    res.push_back(13);

    //1
    itemp = {4,6,1,2,7};
    i1.push_back(itemp);
    res.push_back(13);

    //2
    itemp = {1,2,3,4,5};
    i1.push_back(itemp);
    res.push_back(9);

    //3
    itemp = {99,99,99,99};
    i1.push_back(itemp);
    res.push_back(198);

    //4
    itemp = {4,6,1,2,7,100,3,51,23,34};
    i1.push_back(itemp);
    res.push_back(193);

    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.maxStolenValue(i1[i]) == res[i]);
    }
}



TEST_CASE( "Count ways to reach the Nth Stair", "Count ways to reach the Nth Stair")
{
    cout << "Test: Count ways to reach the Nth Stair\n\n";

    vector<vector<int>> i1; //numSteps
    vector<int> i2;
    vector<int> res;
    vector<int> itemp;

    //0
    itemp = {1};
    i1.push_back(itemp);
    i2.push_back(0); //reach 0th step
    res.push_back(1);

    //1
    itemp = {1};
    i1.push_back(itemp);
    i2.push_back(1);
    res.push_back(1);

    //2
    itemp = {1};
    i1.push_back(itemp);
    i2.push_back(2);
    res.push_back(1);

    //3
    itemp = {1,2};
    i1.push_back(itemp);
    i2.push_back(4);
    res.push_back(5);

    //4
    itemp = {1,2};
    i1.push_back(itemp);
    i2.push_back(2);
    res.push_back(2);

    //5
    itemp = {1,2};
    i1.push_back(itemp);
    i2.push_back(10);
    res.push_back(89);

    //6
    itemp = {1,2};
    i1.push_back(itemp);
    i2.push_back(25);
    res.push_back(121393);

    //7
    itemp = {2, 3};
    i1.push_back(itemp);
    i2.push_back(6);
    res.push_back(2);

    //8
    itemp = {2, 3};
    i1.push_back(itemp);
    i2.push_back(9);
    res.push_back(5);

    //9
    itemp = {2, 3, 5};
    i1.push_back(itemp);
    i2.push_back(25);
    res.push_back(2652);

    //10
    itemp = {1, 2};
    i1.push_back(itemp);
    i2.push_back(15);
    res.push_back(987);

    //11
    itemp = {3, 4, 7};
    i1.push_back(itemp);
    i2.push_back(20);
    res.push_back(42);

    //12
    itemp = {4, 4};
    i1.push_back(itemp);
    i2.push_back(22);
    res.push_back(0);

    //13
    itemp = {2, 3, 5};
    i1.push_back(itemp);
    i2.push_back(50);
    res.push_back(19908673);


    itemp = {1, 2};
    i1.push_back(itemp);
    i2.push_back(35);
    res.push_back(14930352);

    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.numWaysToClimb(i1[i],i2[i]) == res[i]);
    }
}

//int maxWin(vector < int > intCoins);
TEST_CASE( "Coin Play: Max money", "Coin Play: Max money")
{
    cout << "Test: Coin Play: Max money\n\n";

    vector<vector<int>> i1;
    vector<int> res;
    vector<int> itemp;

    //0
    itemp = {8, 15, 3, 7};
    i1.push_back(itemp);
    res.push_back(22);

    itemp = {1, 5};
    i1.push_back(itemp);
    res.push_back(5);

    itemp = {5, 3, 7, 10};
    i1.push_back(itemp);
    res.push_back(15);

    //3
    itemp = {149, 154, 63, 242, 12, 72, 65};
    i1.push_back(itemp);
    res.push_back(289);

    //4
    itemp =  { 135, 174, 220, 51, 88, 212, 162, 132, 97, 163, 54, 185};
    i1.push_back(itemp);
    res.push_back(917);

    //5
    itemp =  { 218, 64, 128, 239, 188, 193, 221, 217,
               159, 97, 91, 140, 11, 54, 206, 227,
               48, 102, 121, 221, 68, 174, 79, 39,
               113, 72, 108, 144, 98, 249, 100, 188,
               165, 18, 64, 159, 186, 30, 199, 192,
               130, 26, 188, 62, 81, 234, 97, 82, 95};
    i1.push_back(itemp);
    res.push_back(3149);

    //6
    itemp =  { 56, 190, 138, 31, 17, 163,
      226, 27, 45, 108, 150, 75,
      69, 139, 28, 103, 21, 9,
      31, 139, 97, 76, 18, 186, 125, 174, 235, 95, 185, 36, 152, 236, 48, 85, 43, 58, 21, 138,
      40, 138, 29, 240, 73, 162, 239, 90, 46, 160, 185 };
    i1.push_back(itemp);
    res.push_back(2317);


    itemp =  {69, 164, 249, 247, 219, 105, 94, 194, 200, 146, 0, 180, 78};
    i1.push_back(itemp);
    res.push_back(909);


    itemp =  {73, 220, 192, 205, 25, 187, 51, 214, 11,
    147, 102, 212, 67, 107, 11, 65, 116, 41,
    73, 96, 135, 142, 156, 162};
    i1.push_back(itemp);
    res.push_back(1798);



    itemp = {120, 194, 81, 197, 58, 224, 10,
    67, 29, 177, 71, 59, 178, 139, 1, 54, 210, 194, 172, 156, 144, 14, 117,  172, 89, 132, 138, 7, 95, 181, 226, 108, 69,
    224, 42, 103};
    i1.push_back(itemp);
    res.push_back(2402);


    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.maxWin(i1[i]) == res[i]);
    }
}


TEST_CASE( "Max Product for rope", "Max Product for rope")
{
    cout << "Test: Max Product for rope\n\n";

    vector<int> i1;
    vector<int> res;

    //0
    i1.push_back(4);
    res.push_back(4);

    i1.push_back(10);
    res.push_back(36);

    i1.push_back(2);
    res.push_back(1);


    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.maxProductFromCutPieces(i1[i]) == res[i]);
    }


}



TEST_CASE( "Longest Substring Length", "Longest Substring Length")
{
    cout << "Test: Longest Substring Length\n\n";

    vector<string> i1;
    vector<string> res;

    //0
    i1.push_back("ABBB");
    res.push_back("ABBB");

    //1
    i1.push_back("ABBBC");
    res.push_back("ABBB");

    //2
    i1.push_back("ABBBCCCCC");
    res.push_back("BBBCCCCC");

    //3
    i1.push_back("ABBBCCCCCDDDD");
    res.push_back("CCCCCDDDD");

    //4
    i1.push_back("ABBBCCCCCDDDDE");
    res.push_back("CCCCCDDDD");

    //5
    i1.push_back("ABC");
    res.push_back("AB");

    //6
    i1.push_back("ECEBA");
    res.push_back("ECE");

    //7
    i1.push_back("AAAAAA");
    res.push_back("");

    //8
    i1.push_back("AAAAAB");
    res.push_back("AAAAAB");

    //9
    i1.push_back("A");
    res.push_back("");


    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.longestSub(i1[i]) == res[i]);
    }
}

TEST_CASE( "Join words to make palindrome", "Join words to make palindrome")
{
    cout << "Test: Join words to make palindrome\n\n";

    vector< vector<string> > i1;
    vector<vector<pair<string,string>>>  res;

    //0
    vector<string> i = {"bat", "tab", "cat"};
    i1.push_back(i);
    vector<pair<string,string>> r;

    //1
     i = {"bat", "tab", "cat", "tac"};
    i1.push_back(i);


    pair<string,string> s = make_pair("bat", "tab");
    r.push_back(s);
    s =  make_pair("cat", "tac");
    r.push_back(s);
    res.push_back(r);


    i = {"ab", "deedba"};
    i1.push_back(i);

    i = {"ant", "cat", "dog"};
    i1.push_back(i);


    i = {"abcd", "dcba", "lls", "s", "sssll"};
    i1.push_back(i);
    //Return [[0, 1], [1, 0], [3, 2], [2, 4]]
    //The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        soln.joinWordToMakePali(i1[i]);
    }
}

TEST_CASE( "Regular Expression Matcher", "Regular Expression Matcher")
{
    cout << "Test: Regular Expression Matcher\n\n";


    vector<string> i1;
    vector<string> i2;
    vector<bool>  res;

    //0
    i1.push_back("aab");
    i2.push_back("c*a*b");
    res.push_back(true);

    //1
    i1.push_back("aa");
    i2.push_back("a");
    res.push_back(false);

    //2
    i1.push_back("aa");
    i2.push_back("aa");
    res.push_back(true);

    //3
    i1.push_back("ab");
    i2.push_back("a*b");
    res.push_back(true);

    //4
    i1.push_back("aaa");
    i2.push_back("aa");
    res.push_back(false);

    //5
    i1.push_back("aa");
    i2.push_back("a*");
    res.push_back(true);

    //6
    i1.push_back("aa");
    i2.push_back("ab");
    res.push_back(false);

    //7
    i1.push_back("aac");
    i2.push_back("aab");
    res.push_back(false);

    //8
    i1.push_back("aabc");
    i2.push_back("aabc");
    res.push_back(true);

    //9
    i1.push_back("aabc");
    i2.push_back("aab");
    res.push_back(false);

    //10
    i1.push_back("aab");
    i2.push_back("aabc");
    res.push_back(false);

    //11
    i1.push_back("aab");
    i2.push_back("aa.");
    res.push_back(true);

    //12
    i1.push_back("aabc");
    i2.push_back("aa.c");
    res.push_back(true);

    //13
    i1.push_back("aab");
    i2.push_back("aa.");
    res.push_back(true);

    //14
    i1.push_back("abc");
    i2.push_back(".*c");
    res.push_back(true);

    //15
    i1.push_back("aa");
    i2.push_back(".*");
    res.push_back(true);

    //16
    i1.push_back("aaaaaa");
    i2.push_back(".a*");
    res.push_back(true);


    i1.push_back("caab");
    i2.push_back("c*a*b");
    res.push_back(true);

    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.regExMatcher(i1[i], i2[i]) == res[i]);
    }


}


TEST_CASE( "Initial tests", "Inits" )
{
    cout << "Initial tests \n\n";

    soln.prLR();
    soln.mergeIntervals();
    soln.findLargestRectangle();
    soln.printPascal(6);

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

    //Node node1; node1.val = 100;
    //node1.left = NULL; node1.right = NULL;
    //Node node2; node2.val = 50; node2.left = NULL; node2.right = NULL;
    //Node node3; node3.val = 150;node3.left = NULL; node3.right = NULL;
    //Node node1; node1.val = 100;
    //node1.left = &node2; node1.right = &node3;
    Node node41; node41.val = 25;node41.left = NULL; node41.right = NULL;
    Node node51; node51.val = 75;node51.left = NULL; node51.right = NULL;
    Node node61; node61.val = 125;node61.left = NULL; node61.right = NULL;
    Node node71; node71.val = 175;node71.left = NULL; node71.right = NULL;
    Node node21; node21.val = 50; node21.left = &node41; node21.right = &node51;
    Node node31; node31.val = 150;node31.left = &node61; node31.right = &node71;
    Node node11; node11.val = 100;
    node11.left = &node21; node11.right = &node31;
    Node* ret = soln.treeToDoubleLL(&node11);
    Node* temp = ret;
    cout << "\n ";
    do
    {
        if(ret != temp)
            cout << " --> ";

        cout <<  temp->val;
        temp = temp->right;

    }while(temp && (temp != ret));


    unsigned int counter = 0;
    unsigned int k = 3;
    soln.findKThSmallestUtil(&node1, k, counter);



}

TEST_CASE( "knights Tour On Chess Board", "knights Tour On Chess Board")
{
    //int rows = 8; int columns = 8; int sx = 0; int sy = 0; int ex = 7; int ey = 7;
    //int rows = 6; int columns = 6; int sx = 0; int sy = 0; int ex = 5; int ey = 5;
    int rows = 3; int columns = 3; int sx = 0; int sy = 0; int ex = 2; int ey = 2;
    soln.knightsTourOnChessBoard(rows, columns, sx, sy, ex, ey);
}

TEST_CASE( "Topological Sort", "Topological Sort")
{
    vector<string> strDict1 = {"caa", "aaa", "aab"};
    vector<string> strDict2 = {"baa","abcd","abca","cab","cad"};
    vector<string> strDict3 = {"aa", "bb", "cc", "dd", "ee"};
    soln.topologicalSort(strDict1); //m is the no of strings and n is the no of chars in string
    soln.topologicalSort(strDict2); //m is the no of strings and n is the no of chars in string
    soln.topologicalSort(strDict3); //m is the no of strings and n is the no of chars in string
}



