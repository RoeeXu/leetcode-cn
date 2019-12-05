/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0121.cpp
* Author:   root
* Date:     2019-12-06 02:31:13
* Brief:
****************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

