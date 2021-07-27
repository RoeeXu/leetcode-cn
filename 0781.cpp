/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0781.cpp
* Author:   root
* Date:     2021-07-27 16:15:27
* Brief:
****************************************************/
 
class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int, int> cnt;
        for (auto x : a)
            cnt[x]++;
        int res = 0;
        for (auto [k, v] : cnt)
            res += (v + k) / (k + 1) * (k + 1);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

