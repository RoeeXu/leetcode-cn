/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0894.cpp
* Author:   root
* Date:     2019-12-18 04:05:53
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0) return {};
        vector<vector<TreeNode*>> dp(N + 1);
        dp[1] = {new TreeNode(0)};
        for(int i = 3; i <= N; i += 2)
            for(int j = 1; j < i; j += 2)
                for(auto p : dp[j]) 
                    for(auto q : dp[i - 1 - j])
                    {
                        TreeNode *root = new TreeNode(0);
                        root->left = p;
                        root->right = q;
                        dp[i].push_back(root);
                    }
        return dp[N];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

