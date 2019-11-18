/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0002.cpp
* Author:   roee
* Date:     2019-11-18 23:14:40
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp = 0;
        int counter1 = 0;
        int counter2 = 0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t1!=NULL)
        {
            counter1++;
            t1 = t1->next;
        }
        while(t2!=NULL)
        {
            counter2++;
            t2 = t2->next;
        }        
        if(counter1 < counter2)
        {
            ListNode* t = l1;
            l1 = l2;
            l2 = t;
        }
        ListNode* head = l1;
        ListNode* t = NULL;
        while(l1!=NULL && l2!=NULL)
        {
            
            temp = temp + l1->val + l2->val;
            if(temp>9)
            {
                l1->val = temp-10;
                temp = 1;
            }
            else
            {
                l1->val = temp;
                temp = 0;
            }
            t = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL)
        {
            
            temp = temp + l1->val;
            if(temp>9)
            {
                l1->val = temp-10;
                temp = 1;
            }
            else
            {
                l1->val = temp;
                temp = 0;
            }
            t = l1;
            l1 = l1->next;
        }
        if(temp>0)
        {
            t->next = new ListNode(1);
        }
        return head;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

