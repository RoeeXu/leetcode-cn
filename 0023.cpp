/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0023.cpp
* Author:   roee
* Date:     2019-11-18 23:25:33
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
    //分治
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n <= 1) return n == 1 ? lists[0] : NULL;
        return mergeRecursive(lists, 0, n - 1);
    }
    
    ListNode* mergeRecursive(vector<ListNode*>& lists, int l, int r){
        if(l == r) return lists[l];
        int mid = (l + r) / 2;
        ListNode* left = mergeRecursive(lists, l , mid);
        ListNode* right = mergeRecursive(lists, mid + 1, r);
        return merge2(left, right);
    }
    
    ListNode* merge2(ListNode* a, ListNode* b){
        if(a == NULL || b == NULL) return a == NULL ? b : a;
        ListNode* ret;
        ListNode* head;
        if(a->val < b->val)
        {
            head = a;
            a = a->next;
        }
        else
        {
            head = b;
            b = b->next;
        }
        ret = head;
        while(a != NULL && b != NULL)
        {
            if(a->val < b->val)
            {
                ret->next = a;
                ret = ret->next;
                a = a->next;
            }
            else
            {
                ret->next = b;
                ret = ret->next;
                b = b->next;
            }
        }
        if(a != NULL) ret->next = a;
        else if(b != NULL) ret->next = b;
        return head;
    }
    //优先队列
//     struct cmp{
//         bool operator ()(ListNode* p, ListNode* q){
//             return p->val > q->val;
//         }
//     };
    
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int n = lists.size();
//         if(n == 0) return NULL;
//         if(n == 1) return lists[0];
//         priority_queue< ListNode*, vector<ListNode*>, cmp > p_q;
//         for(int i=0;i<lists.size();i++)
//             if(lists[i] != NULL)
//                 p_q.push(lists[i]);
//         ListNode* head = new ListNode(0);
//         ListNode* p = head;
//         while(p_q.size() > 0)
//         {
//             ListNode* now_p = p_q.top();
//             p_q.pop();
//             p->next = now_p;
//             p = p->next;
//             now_p = now_p->next;
//             if(now_p != NULL)
//                 p_q.push(now_p);
//         }
//         return head->next;
//     }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

