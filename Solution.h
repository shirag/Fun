#include<string>

#ifndef SOLUTIONS_H
#define SOLUTIONS_H

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
        string zigZagConvert(string s, int numRows);

};

#endif
