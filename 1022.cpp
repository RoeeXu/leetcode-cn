/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1022.cpp
* Author:   roeexu
* Date:     2020-06-09 14:19:48
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
    int res = 0;
    
    void dfs(TreeNode* p, int x)
    {
        if(!p->left && !p->right)
        {
            res += 2 * x + p->val;
            res %= 1000000007;
        }
        else
        {
            if(p->left) dfs(p->left, 2 * x + p->val);
            if(p->right) dfs(p->right, 2 * x + p->val);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

