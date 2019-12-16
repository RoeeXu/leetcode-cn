/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1105.cpp
* Author:   roeexu
* Date:     2019-12-16 11:39:36
* Brief:
****************************************************/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n + 1, 1000001);
        dp[0] = 0;
        for(int i = 1; i < n + 1; i++)
        {
            int tmp_width = 0, j = i, h = 0;
            while(j > 0)
            {
                tmp_width += books[j - 1][0];
                if(tmp_width > shelf_width) break;
                h = max(h, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + h);
                j--;
            }
        }
        return dp[n];
    }
};


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

