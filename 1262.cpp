/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1262.cpp
* Author:   roeexu
* Date:     2019-11-18 22:26:54
* Brief:
****************************************************/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size(), step = 1, idx;
        int *dp = new int[3]();
        int *tmp = new int[3]();
        if(n == 0) return 0;
        dp[nums[0] % 3] = nums[0];
        while(step < n)
        {
            idx = nums[step] % 3;
            for(int i = 0; i < 3; i++)
                tmp[i] = max(dp[i], dp[(i - idx + 3) % 3] == 0 ? (idx == i ? nums[step] : 0) : dp[(i - idx + 3) % 3] + nums[step]);
            for(int i = 0; i < 3; i++)
                dp[i] = tmp[i];
            step++;
        }
        return dp[0];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

