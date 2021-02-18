/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1721.cpp
* Author:   roeexu
* Date:     2021-01-20 21:58:59
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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* a = head;
        ListNode* b = head;
        ListNode* c = NULL;
        while(a)
        {
            n++;
            if(n == k) break;
            a = a->next;
        }
        c = a;
        while(c->next)
        {
            c = c->next;
            b = b->next;
        }
        swap(a->val, b->val);
        return head;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

