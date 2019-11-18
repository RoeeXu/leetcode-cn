/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0047.cpp
* Author:   roee
* Date:     2019-11-19 00:18:31
* Brief:
****************************************************/

class Solution {
public:
    void backtracking(unordered_map<int, int>& cnt, int k, int n, vector<int>& tmp, vector<vector<int>>& res) {
        if (k == n) {
            res.push_back(tmp);
            return;
        }
        for (auto& p : cnt) {
            if (p.second == 0) continue;
            --p.second;
            tmp.push_back(p.first);
            backtracking(cnt, k + 1, n, tmp, res);
            ++p.second;
            tmp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto x : nums) ++cnt[x];
        vector<vector<int>> res;
        vector<int> tmp;
        backtracking(cnt, 0, nums.size(), tmp, res);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

