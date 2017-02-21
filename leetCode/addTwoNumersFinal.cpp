/*
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 *  Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
*/


#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
 };


class Solution {

    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
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
} ;

#if 0
int main()
{
    cout << " Hello World!!!";
    
    Solution mySolution;
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
#endif
