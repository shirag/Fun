/*
 * IKHWStackQueueLLP1.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: raghav
 */

#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"



/****************************************************************************************************************************/
/*
(Using difference of node counts)
1) Get count of the nodes in first list, let count be c1.
2) Get count of the nodes in second list, let count be c2.
3) Get the difference of counts d = abs(c1 – c2)
4) Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
5) Then we can traverse both the lists in parallel till we come across a common node.
   (Note that getting a common node is done by comparing the address of the nodes)
*/
list<int>::iterator IKSolution::interSectionOfTwoLists(list<int>& L1, list<int>& L2)
{
    list<int> temp;
    int counter = 0;
    list<int>::iterator it1;
    list<int>::iterator it2;

    int size1 = L1.size();
    int size2 = L2.size();

    it1 = L1.begin();
    it2 = L2.begin();

    if(size1 > size2)
    {
        for(it1 = L1.begin(), counter = 0; counter < (size1 - size2); counter++)
        {
            it1++;
        }
    }
    else if(size2 > size1)
    {
        for(it2 = L2.begin(), counter = 0; counter < (size2 - size1); counter++)
        {
            it2++;
        }
    }

    while((it1 != L1.end()) && (it2 != L2.end()) && (it1 != it2) )
    {
        DEBUG_TRACE(cout << " No match yet \n");
        it1++;
        it2++;
    }

    if(it1 == it2)
    {
        DEBUG_DEBUG(cout << "Intersection of two lists found \n");
        return it1;
    }
    else
    {
        DEBUG_DEBUG(cout << "Intersection of two lists NOT found \n");
        return L1.end();
    }

}

/* Input: Arbitrary pointer to a sorted circular linked list.
 * Return: The median value.
 * Approach:
 *     1. Find the tipping point.
 *     2. From the tipping point, have two pointers, slow and first.
 *     3. When the fast hits the beginning of the tipping point again,
 *     slow points to the median.
 *
 *     Please observe for similarities between this problem and next(middle node) problem.
 **    If fast points to a node whose next is 'beginning node", its time to come out of the loop.
  *    If fast points to 'beginning node", its time to come out of the loop.

 */
int IKSolution::Median(List *l1)
{
    List *temp = l1;

    if(temp == nullptr)
        return 0;

    while(temp->val < temp->next->val)
    {
        temp = temp->next;
    }

    DEBUG_TRACE(cout << "Starting value = " <<  temp->next->val << " \n");

    List *slow = temp->next;
    List *fast = temp->next;
    DEBUG_DEBUG(cout << "slow init value = " <<  slow->val << " \n");
    DEBUG_DEBUG(cout << "fast init value = " <<  fast->val << " \n");

    //Until you process all nodes in the list
    while((fast != temp) && (fast->next != temp))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    DEBUG_DEBUG(cout << "Median Val = " <<  slow->val << " \n");

    return slow->val;

}


/****************************************************************************************************************************/
/* Problem:
 * Example:
 * Approach:
 *     Same as finding the median in a circular list. Instead of checking for null for fast, we are checking
 *     for the beginning of the loop.
 *     If fast points to a node whose next is null, its time to come out of the loop.
 *     If fast points to a null, its time to come out of the loop.
   Time Complexity:
   Space Complexity:
 *
 **/
int IKSolution::findMiddleNode(List *head)
{
    List *slow = head;
    List *fast = head;

    if(head == nullptr)
    {
        return 0;
    }

    //Until you process all nodes in the list
    while((fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = fast->next->next; //Jump two at a time. That is the reason for fast != nullptr && fast->next != nullptr
    }

    DEBUG_DEBUG(cout << "Middle element = " << slow->val << "\n");
    return slow->val;

}

/*
 * Problem:
 *     Return a pointer to the beginning of the cycle.
       Find if there is a loop/cycle, then look at the length and then
       find length of the cycle. One you know the length, then set the slow pointer to the
       head and fast pointer to the length + head. They will meet at beginning of the cycle.

 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 *
 **/
/**********************************************************************************************/
List *IKSolution::pointerToCycle(List *head)
{
    List* fast = NULL;
    List* slow = NULL;
    int counter = 0;

    if(head == NULL)
        return nullptr;

    slow = head;
    fast = head;

    //Until you process all nodes in the list
    while((fast != nullptr) && (fast->next != nullptr))
    {
         slow = slow->next;
         fast = fast->next->next;

         if(fast == slow)
         {
             DEBUG_DEBUG(cout << "Found a loop !!!! \n");
             break;
         }
    }

    // To count no of nodes in the loop
    if((slow) && (fast) && (slow == fast))
    {
        List *temp = slow;
        temp = temp->next; // beginning of the list
        while(temp != fast) //until you find the last item in the list.
        {
            temp = temp->next; //Jump one at a time. That is the reason for test temp != fast above.
            counter++;
        }
    }
    else
    {
        DEBUG_DEBUG(cout << "Did not find a loop !!!! \n");
        return nullptr;

    }

    DEBUG_DEBUG(cout << "length of loop " << counter << "\n");


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
        DEBUG_DEBUG(cout << "The value of cycle = " << slow->val << "\n");

    return slow;

}
/******************************************************************************************************/
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
    DEBUG_DEBUG(cout << "Insert a new node at the head of the linked list \n");
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
    DEBUG_DEBUG(cout << "Move an existing node to the head of the linked list \n");

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
    DEBUG_DEBUG(cout << "Remove the tail of the linked list \n");
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
    DEBUG_DEBUG(cout << "LRU cache is full. Time to evict \n");

    auto it = lrum.find(tail->key);
    if(it == lrum.end())
    {
        DEBUG_DEBUG(cout << "Value not found in the cache \n");
        return -1;
    }
    lrum.erase(it);
    pop_back();

    return 0;
}

