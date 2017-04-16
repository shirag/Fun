/*
 * LinkedListClass.cpp
 *
 *  Created on: Apr 15, 2017
 *      Author: raghav
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>
#include <cassert>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <functional>
#include <memory>


using namespace std;


struct LinkedListNode
{
    int val;
    LinkedListNode *next;
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
        LinkedListNode *head = nullptr;


};


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

#if 0
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

}

#endif

