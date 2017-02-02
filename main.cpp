#include<iostream>
#include<string>
#include<algorithm>
#include"Solution.h"
#include<map>
#include "IKSolution.hpp"

int testZigZagConversion();
int testAddTwoNos();

Solution mySolution;
int understandStringFuncs();
void reverseWordsInAString(string &s);


using namespace std;



int testIKWork();
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

    IKSolution soln;

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

    //ls dict = {"cat", "bat", "hat", "bad", "had"};
    //string s1 = "bat";
    //string s2 = "had";

    ls dict = {"bit", "bal", "hal", "hit", "had", "cad", "bat", "hat", "bil", "kit"};
    string s1 = "hit";
    string s2 = "kit";

    cout << "src = " << s1;
    cout << " dest = " <<  s2 << "\n";

    soln.convertAString(dict, s1, s2);
#endif

    //vector<string> strDict = {"caa", "aaa", "aab"};
    //vector<string> strDict = {"baa","abcd","abca","cab","cad"};
    vector<string> strDict = {"aa", "bb", "cc", "dd", "ee"};
    soln.topologicalSort(strDict); //m is the no of strings and n is the no of chars in string

#if 0
    vvi a = {
                {1, 1, 0, 0, 0},
                {0, 1, 0, 0, 1},
                {1, 0, 0, 1, 1},
                {0, 0, 0, 0, 0},
                {1, 0, 1, 0, 1}
            };
#endif
    vvi a = {
                    {1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1},
            };

    vvi b = {
                 {0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0},
            };
    //int counter = soln.countNoOfIslands(a);
    //cout << " no of islands = " << counter;

#if 0
    string str("222");
    expressionCreator(str,24);
#endif

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