/* Problem:
 * Example:
 * Approach:
   Time Complexity:
   Space Complexity:
 *
 **/
void LRUCache::set(int key, int val)
{

    DEBUG_DEBUG(cout << "set " << "key = " << key << " value = " << val << "\n");

    auto it = lrum.find(key);
    if(it == lrum.end())
    {
        if(lRUCachSize >= lRUMaxSizeCache)
            evict();
        lRUCachSize++;
        List *temp = createANewNode(key,val);
        push_front(temp);
        lrum.insert(make_pair(key,temp));
    }
    else
    {
        DEBUG_DEBUG(cout << "Key already exists. So, just moving to the top" << "\n");
        List* node = it->second;
        node->val = val;
        move_front(node);
    }

    return;

}

int LRUCache::get(int key)
{
    auto it = lrum.find(key);
    if(it == lrum.end())
    {
        DEBUG_DEBUG(cout << "Value not found in the cache \n");
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
        DEBUG_DEBUG(cout << "Value not found in the cache \n");
        return;
    }

    List* node = it->second;
    remove_node(node);
    lrum.erase(it);

}


/* Problem:
 *     Swap Kth node from beginning with Kth node from end in a Linked List. Given a singly linked list, swap kth node
 *     from beginning with kth node from end. Swapping of data is not allowed, only pointers should be changed.
 *
 * Example:
 * Approach:
 *      Find K from beginning.
 *      Find K from End.
 *      Swap both. Use a dummy head so that all corner cases become very simple.
 *

   Time Complexity:
   Space Complexity:
   Corner cases:
        Let X be the kth node from beginning and Y be the kth node from end. Following are the interesting cases that must be handled.
        1) Y is next to X
        2) X is next to Y
        3) X and Y are same
        4) X and Y don’t exist (k is more than number of nodes in linked list)
 * Take away:
 *      Very important. While moving two pointers, if the first one fails to move because next ptr is null, you must not move the second one.
 *      So, check for ptr->next == NULL before moving the other pointer.

 **/
List* IKSolution::swapKthNodes(List* head, int k)
{
    DEBUG_TRACE(cout << "k = " << k << "\n");

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
    while((temp != nullptr) && (temp->next != nullptr))
    {
        temp = temp->next;
        kEp = kE;
        kE = kE->next;

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

    if(curr != nullptr)
        myList->next = reverseUtil(curr, k); //Attach the haed provided by the recursive funnction to my tail.
    else
        return prev; //My head

    return prev; //My head
}

/* Problem:
       Reverse a Linked List in groups of given size. Given a linked list, write a function to reverse every k
       nodes (where k is an input to the function).
 * Example:
 *     Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3
       Output:  3->2->1->6->5->4->8->7->NULL.

       Inputs:   1->2->3->4->5->6->7->8->NULL and k = 5
       Output:  5->4->3->2->1->8->7->6->NULL.
 * Approach:
 *     Contract: I reverse K values and provide the head.
 *     My Job:
 *     *     I reverse k values. Call the same onto my right.
             I attach the pointer returned by the right to my tail.
             I return my head.
 *     Base case:
        *     When there is no more nodes on my right I return my head.
 *     Delegation: Request guys on my right to reverse k values and provide the head.
 *
 * Time Complexity:
   Space Complexity:
 *
 **/
List * IKSolution::myListreverseAListInGroupsOfGivenSize(List *myList, int k)
{
    if(k == 0)
    {
        return myList;
    }
    return reverseUtil(myList, k);

}

/****************************************************************************************************************************/

/* Problem:
 *        Zip a linked list from its two ends.
 * Example:
 *        Given a linked list <1, 2, 3, 4, 5, 6>, zip of this linked list is defined as 1, 6 , 2, 5 , 3, 4.
 *        And the task is to achieve desired linked list using O(1) space.
 *
 * Approach:
 *        While traversing the list push all node references to a stack. Then during the second traversing
 *        pop the stack and insert nodes.
   Time Complexity: O(n)
   Space Complexity: O(n)
 * Alternate approach: Use the APIs provided by C++ STLs provided by C++
 * http://programming-puzzle.blogspot.com/2014/02/zip-of-linked-list.html
 *
 **/
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

    /*Insert nodes from the stack */
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

    /*Set the tail of the list as null */
    if(ms.top() == temp)
        temp->next = nullptr;
    else if(temp->next == ms.top())
        temp->next->next = nullptr;

    return myList;
}

