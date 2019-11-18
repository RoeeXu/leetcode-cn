/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0021.cpp
* Author:   roee
* Date:     2019-11-18 23:25:01
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 == NULL || (l1 != NULL && l2 != NULL && l1->val > l2->val))
            {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
            else if(l2 == NULL || (l1 != NULL && l2 != NULL && l1->val <= l2->val))
            {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
        }
        return head->next;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

