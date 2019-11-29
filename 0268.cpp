/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0268.cpp
* Author:   roeexu
* Date:     2019-11-29 20:41:01
* Brief:
****************************************************/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), s = (n + 1) * n / 2;
        for(auto x : nums) s -= x;
        return s;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

