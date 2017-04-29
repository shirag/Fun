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


TEST_CASE( "Magic Map", "Magic Map")
{

    soln.setVal("poomba", 2);
    soln.setVal("raghav", 41);
    soln.setVal("shivani", 35);
    soln.setVal("shourya", 4);
    soln.setVal("Lakshmi", 2);

    cout << soln.getValue("raghav");

    soln.deleteVal("poomba");
    soln.setVal("Mussaffa", 50);
    soln.setVal("Raffiki", 25);

    int i = 0;
    while(i < 20)
    {
        cout << soln.getRandomVal();
        cout << "\n";
        i++;
    }

}

TEST_CASE( "Find Max Sum Sub Array(Kadane's algo)", "Find Max Sum Sub Array(Kadane's algo)" )
{

    cout << "Find Max Sum Sub Array(Kadane's algo)";

    //0
    vector<int> i1 = {1, 2, 3, 4, 5};
    REQUIRE(soln.findMaxSumSubArray(i1) == 15);

    i1 = {1, 2, 3, 4, 5, -15};
    REQUIRE(soln.findMaxSumSubArray(i1) == 15);

    i1 = {1, 2, 3, 4, 5, -15, 14};
    REQUIRE(soln.findMaxSumSubArray(i1) == 15);

    i1 = {1, 2, 3, 4, 5, -15, 14, 3};
    REQUIRE(soln.findMaxSumSubArray(i1) == 17);

    i1 = {1, 2, 3, 4, 5, -15, 14, 3, 3};
    REQUIRE(soln.findMaxSumSubArray(i1) == 20);

    i1 = {1, 2, 3, 4, 5, -15, 14, 3, 3, -15};
    REQUIRE(soln.findMaxSumSubArray(i1) == 20);

    i1 = {1, 2, 3, 4, 5, -15, 14, 3, 3, -15, 20};
    REQUIRE(soln.findMaxSumSubArray(i1) == 25);

    i1 = {1, 2, 3, 4, 5, -15, 14, 3, 3, -15, 20, -25};
    REQUIRE(soln.findMaxSumSubArray(i1) == 25);

    i1 = {-1, -2, -3};
    REQUIRE(soln.findMaxSumSubArray(i1) == 25);

    cout << "\n";
}



TEST_CASE( "Find the duplicate that occurs once", "Find the duplicate that occurs once" )
{
    vector<int> v = {1,2,3,4,4};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 4);

    v = {4,4,3,1,2};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 4);

    v = {4,3,3,1,2};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 3);

    v = {4,1,3,3,2};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 3);

    v = {1,1,4,3,2};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 1);

    v = {1,1,1,3,2};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 1);

    v = {1,1,1,1,2};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 1);

    v = {1,1,1,1,1};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 1);

    v = {4,1,3,2,4};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 4);

    v = {1,3,2,3};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 3);

    v = {1,3,2,3,4,5};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 3);

    v = {1,3,2,3,5,4};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 3);

    v = {1,3,2,3,2,4};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 2);

    v = {1,3,2,3,2,1};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 1);

    v = {5,3,2,1,4,5};
    REQUIRE(soln.findDuplicateThatOccursOnce(v) == 5);

}

TEST_CASE( "Arrays tests", "Arrays tests" )
{
    cout << "Arrays tests \n\n";
    vi vr;
    vi intArr;
    vector<string> vs;

    soln.prLR();

    vpii v1; vpii res;
    v1.push_back(make_pair(1,3));
    v1.push_back(make_pair(2,4));
    v1.push_back(make_pair(5,7));
    v1.push_back(make_pair(6,8));
    res.push_back(make_pair(1,4));
    res.push_back(make_pair(5,8));
    soln.mergeIntervals(v1);

    REQUIRE(soln.mergeIntervals(v1) == res);

    cout << "Largest rectangle test \n";
    vr = {10,20,30};
    REQUIRE(soln.findLargestRectangle(vr) == 40);

    vr = {10,40,30};
    REQUIRE(soln.findLargestRectangle(vr) == 60);

    vr = {10,20,20,30,10};
    REQUIRE(soln.findLargestRectangle(vr) == 60);

    soln.printPascal(6);

    cout << "********* Sum zero tests *****************\n";
    vr = {1,2,3,-10,8,-8,6,10};
    vs = soln.sumZero(intArr);
    for(unsigned int i = 0; i < vs.size(); i++)
        cout << vs[i] << " ";
    cout << "\n";

    intArr = {1,2,3,-10,8,6,10};
    vs = soln.sumZero(intArr);
    for(unsigned int i = 0; i < vs.size(); i++)
        cout << vs[i] <<  " ";
    cout << "\n";


    intArr = {};
    vs = soln.sumZero(intArr);
    for(unsigned int i = 0; i < vs.size(); i++)
        cout << vs[i] <<  " ";
    cout << "\n";

    intArr = {0,1,2,3,4,-10};
    vs = soln.sumZero(intArr);
    for(unsigned int i = 0; i < vs.size(); i++)
        cout << vs[i] <<  " ";
    cout << "\n";


    intArr = {0};
    vs = soln.sumZero(intArr);
    for(unsigned int i = 0; i < vs.size(); i++)
        cout << vs[i] <<  " ";
    cout << "\n";


    intArr = {0,1,2,-3};
    vs = soln.sumZero(intArr);
    for(unsigned int i = 0; i < vs.size(); i++)
        cout << vs[i] <<  " ";
    cout << "\n";

    intArr = {1,2,3};
    vs = soln.sumZero(intArr);
    for(unsigned int i = 0; i < vs.size(); i++)
        cout << vs[i] <<  " ";
    cout << "\n";

    intArr = {1,2,5,-7,10};
    vs = soln.sumZero(intArr);
    for(unsigned int i = 0; i < vs.size(); i++)
        cout << vs[i] <<  " ";
    cout << "\n";

    intArr = {1,2,-3};
    vs = soln.sumZero(intArr);
    for(unsigned int i = 0; i < vs.size(); i++)
        cout << vs[i] <<  " ";
    cout << "\n";
}




TEST_CASE( "Next Palindrome", "Next Palindrome" )
{

    //0
    int i1 = 23545;
    int res = 23632;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //1
    i1 = 6789876;
    res = 6790976;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //2
    i1 = 4332;
    res = 4334;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //3
    i1 = 4336;
    res = 4334;
    REQUIRE(soln.nextPalindrome(i1) == res);


    //4
    i1 = 8998;
    res = 9009;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //5
    i1 = 9999;
    res = 10001;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //6
    i1 = 99;
    res = 101;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //7
    i1 = 1234;
    res = 1331;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //8
    i1 = 1;
    res = 2;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //9
    i1 = 1234; //Not a palindrome
    res = 1331;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //10
    i1 = 999;
    res = 1001;
    REQUIRE(soln.nextPalindrome(i1) == res);

    //11
    i1 = 8998;
    res = 9009;
    REQUIRE(soln.nextPalindrome(i1) == res);


}

TEST_CASE( "Alternate Positive and Negative", "Alternate Positive and Negative" )
{

    //0
    vector<int> i1 =  {2, 3, -4, -9, -1, -7, 1, -5, -6};
    vector<int> res =  {2, -4, 3, -9, 1, -1, -7, -5, -6};
    REQUIRE(soln.AlternatePosNegative(i1) == res);

    //1
    i1 =  { 1, 2, 3, -4, -1, 4};
    res =  {1, -4, 2, -1, 3, 4};
    REQUIRE(soln.AlternatePosNegative(i1) == res);


    //2
    i1 = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    res =  {5, -5, 2, -2, 4, 0, 7, -8, 1, 8};
    REQUIRE(soln.AlternatePosNegative(i1) == res);


}

TEST_CASE( "Sky Line", "Sky Line" )
{
    vvi ip;
    vector<pair<int,int>> res;

    //0
    ip = {{1, 11, 5}, {2, 6, 7}, {3, 13, 9}, {12, 7, 16}, {14, 3, 25},
            {19, 18, 22}, {23, 13, 29}, {24, 4, 28}};
    res.push_back(make_pair(1,11));
    res.push_back(make_pair(3,13));
    res.push_back(make_pair(9,0));
    res.push_back(make_pair(12,7));
    res.push_back(make_pair(16,3));
    res.push_back(make_pair(19,18));
    res.push_back(make_pair(22,3));
    res.push_back(make_pair(23,13));
    res.push_back(make_pair(29,0));
    REQUIRE(soln.skyLine(ip) == res);
    res.clear();

    //1
    ip = {{2,10,9},{3,15,7},{5,12,12},{15,10,20},{19,8,24}};
    res.push_back(make_pair(2,10));
    res.push_back(make_pair(3,15));
    res.push_back(make_pair(7,12));
    res.push_back(make_pair(12,0));
    res.push_back(make_pair(15,10));
    res.push_back(make_pair(20,8));
    res.push_back(make_pair(24,0));
    REQUIRE(soln.skyLine(ip) == res);
    res.clear();

    //2
    ip = {{1,11,5}};
    res.push_back(make_pair(1,11));
    res.push_back(make_pair(5,0));
    REQUIRE(soln.skyLine(ip) == res);
    res.clear();

    //3
    ip = {{0,2147483647,2147483647}};
    res.push_back(make_pair(0,2147483647));
    res.push_back(make_pair(2147483647,0));
    REQUIRE(soln.skyLine(ip) == res);
    res.clear();


    //4
    ip = {{1,1,2},{1,2,2},{1,3,2}};
    res.push_back(make_pair(1,3));
    res.push_back(make_pair(2,0));
    REQUIRE(soln.skyLine(ip) == res);
    res.clear();
}


TEST_CASE( "Run Length Encoding", "Run Length Encoding" )
{
    //0
    string ip = "AAAAA";
    string res = "5A";
    REQUIRE(soln.RLE(ip) == res);

    ip = "BAAAB";
    res = "B3AB";
    REQUIRE(soln.RLE(ip) == res);

    ip = "ABAB";
    res = "ABAB";
    REQUIRE(soln.RLE(ip) == res);

}

TEST_CASE( "Find minimum in a rotated sorted array", "Find minimum in a rotated sorted array" )
{
    //0
    vector<int> i1 = {85,87,88,98,99,55,56,57,58};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 55);
    cout << "\n\n\n";

    //1
    i1 = {1,2,3};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //2
    i1 = {3,1,2};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //3
    i1 = {2,3,1};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //4
    i1 = {1,2};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //5
    i1 = {2,1};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //6
    i1 = {5, 6, 1, 2, 3, 4};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //7
    i1 = {5, 6, 1, 2, 3};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //8
    i1 = {3, 5, 6, 1, 2};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //9
    i1 = {5, 1, 2, 3, 4};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //10
    i1 = {1, 2, 3, 4};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //11
    i1 = {2, 3, 4, 1};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //12
    i1 = {1, 2, 3, 4};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";

    //13
    i1 = {1, 2, 3, 4, 5};
    cout << "next test \n"; for(auto it:i1) cout << it << " ";;cout << "\n";
    REQUIRE(soln.findMinimum(i1) == 1);
    cout << "\n\n\n";


}


