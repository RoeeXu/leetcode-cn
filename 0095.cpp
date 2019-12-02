/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0095.cpp
* Author:   roeexu
* Date:     2019-12-02 10:42:26
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
    vector<TreeNode*> gentreefromvec(vector<int>& g, int l, int r)
    {
        if(l >= r) return vector<TreeNode*>({NULL});
        if(l + 1 == r)
        {
            TreeNode* head = new TreeNode(g[l]);
            return vector<TreeNode*>({head});
        }
        vector<TreeNode*> res;
        for(int i = l; i < r; i++)
        {
            vector<TreeNode*> new_t_left = gentreefromvec(g, l, i);
            vector<TreeNode*> new_t_right = gentreefromvec(g, i + 1, r);
            for(auto& x : new_t_left)
                for(auto& y : new_t_right)
                {
                    TreeNode* new_t = new TreeNode(g[i]);
                    new_t->left = x;
                    new_t->right = y;
                    res.push_back(new_t);
                }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>({});
        vector<int> nums;
        for(int i = 0; i < n; i++) nums.push_back(i + 1);
        return gentreefromvec(nums, 0, nums.size());
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

