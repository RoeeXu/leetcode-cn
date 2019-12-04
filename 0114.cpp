/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0114.cpp
* Author:   root
* Date:     2019-12-05 00:26:32
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
    TreeNode* helper(TreeNode* root)
    {
        if(root->left && root->right)
        {
            TreeNode* left_tail = helper(root->left);
            TreeNode* right_tail = helper(root->right);
            right_tail->right = NULL;
            left_tail->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return right_tail;
        }
        else if(root->left)
        {
            TreeNode* left_tail = helper(root->left);
            left_tail->right = NULL;
            root->right = root->left;
            root->left = NULL;
            return left_tail;
        }
        else if(root->right)
        {
            TreeNode* right_tail = helper(root->right);
            right_tail->right = NULL;
            return right_tail;
        }
        return root;
    }

    void flatten(TreeNode* root) {
        if(root) helper(root);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

