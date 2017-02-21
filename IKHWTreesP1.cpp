/*
 * HomeWork2.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: GouriShivani
 */



#include "IKSolution.hpp"


/* Problem: Given a binary tree, print all root-to-leaf paths one per line
 * Example:
 * Approach: Pre order DFS. Push the value to a stack when you process a node. After you are done processing all node's children
 *           pop out pushed value. If there is no children(leaf node) print values.
 * Time Complexity: O(n)
 * Space Complexity: O(logN) Best case.
 * Any other better approach:
 * Corner case:
 * Take away:
 */
/************************************************************************************************************************/

int printAllPathsRecurse(Node *node, vi& p)
{
    if(node == NULL)
        return 0;

    p.push_back(node->val);

    if( !node->left && !node->right)
    {
        int size = p.size();
        for(int i = 0; i < size; i++)
            cout <<  p[i] << " ";

        cout << "\n";
    }
    else
    {
        printAllPathsRecurse(node->left,p);
        printAllPathsRecurse(node->right,p);
    }

    p.erase(p.end()-1);

    return 0;

}

int IKSolution::printAllPathsInATee(Node* root)
{
   vi p;
   printAllPathsRecurse(root, p);
   return 0;
}
/*********************************************************************************************************/



Node* generateBBST(vector<int>& vals, int low, int high)
{
    if(low > high)
        return 0;

    int middle = (low + high)/2;

    Node *root = createTreeNode(vals[middle]);

    root->left = generateBBST(vals,low,middle-1);
    root->right = generateBBST(vals,middle+1,high);

    return root;
}


int storeInOrder(Node *node, vector<int>& vals)
{
    if(node == NULL)
        return 0;

    storeInOrder(node->left,vals);
    cout<< "vals = " <<  node->val << "\n";
    vals.push_back(node->val);
    storeInOrder(node->right,vals);

    return 0;
}


/* Problem: Merge Two BSTs
 * Example:
 * Approach:
 *  Inorder traversal of node1 and generate a sorted array
    Inorder traversal of node1 and generate a sorted array
    Merge two arrays
    Generate a balanced BST from merged array
 *
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */
Node* IKSolution::mergeTwoBSTs(Node* node1, Node* node2)
{

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    Node* node3;

    storeInOrder(node1, v1);
    storeInOrder(node2, v2);

    v3 = mergeVector(v1,v2);

    node3 = generateBBST(v3, 0, v3.size()-1);



    return node3;
}
/************************************************************************************************************************/

/* Problem: Post order traversal
 * Example:
 * Approach: DFS Use auxillary stack. Push into the stack whatever you pop from main stack.
 *           while pushing into the main stack push left first and right next.
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */

void IKSolution::postorderTraversal(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> v1;
    vector<int>v2;

    v1.push(root);

    while(!v1.empty())
    {
        Node *tn = v1.top();
        v1.pop();

        v2.push_back(tn->val);

        postorderTraversal(tn->left);
        postorderTraversal(tn->right);

    }

    for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << " " << *it << " ";
    }


    return;
}
/**************************************************************************************************/

int countUniValSubtreesRec(Node *node, int& counter)
{

   if(node == NULL)
       return 0;


   if((node->left == NULL) && (node->right == NULL))
   {
       counter++;
       return 1;
   }

   if(node->left && node->right)
   {
       int ret1 = countUniValSubtreesRec(node->left, counter);
       int ret2 = countUniValSubtreesRec(node->right, counter);
       if ( (node->left->val == node->val) && (node->right->val == node->val) )
           if( ret1 && ret2 )
           {
               counter++; return 1;
           }
   }

   else if(node->left)
   {

       int ret1 = countUniValSubtreesRec(node->left, counter);
       if (node->left->val == node->val)
           if(ret1)
           {
               counter++; return 1;
           }

   }
   else
   {
       int ret1 = countUniValSubtreesRec(node->right, counter);
       if (node->right->val == node->val)
           if(ret1)
           {
               counter++;  return 1;
           }
   }

   return 0;
}
/**************************************************************************************************************/
/* Problem: Given a binary tree, we need to count the number of unival subtrees (all nodes have same value).
 * Example:
 * Approach: DFS search. If children's value is same as root and children are also unival trees then increment the counter.
 * Complexity: O(n)
 * Space Complexity: O(n)
 * Any other better approach:
 * Corner case:
 * Take away:
 */
int IKSolution::countUniValSubtrees(Node *node)
{
    int counter = 0;
    int val = countUniValSubtreesRec(node,counter);

    cout << "val = " << val << "\n";
    cout << "counter =  " << counter << "\n";

    return 0;
}
/****************************************************************************************************************/
/* Problem:
 *     Convert a BST to Circular Doubly Linked List.
 * Example:
 * Approach:
 *     Contract with a node: Ill give you a tail. You attach your head to the given tail and return a new tail.
 *     Head argument is set the very first time and remains constant.
 *
 *     Steps:
 *     1. Ask your left node(contract) to use the old tail and provide a new tail.
 *     2. You attach your left to that tail.
 *     3. You attach tail's left to you.
 *     4. Ask your right node(contract) to use yourself as the tail, use it and provide a new tail.
 *     5. Just return the tail returned by your right.
 * Complexity:O(n)
 * Space Complexity:O(n) or O(logn)
 * Any other better approach:
 * Corner case:
 * Take away:
 */

