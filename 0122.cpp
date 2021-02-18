/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0122.cpp
* Author:   roeexu
* Date:     2021-02-18 21:04:24
* Brief:
****************************************************/
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = 0;
        for(int i = 1; i < prices.size(); i++)
            s += max(0, prices[i] - prices[i - 1]);
        return s;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

