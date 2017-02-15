/*
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 */


#include <stdio.h>
#include <iostream>
#include "Solution.h"

using namespace std;

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



