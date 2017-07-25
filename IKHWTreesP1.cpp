/*
 * HomeWork2.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Raghav Navada
 */



#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"

#define  PRE_ORDER   1
#define   IN_OPDER   2
#define POST_ORDER   3

#define ORDER_OF_TRAVERSAL PRE_ORDER

TreeNode* createTreeNode(int key)
{
    TreeNode* node = new(TreeNode);
    node->val = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}


/*
 * A tree BFS implementation using Queue
 */
void IKSolution::treeBFS(TreeNode *root)
{
    queue<TreeNode *> mQ;
    TreeNode* tn;

    if(root == NULL)
        return;

    mQ.push(root);

    while(!mQ.empty())
    {
        tn = mQ.front();
        mQ.pop();

        if(tn->left)
            mQ.push(tn->left);

        if(tn->right)
            mQ.push(tn->right);
    }

}

/************************************************************************************************************************************/
/* Its OK to make the tree unbalanced during the process.
 * Function that creates a new and returns its pointer.
 * Each node returns its pointer.
 *  */
TreeNode* IKSolution::bSTTreeInsert(TreeNode *root, int key)
{
    if (root == NULL)
        return createTreeNode(key);

    if(key == root->val)
        return root;

    if(key < root->val)
        root->left = bSTTreeInsert(root->left, key);
    else
        root->right = bSTTreeInsert(root->right, key);

    return root;


}

/*********************************************************************************************************************/

bool isP(string str)
{

    int l = 0;
    int h = str.length() - 1;

    while (h > l)
        if (str[l++] != str[h--])
           return false;

    return true;
}


/* Problem:
 *        Check if the string is rotated it will generate a Palindrome
 *        This is not a tree problem.
 * Example:  bbaa
 * Approach: Generate a pointer that splits the strings into two substrings. Concatenate the first substring
 *           to the end of the second and see if its a Palindrome. Repeat the process until you move the pointer
 *           till end of the string.
 * Complexity: O(n^2)
 * Space Complexity: O(n)
 * Any other better approach:
 *           Constant space solution can be produced by doing everything in place
 *           and by two utility functions getLeft() and getRight()
 */
int IKSolution::checkIfPalindromeRotate(string& str)
{

    if(isP(str))
        return true;

    int n = str.length();
    for (int i = 0; i < n-1; i++)
    {
        string str1 = str.substr(i+1, n-i-1);
        string str2 = str.substr(0, i+1);

        if (isP(str1.append(str2)))
            return true;
    }

    return false;

}

/**********************************************************************************************************************/
void printAllPathsRecurse(TreeNode *node, vi& p)
{
    if(node == NULL)
        return;

    p.push_back(node->val);

    if((node->left == nullptr) && (node->right == nullptr))
    {
        int size = p.size();
        for(int i = 0; i < size; i++)
            cout <<  p[i] << " ";
        cout << "\n";
        p.erase(p.end()-1);
        return;
    }

    printAllPathsRecurse(node->left,p);
    printAllPathsRecurse(node->right,p);
    p.erase(p.end()-1);

    return;
}

/* Problem: Given a binary tree, print all root-to-leaf paths one per line.
 * Example:
 * Approach: Pre order DFS.
 *           * Checkfor base case
 *           * Process root: Push the value to a stack. Check it meets the criterion(leaf node in this case).
 *           * Visit the left node.
 *           * Visit the right node.
  *          * Pop out pushed value.
 * Time Complexity: O(n)
 * Space Complexity: O(logN) Best case.
 * Any other better approach:
 * Corner case:
 * Take away:
 *       * Three parts: Base case, my job, and delegation.
 *       * If you are OK with printing from leaf to root, you might want to use stack.
 *
 *
 */
void IKSolution::printAllPathsInATee(TreeNode* root)
{
   vi p;
   printAllPathsRecurse(root, p);
   return;
}
/*********************************************************************************************************/

vvi printAllPathsInATeeToASumUtil(TreeNode *node, int k, vi& p, int currSum)
{
    vvi resl, resr;

    if(node == NULL)
        return resl;

    p.push_back(node->val);

    if((node->left == nullptr) && (node->right == nullptr) && (currSum + node->val == k))
    {
        int size = p.size();
        for(int i = 0; i < size; i++)
            cout <<  p[i] << " ";
        cout << "\n";
        resl.push_back(p);
        p.erase(p.end()-1);
        return resl;
    }

    resl = printAllPathsInATeeToASumUtil(node->left, k, p, currSum + node->val);
    resr = printAllPathsInATeeToASumUtil(node->right, k, p, currSum + node->val);

    resl.insert(resl.end(),resr.begin(),resr.end());
    p.erase(p.end()-1);

    return resl;
}

/* Problem:
 * Example:
 * Approach:
 * Time Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 *
 *
 */
