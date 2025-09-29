#include <bits/stdc++.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode();
        auto res{result};
        int rest{0};
        while (l1 or l2)
        {
            int l1Val{l1 ? l1->val : 0};
            int l2Val{l2 ? l2->val : 0};
            res->val += l1Val + l2Val;
            rest = res->val / 10;
            res->val %= 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            if (l1 or l2 or rest != 0)
            {
                res->next = new ListNode(rest);
                res = res->next;
            }
        }
        return result;
    }
};