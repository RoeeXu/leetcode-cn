/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0091.cpp
* Author:   root
* Date:     2019-11-30 03:16:38
* Brief:
****************************************************/

class Solution {
public:
    int kick(vector<int>& dp, string& s, int n, int p)
    {
        if(dp[p] != -1) return dp[p];
        if(n == p) return 1;
        if(s[p] == '0') return 0;
        if(n == 1 + p) return 1;
        bool f = (p + 1 < n && s[p] == '2' && s[p + 1] <= '6') || (p + 1 < n && s[p] == '1');
        dp[p] = kick(dp, s, n, p + 1) + (f ? kick(dp, s, n, p + 2) : 0);
        return dp[p];
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        int res = kick(dp, s, n, 0);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

