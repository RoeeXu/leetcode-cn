/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1289.cpp
* Author:   roeexu
* Date:     2019-12-23 10:57:41
* Brief:
****************************************************/

class Solution {
public:
    // best
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int first_sum = 0, first_pos = -1, second_sum = 0;
        for (int i = 0; i < n; ++i) {
            int fs = INT_MAX, fp = -1, ss = INT_MAX;
            for (int j = 0; j < n; ++j) {
                int cur_sum = (first_pos != j ? first_sum : second_sum) + arr[i][j];
                if (cur_sum < fs) {
                    ss = fs;
                    fs = cur_sum;
                    fp = j;
                }
                else if (cur_sum < ss) {
                    ss = cur_sum;
                }
            }
            first_sum = fs;
            first_pos = fp;
            second_sum = ss;
        }
        return first_sum;
    }

    // mine
    // int minFallingPathSum(vector<vector<int>>& arr) {
    //     int n = arr.size();
    //     int dp[201][201] = {0};
    //     for(int i = 0; i < n; i++)
    //         for(int j = 0; j < n; j++)
    //             if(i == 0) dp[i][j] = arr[i][j];
    //             else
    //             {
    //                 int aim = 1000000000;
    //                 for(int k = 0; k < n; k++) if(k != j && dp[i-1][k] < aim) aim = dp[i-1][k];
    //                 dp[i][j] = arr[i][j] + aim;
    //             }
    //     int res = 1000000000;
    //     for(int k = 0; k < n; k++) if(dp[n-1][k] < res) res = dp[n-1][k];
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

