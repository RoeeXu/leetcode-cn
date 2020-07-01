/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1420.cpp
* Author:   roee
* Date:     2020-07-02 00:34:49
* Brief:
****************************************************/

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long dp[51][51][101];
        memset(dp, 0, sizeof(dp));
        for(int c = 1; c <= m; c++) dp[1][1][c] = 1;
        for(int a = 2; a <= n; a++)
            for(int b = 1; b <= k; b++)
                for(int c = 1; c <= m; c++)
                    for(int i = 1; i <= c; i++) {
                        if(i == c) dp[a][b][c] += dp[a - 1][b][c] * c;
                        else dp[a][b][c] += dp[a - 1][b - 1][i];
                        dp[a][b][c] %= 1000000007;
                    }
        long res = 0;
        for(int c = 1; c <= m; c++) res += dp[n][k][c];
        return res % 1000000007;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
