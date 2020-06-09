/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1403.cpp
* Author:   roeexu
* Date:     2020-06-05 19:22:13
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size(), s = 0, t = 0, i = 0;
        for(auto& x : nums) s += x;
        while(1) {
            t += nums[i++];
            if(2 * t > s) break;
        }
        vector<int> res(nums.begin(), nums.begin() + i);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

