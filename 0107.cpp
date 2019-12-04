/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0107.cpp
* Author:   roeexu
* Date:     2019-12-04 12:48:50
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> r;
        int p;
        queue<TreeNode*> q;
        TreeNode* tmp;
        q.push(root);
        while(!q.empty())
        {
            p = q.size();
            r.clear();
            while(p-- > 0)
            {
                tmp = q.front();
                q.pop();
                r.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(r);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

