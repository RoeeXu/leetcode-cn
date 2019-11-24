/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0988.cpp
* Author:   root
* Date:     2019-11-25 06:01:24
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
    void dfs(vector<string>& res, string& tmp, TreeNode* root)
    {
        tmp.insert(tmp.begin(), root->val + 'a');
        if(root->left) dfs(res, tmp, root->left);
        if(root->right) dfs(res, tmp, root->right);
        if(!root->left && !root->right) res.push_back(tmp);
        tmp.erase(tmp.begin());
        return;
    }
    
    string smallestFromLeaf(TreeNode* root) {
        vector<string> res;
        string tmp = "";
        if(root == NULL) return "";
        dfs(res, tmp, root);
        sort(res.begin(), res.end());
        return res[0];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

