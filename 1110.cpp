/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1110.cpp
* Author:   roeexu
* Date:     2019-12-24 20:09:56
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        if(dfs(root, del, res)) res.push_back(root);
        return res;
    }

    TreeNode* dfs(TreeNode* root, unordered_set<int>& del, vector<TreeNode*>& res) {
        if(root == NULL) return NULL;
        root->left = dfs(root->left, del, res);
        root->right = dfs(root->right, del, res);
        if(del.count(root->val) > 0) {
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            return NULL;
        }
        return root;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

