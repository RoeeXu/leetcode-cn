/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0979.cpp
* Author:   roeexu
* Date:     2019-12-24 11:38:34
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
    int res = 0;
    
    int track_back(TreeNode* node) {
        if(!node) return 0;
        if(node->left) node->val += track_back(node->left);
        if(node->right) node->val += track_back(node->right);
        node->val -= 1;
        res += abs(node->val);
        return node->val;
    }
    
    int distributeCoins(TreeNode* root) {
        track_back(root);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

