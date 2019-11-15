/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0040.cpp
* Author:   roeexu
* Date:     2019/11/15 16:45:38
* Brief:
****************************************************/

class Solution {
public:
    // dfs
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, int pos, vector<int>& tmp)
    {
        if(target == 0) res.push_back(tmp);
        for(int i = pos; i < candidates.size() && candidates[i] <= target;)
        {
            tmp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], res, i + 1, tmp);
            tmp.pop_back();
            i++;
            while (i < candidates.size() && candidates[i] == candidates[i - 1]) i++;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, res, 0, tmp);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

