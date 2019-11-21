/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0078.cpp
* Author:   root
* Date:     2019-11-22 05:23:05
* Brief:
****************************************************/

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& tmp, int& n, int pos)
    {
        if(n == pos)
        {
            res.push_back(tmp);
            return;
        }
        dfs(res, nums, tmp, n, pos + 1);
        tmp.push_back(nums[pos]);
        dfs(res, nums, tmp, n, pos + 1);
        tmp.pop_back();
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int n = nums.size();
        dfs(res, nums, tmp, n, 0);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

