/*
 * LinkedListClass.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: raghav
 */

#include "IKSolution.hpp"
#include <iostream>
#include <limits.h>

using namespace std;




LinkedList::LinkedList()
{
    head = new LinkedListNode; //dummyhead. Makes the code very simple
    head->next = nullptr;
    head->val = INT_MIN;
}


void LinkedList::addValue(int x)
{
    LinkedListNode *temp = head;
    LinkedListNode *prev = head;

    LinkedListNode *tnode = new LinkedListNode;
    tnode->val = x;

    while(temp != nullptr && temp->val < x)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = tnode;
    tnode->next = temp;

    return;
 }

void LinkedList::deleteValue(int x)
{

    LinkedListNode *temp = head;
    LinkedListNode *prev = head;

    while(temp != nullptr && temp->val != x)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp != nullptr)
    {
        prev->next = temp->next;
        delete temp;
    }

}

bool LinkedList::find(int x)
{
    LinkedListNode *temp = head;

    while(temp != nullptr && temp->val != x)
        temp = temp->next;

    if(temp != nullptr)
        return true;

    return false;
}


LinkedList::~LinkedList()
{
    LinkedListNode *temp = head;
    LinkedListNode *prev = head;

    while(temp != nullptr)
    {
        prev = temp;
        temp = temp->next;
        delete prev;
    }
}


void LinkedList::printList()
{

    LinkedListNode *temp = head;

    while(temp != nullptr)
    {
        cout << "val = " << temp->val << " \n";
        temp = temp->next;
    }
}

