/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0131.cpp
* Author:   root
* Date:     2021-07-27 21:01:06
* Brief:
****************************************************/
 
class Solution {
public:
    void extend(string& s, map<int, vector<int>>& dp, int left, int right, int n)
    {
        while (s[left] == s[right])
        {
            dp[left].push_back(right - left + 1);
            left--;
            right++;
            if (right >= n || left < 0) break;
        }
    }
    
    void dfs(vector<vector<string>>& res, string& s, map<int, vector<int>>& dp, int p, int n, vector<string>& r)
    {
        if (p == n)
        {
            res.emplace_back(r);
            return;
        }
        for (auto x : dp[p])
        {
            r.push_back(s.substr(p, x));
            dfs(res, s, dp, p + x, n, r);
            r.pop_back();
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        map<int, vector<int>> dp;
        for (int i = 0; i < n - 1; i++)
        {
            extend(s, dp, i, i, n);
            extend(s, dp, i, i + 1, n);
        }
        extend(s, dp, n - 1, n - 1, n);
        vector<vector<string>> res;
        vector<string> r;
        dfs(res, s, dp, 0, n, r);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

