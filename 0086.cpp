/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0086.cpp
* Author:   roeexu
* Date:     2019-11-25 16:08:19
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left, *right, *p, *q;
        left = right = p = q = NULL;
        while(head != NULL) {
            if(head->val >= x)
                if(right == NULL) right = q = head;
                else q = q->next = head;
            else
                if(left == NULL) left = p = head;
                else p = p->next = head;
            head = head->next;
        }
        if(q != NULL) q->next = NULL;
        if(p != NULL) p->next = right;
        else left = right;
        return left;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

