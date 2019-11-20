/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0063.cpp
* Author:   roee
* Date:     2019-11-20 10:20:39
* Brief:
****************************************************/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) return 1;
        int n = obstacleGrid[0].size();
        long *dp = new long[n + 1]();
        for(int i = 0; i < m; i++)
        {
            dp[0] = (long)(i == 0);
            for(int j = 1; j <= n; j++)
                if(obstacleGrid[i][j - 1] == 1) dp[j] = 0;
                else dp[j] += dp[j - 1];
        }
        return dp[n];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