TEST_CASE( "How Many bits set(Hamming Weight)", "How Many bits set(Hamming Weight)" )
{

    //0
    vector<int> i1 = {31, 51};
    REQUIRE(soln.printCountOfBitsSet(i1) == 9);

    i1 = {2147483647, 3};
    REQUIRE(soln.printCountOfBitsSet(i1) == 33);
    cout << "\n\n\n";
}




Node root;
Node node1; Node node3; Node node2;
Node node4; Node node5; Node node6; Node node7;
Node node8; Node node9; Node node10; Node node11; Node node12; Node node13; Node node14; Node node15;
Node node41; Node node51; Node node61; Node node71; Node node21; Node node31;


TEST_CASE( "Trees tests", "Trees tests" )
{


    node1.val = 3; node2.val = 4;
    node3.val = 5;

    node2.left = &node1;
    node2.right = &node3;
    node1.left = NULL; node1.right = NULL;
    node3.left = NULL; node3.right = NULL;
    REQUIRE(soln.isBST(&node2) == true);

    /***********************************************************/
    REQUIRE(soln.findKThSmallest(&node2, 1) == 3);
    REQUIRE(soln.findKThSmallest(&node2, 2) == 4);
    REQUIRE(soln.findKThSmallest(&node2, 3) == 5);


    node1.val = 8; node2.val = 20; node3.val = 22;
    node4.val = 4; node5.val = 12; node6.val = 10; node7.val = 14;

    node2.left = &node1; node2.right = &node3;
    node1.left = &node4; node1.right = &node5;
    node3.left = NULL; node3.right = NULL;
    node4.left = NULL; node4.right = NULL;
    node5.left = &node6; node5.right = &node7;
    node6.left = NULL; node6.right = NULL;
    node7.left = NULL; node7.right = NULL;

    REQUIRE(soln.findKThSmallest(&node2, 3) == 10);
    REQUIRE(soln.findKThSmallest(&node2, 5) == 14);
    /***********************************************************/

    cout << "Level Order Print test \n";
    //Test "Construct tree from Arrays" tests this one.
    soln.treeLevelOrderPrint(&node2);
    cout << "\n";
    /************************************************************/


    cout << "********* Count uni val sub trees *****************\n";
    node1.val = 5; node2.val = 5;
    node3.val = 5; node4.val = 5;
    node5.val = 5; node6.val = 5;
    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = NULL;   node3.right = &node6;
    node4.left = NULL;   node4.right = NULL;
    node5.left = NULL;   node5.right = NULL;
    node6.left = NULL;   node6.right = NULL;
    soln.countUniValSubtrees(&node1);

    /*************************************************************/

    node41.val = 25;  node41.left = NULL; node41.right = NULL;
    node51.val = 75;  node51.left = NULL; node51.right = NULL;
    node61.val = 125; node61.left = NULL; node61.right = NULL;
    node71.val = 175; node71.left = NULL; node71.right = NULL;
    node21.val = 50;  node21.left = &node41; node21.right = &node51;
    node31.val = 150; node31.left = &node61; node31.right = &node71;
    node11.val = 100; node11.left = &node21; node11.right = &node31;
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

    cout << "\n\n\n";
}

TEST_CASE( "Print all paths in a tree", "Print all paths in a tree")
{
    cout << "Print all paths in a tree \n";

    node1.val = 3; node2.val = 4;
    node3.val = 5;
    node2.left = &node1;
    node2.right = &node3;
    node1.left = NULL; node1.right = NULL;
    node3.left = NULL; node3.right = NULL;
    soln.printAllPathsInATee(&node2);
    vvi expected = {{4,3}};
    REQUIRE(soln.printAllPathsInATeeToASum(&node2, 7) == expected);

    node1.val = 8; node2.val = 20; node3.val = 22;
    node4.val = 4; node5.val = 12; node6.val = 10; node7.val = 14;
    node2.left = &node1; node2.right = &node3;
    node1.left = &node4; node1.right = &node5;
    node3.left = &node6; node3.right = &node7;
    node4.left = NULL; node4.right = NULL;
    node5.left = NULL; node5.right = NULL;
    node6.left = NULL; node6.right = NULL;
    node7.left = NULL; node7.right = NULL;
    soln.printAllPathsInATee(&node2);
    expected = {{20, 22, 14}};
    REQUIRE(soln.printAllPathsInATeeToASum(&node2, 56) == expected);

    node1.val = 8; node2.val = 20; node3.val = 22;
    node4.val = 4; node5.val = 12; node6.val = 10; node7.val = 14;
    node8.val = 4;
    node2.left = &node1; node2.right = &node3;
    node1.left = &node4; node1.right = &node5;
    node3.left = &node6; node3.right = &node7;
    node4.left = NULL; node4.right = NULL;
    node5.left = NULL; node5.right = NULL;
    node6.left = NULL; node6.right = &node8;
    node7.left = NULL; node7.right = NULL;
    node8.left = NULL; node8.right = NULL;
    soln.printAllPathsInATee(&node2);
    expected = {{20, 22, 10, 4}, {20, 22, 14}};
    REQUIRE(soln.printAllPathsInATeeToASum(&node2, 56) == expected);


    node1.val = 8; node2.val = 20; node3.val = 22;
    node4.val = 4; node5.val = 12; node6.val = 10; node7.val = 14;
    node8.val = 4;
    node2.left = &node1; node2.right = &node3;
    node1.left = &node4; node1.right = &node5;
    node3.left = &node6; node3.right = &node7;
    node4.left = NULL; node4.right = &node9; node9.val = -1;
    node5.left = NULL; node5.right = NULL;
    node6.left = NULL; node6.right = &node8;
    node7.left = NULL; node7.right = NULL;
    node8.left = NULL; node8.right = NULL;
    node9.left = NULL; node9.right = NULL;
    soln.printAllPathsInATee(&node2);
    expected = {};
    REQUIRE(soln.printAllPathsInATeeToASum(&node2, 32) == expected);


    node1.val = 8; node2.val = 20; node3.val = 22;
    node4.val = 4; node5.val = 12; node6.val = 10; node7.val = 14;
    node2.left = &node1; node2.right = &node3;
    node1.left = &node4; node1.right = &node5;
    node3.left = NULL; node3.right = NULL;
    node4.left = NULL; node4.right = NULL;
    node5.left = &node6; node5.right = &node7;
    node6.left = NULL; node6.right = NULL;
    node7.left = NULL; node7.right = NULL;
    soln.printAllPathsInATee(&node2);


    cout << "Print all paths in a tree that sum to k \n";

    node1.val = 3; node2.val = 4;
    node3.val = 3;
    node2.left = &node1;
    node2.right = &node3;
    node1.left = NULL; node1.right = NULL;
    node3.left = NULL; node3.right = NULL;
    expected = {{4,3}, {4,3}};
    REQUIRE(soln.printAllPathsInATeeToASum(&node2, 7) == expected);


    node1.val = 3; node2.val = 4;
    node3.val = 3;
    node2.left = &node1;
    node2.right = &node3;
    node1.left = NULL; node1.right = NULL;
    node3.left = NULL; node3.right = NULL;
    expected = {};
    REQUIRE(soln.printAllPathsInATeeToASum(&node2, 6) == expected);

}


TEST_CASE( "Flip a Tree", "Flip a Tree")
{


    node1.val = 1;
    node1.left = &node2;  //3
    node1.right = &node3; //5

    node2.val = 2;
    node2.left = NULL; node2.right = NULL;

    node3.val = 3;
    node3.left = NULL; node3.right = NULL;

    soln.flipATree(&node1);
    REQUIRE(node1.val == 1);
    REQUIRE(node1.left->val == 3);
    REQUIRE(node1.right->val == 2);

    /*
    //              1
    //             /  \
    //            /    \
    //           /      \
    //          2        3
    //         / \      / \
    //        /   \    /   \
    //       4     5  6     7
    */

    node1.val = 1;
    node2.val = 2; node3.val = 3;
    node4.val = 4; node5.val = 5; node6.val = 6; node7.val = 7;

    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = &node6; node3.right = &node7;

    node4.left = NULL; node4.right = NULL;
    node5.left = NULL; node5.right = NULL;
    node6.left = NULL; node6.right = NULL;
    node7.left = NULL; node7.right = NULL;

    soln.flipATree(&node1);
    REQUIRE(node1.val == 1);
    REQUIRE(node1.left->val == 3);
    REQUIRE(node1.right->val == 2);

    REQUIRE(node2.left->val == 5);
    REQUIRE(node2.right->val == 4);
    REQUIRE(node3.left->val == 7);
    REQUIRE(node3.right->val == 6);

    /*
    //                1
    //               /  \
    //              /    \
    //             /      \
                  /        \
   //            2          3
   //          / \          / \
   //         /   \        /   \
   //        4     5       6    7
   //       /\    / \      /\     / \
   //      /  \  /   \    /  \   /   \
   //     8   9  10  11  12   13 14   15
   */
    node1.val = 1;
    node2.val = 2; node3.val = 3;
    node4.val = 4; node5.val = 5; node6.val = 6; node7.val = 7;
    node8.val = 8; node9.val = 9; node10.val = 10; node11.val = 11; node12.val = 12; node13.val = 13; node14.val = 14; node15.val = 15;

    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = &node6; node3.right = &node7;
    node4.left = &node8; node4.right = &node9;
    node5.left = &node10; node5.right = &node11;
    node6.left = &node12; node6.right = &node13;
    node7.left = &node14; node7.right = &node15;

    node8.left = NULL; node8.right = NULL;
    node9.left = NULL; node9.right = NULL;
    node10.left = NULL; node10.right = NULL;
    node11.left = NULL; node11.right = NULL;
    node12.left = NULL; node12.right = NULL;
    node13.left = NULL; node13.right = NULL;
    node14.left = NULL; node14.right = NULL;
    node15.left = NULL; node15.right = NULL;



    soln.flipATree(&node1);
    REQUIRE(node1.val == 1);
    REQUIRE(node1.left->val == 3);
    REQUIRE(node1.right->val == 2);

    REQUIRE(node2.left->val == 5);
    REQUIRE(node2.right->val == 4);
    REQUIRE(node3.left->val == 7);
    REQUIRE(node3.right->val == 6);

    REQUIRE(node4.left->val == 9);
    REQUIRE(node4.right->val == 8 );
    REQUIRE(node5.left->val == 11);
    REQUIRE(node5.right->val == 10 );

    REQUIRE(node6.left->val == 13);
    REQUIRE(node6.right->val == 12 );
    REQUIRE(node7.left->val == 15);
    REQUIRE(node7.right->val == 14 );

}



