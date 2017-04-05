/*
 * IKHWTreesP2.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: raghav
 */


#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


/* Problem:
 *      Given a binary tree, clone it. Return the root node of the cloned tree.
 * Approach:
 *      Preorder DFS based copy.
 * Time Complexity: n
 * Space Complexity:
 *
 *
 * */
Node* IKSolution::cloneATree(Node *root)
{
    if(root == nullptr)
        return nullptr;


    Node *nnode = new(Node);
    nnode->val = root->val;
    nnode->right = cloneATree(root->right);
    nnode->left = cloneATree(root->left);

    return nnode;

}
/**********************************************************************************************/

/* Problem: Reverse a tree. Each node's left pointer should be swapped with right pointer.
 *
 * Example:
 *
 *        6
        /   \
       3     4
      / \   / \
     7   3 8   1

    Should be converted to
           6
         /   \
        4     3
       / \   / \
      1   8 3   7
 *
 * Approach:
 *     Pre-order recursive traverse. Reverse root's left and right and perform the same operation on
 *     left and right pointer.
 *
 * Time Complexity:
 *      O(n)
 *
 * Space Complexity:
 *      O(logn)/O(h)
 *
 */

Node* IKSolution::flipATree(Node *root)
{
    if(root == nullptr)
        return nullptr;

    swap(root->left, root->right);

    flipATree(root->left);
    flipATree(root->right);

    return root;

}

/**********************************************************************************************/
/*
 * Problem:
 *
 *     Given a binary tree, find the largest Binary Search Tree(BST), where largest means BST with largest
 *     number of nodes in it. The largest BST must include all of its descendants.
 *
 * Example:
 * Approach:
 *
 * */


/* Is this the right BST logic?
 * Can I use this logic to test if its a cpmplete  BST?
 * Write Ashok questions.
 * More tree examples.
 *
 * */

int largestBSTUtil(Node *root, bool& isBST)
{

    if(root == nullptr)
      {
          cout << "return null \n";
          isBST = true;
          return 0;
      }

      cout << "val = " << root->val << " \n";

      bool isBSTL; bool isBSTR; bool isBSTM = true;

      int leftVal = largestBSTUtil(root->left, isBSTL);
      int rightVal = largestBSTUtil(root->right, isBSTR);
      int maxVal = leftVal > rightVal ? leftVal : rightVal;

      if((root->left != nullptr) && (root->right != nullptr))
      {
          if((root->left->val < root->val) && (root->right->val > root->val) )
              isBSTM = true;
          else
              isBSTM = false;
      }
      else if((root->left == nullptr) && (root->right == nullptr))
      {
          isBSTM = true;
      }
      else if( (root->left != nullptr) && (root->right == nullptr))
      {
          isBSTM = false;
      }
       else if( (root->right != nullptr) && (root->left == nullptr))
      {
          isBSTM = false;
      }


      if((isBSTR == true) && (isBSTL == true) && (isBSTM == true))
      {
          isBST = true;
          cout << "returning BST " << leftVal + rightVal + 1 << " \n";
          return (leftVal + rightVal + 1);
      }

      isBST = false;
      cout << "returning " << maxVal << " \n";
      return maxVal;

}


int IKSolution::largestBST(Node *root)
{

    bool isBST;
    return largestBSTUtil(root, isBST);

}
/***********************************************************************************************/

/*
 * Problem:
 *     Construct Binary Tree from Preorder and Inorder Traversal results of a binary tree. Return pointer to the
 *     root of the tree.
 *
 * Approach:
 *    1. From the pre-order array, we know that first element is the root.
 *    2. We can find the root in in-order array.
 *    3. Then we can identify the left and right sub-trees of the root from in-order array.
      4. Using the length of left sub-tree, we can identify left and right sub-trees in pre-order array.
         Recursively, we can build up the tree.

  //               1
  //             /  \
  //            /    \
  //           /      \
  //          2        3
  //         / \      / \
  //        /   \    /   \
  //       4     5  7     8
  //               /
  //              /
  //             6

  // In Order  4 2 5 (1) 6 7 3 8
  // Pre Order (1) 2 4 5  3 7 6 8
 *
 */


