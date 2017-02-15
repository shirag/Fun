/*
 * IKHWStackQueueLLP1.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: raghav
 */

#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


/* Longest Substring with matching parentheses*/
int IKSolution::maxLenMatchingParen(string strParenExpression)
{
    stack<char> res;
    int counter = 0;
    int maxCount = 0;

    /* Push the opening para to a stack. Reset the counter */
    /* When you come across a closing call pop, increment the counter, if counter > max, max = counter */

    for(auto it : strParenExpression )
    {
        if(it == '(')
        {
            res.push('(');
            counter = 0;
        }
        else
        {
            if(!res.empty())
            {
                res.pop();
                counter += 2;
                maxCount = counter > maxCount ? counter : maxCount;
            }

        }
    }

    return maxCount;

}

/****************************************************************************************************************************/
int IKSolution::findMiddleNode(List *head)
{
    List *slow = head;
    List *fast = head;

    if(slow && fast)
        cout << "val = " << slow->val << "\n";

    while((fast != nullptr) && (fast->next != nullptr))
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(slow)
    {
        cout << "Middle element = " << slow->val << "\n";
        return slow->val;
    }

    return 0;

}

/**********************************************************************************************/
/* Problem:
 *     Return a pointer to the beginning of the cycle.
       Find if there is a loop/cycle, then look at the length and then
       find length of the cycle. One you know the length, then set the slow pointer to the
       head and fast pointer to the length + head. They will meet at beginning of the cycle.
   */
List *IKSolution::pointerToCycle(List *head)
{
    List* fast = NULL;
    List* slow = NULL;
    int counter = 0;

    if(head == NULL)
        return nullptr;

    slow = head;
    fast = slow->next;

    while((slow) && (fast) && (fast != slow))
    {
        if(fast->next)
            fast = fast->next->next;
        slow = slow -> next;
        cout << "slow = " << slow << "\n";
        cout << "fast = " << fast << "\n";
    }

    if((slow) && (fast) && (slow == fast))
    {
        DEBUG_DEBUG(cout << "Found a loop !!!! \n");
        List *temp = slow;
        temp = temp->next;
        while(temp != fast)
        {
            temp = temp->next;
            counter++;
        }
    }
    else
    {
        DEBUG_DEBUG(cout << "Did not find a loop !!!! \n");
        return nullptr;

    }

    cout << "length of loop " << counter << "\n";


    slow = head;
    fast = head + counter;

    while((slow) && (fast) && (slow != fast))
    {
        slow = slow->next;
        fast = fast->next;
        if(slow) cout << "slow = " << slow << "\n";
        if(fast) cout << "fast = " << fast << "\n";
    }

    if(slow)
        cout << "The value of cycle = " << slow->val << "\n";

    return slow;

}
/******************************************************************************************************/

//Create a new LL node
List* LRUCache::createANewNode(int key,int val)
{
    List *n = new(List);
    n->val = val;
    n->key = key;
    n->next = nullptr;
    n->prev = nullptr;

    return n;
}

void LRUCache::push_front(List *node)
{
    cout << "Insert a new node at the head of the linked list \n";
    if(head == nullptr)
    {
        head = node;
        tail = head;
    }
    else
    {
        List *temp = head;
        head = node;
        node->next = temp;
        temp->prev = node;
    }
}


void LRUCache::move_front(List *node)
{
    cout << "Move an existing node to the head of the linked list \n";

    List *prev = node->prev;
    if(prev != nullptr)
        prev->next = node->next;
    else
        head = nullptr;

    List *next = node->next;
    if(next != nullptr)
        next->prev = node->prev;

    if(node == tail)
        tail = prev;

    push_front(node);

}

void LRUCache::pop_back()
{
    cout << "Remove the tail of the linked list \n";
    if(tail == nullptr)
        return;

    List *prev = tail->prev;
    if(prev != nullptr)
        prev->next = nullptr;
    else
        head = nullptr;

    delete(tail);
    tail = prev;
}

//Remove a node in the middle of the Linked List
void LRUCache::remove_node(List* node)
{

    List *prev = node->prev;
    if(prev != nullptr)
        prev->next = node->next;
    else
        head = nullptr;

    List *next = node->next;
    if(next != nullptr)
        next->prev = node->prev;
    else
        tail = nullptr;

    delete(node);
}

/* Look at an entry in the top of the doubly linked list and then remove it */
int LRUCache::evict()
{
    cout << "LRU cache is full. Time to evict \n";

    auto it = lrum.find(tail->key);
    if(it == lrum.end())
    {
        cout << "Value not found in the cache \n";
        return -1;
    }
    lrum.erase(it);
    pop_back();

    return 0;
}


void LRUCache::set(int key, int val)
{

    cout << "set " << "key = " << key << " value = " << val << "\n";

    if(lRUCachSize >= lRUMaxSizeCache)
        evict();

    lRUCachSize++;
    List *temp = createANewNode(key,val);
    push_front(temp);
    lrum.insert(make_pair(key,temp));

}

