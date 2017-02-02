#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <vector>

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











