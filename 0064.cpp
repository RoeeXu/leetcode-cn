/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0064.cpp
* Author:   roee
* Date:     2019-11-20 10:36:23
* Brief:
****************************************************/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        int *dp = new int[n]();
        for(int i = 0; i < m; i++)
        {
            dp[0] += grid[i][0];
            if(i == 0)
                for(int j = 1; j < n; j++)
                    dp[j] += (grid[0][j] + dp[j - 1]);
            else
                for(int j = 1; j < n; j++)
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
        }
        return dp[n - 1];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

