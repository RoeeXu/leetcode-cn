/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0109.cpp
* Author:   roeexu
* Date:     2019-12-04 13:05:21
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int l, int r)
    {
        if(l == r) return NULL;
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        if(l + 1 == r) return root;
        root->left = helper(nums, l, m);
        root->right = helper(nums, m + 1, r);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return helper(nums, 0, nums.size());
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

