/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0920.cpp
* Author:   root
* Date:     2019-11-25 19:40:34
* Brief:
****************************************************/

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        int gap = 1000000007;
        long dp[101][101];
        for (int i = 0; i <= L; ++i)
            for (int j = 0; j <= N; ++j)
                dp[i][j] = 0;
        dp[0][0] = 1;
        for (int i = 1; i <= L; ++i)
            for (int j = 1; j <= N; ++j) {
                dp[i][j] += dp[i-1][j-1] * (N-j+1);
                dp[i][j] += dp[i-1][j] * max(j-K, 0);
                dp[i][j] %= gap;
            }
        return dp[L][N];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

