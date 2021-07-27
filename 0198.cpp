/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0198.cpp
* Author:   root
* Date:     2021-07-28 02:15:30
* Brief:
****************************************************/
 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[101][2];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = dp[i - 1][0] + nums[i - 1];
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

