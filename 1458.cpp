/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1458.cpp
* Author:   roeexu
* Date:     2020-06-04 11:32:30
* Brief:
****************************************************/
 
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1e9));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = max(max(max(dp[i][j-1], dp[i-1][j]), max(dp[i-1][j-1], (dp[i-1][j-1] == -1e9 ? 0 : dp[i-1][j-1])+nums1[i-1]*nums2[j-1])), nums1[i-1]*nums2[j-1]);
        return dp[m][n];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