TEST_CASE( "No of Nodes is largest BST", "No of Nodes is largest BST")
{

    node1.val = 4;
    node1.left = &node2;
    node1.right = nullptr;
    node2.val = 2;
    node2.left = NULL; node2.right = NULL;
    REQUIRE(soln.largestBST(&node1) == 2);


    node1.val = 4;
    node1.left = &node2;
    node1.right = &node3;
    node2.val = 2;
    node2.left = NULL; node2.right = NULL;
    node3.val = 5;
    node3.left = NULL; node3.right = NULL;
    REQUIRE(soln.largestBST(&node1) == 3);



    //node1.val = 4;
    //node1.left = nullptr;
    //node1.right = &node2;
    //node2.val = 2;
    //node2.left = NULL; node2.right = NULL;
    //REQUIRE(soln.largestBST(&node1) == 1);


    /*
                       10
                      /  \
                     /    \
                    /      \
                   /        \
                  15         1
                 / \        / \
                /   \      /   \
               7     16   9    14

    */
    node1.val = 10;
    node2.val = 15; node3.val = 1;
    node4.val = 7; node5.val = 16; node6.val = 9; node7.val = 14;
    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = &node6; node3.right = &node7;
    node4.left = NULL; node4.right = NULL;
    node5.left = NULL; node5.right = NULL;
    node6.left = NULL; node6.right = NULL;
    node7.left = NULL; node7.right = NULL;
    REQUIRE(soln.largestBST(&node1) == 3);



    /*
                    10
                   /  \
                  /    \
                 /      \
                /        \
                6         12
              / \         / \
             /   \       /   \
            7(4)  4(5)  9(6)  14(7)
                              /  \
                             /    \
                         13(12)   16(15)
    */
    node1.val = 10;
    node2.val = 6; node3.val = 12;
    node4.val = 7; node5.val = 4; node6.val = 9; node7.val = 14;
    node12.val = 13; node15.val = 16;

    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = &node6; node3.right = &node7;

    node4.left = nullptr; node4.right = nullptr;
    node5.left = nullptr; node5.right = nullptr;
    node6.left = nullptr; node6.right = nullptr;
    node7.left = &node12; node7.right = &node15;
    node12.left = nullptr; node12.right = nullptr;
    node15.left = nullptr; node15.right = nullptr;
    REQUIRE(soln.largestBST(&node1) == 5);


    /*
                      100
                     /  \
                    /    \
                   /      \
                  /        \
                 30         150
                / \          /  \
               /   \        /    \
              20(4)  50(5) 125(6) 200(7)
                    /  \
                   /    \
                 25(12)   500(15)

      */

    node1.val = 100;
    node2.val = 30; node3.val = 150;
    node4.val = 20; node5.val = 50; node6.val = 125; node7.val = 200;
    node12.val = 25; node15.val = 500;

    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = &node6; node3.right = &node7;

    node4.left = nullptr; node4.right = nullptr;
    node5.left = &node12; node5.right = &node15;
    node6.left = nullptr; node6.right = nullptr;
    node7.left = nullptr; node7.right = nullptr;
    node12.left = nullptr; node12.right = nullptr;
    node15.left = nullptr; node15.right = nullptr;
    REQUIRE(soln.largestBST(&node1) == 3);



}


TEST_CASE( "Construct tree from Arrays", "Construct tree from Arrays")
{
    vi v;
    vvi res;

    vector<int> iOA = {4, 2, 5, 1, 6, 7, 3, 8};
    vector<int> pOA = {1, 2, 4, 5, 3, 7, 6, 8};
    v = {1};
    res.push_back(v);
    v = {2, 3};
    res.push_back(v);
    v = {4, 5, 7, 8};
    res.push_back(v);
    v = {6};
    res.push_back(v);
    REQUIRE(soln.constrctTree(iOA, pOA )== res);
    res.clear();

    iOA = {10, 30, 40, 50, 60, 70, 90};
    pOA = {50, 30, 10, 40, 70, 60, 90};
    v = {50};
    res.push_back(v);
    v = {30, 70};
    res.push_back(v);
    v = {10, 40, 60, 90};
    res.push_back(v);
    REQUIRE(soln.constrctTree(iOA, pOA) == res);
    res.clear();

    iOA = {113, 435, 1347, 2405, 2719, 3093, 4065, 4135, 4478, 5086, 5771, 6260, 6307, 6728, 7663, 7904, 8595, 9278, 9750, 9898};
    pOA = {4478, 435, 113, 2405, 1347, 2719, 4135, 3093, 4065, 5086, 9750, 9278, 8595, 6307, 5771, 6260, 7904, 6728, 7663, 9898};

    v = {4478};
    res.push_back(v);
    v = {435, 5086};
    res.push_back(v);
    v = {113, 2405, 9750};
    res.push_back(v);
    v = {1347, 2719, 9278, 9898};
    res.push_back(v);
    v = {4135, 8595};
    res.push_back(v);
    v = {3093, 6307};
    res.push_back(v);
    v = {4065, 5771, 7904};
    res.push_back(v);
    v = {6260, 6728};
    res.push_back(v);
    v = {7663};
    res.push_back(v);
    REQUIRE(soln.constrctTree(iOA, pOA) == res);
    res.clear();


    iOA = {219, 494, 1067, 1717, 1828, 1916, 2158, 2508, 2652, 2671, 3418, 4420, 4606, 4905, 6169, 6659, 7164, 9455, 9631};
    pOA = {1828, 1067, 219, 494, 1717, 4606, 4420, 2508, 1916, 2158, 3418, 2671, 2652, 9455, 6169, 4905, 6659, 7164, 9631};
    v = {1828};
    res.push_back(v);
    v = {1067, 4606};
    res.push_back(v);
    v = {219, 1717, 4420, 9455};
    res.push_back(v);
    v = {494, 2508, 6169, 9631};
    res.push_back(v);
    v = {1916, 3418, 4905, 6659};
    res.push_back(v);
    v = {2158, 2671, 7164};
    res.push_back(v);
    v = {2652};
    res.push_back(v);
    REQUIRE(soln.constrctTree(iOA, pOA) == res);
    res.clear();

    iOA = { 297, 695, 773, 849, 1126, 1506, 1622, 1846, 2015, 2308, 2584, 3465, 3726, 4000, 4162, 4171, 4392, 4439,
      4451, 4645, 4647, 4743, 5380, 5430, 5574, 6210, 6215, 6337, 6532, 6598, 7021, 7057, 7119, 7398, 7679,
      7733, 7759, 7829, 7857, 7922, 8012, 8348, 8435, 8451, 9000, 9476, 9648};
    pOA = {  849, 297, 695, 773, 8348, 1846, 1506, 1126, 1622, 4171, 2015, 4000, 2308, 2584, 3465, 3726, 4162,
       4743, 4645, 4439, 4392, 4451, 4647, 8012, 7922, 7857, 5574, 5380, 5430, 7398, 6210, 7057, 6215, 6598,
       6337, 6532, 7021, 7119, 7733, 7679, 7829, 7759, 9000, 8451, 8435, 9476, 9648};
    v = {849};
    res.push_back(v);
    v = {297, 8348};
    res.push_back(v);
    v = {695, 1846, 9000};
    res.push_back(v);
    v = {773, 1506, 4171, 8451, 9476};
    res.push_back(v);
    v = {1126, 1622, 2015, 4743, 8435, 9648};
    res.push_back(v);
    v = {4000, 4645, 8012};
    res.push_back(v);
    v = {2308, 4162, 4439, 4647, 7922};
    res.push_back(v);
    v = {2584, 4392, 4451, 7857};
    res.push_back(v);
    v = {3465, 5574};
    res.push_back(v);
    v = {3726, 5380, 7398};
    res.push_back(v);
    v = {5430, 6210, 7733};
    res.push_back(v);
    v = {7057, 7679, 7829};
    res.push_back(v);
    v = {6215, 7119, 7759};
    res.push_back(v);
    v = {6598};
    res.push_back(v);
    v = {6337, 7021};
    res.push_back(v);
    v = {6532};
    res.push_back(v);
    REQUIRE(soln.constrctTree(iOA, pOA) == res);
    res.clear();


    iOA = {-59, 213, 261, 530, 957, 1045, 1189, 1426, 1550, 1634, 1658, 1703, 1822, 2021,
    2710, 3069, 3121, 3349, 4302, 4388, 4480, 4687, 5394, 5928, 6028, 6079, 6096,
    6130, 6536, 6679, 7007, 7119, 7120, 7152, 7569, 7689, 7819, 8252, 8772, 8793,
    8837, 8879, 8934, 8968, 9344, 9460, 9581, 9731};
    pOA = {8772, 1189, 1045, 957, -59, 530, 261, 213, 7120, 4687, 4480, 1822, 1550, 1426,
    1703,1634, 1658, 3069, 2710, 2021,   4388, 3349, 3121, 4302, 5928, 5394, 6130,
    6028, 6096, 6079, 7007, 6536, 6679, 7119, 7819, 7569, 7152, 7689, 8252,
    9731, 8879, 8837, 8793, 9344, 8934, 8968, 9460, 9581};
    v = {8772};
    res.push_back(v);
    v = {1189, 9731};
    res.push_back(v);
    v = {1045, 7120, 8879};
    res.push_back(v);
    v = {957, 4687, 7819, 8837, 9344};
    res.push_back(v);
    v = {-59, 4480, 5928, 7569, 8252, 8793, 8934, 9460};
    res.push_back(v);
    v = {530, 1822, 5394, 6130, 7152, 7689, 8968, 9581};
    res.push_back(v);
    v = {261, 1550, 3069, 6028, 7007};
    res.push_back(v);
    v = {213, 1426, 1703, 2710, 4388, 6096, 6536, 7119};
    res.push_back(v);
    v = {1634, 2021, 3349, 6079, 6679};
    res.push_back(v);
    v = {1658, 3121, 4302};
    res.push_back(v);
    REQUIRE(soln.constrctTree(iOA, pOA) == res);
    res.clear();

    iOA = { -140, -34, 425, 827, 901, 972, 2128, 2267, 3103, 3130, 3184, 3318, 3622, 4253,
    4343, 4442, 4518, 4821, 4880, 4968, 5071, 5173, 5372, 5426, 5556, 5887, 5996,
    6215, 6297, 6522, 6936, 6956, 7057, 7393, 7444, 7538, 7557, 7914, 8475, 8729,
    8819, 9006, 9118};
    pOA = { 4343, 3103, 901, -34, -140, 425, 827, 2267, 972, 2128, 3184, 3130, 3318, 4253,
    3622, 5071, 4880, 4821, 4442, 4518, 4968, 6956, 6297, 6215, 5426, 5372, 5173,
    5996, 5887, 5556, 6936, 6522, 8729, 7057, 7538, 7393, 7444, 7914, 7557, 8475,
    8819, 9006, 9118 };
    v = {4343};
    res.push_back(v);
    v = {3103, 5071};
    res.push_back(v);
    v = {901, 3184, 4880, 6956};
    res.push_back(v);
    v = {-34, 2267, 3130, 3318, 4821, 4968, 6297, 8729};
    res.push_back(v);
    v = {-140, 425, 972, 4253, 4442, 6215, 6936, 7057, 8819};
    res.push_back(v);
    v = {827, 2128, 3622, 4518, 5426, 6522, 7538, 9006};
    res.push_back(v);
    v = {5372, 5996, 7393, 7914, 9118};
    res.push_back(v);
    v = {5173, 5887, 7444, 7557, 8475};
    res.push_back(v);
    v = {5556};
    res.push_back(v);
    REQUIRE(soln.constrctTree(iOA, pOA) == res);
    res.clear();
}




