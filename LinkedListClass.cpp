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


struct ALinkedListNode
{
    int val;
    ALinkedListNode *next;
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
        ALinkedListNode *head = nullptr;


};

LinkedList::LinkedList()
{
    head = new ALinkedListNode; //dummyhead. Makes the code very simple
    head->next = nullptr;
    head->val = INT_MIN;

}

void LinkedList::addValue(int x)
{
    ALinkedListNode *current = head->next;
    ALinkedListNode *prev = head;

    ALinkedListNode *tnode = new ALinkedListNode;
    tnode->val = x;
    while(current != nullptr && current->val < x)
    {
        prev = current;
        current = current->next;
    }

    prev->next = tnode;
    tnode->next = current;

    return;
}

void LinkedList::deleteValue(int x)
{
    ALinkedListNode *current = head->next;
    ALinkedListNode *prev = head;

    while(current != nullptr && current->val != x)
    {
        prev = current;
        current = current->next;
    }

    if(current != nullptr)
    {
        prev->next = current->next;
        delete current;
    }

}

bool LinkedList::find(int x)
{
    ALinkedListNode *current = head->next;

    while(current != nullptr && current->val != x)
        current = current->next;

    if(current != nullptr)
        return true;

    return false;
}

LinkedList::~LinkedList()
{
    ALinkedListNode *current = head;
    ALinkedListNode *prev = head;

    while(current != nullptr)
    {
        prev = current;
        current = current->next;
        delete prev;
    }
}

void LinkedList::printList()
{

    ALinkedListNode *current = head;

    while(current != nullptr)
    {
        cout << "val = " << current->val << " \n";
        current = current->next;
    }
}

#if 0
TEST_CASE( "Test my sorted Linked List", "Test my sorted Linked List" )
{

    {   //Sorted in the descending order
        ALinkedList l1;

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
        ALinkedList l2;

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
        ALinkedList l2;

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
        ALinkedList l2;

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
        ALinkedList l2;

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

        ALinkedList l2;
        l2.printList();
        REQUIRE(l2.find(10) == false);
        l2.deleteValue(10);
        REQUIRE(l2.find(INT_MIN) == false);
        l2.printList();

     }

     {
        ALinkedList l2;
        l2.printList();
        REQUIRE(l2.find(10) == false);
        l2.deleteValue(10);
        REQUIRE(l2.find(INT_MIN) == false);
        l2.printList();

     }

     {
        ALinkedList l2;
        l2.printList();
        l2.deleteValue(INT_MIN);
        REQUIRE(l2.find(INT_MIN) == false);
        l2.printList();

     }

     {
        ALinkedList l2;
        l2.addValue(INT_MIN);
        l2.printList();
        REQUIRE(l2.find(INT_MIN) == true);
        REQUIRE(l2.find(10) == false);
        l2.deleteValue(INT_MIN);
        REQUIRE(l2.find(INT_MIN) == false);
        l2.printList();

     }

}
#endif

