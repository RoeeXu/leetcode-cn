/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0061.cpp
* Author:   roee
* Date:     2019-11-20 01:21:13
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* q = head, * p = head;
        if(head == NULL) return NULL;
        int n = 0;
        while(q)
        {
            q = q->next;
            n++;
        }
        k %= n;
        q = head;
        while(k > 0)
        {
            q = q->next;
            k--;
        }
        while(q->next)
        {
            p = p->next;
            q = q->next;
        }
        q->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