TEST_CASE( "Populate Sibling Pointers", "Populate Sibling Pointers")
{

    /*
    //              1
    //             /  \
    //            /    \
    //           /      \
    //          2        3
    //         / \      / \
    //        /   \    /   \
    //       4     5  6     7
    */

    node1.val = 1;
    node2.val = 2; node3.val = 3;
    node4.val = 4; node5.val = 5; node6.val = 6; node7.val = 7;

    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = &node6; node3.right = &node7;

    node4.left = NULL; node4.right = NULL;
    node5.left = NULL; node5.right = NULL;
    node6.left = NULL; node6.right = NULL;
    node7.left = NULL; node7.right = NULL;

    soln.PopulateSiblingPointers(&node1);
    REQUIRE(node1.nextRight == nullptr);
    REQUIRE(node2.nextRight->val == 3);
    REQUIRE(node3.nextRight == nullptr);
    REQUIRE(node4.nextRight->val == 5);
    REQUIRE(node5.nextRight->val == 6);
    REQUIRE(node6.nextRight->val == 7);
    REQUIRE(node7.nextRight == nullptr);



    node1.val = 1;
    node1.left = &node2;
    node1.right = &node3;

    node2.val = 2;
    node2.left = NULL; node2.right = NULL;

    node3.val = 3;
    node3.left = NULL; node3.right = NULL;

    soln.PopulateSiblingPointers(&node1);
    REQUIRE(node1.nextRight == nullptr);
    REQUIRE(node2.nextRight->val == 3);
    REQUIRE(node3.nextRight == nullptr);



    /*
    //              1
    //             /  \
    //            /    \
    //           /      \
    //          2        3
    //         / \      / \
    //        /   \    /   \
    //       4     5  X     7
    */

    node1.val = 1;
    node2.val = 2; node3.val = 3;
    node4.val = 4; node5.val = 5; node7.val = 7;
    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = nullptr; node3.right = &node7;
    node4.left = NULL; node4.right = NULL;
    node5.left = NULL; node5.right = NULL;
    node7.left = NULL; node7.right = NULL;

    soln.PopulateSiblingPointers(&node1);
    REQUIRE(node1.nextRight == nullptr);
    REQUIRE(node2.nextRight->val == 3);
    REQUIRE(node3.nextRight == nullptr);
    REQUIRE(node4.nextRight->val == 5);
    REQUIRE(node5.nextRight->val == 7);
    REQUIRE(node7.nextRight == nullptr);

}


TEST_CASE( "BST Iterator", "BST Iterator")
{
    Tree tree;
    vector<int> res;

    /*
    //              100
    //             /  \
    //            /    \
    //           /      \
    //          25      300
    //         / \      / \
    //        /   \    /   \
    //       4     50  250  350
    */

    node1.val = 100;
    node2.val = 25; node3.val = 300;
    node4.val = 4; node5.val = 50; node6.val = 250; node7.val = 350;

    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = &node5;
    node3.left = &node6; node3.right = &node7;

    node4.left = NULL; node4.right = NULL;
    node5.left = NULL; node5.right = NULL;
    node6.left = NULL; node6.right = NULL;
    node7.left = NULL; node7.right = NULL;
    tree.init(&node1);
    res = {4, 25, 50, 100, 250, 300, 350};
    int i = 0;
    while(tree.hasNext() == true)
    {
        Node *temp = tree.next();
        REQUIRE(res[i] == temp->val);
        i++;
    }


    /*
    //              100
    //             /  \
    //            /    \
    //           /      \
    //          25      300
    //         /         \
    //        /           \
    //       4            350
    */

    node1.val = 100;
    node2.val = 25; node3.val = 300;
    node4.val = 4; node7.val = 350;

    node1.left = &node2; node1.right = &node3;
    node2.left = &node4; node2.right = nullptr;
    node3.left = nullptr; node3.right = &node7;

    node4.left = NULL; node4.right = NULL;
    node7.left = NULL; node7.right = NULL;
    tree.init(&node1);
    res = {4, 25, 100, 300, 350};
    i = 0;
    while(tree.hasNext() == true)
    {
        Node *temp = tree.next();
        REQUIRE(res[i] == temp->val);
        i++;
    }



   /*
   //              100
   //             /  \
   //            /    \
   //           /      \
   //          25      300
   //           \      /
   //            \    /
   //            50  250
   */

   node1.val = 100;
   node2.val = 25;node3.val = 300;
   node5.val = 50; node6.val = 250;

   node1.left = &node2; node1.right = &node3;
   node2.left = nullptr; node2.right = &node5;
   node3.left = &node6; node3.right = nullptr;

   node5.left = NULL; node5.right = NULL;
   node6.left = NULL; node6.right = NULL;
   tree.init(&node1);
   res = {25, 50, 100, 250, 300};
   i = 0;
   while(tree.hasNext() == true)
   {
       Node *temp = tree.next();
       REQUIRE(res[i] == temp->val);
       i++;
   }

}

TEST_CASE( "knights Tour On Chess Board", "knights Tour On Chess Board")
{
    int rows = 8; int columns = 8; int sx = 0; int sy = 0; int ex = 7; int ey = 7;
    REQUIRE(soln.knightsTourOnChessBoard(rows, columns, sx, sy, ex, ey) == 6);

    rows = 6; columns = 6; sx = 0; sy = 0; ex = 5; ey = 5;
    REQUIRE(soln.knightsTourOnChessBoard(rows, columns, sx, sy, ex, ey) == 4);

    rows = 3; columns = 3; sx = 0; sy = 0; ex = 2; ey = 2;
    REQUIRE(soln.knightsTourOnChessBoard(rows, columns, sx, sy, ex, ey) == 4);

}

TEST_CASE( "Topological Sort", "Topological Sort")
{
    vector<string> strDict1 = {"caa", "aaa", "aab"};
    string res = {"cab"};
    REQUIRE(soln.topologicalSort(strDict1) == res);


    vector<string> strDict2 = {"baa","abcd","abca","cab","cad"};
    res = {"bdac"};
    REQUIRE(soln.topologicalSort(strDict2) == res);

    vector<string> strDict3 = {"aa", "bb", "cc", "dd", "ee"};
    res = {"abcde"};
    REQUIRE(soln.topologicalSort(strDict3) == res);
}




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

/* Recursion */
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

