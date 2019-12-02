/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0098.cpp
* Author:   root
* Date:     2019-12-03 02:56:46
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
    // best
    bool isValidBST(TreeNode *root) {
        return helper(root, nullptr, nullptr);
    }

    bool helper(TreeNode *node, TreeNode *lower, TreeNode *upper) {
        if (!node) return true;
        if (lower && lower->val >= node->val) return false;
        if (upper && upper->val <= node->val) return false;
        return helper(node->left, lower, node) && helper(node->right, node, upper);
    }

    // mine
    // vector<int> is_valid_vec(TreeNode* root)
    // {
    //     vector<int> left, right;
    //     if(root->left) left = is_valid_vec(root->left);
    //     if(root->right) right = is_valid_vec(root->right);
    //     if(root->left && root->right && left.size() == 2 && right.size() == 2 && root->val > left[1] && root->val < right[0])
    //         return {left[0], right[1]};
    //     else if(root->left && !root->right && left.size() == 2 && root->val > left[1])
    //         return {left[0], root->val};
    //     else if(!root->left && root->right && right.size() == 2 && root->val < right[0])
    //         return {root->val, right[1]};
    //     else if(!root->left && !root->right)
    //         return {root->val, root->val};
    //     return {};
    // }

    // bool isValidBST(TreeNode* root) {
    //     if(!root) return 1;
    //     vector<int> value = is_valid_vec(root);
    //     if(value.size() == 2) return 1;
    //     return 0;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

