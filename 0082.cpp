/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0082.cpp
* Author:   root
* Date:     2019-11-24 05:11:12
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
        ListNode* new_head = new ListNode(0);
        ListNode* q = new_head;
        int tmp;
        while(p != NULL)
        {
            if((p->next != NULL && p->next->val != p->val) || p->next == NULL)
            {
                q = q->next = p;
                p = p->next;
            }
            else
            {
                tmp = p->val;
                while(p != NULL && p->val == tmp) p = p->next;
            }
        }
        q->next = NULL;
        return new_head->next;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