/* Problem:
 * Example:
 * Approach:
 *     Push value to the priority queue
       Get the value from the top of the queue. This is the max value for the current window.
           If the top of the queue's index does not fall in window range, then pop it out.
              Continue popping out until you hit an entry whose index is in the window.
           Else process the next element in the array.

       Trick here: Since we dont really have a straight forward technique to delete an element in
       a priority queue we adopt this trick. Deleting by popping out. If we cant pop out an element
       because a higher value is sitting above that its OK. When we come across a value higher it will flush smaller one's out.
       But, if the value comes in keeps growing then we may not delete at all.
       http://articles.leetcode.com/sliding-window-maximum
   Time Complexity:
   Space Complexity:
 *
 **/
vector<int> IKSolution::slidingWindowMax(vector<int> v, int w)
{
    priority_queue<pair<int,int>> mypq;
    vector<int> ret;
    int index = 0;

    for(auto it : v)
    {
        DEBUG_DEBUG(cout << "prio Q index = " << index << " val = " << it << "\n");
        mypq.push(make_pair(it,index));
        if(mypq.size() >= w)
        {
            pair<int,int> p = mypq.top();
            ret.push_back(p.first);
            DEBUG_DEBUG(cout << "Result vector val  = " << p.first  << "\n");

            //Pop out indexes that are not in the window
            while(p.second <= (index - w + 1))
            {
                DEBUG_DEBUG(cout << "About to pop " << p.first << "\n");
                mypq.pop();
                p = mypq.top();
            }
            DEBUG_DEBUG(cout<< "size of queue =  " <<  mypq.size() << "\n");

        }
        index++;
    }

    return ret;
}


/****************************************************************************************************************************/
/* Problem:
 *     Min stack. A stack that provides getMin() operation which provides the minimum values present in the stack in O(1)
 * Example:
 *     Approach: Maintain another heap that has min value on its top. Any value less than min is not pushed into this stack.
 *     Any value less that this is pushed into stack.
   Time Complexity:
   Space Complexity:
 *
 */
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

/* Problem: Longest Substring with matching parentheses
 * Example:
 *
 * Approach:
 *     The key here is to store the index of the last unhappy parentheses.
 *     The sum = my index - index of the last unhappy parentheses.
 *     ( (()) ((()))
 *     In the case of above string we we process the last parentheses we have -1, and 0 in the stack.
 *     We calculate the sum as 10 - 0 = 10
 *
 *     ( (()) ((()
 *     In the case of above string we we process the last parentheses we have -1, and 0 in the stack.
 *     We calculate the sum as 8 - 6 = 2
 *
   Time Complexity: O(n)
   Space Complexity:
 * Take Away:
 *
 **/
int IKSolution::maxLenMatchingParen(string str)
{
    int n = str.length();

    // Create a stack and push -1 as initial index to it.
    stack<int> stk;
    stk.push(-1);

    // Initialize result
    int result = 0;

    // Traverse all characters of given string
    for (int i = 0; i < n; i++)
    {
        // If opening bracket, push index of it
        if (str[i] == '(')
          stk.push(i);

        else // If closing bracket, i.e.,str[i] = ')'
        {
            // Pop the previous opening bracket's index
            stk.pop();

            // Check if this length formed with base of
            // current valid substring is more than max
            // so far
            if (!stk.empty())
                result = max(result, i - stk.top());

            // If stack is empty. push current index as
            // base for next valid substring (if any)
            else stk.push(i);
        }
    }

    return result;
}