void treeToDoubleLLUtil(Node* root, Node*& tail, Node* &head)
{
    if(root == NULL)
        return;

    treeToDoubleLLUtil(root->left, tail, head);
    if(tail != NULL)
    {
        tail->right = root;
        root->left = tail;
    }
    else
        head = root;


    tail = root;
    treeToDoubleLLUtil(root->right, tail, head);

    return;
}

Node* IKSolution::treeToDoubleLL(Node* root)
{
    Node* tail = NULL;
    Node* head = NULL;

    treeToDoubleLLUtil(root, tail, head);

    if(head)
        head->left = tail;

    tail->right = head;
    return head;
}


/****************************************************************************************************************/
int lcaUtilRec(Node* node, vector<Node*>&v, int n)
{
    if(node == NULL)
        return 0;

    v.push_back(node);

    if(node->val == n)
        return 1;

    if( lcaUtilRec(node->left, v, n) || lcaUtilRec(node->right, v, n))
        return 1;

    v.erase(v.end()-1);

    return 0;
}

/* Problem: Find Least Common Ancestor
 * Example:
 *
 * Approach:
 *          Perform individual DFS and store the path in a stack. Compare stacks in the end to
 *          find out the where they diverge.
 * Time Complexity:O(n)
 * Space Complexity: O(logn) if balanaced. Worst O(n)
 * Any other better approach:
 * Corner case:
 * Take away:
 */
Node* IKSolution::findLCA(Node* root, int n1, int n2)
{
    vector<Node*> v1, v2;

    if(!(lcaUtilRec(root,v1,n1) && lcaUtilRec(root,v2,n2)))
        return NULL;

    int size1 = v1.size();
    int size2 = v2.size();
    int index = 0;

    for( ;(index < size1) && (index <size2); index++ )
    {
        if(v1[index] != v2[index])
            break;
    }
    return v1[index-1];
}

/****************************************************************************************************************/
bool isBSTUtil(Node *node,int min, int max)
{
    if(node == NULL) //Empty tree is a BST.
        return true;

    if( (node->val < min) || (node->val > max) )
        return false;

    return ( isBSTUtil(node->left, min, (node->val) - 1) &&
        isBSTUtil(node->right, (node->val) + 1, max));

}

/* Problem:
       Check if a tree is a BST?
 * Example:
 *
 * Wrong example
 *          3
 *          /\
 *         2  5
 *        / \
 *       /   \
 *      1      4
 * Approach: Preorder DFS. You check a node's value. If its more than max allowed or less than min allowed, they are not a binary search tree.
 *           For children you query specifying the 'max' and 'min' allowed. If children say they are not a binary search tree then
 *           its not a binary search tree. When you invoke the function for children on the left, specify val - 1 for max and inside
 *           children check for greater than condition.
 * Complexity:O(n) . You got to visit all nodes.
 * Space Complexity: O(logn). Considering the stack.
 * Any other better approach: Do a inorder traversal and place the contents in a array. If the array is sorted then its a BST.
 * Any corner cases:
 * Take away:
 */
bool IKSolution::isBST(Node* node)
{
    return isBSTUtil(node, INT_MIN, INT_MAX);
}


Node* createBalancedBSTUtil(vector<int> &iArray, int low, int high)
{

    if(low > high)
        return NULL;

    int mid = (low + high)/2;
    Node* temp = createTreeNode(iArray[mid]);

    temp->left = createBalancedBSTUtil(iArray, low, mid-1);
    temp->right = createBalancedBSTUtil(iArray, mid+1, high);

    return temp;

}

/* Problem: printing-binary-tree-in-level-order
 * Example:
 *    3
     /  \
 *  9    20
        /  \
       15    7
 *
 *      3
        9 20
        15 7
 *
 * Approach:
 *
 * Time Complexity:O(n)
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */

void IKSolution::createBalancedBST(vector < int > iArray)
{
    int size = iArray.size();
    createBalancedBSTUtil(iArray,0,size-1);

    /* Now print the tree at each level. Use a pair to store the level when you push a node to a stack
     * When you pop out of stack, if the level is higher than previous introduce a \n */

    /* Soln 1: The most natural solution for level-order traversal is Breadth First Search (BFS). Use a pair with level
     * and node information  */
    /* The single queue solution requires two extra counting variables which keep tracks of the number of nodes in the
     * current level (nodesInCurrentLevel) and the next level (nodesInNextLevel). When we pop a node off the queue,
     * current  we decrement nodesInCurrentLevel by one. When we push its child nodes to the queue,
     * we increment nodesInNextLevel by two. When nodesInCurrentLevel reaches 0,
     * we know that the current level has ended, therefore we print an endline here.
     * http://articles.leetcode.com/printing-binary-tree-in-level-order/
     */
}

/*
 * Approach: Inorder traversal prints no is sorting order. When you are done printing k nos just come out.
 * */
int IKSolution::findKThSmallestUtil(Node* root, unsigned int& k, unsigned int& counter)
{
    if(root == NULL)
        return 0;

    if(findKThSmallestUtil(root->left, k, counter))
        return 1;

    counter++;
    cout << "counter = " << counter <<  " " << root->val << " k = " << k <<"\n";
    if(counter == k)
        return 1;

    if(findKThSmallestUtil(root->right, k, counter))
        return 1;

    return 0;

}
