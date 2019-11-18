/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0044.cpp
* Author:   roeexu
* Date:     2019/11/18 13:20:33
* Brief:
****************************************************/

class Solution {
public:
    // back
    bool isMatch(string s, string p)
    {
        int j = 0;
	    for(int h = 0, i = 0, t = 0; i < s.length();)
        {
		    if(j < p.size() && (s[i] == p[j] || p[j] == '?')) { ++i; ++j; }
		    else if(j < p.size() && p[j] == '*') { t = i; h = ++j; }
		    else if(h != 0) { i = ++t; j = h; }
		    else return 0;
		}
		while(j < p.size() && p[j] == '*') ++j;
		return j == p.size();
    }

    // dp
    // bool isMatch(string s, string p) {
    //     int m = s.length(), n = p.length();
    //     bool *dp = new bool[(m + 1) * (n + 1)]();
    //     dp[0] = 1;
    //     for(int j = 1; j <= n; j++)
    //         if(p[j - 1] == '*')
    //             dp[j] = dp[j - 1];
    //     for(int i = 1; i <= m; i++)
    //         for(int j = 1; j <= n; j++)
    //             if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
    //                 dp[i * (n + 1) + j] = dp[(i - 1) * (n + 1) + j - 1];
    //             else if(p[j - 1] == '*')
    //                 dp[i * (n + 1) + j] = dp[(i - 1) * (n + 1) + j] || dp[i * (n + 1) + j - 1];
    //     return dp[(m + 1) * (n + 1) - 1];
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

