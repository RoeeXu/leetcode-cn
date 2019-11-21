/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0070.cpp
* Author:   roeexu
* Date:     2019-11-21 18:44:26
* Brief:
****************************************************/

class Solution {
public:
    int climbStairs(int n) {
        int *dp = new int[n + 1]();
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