/* Linked LinkedListNodes */
TEST_CASE( "Find the head of the loop in a LL", "Linked LinkedListNode" )
{
    cout << "Head of the loop \n\n";

    vector<LinkedListNode*> is;
    vector<LinkedListNode*> res;

    LinkedListNode *ptr1 = nullptr;
    LinkedListNode *ptr2 = nullptr;
    is.push_back(ptr1);
    res.push_back(ptr2);

    //no cycle test.
    LinkedListNode node3; node3.next = nullptr;
    LinkedListNode node4; node4.next = &node3;
    LinkedListNode node5; node5.next = &node4;
    LinkedListNode node6; node6.next = &node5;
    LinkedListNode node7; node7.next = &node6;
    LinkedListNode node8; node8.next = &node7;
    LinkedListNode node9; node9.next = &node8;
    LinkedListNode node10; node10.next = &node9;
    LinkedListNode node11; node11.next = &node10;
    LinkedListNode node12; node12.next = &node11;
    LinkedListNode node13; node13.next = &node12;
    LinkedListNode node14; node14.next = &node13;
    LinkedListNode node15; node15.next = &node14;
    is.push_back(&node15);
    res.push_back(ptr2);

    //create a loop
    LinkedListNode nodea3; nodea3.next = nullptr; nodea3.val = 3;
    LinkedListNode nodea4; nodea4.next = &nodea3; nodea4.val = 4;
    LinkedListNode nodea5; nodea5.next = &nodea4; nodea5.val = 5;
    LinkedListNode nodea6; nodea6.next = &nodea5; nodea6.val = 6;
    LinkedListNode nodea7; nodea7.next = &nodea6; nodea7.val = 7;
    LinkedListNode nodea8; nodea8.next = &nodea7; nodea8.val = 8;
    LinkedListNode nodea9; nodea9.next = &nodea8; nodea9.val = 9;
    LinkedListNode nodea10; nodea10.next = &nodea9; nodea10.val = 10;
    LinkedListNode nodea11; nodea11.next = &nodea10; nodea11.val = 11;
    LinkedListNode nodea12; nodea12.next = &nodea11; nodea12.val = 12;
    LinkedListNode nodea13; nodea13.next = &nodea12; nodea13.val = 13;
    LinkedListNode nodea14; nodea14.next = &nodea13; nodea14.val = 14;
    LinkedListNode nodea15; nodea15.next = &nodea14; nodea15.val = 15;

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


TEST_CASE( "find All Different Ways To Add Parentheses", "find All Different Ways To Add Parentheses" )
{
    cout << "find All Different Ways To Add Parentheses \n";


    vector<int> res;

    res = {2, 0};
    REQUIRE(soln.diffWaysToCompute("2-1-1") == res);

    res = {132};
    REQUIRE(soln.diffWaysToCompute("11*12") == res);

    res = {132};
    REQUIRE(soln.diffWaysToCompute("132") == res);

    res = {-34, -10, -14, -10, 10};
    REQUIRE(soln.diffWaysToCompute("2*3-4*5") == res);
}





TEST_CASE( "Add Two Linked LinkedListNodes", "Add Two Linked LinkedListNodes" )
{

    LinkedListNode node1; LinkedListNode node2; LinkedListNode node3;
    node3.next = nullptr; node3.val = 9;
    node2.next = &node3; node2.val = 9;
    node1.next = &node2; node1.val = 9;

    LinkedListNode nodea; LinkedListNode nodeb; LinkedListNode nodec;
    nodec.next = nullptr; nodec.val = 9;
    nodeb.next = &nodec; nodeb.val = 9;
    nodea.next = &nodeb; nodea.val = 9;

    LinkedListNode node4; LinkedListNode node5; LinkedListNode node6; LinkedListNode node7;
    node7.next = nullptr; node7.val = 8;
    node6.next = &node7; node6.val = 9;
    node5.next = &node6; node5.val = 9;
    node4.next = &node5; node4.val = 1;
    LinkedListNode *expected = &node4;

    LinkedListNode *res = soln.AddTwoLinkedListNodes(&node1, &nodea);
    REQUIRE(identicalLinkedListNodes(res, expected) == true);


    node3.next = nullptr; node3.val = 3;
    node2.next = &node3; node2.val = 2;
    node1.next = &node2; node1.val = 1;

    nodec.next = nullptr; nodec.val = 3;
    nodeb.next = &nodec; nodeb.val = 5;
    nodea.next = &nodeb; nodea.val = 4;

    node7.next = nullptr; node7.val = 6;
    node6.next = &node7; node6.val = 7;
    node5.next = &node6; node5.val = 5;
    expected = &node5;

    res = soln.AddTwoLinkedListNodes(&node1, &nodea);
    REQUIRE(identicalLinkedListNodes(res, expected) == true);


}


TEST_CASE( "Add Digits in Linked LinkedListNodes: LSD first", "Add Digits in Linked LinkedListNodes: LSD first" )
{

    LinkedListNode node1; LinkedListNode node2; LinkedListNode node3; LinkedListNode node4;
    LinkedListNode nodea; LinkedListNode nodeb; LinkedListNode nodec;
    LinkedListNode node5; LinkedListNode node6; LinkedListNode node7;
    LinkedListNode *expected;
    LinkedListNode *res;

    node2.next = nullptr; node2.val = 1; //12
    node1.next = &node2; node1.val = 2;

    nodeb.next = nullptr; nodeb.val = 2; //23
    nodea.next = &nodeb; nodea.val = 3;

    node7.next = nullptr; node7.val = 3;
    node6.next = &node7; node6.val = 5;

    expected = &node6;
    res = soln.AddTwoLinkedListNodesLSDFirst(&node1, &nodea);
    REQUIRE(identicalLinkedListNodes(res, expected) == true);


    node3.next = nullptr; node3.val = 9;
    node2.next = &node3; node2.val = 9;
    node1.next = &node2; node1.val = 9;

    nodec.next = nullptr; nodec.val = 9;
    nodeb.next = &nodec; nodeb.val = 9;
    nodea.next = &nodeb; nodea.val = 9;

    node7.next = nullptr; node7.val = 1;
    node6.next = &node7; node6.val = 9;
    node5.next = &node6; node5.val = 9;
    node4.next = &node5; node4.val = 8;

    expected = &node4;
    res = soln.AddTwoLinkedListNodesLSDFirst(&node1, &nodea);
    REQUIRE(identicalLinkedListNodes(res, expected) == true);


    node2.next = nullptr; node2.val = 9;
    node1.next = &node2; node1.val = 9;

    nodec.next = nullptr; nodec.val = 9;
    nodeb.next = &nodec; nodeb.val = 9;
    nodea.next = &nodeb; nodea.val = 9;

    node7.next = nullptr; node7.val = 1;
    node6.next = &node7; node6.val = 0;
    node5.next = &node6; node5.val = 9;
    node4.next = &node5; node4.val = 8;

    expected = &node4;
    res = soln.AddTwoLinkedListNodesLSDFirst(&node1, &nodea);
    REQUIRE(identicalLinkedListNodes(res, expected) == true);


    node3.next = nullptr; node3.val = 9;
    node2.next = &node3; node2.val = 9;
    node1.next = &node2; node1.val = 9;

    nodea.next = nullptr; nodea.val = 9;

    node7.next = nullptr; node7.val = 1;
    node6.next = &node7; node6.val = 0;
    node5.next = &node6; node5.val = 0;
    node4.next = &node5; node4.val = 8;

    expected = &node4;
    res = soln.AddTwoLinkedListNodesLSDFirst(&node1, &nodea);
    REQUIRE(identicalLinkedListNodes(res, expected) == true);

}



TEST_CASE( "Merge Sort Linked List", "Merge Sort Linked List" )
{

    LinkedListNode node1; LinkedListNode node2; LinkedListNode node3; LinkedListNode node4;
    LinkedListNode nodea; LinkedListNode nodeb; LinkedListNode nodec;
    LinkedListNode node5; LinkedListNode node6; LinkedListNode node7; LinkedListNode node8;

    LinkedListNode *expected;
    LinkedListNode *res;

    node4.next = nullptr; node4.val = 4;
    node3.next = &node4; node3.val = 3;
    node2.next = &node3; node2.val = 2;
    node1.next = &node2; node1.val = 1;

    node7.next = nullptr; node7.val = 4;
    node6.next = &node7; node6.val = 3;
    node5.next = &node6; node5.val = 2;
    node4.next = &node5; node4.val = 1;

    expected = &node4;
    res = soln.MergeSortLinkedListNodePtr(&node1);
    REQUIRE(identicalLinkedListNodes(res, expected) == true);


    node4.next = nullptr; node4.val = 1;
    node3.next = &node4; node3.val = 2;
    node2.next = &node3; node2.val = 3;
    node1.next = &node2; node1.val = 4;

    node7.next = nullptr; node7.val = 4;
    node6.next = &node7; node6.val = 3;
    node5.next = &node6; node5.val = 2;
    node4.next = &node5; node4.val = 1;

    expected = &node4;
    res = soln.MergeSortLinkedListNodePtr(&node1);
    REQUIRE(identicalLinkedListNodes(res, expected) == true);


    node5.next = nullptr; node5.val = 5;
    node4.next = &node5; node4.val = 1;
    node3.next = &node4; node3.val = 2;
    node2.next = &node3; node2.val = 3;
    node1.next = &node2; node1.val = 4;

    node8.next = nullptr; node8.val = 5;
    node7.next = &node8; node7.val = 4;
    node6.next = &node7; node6.val = 3;
    node5.next = &node6; node5.val = 2;
    node4.next = &node5; node4.val = 1;

    expected = &node4;
    res = soln.MergeSortLinkedListNodePtr(&node1);
    REQUIRE(identicalLinkedListNodes(res, expected) == true);

}


TEST_CASE( "Clone A Special Linked List", "Clone A Special Linked List" )
{
    cout << "Clone A Special Linked List \n";
    LinkedListNode *res;
    LinkedListNode node1; LinkedListNode node2; LinkedListNode node3; LinkedListNode node4;
    LinkedListNode node5; LinkedListNode node6; LinkedListNode node7; LinkedListNode node8;

    node5.next = nullptr; node5.val = 5;
    node4.next = &node5; node4.val = 4;
    node3.next = &node4; node3.val = 3;
    node2.next = &node3; node2.val = 2;
    node1.next = &node2; node1.val = 1;

    node5.rand = &node2;
    node4.rand = &node3;
    node3.rand = &node5;
    node2.rand = &node1;
    node1.rand = &node3;

    res = soln.cloneASpecialLinkedList(&node1);

    LinkedListNode *res1 = res;

    REQUIRE(node1.val == 1);
    REQUIRE(node2.val == 2);
    REQUIRE(node3.val == 3);
    REQUIRE(node4.val == 4);
    REQUIRE(node5.val == 5);


    REQUIRE(node1.rand->val == 3);
    REQUIRE(node2.rand->val == 1);
    REQUIRE(node3.rand->val == 5);
    REQUIRE(node4.rand->val == 3);
    REQUIRE(node5.rand->val == 2);

    REQUIRE(res->rand->val == 3);
    res = res->next;
    REQUIRE(res->rand->val == 1);
    res = res->next;
    REQUIRE(res->rand->val == 5);
    res = res->next;
    REQUIRE(res->rand->val == 3);
    res = res->next;
    REQUIRE(res->rand->val == 2);
    res = res->next;

    REQUIRE(res1->val == 1);
    res1 = res1->next;
    REQUIRE(res1->val == 2);
    res1 = res1->next;
    REQUIRE(res1->val == 3);
    res1 = res1->next;
    REQUIRE(res1->val == 4);
    res1 = res1->next;
    REQUIRE(res1->val == 5);
    res1 = res1->next;
    REQUIRE(res1 == nullptr);

    /****************************************************************************/
    //One node test..
    node1.next = nullptr; node1.rand = nullptr; node1.val = 1;
    res = soln.cloneASpecialLinkedList(&node1);
    REQUIRE(node1.val == 1);
    REQUIRE(node1.next == nullptr);
    REQUIRE(node1.rand == nullptr);
    REQUIRE(res->val == 1);
    REQUIRE(res->next == nullptr);
    REQUIRE(res->rand == nullptr);

    /****************************************************************************/
    node2.next = nullptr; node2.rand = &node1; node2.val = 2;
    node1.next = &node2; node1.rand = &node2; node1.val = 1;

    res = soln.cloneASpecialLinkedList(&node1);
    res1 = res;

    REQUIRE(node1.val == 1);
    REQUIRE(node2.val == 2);
    REQUIRE(node1.next == &node2);
    REQUIRE(node1.rand == &node2);
    REQUIRE(node2.next == nullptr);
    REQUIRE(node2.rand == &node1);

    REQUIRE(res->rand->val == 2);
    res = res->next;
    REQUIRE(res->rand->val == 1);

    REQUIRE(res1->val == 1);
    res1 = res1->next;
    REQUIRE(res1->val == 2);
    res1 = res1->next;
    REQUIRE(res1 == nullptr);
    /****************************************************************************/

}

TEST_CASE( "Alternative Split", "Alternative Split" )
{
    cout << "Alternative Split \n";

    //soln.alternativeSplit(&node1);

}

TEST_CASE( "Has Matching Parantheses", "Has Matching Parantheses" )
{
    cout << "Has Matching Parantheses\n";

    REQUIRE(soln.hasMatchingParantheses("( ( 1 + 2 ) * 3 )") == true);
    REQUIRE(soln.hasMatchingParantheses("( { 1 + 2 ) * 3 )") == false);
    REQUIRE(soln.hasMatchingParantheses("( ( (1 + 2) * 3 ))") == true);
    REQUIRE(soln.hasMatchingParantheses("[([])}") == false);
    REQUIRE(soln.hasMatchingParantheses("} ( 1 * 2) + 3 * ( 5 - 6)") == false);

}


TEST_CASE( "Find the middle of a Linked LinkedListNode", "Middle LinkedListNode" )
{
    cout << "Find the middle of a Linked LinkedListNode \n\n";

    vector<LinkedListNode*> is;
    vector<int> res;

    LinkedListNode *ptr1 = nullptr;
    is.push_back(ptr1);
    res.push_back(0);

    LinkedListNode node3; node3.next = nullptr;   node3.val = 3;
    LinkedListNode node4; node4.next = &node3;    node4.val = 4;
    LinkedListNode node5; node5.next = &node4;    node5.val = 5;
    LinkedListNode node6; node6.next = &node5;    node6.val = 6;
    LinkedListNode node7; node7.next = &node6;    node7.val = 7;
    LinkedListNode node8; node8.next = &node7;    node8.val = 8;
    LinkedListNode node9; node9.next = &node8;    node9.val = 9;//middle
    LinkedListNode node10; node10.next = &node9;  node10.val = 10;
    LinkedListNode node11; node11.next = &node10; node11.val = 11;
    LinkedListNode node12; node12.next = &node11; node12.val = 12;
    LinkedListNode node13; node13.next = &node12; node13.val = 13;
    LinkedListNode node14; node14.next = &node13; node14.val = 14;
    LinkedListNode node15; node15.next = &node14; node15.val = 15;
    is.push_back(&node15);
    res.push_back(9);

    LinkedListNode nod3; nod3.next = nullptr;  nod3.val = 3;
    LinkedListNode nod4; nod4.next = &nod3;    nod4.val = 4;
    LinkedListNode nod5; nod5.next = &nod4;    nod5.val = 5;
    LinkedListNode nod6; nod6.next = &nod5;    nod6.val = 6;
    LinkedListNode nod7; nod7.next = &nod6;    nod7.val = 7;
    LinkedListNode nod8; nod8.next = &nod7;    nod8.val = 8;
    LinkedListNode nod9; nod9.next = &nod8;    nod9.val = 9; //middle
    LinkedListNode nod10; nod10.next = &nod9;  nod10.val = 10;
    LinkedListNode nod11; nod11.next = &nod10; nod11.val = 11;
    LinkedListNode nod12; nod12.next = &nod11; nod12.val = 12;
    LinkedListNode nod13; nod13.next = &nod12; nod13.val = 13;
    LinkedListNode nod14; nod14.next = &nod13; nod14.val = 14;
    LinkedListNode nod15; nod15.next = &nod14; nod15.val = 15;
    LinkedListNode nod16; nod16.next = &nod15; nod16.val = 16;
    is.push_back(&nod16);
    res.push_back(9);


    //Test Case: One element.
    LinkedListNode node1; node1.val = 100; node1.next = nullptr;
    is.push_back(&node1);
    res.push_back(100);

    //Test Case: Two elements.
    LinkedListNode node1a; node1a.val = 100;
    LinkedListNode node1b; node1b.val = 200;
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

    vector<LinkedListNode*> is;
    vector<int> res;

    LinkedListNode *ptr1 = nullptr;
    is.push_back(ptr1);
    res.push_back(0);

    //Test Case: One element.
    LinkedListNode node1; node1.val = 100; node1.next = &node1;
    is.push_back(&node1);
    res.push_back(100);

    //Test Case: Two elements.
    LinkedListNode node1a; node1a.val = 100;
    LinkedListNode node1b; node1b.val = 200;
    node1a.next = &node1b;
    node1b.next = &node1a;
    is.push_back(&node1b);
    res.push_back(100);

    //Test Case: Odd no of elements.
    LinkedListNode n1; LinkedListNode n2; LinkedListNode n3; LinkedListNode n4; LinkedListNode n5; LinkedListNode n6;
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
    LinkedListNode node1; LinkedListNode node2; LinkedListNode node3; LinkedListNode node4; LinkedListNode node5; LinkedListNode node6;

    //TEST CASE: Nullptr case
    LinkedListNode *ptr1 = nullptr;
    REQUIRE(soln.swapKthNodes(ptr1,5) == nullptr);


    //TEST CASE: Regular case
    node1.next = &node2;  node1.val = 1;
    node2.next = &node3;  node2.val = 2;
    node3.next = &node4;  node3.val = 3;
    node4.next = &node5;  node4.val = 4;
    node5.next = &node6;  node5.val = 5;
    node6.next = nullptr; node6.val = 6;
    LinkedListNode *temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    LinkedListNode *res = soln.swapKthNodes(&node1,2);
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


    //TEST CASE: Where k does not exist. LinkedListNode is shorter
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


TEST_CASE( "Generate All Permutations")
{

    cout << "Generate All Permutations \n";
    string s("abc");
    vector<string> res;

    res = soln.generateAllPermutations(s);
    for(auto val : res)
        cout << " " << val << " ";

    cout << "\n";

}


TEST_CASE( "Reverse a linked list in groups", "Reverse in groups" )
{
    cout << "Reverse a linked list in groups \n\n";
    LinkedListNode node1; LinkedListNode node2; LinkedListNode node3; LinkedListNode node4;
    LinkedListNode node5; LinkedListNode node6; LinkedListNode node7; LinkedListNode node8;

    node1.val = 1; node2.val = 2; node3.val = 3;
    node1.next = &node2; node2.next = &node3; node3.next = nullptr;

    LinkedListNode* temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    LinkedListNode *res = soln.myLinkedListNodereverseALinkedListNodeInGroupsOfGivenSize(&node1,3);
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
    res = soln.myLinkedListNodereverseALinkedListNodeInGroupsOfGivenSize(&node1,3);
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
    res = soln.myLinkedListNodereverseALinkedListNodeInGroupsOfGivenSize(&node1,5);
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
    res = soln.myLinkedListNodereverseALinkedListNodeInGroupsOfGivenSize(&node1,0);
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
    res = soln.myLinkedListNodereverseALinkedListNodeInGroupsOfGivenSize(&node1,1);
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
    res = soln.myLinkedListNodereverseALinkedListNodeInGroupsOfGivenSize(&node1,10);
    while(res)
    {
        cout << " val = " << res->val;
        res = res->next;
    }
    cout << "\n";


}

TEST_CASE( "Zip A Linked LinkedListNode from its two ends", "Zip LinkedListNode" )
{
    cout << "Zip list from its two ends  \n\n";
    LinkedListNode node1; LinkedListNode node2; LinkedListNode node3; LinkedListNode node4; LinkedListNode node5; LinkedListNode node6;


    //Basic test case:
    node1.val = 1; node2.val = 2; node3.val = 3; node4.val = 4; node5.val = 5; node6.val = 6;
    node1.next = &node2; node2.next = &node3; node3.next = &node4; node4.next = &node5;
    node5.next = &node6; node6.next = nullptr;
    LinkedListNode* temp = &node1;
    while(temp)
    {
        cout << " val = " << temp->val;
        temp = temp->next;
    }
    cout << "\n";
    LinkedListNode * res = soln.zipALinkedListNode(&node1);
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
    res = soln.zipALinkedListNode(&node1);
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
    res = soln.zipALinkedListNode(&node1);
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
    res = soln.zipALinkedListNode(&node1);
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
    res = soln.zipALinkedListNode(&node1);
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
    cout << "Intersection of two LinkedListNodes \n\n";

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



TEST_CASE( "Super Stack", "Super Stack")
{
    cout << "Super Stack \n\n";

    superStack ss;

    ss.push(4);
    ss.pop();
    ss.push(3);
    ss.push(5);
    ss.push(2);
    ss.inc(3, 1);
    ss.pop();
    ss.push(1);
    ss.inc(2, 2);
    ss.push(4);
    ss.pop();
    ss.pop();

    cout << "Super Stack \n\n";

    superStack ss1;
    ss1.push(15);
    ss1.pop();
    ss1.push(-51);
    ss1.pop();
    ss1.push(41);
    ss1.pop();
    ss1.push(-76);
    ss1.push(51);
    ss1.push(-10);
    ss1.inc(1,-49);

    cout << "Super Stack \n\n";
    superStack ss2;
    ss2.push(-36);
    ss2.push(20);
    ss2.pop();
    ss2.push(-9);
    ss2.pop();
    ss2.push(-53);
    ss2.pop();
    ss2.inc(1,-17);

}


TEST_CASE( "Test my sorted Linked List", "Test my sorted Linked List" )
{

    {   //Sorted in the descending order
        LinkedList l1;

        l1.addValue(10);
        l1.addValue(9);
        l1.addValue(8);
        l1.addValue(7);

        l1.printList();
        REQUIRE(l1.find(10) == true);
        REQUIRE(l1.find(7) == true);
        l1.deleteValue(10);
        l1.deleteValue(7);

        REQUIRE(l1.find(10) == false);
        REQUIRE(l1.find(7) == false);
        l1.printList();
    }

    {
        //Sorted in the ascending order
        LinkedList l2;

        l2.addValue(7);
        l2.addValue(8);
        l2.addValue(9);
        l2.addValue(10);

        l2.printList();
        REQUIRE(l2.find(10) == true);
        REQUIRE(l2.find(7) == true);
        l2.deleteValue(10);
        l2.deleteValue(7);

        REQUIRE(l2.find(10) == false);
        REQUIRE(l2.find(7) == false);
        l2.printList();
    }



    {
        //Mixed sorting
        LinkedList l2;

        l2.addValue(7);
        l2.addValue(9);
        l2.addValue(8);
        l2.addValue(10);

        l2.printList();
        REQUIRE(l2.find(10) == true);
        REQUIRE(l2.find(7) == true);
        l2.deleteValue(10);
        l2.deleteValue(7);

        REQUIRE(l2.find(10) == false);
        REQUIRE(l2.find(7) == false);
        l2.printList();
    }


    {
        //Null list
        LinkedList l2;

        l2.printList();
        REQUIRE(l2.find(10) == false);
        REQUIRE(l2.find(7) == false);
        l2.deleteValue(10);
        l2.deleteValue(7);

        REQUIRE(l2.find(10) == false);
        REQUIRE(l2.find(7) == false);
        l2.printList();

    }

    {
        //positive and negative values
        LinkedList l2;

        l2.addValue(7);
        l2.addValue(-2);
        l2.addValue(-3);
        l2.addValue(10);

        l2.printList();
        REQUIRE(l2.find(10) == true);
        REQUIRE(l2.find(7) == true);
        l2.deleteValue(10);
        l2.deleteValue(7);

        REQUIRE(l2.find(10) == false);
        REQUIRE(l2.find(7) == false);
        l2.printList();
    }

    {

        LinkedList l2;
        l2.printList();
        REQUIRE(l2.find(10) == false);
        l2.deleteValue(10);
        REQUIRE(l2.find(INT_MIN) == false);
        l2.printList();

     }

     {
        LinkedList l2;
        l2.printList();
        REQUIRE(l2.find(10) == false);
        l2.deleteValue(10);
        REQUIRE(l2.find(INT_MIN) == false);
        l2.printList();

     }

     {
        LinkedList l2;
        l2.printList();
        l2.deleteValue(INT_MIN);
        REQUIRE(l2.find(INT_MIN) == false);
        l2.printList();

     }

     {
        LinkedList l2;
        l2.addValue(INT_MIN);
        l2.printList();
        REQUIRE(l2.find(INT_MIN) == true);
        REQUIRE(l2.find(10) == false);
        l2.deleteValue(INT_MIN);
        REQUIRE(l2.find(INT_MIN) == false);
        l2.printList();

     }

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

    //10
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


string minWindow(string strText, string strCharacters);

TEST_CASE( "Minimum length window", "Minimum length window")
{

    string s1("ADOBECODEBANC");
    string s2("ABC");
    string res("BANC");
    REQUIRE(soln.minWindow(s1,s2) == res);

    s1 = "ADOBECODEBANC";
    s2 = "ZYD";
    res = "";
    REQUIRE(soln.minWindow(s1,s2) == res);

    s1 = "acdbddddddddaaaaaaaadabbbba";
    s2 = "baad";
    res = "adab";
    REQUIRE(soln.minWindow(s1,s2) == res);

    s1 = "caaec";
    s2 = "ace";
    res  = "aec";
    REQUIRE(soln.minWindow(s1,s2) == res);

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

    //17
    i1.push_back("caab");
    i2.push_back("c*a*b");
    res.push_back(true);

    //18
    i1.push_back("abc");
    i2.push_back("abcd");
    res.push_back(false);

    //19
    i1.push_back("abcd");
    i2.push_back("abc");
    res.push_back(false);

    //20
    i1.push_back("aab");
    i2.push_back("c*a*b");
    res.push_back(true);

    //21
    i1.push_back("ab");
    i2.push_back("ab*");
    res.push_back(true);

    //22
    i1.push_back("ab");
    i2.push_back("abc*");
    res.push_back(true);
    //23
    i1.push_back("abbc");
    i2.push_back("ab*bbc");
    res.push_back(true);

    //24
    i1.push_back("abcbcd");
    i2.push_back("a.*c.*d");
    res.push_back(true);

    //25
    i1.push_back("b");
    i2.push_back("b*a");
    res.push_back(false);

    //26
    i1.push_back("b");
    i2.push_back("b.cdf");
    res.push_back(false);

    //27
    i1.push_back("aabc");
    i2.push_back("a*abc");
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

TEST_CASE( "KMP Algorithm for pattern search", "KMP Algorithm for pattern search")
{
    cout << "Test: KMP Algorithm for pattern search \n\n";


    vector<string> i1;
    vector<string> i2;
    vector<bool>  res;

    //0
    i1.push_back("AAAA");
    i2.push_back("AAAA");
    res.push_back(true);


    //1
    i1.push_back("ABCDEABCDE");
    i2.push_back("ABCDE");
    res.push_back(true);

    //2
    i1.push_back("ABC ABCDAB ABCDABCDABDE");
    i2.push_back("ABCDABD");
    res.push_back(true);

    //3
    i1.push_back("THIS IS A TEST TEXT TEST");
    i2.push_back("TEST");
    res.push_back(true);

    //4
    i1.push_back("SheSells SeaShells On SeaShore");
    i2.push_back("See");
    res.push_back(false);


    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.KMP(i1[i], i2[i]) == res[i]);
    }

}


TEST_CASE( "Neuronyms", "Neuronyms")
{
    cout << "Test: :Neuronyms( \n\n";

    soln.Neuronyms("nailed");
    soln.Neuronyms("batch");

}


TEST_CASE( "Print Spirally", "Print Spirally")
{
    cout << "Test: Print Spirally\n\n";

    vector<vector<vector<char>>> i1;
    vector<string>  res;

    //0
    vector<vector<char> > matrix(1, vector<char>(1));
    matrix[0][0] = 'x';
    i1.push_back(matrix);
    res.push_back("x");

    //1
    vector<vector<char> > matrix1(3, vector<char>(3));
    matrix1[0] = {'A', 'B', 'C'};
    matrix1[1] = {'D', 'E', 'F'};
    matrix1[2] = {'G', 'H', 'I'};
    i1.push_back(matrix1);
    res.push_back("ABCFIHGDE");

    //2
    vector<vector<char> > matrix2(2, vector<char>(2));
    matrix2[0] = {'A', 'A'};
    matrix2[1] = {'A', 'A'};
    i1.push_back(matrix2);
    res.push_back("AAAA");

    //3
    vector<vector<char> > matrix3(4, vector<char>(4));
    matrix3[0] = {'A', 'A', 'B', 'B'};
    matrix3[1] = {'C', 'C', 'D', 'D'};
    matrix3[2] = {'E', 'E', 'F', 'F'};
    matrix3[3] = {'G', 'G', 'H', 'H'};
    i1.push_back(matrix3);
    res.push_back("AABBDFHHGGECCDFE");

    //4
    vector<vector<char> > matrix4(2, vector<char>(3));
    matrix4[0] = {'1', 'Y', 'Z'};
    matrix4[1] = {'A', 'B', 'C'};
    i1.push_back(matrix4);
    res.push_back("1YZCBA");

    //5
    vector<vector<char> > matrix5(3, vector<char>(2));
    matrix5[0] = {'1', 'Y'};
    matrix5[1] = {'A', 'B'};
    matrix5[2] = {'C', 'D'};
    i1.push_back(matrix5);
    res.push_back("1YBDCA");

    //6
    vector<vector<char> > matrix6(3, vector<char>(6));
    matrix6[0] = {'1','2','3','4','5','6'};
    matrix6[1] = {'7','8','9','A','B','C'};
    matrix6[2] = {'D','E','F','G','H','I'};
    i1.push_back(matrix6);
    res.push_back("123456CIHGFED789AB");

    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.printSpirally(i1[i]) == res[i]);
    }

}



TEST_CASE( "Move all letters to left", "Move all letters to left")
{
    cout << "Test: Move all letters to left\n\n";

    vector<string> i1;
    vector<string> res;

    //0
    i1.push_back("1234abc");
    res.push_back("abc4123");

    //1
    i1.push_back("0a193zbr6");
    res.push_back("azbr30196");

    //2
    i1.push_back("abcd");
    res.push_back("abcd");

    //3
    i1.push_back("1234");
    res.push_back("1234");


    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.moveAllLettersToLeftSide(i1[i]) == res[i]);
    }

}

