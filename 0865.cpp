/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0865.cpp
* Author:   roeexu
* Date:     2020-01-07 15:43:07
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
    pair<int, TreeNode*> helper(TreeNode* node){
        if(!node) return {0, NULL};
        auto left = helper(node->left);
        auto right = helper(node->right);
        int d1 = left.first, d2 = right.first;
        return {max(d1, d2) + 1, d1 == d2 ? node : (d1 > d2 ? left.second : right.second)};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return helper(root).second;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

