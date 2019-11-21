/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0077.cpp
* Author:   root
* Date:     2019-11-22 05:12:45
* Brief:
****************************************************/

class Solution {
public:
    // void backtracking(vector<vector<int>>& res, int& n, int& k, int pos, int l, vector<int>& tmp)
    // {
    //     if(l == k)
    //     {
    //         res.push_back(tmp);
    //         return;
    //     }
    //     if(n == pos) return;
    //     for(int i = pos; i < n; i++)
    //     {
    //         tmp.push_back(i + 1);
    //         backtracking(res, n, k, i + 1, l + 1, tmp);
    //         tmp.pop_back();
    //     }
    //     return;
    // }

    // vector<vector<int>> combine(int n, int k) {
    //     vector<vector<int>> res;
    //     vector<int> tmp;
    //     backtracking(res, n, k, 0, 0, tmp);
    //     return res;
    // }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        vector<int> nums(k + 1, 0);
        for(int i = 0; i < k; i++) nums[i] = i + 1;
        nums[k] = n + 1;
        int j = 0;
        while(j < k)
        {
            output.push_back(vector<int>(nums.begin(), nums.begin() + k));
            j = 0;
            while(j < k && nums[j + 1] == nums[j] + 1) nums[j++] = j + 1;
            nums[j]++;
        }
        return output;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

