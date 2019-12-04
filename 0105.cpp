/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0105.cpp
* Author:   roeexu
* Date:     2019-12-04 12:40:28
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
    TreeNode* helper(unordered_map<int, int>& pos, vector<int>& preorder, int a, int b, vector<int>& inorder, int x, int y)
    {
        if(a == b) return NULL;
        TreeNode *root = new TreeNode(preorder[a]);
        if(a + 1 == b) return root;
        int p = pos[preorder[a]];
        root->left = helper(pos, preorder, a + 1, a + 1 + p - x, inorder, x, p);
        root->right = helper(pos, preorder, a + 1 + p - x, b, inorder, p + 1, y);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> pos;
        for(int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
        return helper(pos, preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

