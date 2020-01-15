/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0889.cpp
* Author:   roeexu
* Date:     2020-01-15 15:25:38
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
    TreeNode* helper(vector<int>& pre, int a, int b, vector<int>& post, int c, int d) {
        if(a > b) return NULL;
        TreeNode* node = new TreeNode(pre[a]);
        if(a == b) return node;
        int next = pre[a + 1];
        int p = c;
        while(post[p] != next) p++;
        node->left = helper(pre, a + 1, p - c + a + 1, post, c, p);
        node->right = helper(pre, p - c + a + 2, b, post, p + 1, d - 1);
        return node;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

