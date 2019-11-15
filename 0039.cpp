/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0039.cpp
* Author:   roeexu
* Date:     2019/11/15 15:36:12
* Brief:
****************************************************/

class Solution {
public:
    // dfs best
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, int pos, vector<int>& tmp)
    {
        if(target == 0) res.push_back(tmp);
        for(int i = pos; i < candidates.size(); i++){
            if(candidates[i] <= target)
            {
                tmp.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], res, i, tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(candidates, target, res, 0, tmp);
        return res;
    }

    // dfs worse
    // void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, int pos, vector<int>& tmp)
    // {
    //     if(target == 0) res.push_back(tmp);
    //     else if(pos == candidates.size()) return;
    //     else
    //     {
    //         if(candidates[pos] <= target)
    //         {
    //             tmp.push_back(candidates[pos]);
    //             dfs(candidates, target - candidates[pos], res, pos, tmp);
    //             tmp.pop_back();
    //         }
    //         dfs(candidates, target, res, pos + 1, tmp);
    //     }
    // }

    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<vector<int>> res;
    //     vector<int> tmp;
    //     dfs(candidates, target, res, 0, tmp);
    //     return res;
    // }

    // dp
    // vector<vector<int>> dp(vector<int>& candidates, int pos, int target)
    // {
    //     if(pos == 0) return {};
    //     if(pos == 1) 
    //         if(target % candidates[0] == 0) return {vector<int>(target / candidates[0], candidates[0])};
    //         else return {};
    //     vector<vector<int>> res;
    //     for(int i = 0; i <= (int)(target / candidates[pos - 1]); i++)
    //     {
    //         vector<vector<int>> r = dp(candidates, pos - 1, target - i * candidates[pos - 1]);
    //         for(int j = 0; j < r.size(); j++)
    //         {
    //             for(int k = 0; k < i; k++)
    //                 r[j].push_back(candidates[pos - 1]);
    //             res.push_back(r[j]);
    //         }
    //     }
    //     return res;
    // }

    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     int n = candidates.size();
    //     return dp(candidates, n, target);
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

