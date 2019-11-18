/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0019.cpp
* Author:   roee
* Date:     2019-11-18 23:24:26
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f1 = head;
        ListNode* f2 = NULL;
        int x = 0;
        n += 1;
        while(f1 != NULL)
        {
            f1 = f1->next;
            x++;
            if(x == n) f2 = head;
            else if(x > n) f2 = f2->next;
        }
        if(f2 == NULL && x == n - 1)
            return head->next;
        else if(f2 == NULL or f2->next == NULL)
            return head;
        else
        {
            f2->next = f2->next->next;
            return head;
        }
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

