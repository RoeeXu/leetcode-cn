/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0148.cpp
* Author:   root
* Date:     2021-07-28 02:03:42
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
    ListNode* merge_sort(ListNode* l1, ListNode* l2) {
        l1 = sortList(l1);
        l2 = sortList(l2);
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = new ListNode();
        ListNode* p = head;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
                p->next = NULL;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
                p->next = NULL;
            }
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode *p = head, *q = head;
        while (q->next && q->next->next)
        {
            p = p->next;
            q = q->next->next;
        }
        ListNode *l1 = head;
        ListNode *l2 = p->next;
        p->next = NULL;
        return merge_sort(l1, l2);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

