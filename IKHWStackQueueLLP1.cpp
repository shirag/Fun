/*
 * IKHWStackQueueLLP1.cpp
 *
 *  Created on: Feb 10, 2017
 *      Author: Raghav Navada
 */

#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


bool identicalLinkedListNodes(LinkedListNode *l1, LinkedListNode *l2)
{
    if(l1 == nullptr && l2 == nullptr)
        return true;

    if(l1 != nullptr && l2 != nullptr)
        if(l1->val == l2 ->val)
            return identicalLinkedListNodes(l1->next, l2->next);

    return false;
}


void printLinkedListNode(list<int> l)
{
    for(auto it : l)
        cout << " " << it << " ";
    cout << "\n";
}


void printLinkedListNodeP(LinkedListNode * p)
{
    while(p != nullptr)
    {
        cout << "val = " << p->val << " ";
        p = p->next;
    }
}


/****************************************************************************************************************************/
/*
(Using difference of node counts)
1) Get count of the nodes in first LinkedListNode, let count be c1.
2) Get count of the nodes in second LinkedListNode, let count be c2.
3) Get the difference of counts d = abs(c1 – c2)
4) Now traverse the bigger LinkedListNode from the first node till d nodes so that from here onwards both the LinkedListNodes have equal no of nodes.
5) Then we can traverse both the LinkedListNodes in parallel till we come across a common node.
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
        DEBUG_DEBUG(cout << "Intersection of two LinkedListNodes found \n");
        return it1;
    }
    else
    {
        DEBUG_DEBUG(cout << "Intersection of two LinkedListNodes NOT found \n");
        return L1.end();
    }

}

/* Input: Arbitrary pointer to a sorted circular linked LinkedListNode.
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
int IKSolution::Median(LinkedListNode *l1)
{
    LinkedListNode *temp = l1;

    if(temp == nullptr)
        return 0;

    while(temp->val < temp->next->val)
    {
        temp = temp->next;
    }

    DEBUG_TRACE(cout << "Starting value = " <<  temp->next->val << " \n");

    LinkedListNode *slow = temp->next;
    LinkedListNode *fast = temp->next;
    DEBUG_DEBUG(cout << "slow init value = " <<  slow->val << " \n");
    DEBUG_DEBUG(cout << "fast init value = " <<  fast->val << " \n");

    //Until you process all nodes in the LinkedListNode
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
 *     Same as finding the median in a circular LinkedListNode. Instead of checking for null for fast, we are checking
 *     for the beginning of the loop.
 *     If fast points to a node whose next is null, its time to come out of the loop.
 *     If fast points to a null, its time to come out of the loop.
   Time Complexity:
   Space Complexity:
 *
 **/
