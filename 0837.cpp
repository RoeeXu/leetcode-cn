/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0837.cpp
* Author:   roeexu
* Date:     2020-01-03 17:05:24
* Brief:
****************************************************/
 
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K + W - 1 <= N) return 1.0;
        vector<double> dp(K + W, 0.0);
        for (int k = K; k <= N; ++k) dp[k] = 1.0;
        double S = min(N - K + 1, W);
        for (int k = K - 1; k >= 0; k--)
        {
            dp[k] = S / W;
            S += dp[k] - dp[k + W];
        }
        return dp[0];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

