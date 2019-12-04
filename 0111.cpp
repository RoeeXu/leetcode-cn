/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0111.cpp
* Author:   roeexu
* Date:     2019-12-04 13:34:44
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left = minDepth(root->left), right = minDepth(root->right);
        if(left == right && left == 0) return 1;
        if(left == 0) return right + 1;
        if(right == 0) return left + 1;
        return min(left, right) + 1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

