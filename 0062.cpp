/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0062.cpp
* Author:   roee
* Date:     2019-11-20 01:38:46
* Brief:
****************************************************/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m > n) return uniquePaths(n, m);
        long *dp = new long[n + 1]();
        for(int i = 0; i < m; i++)
        {
            dp[0] = 1;
            for(int j = 1; j <= n; j++) dp[j] += dp[j - 1];
        }
        return dp[n - 1];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

