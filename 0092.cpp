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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp = new ListNode();
        tmp->next = head;
        ListNode *p, *fp = tmp, *q;
        int k = right - left;
        while (left-- > 1) fp = fp->next;
        p = fp->next;
        while (k--)
        {
            q = p->next;
            p->next = q->next;
            q->next = fp->next;
            fp->next = q;
        }
        return tmp->next;
    }
};

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