TEST_CASE( "Group Odd and Even Numbers", "Group Odd and Even Numbers")
{
    cout << "Test: Group Odd and Even Numbers\n\n";

    vector<vector<int>> i1;
    vector<vector<int>> res;

    //0
    vector<int> tempi = {1,2,3,4,5};
    i1.push_back(tempi);
    vector<int> resi = {2,4,3,1,5};
    res.push_back(resi);

    //1
    tempi = {1,2,3,4,5,6};
    i1.push_back(tempi);
    resi = {2,4,6,1,5,3};
    res.push_back(resi);

    //2
    tempi = {2,4,6};
    i1.push_back(tempi);
    resi = {2,4,6};
    res.push_back(resi);

    //3
    tempi = {1,3,5};
    i1.push_back(tempi);
    resi = {1,3,5};
    res.push_back(resi);


    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.groupNumbers(i1[i]) == res[i]);
    }
}


TEST_CASE( "Quick Sort", "Quick Sort")
{
    cout << "Test: Quick Sort \n\n";

    vector<vector<int>> i1;
    vector<vector<int>> res;


    //0
    vector<int> tempi = {1};
    i1.push_back(tempi);
    vector<int> resi = {1};
    res.push_back(resi);

    //1
    tempi = {2, 1};
    i1.push_back(tempi);
    resi = {1, 2};
    res.push_back(resi);

    //2
    tempi = {1,2,3,4,5};
    i1.push_back(tempi);
    resi = {1,2,3,4,5};
    res.push_back(resi);

    //3
    tempi = {5,4,3,2,1};
    i1.push_back(tempi);
    resi = {1,2,3,4,5};
    res.push_back(resi);

    //4
    tempi = {6,5,4,3,2,1};
    i1.push_back(tempi);
    resi = {1,2,3,4,5,6};
    res.push_back(resi);

    //5
    tempi = {3,4,6,5,2,1};
    i1.push_back(tempi);
    resi = {1,2,3,4,5,6};
    res.push_back(resi);

    //6
    tempi = {10, 80, 30, 90, 40, 50, 70};
    i1.push_back(tempi);
    resi = {10, 30, 40, 50, 70, 80, 90};
    res.push_back(resi);

    //7
    tempi = {10, 80, 30, 90, 40, 40, 70};
    i1.push_back(tempi);
    resi = {10, 30, 40, 40, 70, 80, 90};
    res.push_back(resi);

    //8
    tempi = {10, 10, 10, 10, 10, 10, 10};
    i1.push_back(tempi);
    resi = {10, 10, 10, 10, 10, 10, 10};
    res.push_back(resi);

     //9
    tempi = {20, 30, 10, 10, 10, 10, 10};
    i1.push_back(tempi);
    resi = {10, 10, 10, 10, 10, 20, 30};
    res.push_back(resi);

    tempi = {20, 30, 10, 10, 5, 10, 10};
    i1.push_back(tempi);
    resi = {5, 10, 10, 10, 10, 20, 30};
    res.push_back(resi);


    int size = i1.size();
    int startIndex = 0;
    int endIndex = size;

    for(int i = startIndex; i < endIndex; i++)
    {
        cout << "*********** Test" << i << " ******************** \n";
        REQUIRE(soln.quickSort(i1[i]) == res[i]);
    }
}

