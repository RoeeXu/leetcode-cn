/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1290.cpp
* Author:   roeexu
* Date:     2019-12-23 10:52:22
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
    int getDecimalValue(ListNode* head) {
        int x = 0;
        while(head != NULL)
        {
            x *= 2;
            x += head->val;
            head = head->next;
        }
        return x;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

