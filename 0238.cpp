/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0238.cpp
* Author:   roeexu
* Date:     2020-06-04 10:27:40
* Brief:
****************************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);
        int s = 1,t = 1;
        for(int i = 0; i < n; i++) {
            output[i] *= s;
            s *= nums[i];
            output[n - 1 - i] *= t;
            t *= nums[n - 1 - i];
        }
        return output;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

