/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0998.cpp
* Author:   roeexu
* Date:     2020-06-09 18:18:44
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(root->val < val)
        {
            TreeNode* head = new TreeNode(val);
            head->left = root;
            return head;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

