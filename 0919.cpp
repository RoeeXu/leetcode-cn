/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0919.cpp
* Author:   root
* Date:     2019-11-25 19:04:51
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
class CBTInserter {
public:
    queue<TreeNode*> que;
    TreeNode* original;
    
    CBTInserter(TreeNode* root) {
        original = root;
        que.push(root);
        while(que.front()->left && que.front()->right)
        {
            que.push(que.front()->left);
            que.push(que.front()->right);
            que.pop();
        }
        if(que.front()->left) que.push(que.front()->left);
    }
    
    int insert(int v) {
        TreeNode* x = new TreeNode(v);
        int res = que.front()->val;
        if(que.front()->left == que.back())
        {
            que.front()->right = x;
            que.pop();
        }
        else que.front()->left = x;
        que.push(x);
        return res;
    }
    
    TreeNode* get_root() {
        return original;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

