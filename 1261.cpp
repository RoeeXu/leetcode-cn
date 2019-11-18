/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1261.cpp
* Author:   roeexu
* Date:     2019-11-18 22:26:20
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
class FindElements {
private:
    unordered_set<int> saver;

    void recover(TreeNode* root, int x) {
        root->val = x;
        saver.insert(x);
        if (root->left) recover(root->left, 2 * x + 1);
        if (root->right) recover(root->right, 2 * x + 2);
    }

public:
    FindElements(TreeNode* root) {
        if(root) recover(root, 0);
    }

    bool find(int target) {
        return saver.count(target) > 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

