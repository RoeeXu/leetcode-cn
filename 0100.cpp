/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0100.cpp
* Author:   root
* Date:     2019-12-04 01:51:28
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if(p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) return 1;
        return 0;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

