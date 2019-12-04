/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0115.cpp
* Author:   root
* Date:     2019-12-05 01:09:59
* Brief:
****************************************************/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        long dp[n + 1] = {0};
        long pre, tmp;
        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++)
            {
                tmp = dp[j];
                if(j == 0) dp[j] = 1;
                else if(i == 0) dp[j] = 0;
                else if(s[i - 1] == t[j - 1]) dp[j] += pre;
                pre = tmp;
            }
        return dp[n];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

