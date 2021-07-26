/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0143.cpp
* Author:   root
* Date:     2021-07-27 02:36:56
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* a, ListNode* b)
    {
        ListNode* c;
        while (b)
        {
            c = b->next;
            b->next = a->next;
            a->next = b;
            a = b->next;
            b = c;
        }
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void reorderList(ListNode* head) {
        ListNode* p = middleNode(head);
        ListNode* tail = reverseList(p->next);
        p->next = NULL;
        mergeList(head, tail);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

