/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0090.cpp
* Author:   root
* Date:     2019-11-30 02:36:27
* Brief:
****************************************************/

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<pair<int, int>>& save, int n, int pos, vector<int>& tmp)
    {
        if(pos == n)
        {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i <= save[pos].second; i++)
        {
            dfs(res, save, n, pos + 1, tmp);
            tmp.push_back(save[pos].first);
        }
        for(int i = 0; i <= save[pos].second; i++)
            tmp.pop_back();
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto& x : nums)
        {
            if(cnt.count(x) > 0) cnt[x]++;
            else cnt[x] = 1;
        }
        vector<pair<int, int>> save(cnt.begin(), cnt.end());
        vector<vector<int>> res;
        vector<int> tmp;
        int n = save.size();
        dfs(res, save, n, 0, tmp);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

