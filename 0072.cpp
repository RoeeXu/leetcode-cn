/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0072.cpp
* Author:   root
* Date:     2019-11-21 12:03:28
* Brief:
****************************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        if(n1 < n2) return minDistance(word2, word1);
        int *dp = new int[n1 + 1]();
        int tmp;
        for(int i = 0; i < n1 + 1; i++) dp[i] = i;
        for(int i = 1; i < n2 + 1; i++)
        {
            tmp = dp[0];
            dp[0] = i;
            for(int j = 1; j < n1 + 1; j++)
            {
                tmp = min(min(dp[j - 1], dp[j]) + 1, tmp + (word1[j - 1] == word2[i - 1] ? 0 : 1));
                swap(tmp, dp[j]);
            }
        }
        return dp[n1];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

