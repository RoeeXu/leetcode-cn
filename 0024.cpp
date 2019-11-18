/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0024.cpp
* Author:   roee
* Date:     2019-11-18 23:25:50
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* fake = new ListNode(0);
        fake->next = head;
        ListNode* p = fake;
        ListNode* q;
        while(p->next && p->next->next)
        {
            q = p->next;
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = q;
            p = q;
        }
        return fake->next;
    }
    // ListNode* swapPairs(ListNode* head) {
    //     ListNode* root=new ListNode(-1);
    //     ListNode *pre=root,*p=head,*q;
    //     root->next=head;
    //     if(!head||!head->next)return head;
    //     q=p->next;
    //     while(q!=nullptr){
    //         pre->next=q;
    //         p->next=q->next;
    //         q->next=p;
    //         pre=p;
    //         if(!p->next)break;
    //         p=p->next;
    //         q=p->next;
    //     }
    //     return root->next;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