//vector<pair<pci,pci>> nutsNBolts();


TEST_CASE( "Nuts n Bolts", "Nuts n Bolts")
{
    cout << "Test: Nuts n Bolts \n\n";

    vector<pair<pci,pci>> res;

    vector<pci> nuts;
    vector<pci> bolts;

    //0
    nuts.push_back(make_pair('N',1));
    nuts.push_back(make_pair('N',2));
    nuts.push_back(make_pair('N',3));
    nuts.push_back(make_pair('N',4));

    bolts.push_back(make_pair('B',1));
    bolts.push_back(make_pair('B',2));
    bolts.push_back(make_pair('B',3));
    bolts.push_back(make_pair('B',4));

    res.push_back(make_pair(make_pair('N',1), make_pair('B',1)));
    res.push_back(make_pair(make_pair('N',2), make_pair('B',2)));
    res.push_back(make_pair(make_pair('N',3), make_pair('B',3)));
    res.push_back(make_pair(make_pair('N',4), make_pair('B',4)));

    REQUIRE(soln.nutsNBolts(nuts, bolts) == res);
    nuts.clear(); bolts.clear(); res.clear();


    //1
    nuts.push_back(make_pair('N',4));
    nuts.push_back(make_pair('N',1));
    nuts.push_back(make_pair('N',2));
    nuts.push_back(make_pair('N',3));

    bolts.push_back(make_pair('B',1));
    bolts.push_back(make_pair('B',3));
    bolts.push_back(make_pair('B',4));
    bolts.push_back(make_pair('B',2));

    res.push_back(make_pair(make_pair('N',1), make_pair('B',1)));
    res.push_back(make_pair(make_pair('N',2), make_pair('B',2)));
    res.push_back(make_pair(make_pair('N',3), make_pair('B',3)));
    res.push_back(make_pair(make_pair('N',4), make_pair('B',4)));

    REQUIRE(soln.nutsNBolts(nuts, bolts) == res);
    nuts.clear(); bolts.clear(); res.clear();


    //2
    nuts.push_back(make_pair('N',4));
    nuts.push_back(make_pair('N',1));
    nuts.push_back(make_pair('N',5));
    nuts.push_back(make_pair('N',3));
    nuts.push_back(make_pair('N',2));

    bolts.push_back(make_pair('B',1));
    bolts.push_back(make_pair('B',3));
    bolts.push_back(make_pair('B',5));
    bolts.push_back(make_pair('B',2));
    bolts.push_back(make_pair('B',4));

    res.push_back(make_pair(make_pair('N',1), make_pair('B',1)));
    res.push_back(make_pair(make_pair('N',2), make_pair('B',2)));
    res.push_back(make_pair(make_pair('N',3), make_pair('B',3)));
    res.push_back(make_pair(make_pair('N',4), make_pair('B',4)));
    res.push_back(make_pair(make_pair('N',5), make_pair('B',5)));

    REQUIRE(soln.nutsNBolts(nuts, bolts) == res);
    nuts.clear(); bolts.clear(); res.clear();


}