int LRUCache::get(int key)
{
    auto it = lrum.find(key);
    if(it == lrum.end())
    {
        cout << "Value not found in the cache \n";
        return -1;
    }

    List* node = it->second;
    move_front(node);
    return node->val;
}


void LRUCache::remove(int key)
{
    auto it = lrum.find(key);

    if(it == lrum.end())
    {
        cout << "Value not found in the cache";
        return;
    }

    List* node = it->second;
    remove_node(node);
    lrum.erase(it);

}

/****************************************************************************************************************************/
/* Stack with min values.*/

void IKSolution::pushMS(int x)
{
    csS.push(x);

    if(minS.empty())
        minS.push(x);
    else
        if(x < minS.top())
            minS.push(x);

}

int IKSolution::popMS()
{
    if(csS.empty())
    {
        return 0;
    }

    int ret = csS.top();
    csS.pop();

    if(ret == minS.top())
    {
        minS.pop();
    }

    return ret;

}

int IKSolution::getMinMS()
{
    int ret = 0;

    if(!minS.empty())
    {
        ret = minS.top();
    }
    return ret;
}

bool IKSolution::emptyMS()
{
    if(csS.empty())
        return true;

    return false;
}
/****************************************************************************************************************************/
/* Swap Kth nodes from the begiining with kth node from end, where head of the node is k = 1 */
//Very important. While moveing two pointers, if the first one fails to move because nex it null, you must not move the second one
List* IKSolution::swapKthNodes(List* head, int k)
{
    cout << "k = " << k << "\n";

    List *temp,*kBp, *kB, *kEp, *kE;

    List dummyNode;
    dummyNode.val = 0;
    dummyNode.next = head;
    int count = 1;

    kBp = nullptr;
    kE = head;
    temp = head;
    kB = head;

    kBp = &dummyNode;
    kEp = &dummyNode;

    if(head == nullptr)
        return head;

    //Find K from beginning
    while((temp != nullptr) && (count != k))
    {
        kBp = temp;
        temp = temp->next;
        count++;
        kB = temp;
    }

    if(temp == nullptr)
        return head;

    //Find K from end
    while(temp != nullptr)
    {
        temp = temp->next;
        if(temp != nullptr)
        {
            kEp = kE;
            kE = kE->next;
        }
    }

    DEBUG_DEBUG(cout << "kB->val = " << kB->val << "\n");
    DEBUG_DEBUG(cout << "kE->val = " << kE->val << "\n");
    if(kBp) DEBUG_DEBUG(cout << "kBp->val = " << kBp->val << "\n");
    if(kEp) DEBUG_DEBUG(cout << "kEp->val = " << kEp->val << "\n");

    /* Time to swap*/
    if((kB != nullptr) && (kE != nullptr))
    {
        //Save previous pointers first
        List* t1 = kB->next;
        List* t2 = kE->next;

        //Update previous pointers
        kBp->next = kE;
        kEp->next = kB;

        //Update next pointers of newly moved nodes. Take care of cycles
        if(kB != kEp)
            kE->next = t1;
        else
            kE->next = kB;

        if(kE != kBp)
            kB->next = t2;
        else
            kB->next = kE;

    }

    return dummyNode.next;
}

/****************************************************************************************************************************/

/* I reverse 5 */
    /* When there is no more nodes on my right I return */
    /* Request guys on my right to do the same *
     * I attach the pointer returned by them to my tail
     * I provide my head.
     * */
List* reverseUtil(List *myList,int k)
{
    List *temp = myList;
    int counter = 1;
    List *curr;
    List *prev = nullptr;

    curr = myList;

    while((curr != nullptr) && (counter <= k))
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        counter++;
    }

    if(curr == nullptr)
        return prev;
    else
        myList->next = reverseUtil(curr, k);

    return prev;
}


List * IKSolution::myListreverseAListInGroupsOfGivenSize(List *myList, int k)
{
    if(k == 0)
    {
        return myList;
    }
    return reverseUtil(myList, k);

}

/****************************************************************************************************************************/

/*
 * Alternate approach: Use the APIs provided by C++ STLs provided by C++
 * http://programming-puzzle.blogspot.com/2014/02/zip-of-linked-list.html
 * */
List * IKSolution::zipAList(List *myList)
{
    List* temp;
    stack<List*> ms;

    if(myList == nullptr)
        return nullptr;

    temp = myList;

    while(temp != nullptr)
    {
        ms.push(temp);
        temp = temp->next;
    }

    temp = myList;
    while((ms.top() != temp) && (temp->next != ms.top()))
    {
        List* t = ms.top();
        ms.pop();

        List* n = temp->next;
        temp->next = t;
        t->next = n;
        temp = n;
    }

    if(ms.top() == temp)
        temp->next = nullptr;
    else if(temp->next == ms.top())
        temp->next->next = nullptr;

    return myList;
}
/****************************************************************************************************************************/



