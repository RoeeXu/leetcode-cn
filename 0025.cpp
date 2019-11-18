/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0025.cpp
* Author:   roee
* Date:     2019-11-18 23:26:12
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1)
            return head;
        int cnt = 0;
        ListNode* p = head;
        ListNode* q;
        ListNode* r;
        while(cnt < k && p)
        {
            p = p->next;
            cnt++;
        }
        if(cnt == k)
        {
            cnt = 1;
            p = head;
            q = p->next;
            while(cnt < k)
            {
                p->next = q->next;
                q->next = head;
                head = q;
                q = p->next;
                cnt++;
            }
            r = reverseKGroup(q, k);
            p->next = r;
        }
        return head;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