TEST_CASE( "Merge Sorted Arrays", "Merge Sorted Arrays")
{
    cout << "Test: Merge Sorted Arrays \n\n";

    vector<vector<int>> i1;
    vector<int> res;

    //0
    vector<int> v1 = {2,   7,  9,   17,   18, 27, 32};
    vector<int> v2 = {3,   4,  8,    9,   17, 501, 1001};
    vector<int> v3 = {100, 101, 102, 105, 111, 520, 750};
    vector<vector<int>> iarray;
    iarray.push_back(v1);
    iarray.push_back(v2);
    iarray.push_back(v3);
    res = { 2, 3, 4, 7, 8, 9, 9, 17, 17, 18, 27, 32, 100, 101, 102, 105, 111, 501, 520, 750, 1001};
    REQUIRE(soln.mergearrays(iarray) == res);
    iarray.clear();

    //1
    v1 = {1, 3, 5, 7};
    v2 = {2, 4, 6, 8};
    v3 = {0, 9, 10, 11};
    iarray.push_back(v1);
    iarray.push_back(v2);
    iarray.push_back(v3);
    res = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    REQUIRE(soln.mergearrays(iarray) == res);
    iarray.clear();

    //2
    v1 = {-1, -2, -3, -4};
    v2 = {-5, -6, -7, -8};
    iarray.push_back(v1);
    iarray.push_back(v2);
    res = {-8, -7, -6, -5, -4, -3, -2, -1};
    REQUIRE(soln.mergearrays(iarray) == res);
    iarray.clear();

    //3
    v1 = {-1, -2, -3, -5};
    v2 = {-6, -7, -8, -10};
    iarray.push_back(v1);
    iarray.push_back(v2);
    res = {-10, -8, -7, -6, -5, -3, -2, -1};
    REQUIRE(soln.mergearrays(iarray) == res);

}

TEST_CASE( "Twitter Top K", "Twitter Top K")
{
    cout << "Test: Twitter Top K \n\n";

    vector<int> res;

    //0
    vector<int> v1 = {2, 7,  9, 17, 18, 27, 32};
    res = {18, 27, 32};
    REQUIRE(soln.twitterTopK(v1, 3) == res);

    //1
    v1 = {2, 7,  9, 17, 18, 27, 32, 3};
    res = {17, 18, 27, 32};
    REQUIRE(soln.twitterTopK(v1, 4) == res);

    //2
    v1 = {2, 7, 9};
    res = {2, 7, 9};
    REQUIRE(soln.twitterTopK(v1, 4) == res);


}



TEST_CASE( "Print Triplets", "Print Triplets")
{
    cout << "Test: Print Triplets \n\n";

    vector<string> res;

    //0
    vector<int> v1 = {0, 0, 0};
    string rest = "0,0,0";
    res.push_back(rest);
    REQUIRE(soln.printTriplets(v1) == res);
    res.clear();

    //1
    v1 = {2, -25, -10, -7, -3, 2, 4, 8, 10 };
    rest = "-10,2,8";
    res.push_back(rest);
    rest = "-7,-3,10";
    res.push_back(rest);
    REQUIRE(soln.printTriplets(v1) == res);
    res.clear();

    //2
    v1 = {6, 10, 3, -4, 1, -6, 4, 9};
    rest = "-6,-4,10";
    res.push_back(rest);
    rest = "-4,1,3";
    res.push_back(rest);
    REQUIRE(soln.printTriplets(v1) == res);
    res.clear();

    //3
    v1 = {12,24,-46};
    rest.clear();
    REQUIRE(soln.printTriplets(v1) == res);
    res.clear();

    //4
    v1 = {-2, -1, 0, 1, 2};
    rest = "-2,0,2";
    res.push_back(rest);
    rest = "-1,0,1";
    res.push_back(rest);
    REQUIRE(soln.printTriplets(v1) == res);
    res.clear();

    //5
    v1 = {12,34,-46,31};
    rest = "-46,12,34";
    res.push_back(rest);
    REQUIRE(soln.printTriplets(v1) == res);
    res.clear();

    //6
    v1 = {6, 10, 3, -4, -4, -6, 1, 10, -6, 4, 9, 10};
    rest = "-6,-4,10";
    res.push_back(rest);
    rest = "-4,1,3";
    res.push_back(rest);
    REQUIRE(soln.printTriplets(v1) == res);
    res.clear();

}

TEST_CASE( "Find if a subset exists with 4 numbers whose sum is K", "Find if a subset exists with 4 numbers whose sum is K")
{
    cout << "Find if a subset exists with 4 numbers whose sum is K \n";

    vector<int> v1;

    //Only 4 elements and not adding to k.
    v1 = {1, 2, 3, 4};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 4) == false);

    //Only 4 elements and adding to k.
    v1 = {1, 2, 3, 4};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 10) == true);

    //more than 4 elements.
    v1 = {1, 2, 3, 4, 5, 6, 7};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 10) == true);


    //More than 4 elements and adding to k.
    v1 = {1, 2, 12, 13, 14, 3, 4};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 10) == true);

    //More than 4 elements not adding to k.
    v1 = {1, 2, 12, 13, 14, 3, 4};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 9) == false);

    //More than 4 elements and adding to k.
    v1 = {1, 2, 12, 13, 14, 3, 4};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 21) == true);

    v1 = {1, 2, 12, 13, 14, 3, 4};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 15) == false);

    v1 = {1, 2, 12, 13, 14, 3, 4};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 34) == true);

    //Duplicate elements
    v1 = {2, 2, 12, 2, 14, 2, 20};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 8) == true);

    v1 = {2, 2, 12, 2, 14, 2, 20};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 9) == false);

    v1 = {2, 2, 12};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 16) == false);

    v1 = {2, 2};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 4) == false);

    v1 = {2, 2};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 5) == false);

    v1 = {2};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 4) == false);

    v1 = {2};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 2) == false);

    //Five numbers add up to the sum
    v1 = {2, 2, 12, 2, 14, 2, 4};
    REQUIRE(soln.findIf4NumbersSumToK(v1, 12) == false);

}



TEST_CASE( "Merge First Into Second", "Merge First Into Second")
{
    vector<int> v1;
    vector<int> v2;
    vector<int> res;

    v1 =  {1,2,3};
    v2 =  {4,5,6,0,0,0};
    res = {1,2,3,4,5,6};
    REQUIRE(soln.mergeFirstIntoAnother(v1,v2) == res);

    v1 =  {4,5};
    v2 =  {4,5,0,0};
    res = {4,4,5,5};
    REQUIRE(soln.mergeFirstIntoAnother(v1,v2) == res);

    v1 =  {4};
    v2 =  {1,0};
    res = {1,4};
    REQUIRE(soln.mergeFirstIntoAnother(v1,v2) == res);

    v1 =  {4};
    v2 =  {1,0};
    res = {1,4};
    REQUIRE(soln.mergeFirstIntoAnother(v1,v2) == res);

    v1 =  {1};
    v2 =  {1,0};
    res = {1,1};
    REQUIRE(soln.mergeFirstIntoAnother(v1,v2) == res);


}


TEST_CASE( "Producer Consumer", "Producer Consumer")
{
    soln.producerConsumerMain();
}

TEST_CASE( "Print Even Odd in two different threads", "Print Even Odd in two different threads")
{
    soln.oddEvenMain();
}



TEST_CASE( "Synchronous Request Dispatcher", "Synchronous Request Dispatcher")
{
    soln.synchrnousRequestDispatcher();
}


TEST_CASE( "Weather Data", "Weather Data")
{
    soln.myMainDisp();
}


