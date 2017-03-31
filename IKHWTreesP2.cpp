/*
 * IKHWTreesP2.cpp
 *
 *  Created on: Mar 29, 2017
 *      Author: raghav
 */


#define DEBUG_LEVEL DEBUG_LEVEL_DEBUG
#include "IKSolution.hpp"


/* Problem: Given a binary tree, clone it. Return the root node of the cloned tree.
 * Approach: Preorder DFS based copy.
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




Node* IKSolution::flipATree(Node *root)
{
    qln mq;
    ln pushln;
    ln popln;

    pushln.push_back(root);
    mq.push(pushln);
    pushln.clear();

    while(!mq.empty())
    {
        popln = mq.front();
        mq.pop();

        Node *beginn = popln.front();
        Node *endNode = popln.back();

        DEBUG_DEBUG(cout << "beginn->val " << beginn->val << " endNode->val " << endNode->val << " \n");
        swap(beginn->val,endNode->val);

        int i = 0;
        Node *prev;
        for(auto it : popln)
        {
            if(it == nullptr)
            {
                cout << "nullptr \n";
                assert(0);
            }

            if(it->left != nullptr)
                pushln.push_back(it->left);

            if(it->right != nullptr)
                pushln.push_back(it->right);

            if((i%2) && (i < (popln.size() - 1)))
            {
                prev = it;
            }
            else if(i != 0 && (i < (popln.size() - 1)))
            {
                cout << "about to swap \n";
                DEBUG_DEBUG(cout << "beginn->val " << it->val << " endNode->val " << prev->val << " \n");
                swap(it->val,prev->val); //Also wasted half hour trying to swap with it + 1

            }
            i++;
        }
        if(!pushln.empty()) //VERY IMPORTANT CHECK: wasted half an hour here..
        {
            mq.push(pushln);
            pushln.clear();
        }
    }

    cout << "Done precessing  \n";
    return root;

}


