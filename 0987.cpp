/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0987.cpp
* Author:   root
* Date:     2019-11-25 05:58:01
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
    void addnode(map<int, map<int, vector<int>>>& pos, TreeNode* root, int x, int y)
    {
        if(root == NULL) return;
        if(pos.count(x) > 0)
        {
            if(pos[x].count(y) > 0) pos[x][y].push_back(root->val);
            else pos[x][y] = vector<int>({root->val});
        }
        else
        {
            map<int, vector<int>> tmp;
            tmp[y] = vector<int>({root->val});
            pos[x] = tmp;
        }
        if(root->left) addnode(pos, root->left, x - 1, y + 1);
        if(root->right) addnode(pos, root->right, x + 1, y + 1);
        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> pos;
        addnode(pos, root, 0, 0);
        vector<vector<int>> res;
        for(auto& x : pos)
        {
            vector<int> r;
            for(auto& y : x.second)
            {
                sort(y.second.begin(), y.second.end());
                for(auto z : y.second)
                    r.push_back(z);
            } 
            res.push_back(r);
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

