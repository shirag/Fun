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
#include "../IKSolution.hpp"

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

int findKthLargest(vector<int> &v1, vector<int> &v2, int k,int& val);
int getMiddleValue(vector<int> &v,int low,int high);
int findKthLargestRecursive(vector<int> &v1, int low1, int high1, vector<int> &v2, int low2, int high2, int k);
Solution mySolution;


int testZigZagConversion();
int testAddTwoNos();
int understandStringFuncs();
void reverseWordsInAString(string &s);

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









