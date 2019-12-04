/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0113.cpp
* Author:   roeexu
* Date:     2019-12-04 13:43:01
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
    void helper(vector<vector<int>>& res, TreeNode* root, int sum, vector<int>& tmp)
    {
        if(!root) return;
        if(root->val == sum && !root->left && !root->right){
            tmp.push_back(sum);
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(root->val);
        sum -= root->val;
        helper(res, root->left, sum, tmp);
        helper(res, root->right, sum, tmp);
        tmp.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, root, sum, tmp);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

