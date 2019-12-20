/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1145.cpp
* Author:   roeexu
* Date:     2019-12-20 11:07:26
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
    int N;
    bool over;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(!root) return false;
        over = false;
        N = n;
        dfs(root, x);
        return over;
    }

    int dfs(TreeNode* root, int x) {
        if(!root) return 0;
        if(over) return 0;
        int l = dfs(root->left, x), r = dfs(root->right, x);
        if(root->val == x && max(max(l, r), N - l - r - 1) > N / 2) over = true;
        return l + r + 1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