vvi IKSolution::printAllPathsInATeeToASum(TreeNode* root, int k)
{
   vi p;
   int currSum = 0;
   vvi res = printAllPathsInATeeToASumUtil(root, k, p, currSum);
   return res;
}
/******************************************************************************************************************/

TreeNode* generateBBST(vector<int>& vals, int low, int high)
{
    if(low > high)
        return 0;

    int middle = (low + high)/2;

    TreeNode *root = createTreeNode(vals[middle]);

    root->left = generateBBST(vals,low,middle-1);
    root->right = generateBBST(vals,middle+1,high);

    return root;
}


int storeInOrder(TreeNode *node, vector<int>& vals)
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
TreeNode* IKSolution::mergeTwoBSTs(TreeNode* node1, TreeNode* node2)
{

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    TreeNode* node3;

    storeInOrder(node1, v1);
    storeInOrder(node2, v2);

    v3 = mergeVector(v1,v2);

    node3 = generateBBST(v3, 0, v3.size()-1);



    return node3;
}
/************************************************************************************************************************/

/* Problem:
 *     Iterative Post order traversal
 * Example:
 * Approach:
 *     Do a DFS. Populate into an auxiliary stack while doing a DFS.
 *     Two stack approach(DFS stack + auxiliary stack).
 *     Push into the auxiliary stack whatever you pop from main stack.
 *     while pushing into the DFS stack push left first and right next.
 * Complexity:
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */
void IKSolution::postorderTraversal(TreeNode* root)
{
    if(root == NULL)
        return;

    stack<TreeNode*> v1;
    vector<int>v2;

    v1.push(root);

    while(!v1.empty())
    {
        TreeNode *tn = v1.top();
        v1.pop();

        v2.push_back(tn->val);

        v1.push(tn->left);
        v1.push(tn->right);

    }

    for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
    {
        cout << " " << *it << " ";
    }


    return;
}
/**************************************************************************************************/

int countUniValSubtreesRec(TreeNode *node, int& counter)
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
/* Problem:
 *     Given a binary tree, we need to count the number of unival subtrees (all nodes have same value).
 * Example:
 * Approach:
 *     DFS search. If children's value is same as root and children are also unival trees then increment the counter.
 * Complexity: O(n)
 * Space Complexity: O(n)
 * Any other better approach:
 * Corner case:
 * Take away:
 */
int IKSolution::countUniValSubtrees(TreeNode *node)
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
 *     Contract with a node: Ill give you a LL with a head and a tail. You attach your head to the given tail and return a new tail.
 *     Head argument is set the very first time and remains constant.
 *
   *                  200
 *                   /  \
 *                  /    \
 *                 /      \
                  /        \
 *              100         300
 *              / \           /\
 *             /   \         /  \
 *            /     \       /    \
 *          25      150   250    350
 *
 *     Steps:
 *     1. Ask your left node(contract) to use the old tail and provide a new tail[magic].
 *     2. You attach your left to that tail.
 *     3. You attach tail's right to you.
 *     4. Make yourself the new tail.
 *     4. Ask your right node(contract) provide a new tail.
 *     5. Just return the tail returned by your right.
 *
 *     1. When it comes to 300
 *        Head -> 25 ->  100  -> 150  -> 200 <- tail
 *                   <-       <-      <-
 *     2. Now we provide this list to 300.
 *     3. When 300 calls the function onto its left it returns the following[magic function]
 *        Head -> 25 ->  100  -> 150  -> 200 <- 250 <- tail
 *                   <-       <-      <-     ->
 *     4. 300 does the following[3 things]
 *        Head -> 25 ->  100  -> 150  -> 200 <- 250 <- 300 < tail
 *             <-       <-      <-     ->           ->
       5. It calls the same function onto its right[magic again]
 *
 *
 * Complexity:O(n)
 * Space Complexity:O(n) or O(logn)
 * Any other better approach:
 * Corner case:
 * Take away:
 */

void treeToDoubleLLUtil(TreeNode* root, TreeNode*& tail, TreeNode* &head)
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

TreeNode* IKSolution::treeToDoubleLL(TreeNode* root)
{
    TreeNode* tail = NULL;
    TreeNode* head = NULL;

    treeToDoubleLLUtil(root, tail, head);

    if(head)
        head->left = tail;

    tail->right = head;
    return head;
}


/****************************************************************************************************************/
int lcaUtilRec(TreeNode* node, vector<TreeNode*>&v, int n)
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
 *     Ashok soln: Dont use the stack. Ask your left and right. The case where both say YES is the right answer.
 * Corner case:
 * Take away:
 */