Node * constrctTreeUtil(vector<int>& iInOrderArray, vector<int>& iPreOrderArray, int pOB, int pOE, int iOB, int iOE)
{

    DEBUG_TRACE(cout << "pOB " << pOB << " pOE " <<pOE << " iOB = "<< iOB << " iOE = " << iOE << "\n");
    if((pOB > pOE) || (iOB > iOE))
    {
        return nullptr;
    }

    /* Root is the first element of preOrder Array  */
    int rtValue = iPreOrderArray[pOB];

    Node *root = new Node();
    root->val = rtValue ;
    root->left = nullptr;
    root->right = nullptr;

    int i;
    /* Look for the value in the irder array. Now you have left and right subtree .*/
    for(i = iOB; i <= iOE; i++)
        if(rtValue == iInOrderArray[i])
            break;

    int lengthOfLeft = i - iOB;

    root->left = constrctTreeUtil(iInOrderArray, iPreOrderArray, pOB + 1, pOB + 1 + (lengthOfLeft - 1), iOB,  (iOB + lengthOfLeft - 1));
    root->right = constrctTreeUtil(iInOrderArray, iPreOrderArray, pOB + 1 + (lengthOfLeft - 1) + 1, pOE, (iOB + lengthOfLeft + 1), iOE);


    return root;

}

vvi IKSolution::constrctTree(vector<int> iInOrderArray, vector<int> iPreOrderArray)
{

    Node* temp = constrctTreeUtil(iInOrderArray, iPreOrderArray, 0, iPreOrderArray.size() - 1 , 0, iInOrderArray.size() - 1);

    //vvi res = treeLevelOrderPrint(temp);

    vvi res = treeLevelOrderPrintUsingList(temp);

    DEBUG_DEBUG(cout << " \n\n");

    return res;
}
/**************************************************************************************************************************************/

/* Problem:
 *        Populating Next Right Pointers in Each Node. What if the given tree could be any binary tree?
 *        Would your previous solution still work?
 *
 * Example:
 *        Given the following binary tree,
 *             1
              /  \
             2    3
            / \    \
           4   5    7

          After calling your function, the tree should look like:

              1 -> NULL
             /  \
            2 -> 3 -> NULL
           / \    \
          4-> 5 -> 7 -> NULL

    Approach:
        Tree BFS traversal. While traversing a particular level, populate the previous node.
 *
 * */
void IKSolution::PopulateSiblingPointers(Node *root)
{

    queue<list<Node *>> mQ;
    list<Node *> pushl;
    list<Node *> popl;

    if(root == nullptr)
    {
        return;
    }

    pushl.push_back(root);
    mQ.push(pushl);
    pushl.clear();

    while(!mQ.empty())
    {
        popl = mQ.front();
        mQ.pop();

        int i = 0;
        Node *prevNode;
        for(auto val : popl)
        {
            if(val->left != nullptr) //IMPORTANT
                pushl.push_back(val->left);
            if(val->right != nullptr)
                pushl.push_back(val->right);

            if(i != 0)
            {
                prevNode->nextRight = val;
            }
            prevNode = val;
            val->nextRight = nullptr;
            i++;
        }
        if(!pushl.empty())
        {
            mQ.push(pushl);
            pushl.clear();
        }
    }

    return;
}

/**************************************************************************************************************************************/

/* Problem:
 *     Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
       Calling next() will return the next smallest number in the BST.
       Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 *
 * Example:
 *        Given the following binary tree,
 *
    //              100
    //             /  \
    //            /    \
    //           /      \
    //          25      300
    //         / \      / \
    //        /   \    /   \
    //       4     50  250  350

    should return {4, 25, 50, 100, 250, 300, 350}; when you keep call next() on tree.

    Approach:
        Maintain a stack. Top of the stack always points to the lowest val.
        After popping out, if the right is not null, keep traversing onto your left. Keep pushing nodes to stack.

 *
 * */


void Tree::init(Node *root)
{
    if(root == nullptr)
        return;

    nextlowestStack.push(root);

    Node *temp = root->left;
    while(temp != nullptr)
    {
        nextlowestStack.push(temp);
        temp = temp->left;
    }
}


Node* Tree::next()
{
    Node* tn = nullptr;

    if(!nextlowestStack.empty())
    {
        tn = nextlowestStack.top();
        nextlowestStack.pop();
    }

    if((tn != nullptr) && (tn->right != nullptr))
    {
        nextlowestStack.push(tn->right);
        Node *temp = tn->right->left;
        while(temp != nullptr)
        {
            nextlowestStack.push(temp);
            temp = temp->left;
        }
    }

    return tn;
}

bool Tree::hasNext()
{
    return (!nextlowestStack.empty());
}

/**************************************************************************************************************************************/

int mySmartPointerDemo()
{
    int *ptr = new int(10);
    *ptr = 100;
    cout << *ptr << " \n" ;
    delete ptr;

    unique_ptr<int> smart_ptr(new int(10));
    *(smart_ptr) = 100;
    cout << *smart_ptr << " \n" ;

    return 0;

}


