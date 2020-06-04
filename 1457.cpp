/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1457.cpp
* Author:   roeexu
* Date:     2020-06-04 11:25:20
* Brief:
****************************************************/
 
class Solution {
public:
    int path[10] = {0};
    int res = 0;
    
    void helper(TreeNode* node) {
        int x = node->val;
        path[x]++;
        if(node->left == NULL && node->right == NULL) {
            int r = 0;
            for(auto n : path) if(n % 2 == 1) r++;
            if(r <= 1) res++;
            path[x]--;
            return;
        }
        if(node->left) helper(node->left);
        if(node->right) helper(node->right);
        path[x]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