int IKSolution::findMiddleNode(LinkedListNode *head)
{
    LinkedListNode *slow = head;
    LinkedListNode *fast = head;

    if(head == nullptr)
    {
        return 0;
    }

    //Until you process all nodes in the LinkedListNode
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
LinkedListNode *IKSolution::pointerToCycle(LinkedListNode *head)
{
    LinkedListNode* fast = NULL;
    LinkedListNode* slow = NULL;
    int counter = 1;

    if(head == NULL)
        return nullptr;

    slow = head;
    fast = head;

    //Until you process all nodes in the LinkedListNode
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
        LinkedListNode *temp = slow;
        temp = temp->next; // beginning of the LinkedListNode
        while(temp != fast) //until you find the last item in the LinkedListNode.
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

    if(counter == 0)
        return nullptr;

    slow = head;
    fast = head;
    while(counter > 0)
    {
        fast = fast->next;
        counter--;
    }


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
LinkedListNode* LRUCache::createANewNode(int key,int val)
{
    LinkedListNode *n = new(LinkedListNode);
    n->val = val;
    n->key = key;
    n->next = nullptr;
    n->prev = nullptr;

    return n;
}

void LRUCache::push_front(LinkedListNode *node)
{
    DEBUG_DEBUG(cout << "Insert a new node at the head of the linked LinkedListNode \n");
    if(head == nullptr)
    {
        head = node;
        tail = head;
    }
    else
    {
        LinkedListNode *temp = head;
        head = node;
        node->next = temp;
        temp->prev = node;
    }
}


void LRUCache::move_front(LinkedListNode *node)
{
    DEBUG_DEBUG(cout << "Move an existing node to the head of the linked LinkedListNode \n");

    LinkedListNode *prev = node->prev;
    if(prev != nullptr)
        prev->next = node->next;
    else
        head = nullptr;

    LinkedListNode *next = node->next;
    if(next != nullptr)
        next->prev = node->prev;

    if(node == tail)
        tail = prev;

    push_front(node);

}

void LRUCache::pop_back()
{
    DEBUG_DEBUG(cout << "Remove the tail of the linked LinkedListNode \n");
    if(tail == nullptr)
        return;

    LinkedListNode *prev = tail->prev;
    if(prev != nullptr)
        prev->next = nullptr;
    else
        head = nullptr;

    delete(tail);
    tail = prev;
}

//Remove a node in the middle of the Linked LinkedListNode
void LRUCache::remove_node(LinkedListNode* node)
{

    LinkedListNode *prev = node->prev;
    if(prev != nullptr)
        prev->next = node->next;
    else
        head = nullptr;

    LinkedListNode *next = node->next;
    if(next != nullptr)
        next->prev = node->prev;
    else
        tail = nullptr;

    delete(node);
}

/* Look at an entry in the top of the doubly linked LinkedListNode and then remove it */
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
       Implement a LRU cache with following methods in O(1).
       set(int key, int val);
       get(int key);
       remove(int key)

 * Example:
 *
 * Approach:
       * Have a unordered_map and a Doubly linked list. Head of the list should be
       * most recently used and tail is the least recently used.

 *
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
        LinkedListNode *temp = createANewNode(key,val);
        push_front(temp);
        lrum.insert(make_pair(key,temp));
    }
    else
    {
        DEBUG_DEBUG(cout << "Key already exists. So, just moving to the top" << "\n");
        LinkedListNode* node = it->second;
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

    LinkedListNode* node = it->second;
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

    LinkedListNode* node = it->second;
    remove_node(node);
    lrum.erase(it);

}




/******************************************************************************************************/


/* Problem:
 *     Swap Kth node from beginning with Kth node from end in a Linked LinkedListNode. Given a singly linked LinkedListNode, swap kth node
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
        4) X and Y don’t exist (k is more than number of nodes in linked LinkedListNode)
 * Take away:
 *      Very important. While moving two pointers, if the first one fails to move because next ptr is null, you must not move the second one.
 *      So, check for ptr->next == NULL before moving the other pointer.

 **/
LinkedListNode* IKSolution::swapKthNodes(LinkedListNode* head, int k)
{
    DEBUG_TRACE(cout << "k = " << k << "\n");

    LinkedListNode *temp,*kBp, *kB, *kEp, *kE;

    LinkedListNode dummyNode;
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
        LinkedListNode* t1 = kB->next;
        LinkedListNode* t2 = kE->next;

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

LinkedListNode* reverseUtil(LinkedListNode *myLinkedListNode,int k)
{
    LinkedListNode *temp = myLinkedListNode;
    int counter = 1;
    LinkedListNode *curr;
    LinkedListNode *prev = nullptr;

    curr = myLinkedListNode;

    while((curr != nullptr) && (counter <= k))
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        counter++;
    }

    if(curr != nullptr)
        myLinkedListNode->next = reverseUtil(curr, k); //Attach the haed provided by the recursive funnction to my tail.
    else
        return prev; //My head

    return prev; //My head
}

/* Problem:
       Reverse a Linked LinkedListNode in groups of given size. Given a linked LinkedListNode, write a function to reverse every k
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
LinkedListNode * IKSolution::myLinkedListNodereverseALinkedListNodeInGroupsOfGivenSize(LinkedListNode *myLinkedListNode, int k)
{
    if(k == 0)
    {
        return myLinkedListNode;
    }
    return reverseUtil(myLinkedListNode, k);

}

/****************************************************************************************************************************/

/* Problem:
 *        Zip a linked LinkedListNode from its two ends.
 * Example:
 *        Given a linked LinkedListNode <1, 2, 3, 4, 5, 6>, zip of this linked LinkedListNode is defined as 1, 6 , 2, 5 , 3, 4.
 *        And the task is to achieve desired linked LinkedListNode using O(1) space.
 *
 * Approach:
 *        While traversing the LinkedListNode push all node references to a stack. Then during the second traversing
 *        pop the stack and insert nodes.
   Time Complexity: O(n)
   Space Complexity: O(n)
 * Alternate approach: Use the APIs provided by C++ STLs provided by C++
 * http://programming-puzzle.blogspot.com/2014/02/zip-of-linked-LinkedListNode.html
 *
 **/
LinkedListNode * IKSolution::zipALinkedListNode(LinkedListNode *myLinkedListNode)
{
    LinkedListNode* temp;
    stack<LinkedListNode*> ms;

    if(myLinkedListNode == nullptr)
        return nullptr;

    temp = myLinkedListNode;
    while(temp != nullptr)
    {
        ms.push(temp);
        temp = temp->next;
    }

    /*Insert nodes from the stack */
    temp = myLinkedListNode;
    while((ms.top() != temp) && (temp->next != ms.top()))
    {
        LinkedListNode* t = ms.top();
        ms.pop();

        LinkedListNode* n = temp->next;
        temp->next = t;
        t->next = n;
        temp = n;
    }

    /*Set the tail of the LinkedListNode as null */
    if(ms.top() == temp)
        temp->next = nullptr;
    else if(temp->next == ms.top())
        temp->next->next = nullptr;

    return myLinkedListNode;
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
/***********************************************************************************************************/

LinkedListNode* AddTwoLinkedListNodesUtil(LinkedListNode *LinkedListNode1, LinkedListNode *LinkedListNode2, int& carry)
{

    if((LinkedListNode1 == nullptr) && (LinkedListNode2 == nullptr))
    {
        return nullptr;
    }

    int gcarry = 0;
    LinkedListNode *nnode = AddTwoLinkedListNodesUtil(LinkedListNode1->next, LinkedListNode2->next, gcarry);

    int sum = LinkedListNode1->val + LinkedListNode2->val + gcarry;
    if (sum >= 10)
        carry = 1;

    LinkedListNode *node = new(LinkedListNode);
    node->val = sum % 10;
    node->next = nnode;

    return node;

}


/*
 *
 * Problem:
 *      Add two numbers in a linked LinkedListNode. Head of the LinkedListNode is the most significant digit.
 *      9 -> 9 -> 9
 *      9 -> 9 -> 9
 *      should give us
 *      1 -> 9 -> 9 -> 8
 *
 *      1 -> 2 -> 3
 *      4 -> 5 -> 3
 *      should give us
 *      5 -> 7 -> 6
 *
 * Approach:
 *      Here we assume two LinkedListNodes are of equal length and recursively call utility function onto the next element.
 *      If two LinkedListNodes are of unequal length then we have to call the recursive function from the point where two lengths are same.
 *      Basically we should skip the first one by those many nodes.
 *
 */

LinkedListNode* IKSolution::AddTwoLinkedListNodes(LinkedListNode *LinkedListNode1, LinkedListNode *LinkedListNode2)
{

    int carry = 0;

    LinkedListNode *nnode = AddTwoLinkedListNodesUtil(LinkedListNode1, LinkedListNode2, carry);

    if (carry == 1)
    {
        LinkedListNode *node = new(LinkedListNode);
        node->val = 1;
        node->next = nnode;
        return node;
    }

    return nnode;

}
/******************************************************************************************/
LinkedListNode* AddTwoLinkedListNodesLSDFirstUtil(LinkedListNode *LinkedListNode1, LinkedListNode *LinkedListNode2, int carry)
{

    if((LinkedListNode1 == nullptr) && (LinkedListNode2 == nullptr))
    {
        if(carry)
        {
            LinkedListNode *node = new(LinkedListNode);
            node->val = carry;
            node->next = nullptr;
            return node;
        }
        else
            return nullptr;
    }

    int sum = carry + (LinkedListNode1 ? LinkedListNode1->val : 0) + (LinkedListNode2 ? LinkedListNode2->val : 0);
    LinkedListNode *node = new LinkedListNode;
    node->val = sum % 10;
    node->next = AddTwoLinkedListNodesLSDFirstUtil((LinkedListNode1 ? LinkedListNode1->next : 0), (LinkedListNode2 ? LinkedListNode2->next : 0), sum/10);
    return node;

}


/*
 *
 * Problem:
 *      Add two numbers in a linked LinkedListNode. Head of the LinkedListNode is the least significant digit.
 *      2 -> 1(12)
 *      3 -> 2(23)
 *      should give us
 *      5 -> 3(35)
 *
 * Approach:
 *      Top-down approach.
 *
 */

LinkedListNode* IKSolution::AddTwoLinkedListNodesLSDFirst(LinkedListNode *LinkedListNode1, LinkedListNode *LinkedListNode2)
{

    int carry = 0;
    return AddTwoLinkedListNodesLSDFirstUtil(LinkedListNode1, LinkedListNode2, carry);

}
/******************************************************************************************/


list<int> mergeLinkedListNodes(list<int> left, list<int> right)
{
    list<int> result;

    list<int>::iterator itl = left.begin();
    list<int>::iterator itr = right.begin();

    while((itl != left.end()) && (itr != right.end()))
    {
        if(*itl < *itr)
        {
            result.push_back(*itl);
            itl++;
        }
        else if(*itr < *itl)
        {
            result.push_back(*itr);
            itr++;
        }
        else
        {
            result.push_back(*itr);
            itr++;

        }
    }

    while(itl != left.end())
    {
        result.push_back(*itl);
        itl++;
    }

    while(itr != right.end())
    {
        result.push_back(*itr);
        itr++;
    }

    return result;

}


list<int> IKSolution::MergeSortLists(list<int> l)
{

    list<int> left;
    list<int> right;

    if(l.size() <= 1)
        return l;

    int size = l.size();
    int i = 0;

    for(auto val : l)
    {
        if(i < size/2)
            left.push_back(val);
        else
            right.push_back(val);

        i++;
    }


    list<int> leftn = MergeSortLists(left);
    list<int> rightn = MergeSortLists(right);

    return mergeLinkedListNodes(leftn, rightn);

}

/*
 * */

LinkedListNode* mergeLinkedListNodesN(LinkedListNode* left, LinkedListNode* right)
{
    LinkedListNode* result = nullptr;
    LinkedListNode* tp = nullptr;

    while((left != nullptr) && (right != nullptr))
    {
        if(left->val < right->val)
        {
            if(result == nullptr)
                result = left;
            else
                tp->next = left;
            tp = left;
            left = left->next;
        }
        else
        {
            if(result == nullptr)
                result = right;
            else
                tp->next = right;
            tp = right;
            right = right->next;
        }
    }

    if(left != nullptr)
    {
        if(result == nullptr)
            result = left;
        else
            tp->next = left;
    }

    if(right != nullptr)
    {
        if(result == nullptr)
            result = right;
        else
            tp->next = right;
    }

    return result;
}

int szLinkedListNode(LinkedListNode *l)
{
    int i = 0;

    while(l != nullptr)
    {
        l = l->next;
        i++;
    }

    return i;
}

LinkedListNode* IKSolution::MergeSortLinkedListNodePtr(LinkedListNode *l)
{

    LinkedListNode *left = nullptr;
    LinkedListNode *right = nullptr;
    LinkedListNode *tl = nullptr;
    LinkedListNode *tr = nullptr;

    if(szLinkedListNode(l) <= 1)
    {
        return l;
    }

    int size = szLinkedListNode(l);
    int i = 0;

    DEBUG_DEBUG(cout << "size = " << size << " \n");

    while(l != nullptr)
    {
        if(i < size/2)
        {
            if(left == nullptr)
                left = l;
            tl = l;
        }
        else
        {
            if(right == nullptr)
                right = l;
            tr = l;
            break;
        }

        i++;
        l = l->next;
    }
    tl->next  = nullptr;

    LinkedListNode* leftn = MergeSortLinkedListNodePtr(left);
    LinkedListNode* rightn = MergeSortLinkedListNodePtr(right);

    return mergeLinkedListNodesN(leftn, rightn);

}

/******************************************************************************************/


/* Problem:
 *     You are given a Double Link List with one pointer of each node pointing to the next node
 *     just like in a single link list. The second pointer however CAN point to any node in the list and
 *     not just the previous node. Now write a program in O(n) time to duplicate this list.
 *     That is, write a program which will create a copy of this list.

       Let us call the second pointer as random pointer as it can point to any arbitrary
       node in the linked list.

   Example:

 *        |-----------|------------
 *        |           ||           |
 *        |           v|           v
          1 -->  2 --> 3 --> 4 --> 5
          ^      ^     ^     |     |
          ------ |     |-----|     |
                 ----------------- |

        in the above diagram
        1's random points to 3
        2's random points to 1
        3's random points to 5
        4's random points to 3
        5's random points to 1

   Approach:
    * Create the copy of node 1 and insert it between node 1 & node 2 in original Linked LinkedListNode, create the copy of 2
 *    and insert it between 2 & 3. Continue in this fashion, add the copy of N after the Nth node
 *
    * Now copy the arbitrary link in this fashion
      original->next->arbitrary = original->arbitrary->next;  /*TRAVERSE TWO NODES

    *  Restore the original linked LinkedListNode.
*/

LinkedListNode* IKSolution::cloneASpecialLinkedList(LinkedListNode *l)
{

    LinkedListNode *newHead = nullptr;

#if 0 //O(n) space and time.
    map<int,LinkedListNode*> table;


    LinkedListNode *l1Current = l;
    LinkedListNode *prev = nullptr;

    while(l1Current != nullptr)
    {
        LinkedListNode *newNode = new LinkedListNode;
        newNode->val = l1Current->val;
        if(newHead == nullptr)
            newHead = newNode;
        else
            prev->next = newNode;
        prev = newNode;

        table.insert({l1Current->val,newNode});
        l1Current = l1Current->next;
    }

    l1Current = l;
    LinkedListNode *l2Current = newHead;
    while(l1Current != nullptr)
    {
        l2Current->rand = table[l1Current->rand->val];
        l1Current = l1Current->next;
        l2Current = l2Current->next;
    }
#endif


    //Insert new node copy after every node in the original LinkedListNode
    LinkedListNode *l1Current = l;
    while(l1Current != nullptr)
    {
        LinkedListNode *newNode = new LinkedListNode;
        newNode->val = l1Current->val;
        newNode->next = l1Current->next;
        newNode->rand = nullptr;
        l1Current->next = newNode;
        l1Current = newNode->next;
    }

    l1Current = l;
    while(l1Current != nullptr)
    {
        if(l1Current->rand != nullptr)
            l1Current->next->rand = l1Current->rand->next;

        l1Current = l1Current->next->next;
    }


    l1Current = l;
    LinkedListNode *newTail = nullptr;
    while(l1Current != nullptr && l1Current->next != nullptr)
    {
        LinkedListNode *temp = l1Current->next->next;

        if(newHead == nullptr)
            newHead = l1Current->next;
        else
            newTail->next = l1Current->next;

        newTail = l1Current->next;

        l1Current->next = temp;
        l1Current = l1Current->next;
    }
    if(newTail != nullptr)
        newTail->next = nullptr;


    return newHead;
}
/***********************************************************************************************************************************/

/* Problem:
 *     Alternative node split: Given a linked list, split it into two such that every other node goes into the new list.
 *     For lists with odd number of nodes, first one should be longer.
 * Example:
       an input list: {a, b, c, d, e, f, g} should results in {a, c, e, g} and {b, d, f}.
 *
 * Approach:
 *
 *
 *
 */

LinkedListNode* IKSolution::alternativeSplit(LinkedListNode* pLinkedListNode)
{
    LinkedListNode* temp = pLinkedListNode;
    int index = 0;
    LinkedListNode* newHead = nullptr;
    LinkedListNode* newTail = nullptr;
    LinkedListNode* prev = nullptr;

    printLinkedListNodeP(pLinkedListNode);

    while(temp != nullptr)
    {
        if(index % 2)
        {
            if(newHead == nullptr)
                newHead = temp;
            else
                newTail->next = temp;

            prev->next = temp->next;
            newTail = temp;
        }

        prev = temp;
        temp = temp->next;
        index++;
    }
    if(newTail != nullptr)
        newTail->next = nullptr;

    return newHead;
}

/* Problem:
 *     Write a function that checks if the given input string has matching opening and closing parentheses.
 *     Valid parentheses are: ‘(‘, ‘)’, ‘{‘, ‘}’, ‘[‘, ‘]’
 *
 * Example:
 *     hasMatchingParantheses("( ( 1 + 2 ) * 3 )") ⇒ true
       hasMatchingParantheses("( { 1 + 2 ) * 3 )") ⇒ false
       hasMatchingParantheses("( ( (1 + 2) * 3 ))") ⇒ true
       hasMatchingParantheses("[([])}") ⇒ false
       hasMatchingParantheses("} ( 1 * 2) + 3 * ( 5 - 6)") ⇒ false

   Approach:
       * set contains open parentheses information.
       * Map contains the match.
       * Process these DS.

 *
 *
 * */

/***********************************************************************************/

bool IKSolution::hasMatchingParantheses(string strExpression)
{
    set<char> openTable;
    map<char, char> closeTable;
    stack<char> iStack;

    openTable = {
                 {'('},
                 {'{'},
                 {'['}
               };

    closeTable = {
                 {')','('},
                 {'}','{'},
                 {']','['},
               };


    for(auto val : strExpression)
    {
        if(openTable.count(val) > 0)
            iStack.push(val);
        else if(closeTable.count(val) > 0)
        {
            if(iStack.empty() || iStack.top() != closeTable[val])
                return false;
            iStack.pop();
        }

    }

    if(!iStack.empty())
        return false;

    return true;
}
/*******************************************************************************************************/

superStack::superStack()
{
    head = new LinkedListNode;
    head->next = nullptr; //IMPORTANT
}

void superStack::push(int x)
{
    LinkedListNode * temp = new LinkedListNode;
    temp->val = x;
    temp->next = head->next;
    head->next = temp;

    size++;
    top();

}

void superStack::pop()
{
    if(size != 0 && head->next != nullptr)
    {
       LinkedListNode *tmp = head->next;
       head->next = head->next->next;
       delete tmp;
       size--;
       top();
    }
}

int superStack::top()
{
    if(head->next != nullptr)
    {   cout << head->next->val << "\n";
        return head->next->val;
    }
    else
        cout << "EMPTY\n";

    return 0;
}

void superStack::inc(int e, int k)
{
    int noOfElementsToSkip;

    noOfElementsToSkip = size > e ? size - e : 0; //IMPORTANT, if k is nore than size, then all of them should be incremented
    LinkedListNode *tmp = head->next;

    while((tmp != nullptr) && noOfElementsToSkip > 0)
    {
        //cout << "skipping \n";
        noOfElementsToSkip--;
        tmp = tmp->next;
    }

    while(tmp != nullptr)
    {
        tmp->val += k;
        tmp = tmp->next;
    }

    top();
    return;

}


#if 0
void insertNodeA(LinkedListNode *prev, LinkedListNode *nnode)
{

    if(prev != nullptr && nnode != nullptr)
    {
        LinkedListNode * tmp = prev->next;
        prev->next = nnode;
        nnode->next = tmp;
    }
    else if(prev == nullptr && nnode != nullptr)
    {
        nnode->next = curr;
    }
}

void removeANode(LinkedListNode *prev, LinkedListNode *nnode)
{
    if(prev != nullptr && nnode != nullptr)
        prev->next = nnode->next;
}
#endif


/*******************************************************************************************************/


LinkedList::LinkedList()
{
    head = new LinkedListNode; //dummyhead. Makes the code very simple
    head->next = nullptr;
    head->val = INT_MIN;

}

/* You want to insert a node to the list at the same time you want to keep the list sorted */
void LinkedList::addValue(int x)
{
    LinkedListNode *current = head->next;
    LinkedListNode *prev = head;

    LinkedListNode *tnode = new LinkedListNode;
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
    LinkedListNode *current = head->next;
    LinkedListNode *prev = head;

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
    LinkedListNode *current = head->next;

    while(current != nullptr && current->val != x)
        current = current->next;

    if(current != nullptr)
        return true;

    return false;
}

LinkedList::~LinkedList()
{
    LinkedListNode *current = head;
    LinkedListNode *prev = head;

    while(current != nullptr)
    {
        prev = current;
        current = current->next;
        delete prev;
    }
}

void LinkedList::printList()
{

    LinkedListNode *current = head;

    while(current != nullptr)
    {
        cout << "val = " << current->val << " \n";
        current = current->next;
    }
}



#if 0
//IMPLEMENT skip list
class skipNode
{
    private:

    public:
        int val;
        vector<skipNode*> next;


};


class skipList
{
    private:
        vector<skipNode *> head = nullptr;
        vector<skipNode *> tail = nullptr;
        skipNode *prevNode = nullptr;
        int count = 0;

    public:
        void addNodeToSkipList(int);

};


void skipList::addNodeToSkipList(int x)
{
    skipNode *temp = new skipNode;
    temp->val = x;

    if(!count%2)
    {
        head.push_back(temp);
    }



}

int mySkipListMain()
{
    skipNode node1;
    skipNode node2;
    skipNode node3;
    skipNode node4;
    skipNode node5;

}
#endif


