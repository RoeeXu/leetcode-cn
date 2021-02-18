/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0136.cpp
* Author:   roeexu
* Date:     2021-02-18 21:06:05
* Brief:
****************************************************/
 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = 0;
        for(auto x : nums) s ^= x;
        return s;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