TreeNode* IKSolution::findLCA(TreeNode* root, int n1, int n2)
{
    vector<TreeNode*> v1, v2;

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
bool isBSTUtil(TreeNode *node,int min, int max)
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
 *
 *           Recursion:
 *           Base case: Empty tree is BST.
 *                      If I satify the condition:
 *                      A node asks its left guy saying min you can go any value, But max is me - 1. If its true, you are good.
 *                      A node asks its right guy saying max you can go any value, But min is me + 1 1. If its true, you are good.
 * Complexity:O(n) . You got to visit all nodes.
 * Space Complexity: O(logn). Considering the stack.
 * Any other better approach: Do a inorder traversal and place the contents in a array. If the array is sorted then its a BST.
 * Any corner cases:
 * Take away:
 */
bool IKSolution::isBST(TreeNode* node)
{
    return isBSTUtil(node, INT_MIN, INT_MAX);
}
/**************************************************************************************************************************/

TreeNode* createBalancedBSTUtil(vector<int> &iArray, int low, int high)
{

    if(low > high)
        return NULL;

    int mid = (low + high)/2;
    TreeNode* temp = createTreeNode(iArray[mid]);

    temp->left = createBalancedBSTUtil(iArray, low, mid-1);
    temp->right = createBalancedBSTUtil(iArray, mid+1, high);

    return temp;

}

void IKSolution::createBalancedBST(vector < int > iArray)
{
    int size = iArray.size();
    createBalancedBSTUtil(iArray,0,size-1);


}
/*****************************************************************************************************************************/


/* Problem:
 *     printing-binary-tree-in-level-order
 * Example:
 *     3
      /  \
 *   9    20
         /  \
        15    7
 *
 *      3
        9 20
        15 7
 *
 * Approach:
 *     Breadth First Search (BFS). Use a pair with level and node information. Now print the tree at each level.
 *     Use a pair to store the level when you push a node to a queue When you deque , if the level is higher than previous
 *     introduce a \n
 *
 * Time Complexity:O(n)
 * Space Complexity:
 * Any other better approach:
 * Corner case:
 * Take away:
 */

vvi IKSolution::treeLevelOrderPrint(TreeNode *root)
{
    queue<pair<TreeNode*,int>> mQ;
    pair<TreeNode*,int> tn;
    int currLevel = 0;
    vi temp;
    vvi res;

    if(root == NULL)
    {
        return res;
    }

    mQ.push(make_pair(root,currLevel));

    while(!mQ.empty())
    {
        tn = mQ.front();
        mQ.pop();

        if(tn.second > currLevel)
        {
            currLevel += 1;
            DEBUG_DEBUG(cout << "\n");
            res.push_back(temp);
            temp.clear();
        }

        DEBUG_DEBUG(cout << " " << tn.first->val << " ");
        temp.push_back(tn.first->val);

        if(tn.first->left)
            mQ.push(make_pair(tn.first->left,(currLevel + 1)));
        if(tn.first->right)
            mQ.push(make_pair(tn.first->right,(currLevel + 1)));
    }
    if(!temp.empty())
    {
        res.push_back(temp);
    }

    return res;
}


vvi IKSolution::treeLevelOrderPrintUsingList(TreeNode *root)
{
    queue<list<TreeNode *>> mQ;

    list<TreeNode *> pushl;
    list<TreeNode *> popl;
    vi temp;
    vvi res;

    if(root == NULL)
    {
        return res;
    }

    pushl.push_back(root);
    mQ.push(pushl);
    pushl.clear();

    while(!mQ.empty())
    {
        popl = mQ.front();
        mQ.pop();

        for(auto val : popl)
        {
            DEBUG_DEBUG(cout << val->val << " ");
            if(val->left != nullptr) //IMPORTANT
                pushl.push_back(val->left);
            if(val->right != nullptr)
                pushl.push_back(val->right);
            temp.push_back(val->val); //results
        }

        if(!pushl.empty())
        {
            res.push_back(temp);
            temp.clear();
            mQ.push(pushl);
            pushl.clear();
            DEBUG_DEBUG(cout << " \n");

        }
    }
    if(!temp.empty())
    {
        res.push_back(temp);
    }


    return res;
}




/* Problem:
 *     Find Kth smallest value in a BST.
 * Approach:
 *     In-order traversal prints no in sorting order. When you are done processing k nos, return the val.
 *     We do a DFS in here.
 */
bool findKThSmallestUtil(TreeNode* root, unsigned int& k, unsigned int& counter, int& val)
{
    if(root == NULL)
        return false;


    if(findKThSmallestUtil(root->left, k, counter, val) == true)
        return true;


    counter++;
    if(counter == k)
    {
        DEBUG_DEBUG(cout << "counter = " << counter <<  " " << root->val << " k = " << k <<"\n");
        val = root->val;
        return true;
    }


    if(findKThSmallestUtil(root->right, k, counter, val) == true)
        return true;

    return false;

}


int IKSolution::findKThSmallest(TreeNode* root, unsigned int k)
{
    int val = 0;
    unsigned int counter = 0;

    if(findKThSmallestUtil(root, k, counter, val) == true)
    {
        return val;
    }
    else
        return 0;

}






