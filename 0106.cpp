/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0106.cpp
* Author:   roeexu
* Date:     2019-12-04 12:44:25
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
    TreeNode* helper(unordered_map<int, int>& pos, vector<int>& postorder, int a, int b, vector<int>& inorder, int x, int y)
    {
        if(a == b) return NULL;
        TreeNode *root = new TreeNode(postorder[b - 1]);
        if(a + 1 == b) return root;
        int p = pos[postorder[b - 1]];
        root->left = helper(pos, postorder, a, a + p - x, inorder, x, p);
        root->right = helper(pos, postorder, a + p - x, b - 1, inorder, p + 1, y);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> pos;
        for(int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;
        return helper(pos, postorder, 0, postorder.size(), inorder, 0, inorder.size());
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

