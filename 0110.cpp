/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0110.cpp
* Author:   roeexu
* Date:     2019-12-04 13:29:34
* Brief:
****************************************************/

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
    int helper(TreeNode* root) {
        if(!root) return 0;
        int left = helper(root->left), right = helper(root->right);
        if(abs(left - right) < 2 && left != -1 && right != -1) return max(left, right) + 1;
        return -1;
    }

    bool isBalanced(TreeNode* root) {
        if(helper(root) >= 0) return 1;
        return 0;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

