/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0103.cpp
* Author:   root
* Date:     2019-12-04 02:14:39
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
    // insert vector
    // vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     if(!root) return res;
    //     vector<int> r;
    //     int p, flag = 1;
    //     queue<TreeNode*> q;
    //     TreeNode* tmp;
    //     q.push(root);
    //     while(!q.empty())
    //     {
    //         p = q.size();
    //         r.clear();
    //         while(p-- > 0)
    //         {
    //             tmp = q.front();
    //             q.pop();
    //             if(flag) r.push_back(tmp->val);
    //             else r.insert(r.begin(), tmp->val);
    //             if(tmp->left) q.push(tmp->left);
    //             if(tmp->right) q.push(tmp->right);
    //         }
    //         flag = !flag;
    //         res.push_back(r);
    //     }
    //     return res;
    // }

    // reverse vector
    // vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     if(!root) return res;
    //     vector<int> r;
    //     int p, flag = 0;
    //     queue<TreeNode*> q;
    //     TreeNode* tmp;
    //     q.push(root);
    //     while(!q.empty())
    //     {
    //         p = q.size();
    //         r.clear();
    //         while(p-- > 0)
    //         {
    //             tmp = q.front();
    //             q.pop();
    //             r.push_back(tmp->val);
    //             if(tmp->left) q.push(tmp->left);
    //             if(tmp->right) q.push(tmp->right);
    //         }
    //         if(flag) reverse(r.begin(), r.end());
    //         flag = 1 - flag;
    //         res.push_back(r);
    //     }
    //     return res;
    // }

    // two stack
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        stack<TreeNode*> left, right;
        left.push(root);
        while (!left.empty() || !right.empty()) {
            if (!left.empty()) {
                result.push_back(vector<int>());
                while (!left.empty()) {
                    TreeNode* curr = left.top();
                    left.pop();
                    result.back().push_back(curr->val);
                    if (curr->left) right.push(curr->left);
                    if (curr->right) right.push(curr->right);
                }
            }
            if (!right.empty()) {
                result.push_back(vector<int>());
                while (!right.empty()) {
                    TreeNode* curr = right.top();
                    right.pop();
                    result.back().push_back(curr->val);
                    if (curr->right) left.push(curr->right);
                    if (curr->left) left.push(curr->left);
                }
            }
        }
        return result;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

