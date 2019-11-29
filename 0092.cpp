/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0092.cpp
* Author:   root
* Date:     2019-11-30 03:30:45
* Brief:
****************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* p, * q, * tmp;
        tmp = new ListNode(0);
        tmp->next = head;
        p = q = head = tmp;
        int t = m;
        while(t-- > 1) p = p->next;
        q = p->next;
        tmp = p->next;
        t = n - m;
        while(t-- > 0)
        {
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = tmp;
            tmp = p->next;
        }
        return head->next;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

