/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1043.cpp
* Author:   roeexu
* Date:     2020-06-10 12:05:23
* Brief:
****************************************************/
 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++) {
            int max_last = A[i - 1];
            for(int j = 1; j <= K; j++) {
                if(i - j >= 0) {
                    max_last = max(max_last, A[i - j]);
                    dp[i] = max(dp[i], dp[i - j] + max_last * j);
                }
                else break;
            }
        }
        return dp[n];
    }
    
    // int maxSumAfterPartitioning(vector<int>& A, int K) {
    //     int n = A.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(K + 1, -1));
    //     vector<int> max_dp(n + 1, -1);
    //     int max_A = A[0];
    //     for(int j = 1; j <= K; j++) {
    //         dp[1][j] = A[0];
    //         if(A[j - 1] > max_A) max_A = A[j - 1];
    //         dp[j][j] = max_A * j;
    //     }
    //     max_dp[1] = A[0];
    //     for(int i = 2; i <= n; i++) {
    //         dp[i][1] = max_dp[i - 1] + A[i - 1];
    //         max_dp[i] = dp[i][1];
    //         int max_last = A[i - 1];
    //         for(int j = 2; j <= K; j++) {
    //             if(j > i) dp[i][j] = dp[i][i];
    //             else if(j < i) {
    //                 if(A[i - j] > max_last) max_last = A[i - j];
    //                 dp[i][j] = max_dp[i - j] + max_last * j;
    //             }
    //             if(dp[i][j] > max_dp[i]) max_dp[i] = dp[i][j];
    //         }
    //     }
    //     return max_dp[n];
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

