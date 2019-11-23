/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0083.cpp
* Author:   root
* Date:     2019-11-24 05:17:18
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while(p != NULL)
            if(p->next != NULL && p->next->val == p->val) p->next = p->next->next;
            else p = p->next;
        return head;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

