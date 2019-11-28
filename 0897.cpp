/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0897.cpp
* Author:   roeexu
* Date:     2019-11-28 20:29:12
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

 static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        TreeNode *l, *r;
        l = increasingBST(root->left);
        r = l;
        while(r && r->right) r = r->right;
        if(!r) r = root;
        else r = r->right = root;
        r->left = NULL;
        r->right = increasingBST(root->right);
        return l ? l : root;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

