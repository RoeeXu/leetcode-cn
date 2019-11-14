/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0035.cpp
* Author:   roeexu
* Date:     2019/11/14 10:46:16
* Brief:
****************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, m;
        while(l < r)
        {
            m = (l + r) / 2;
            if(nums[m] > target) r = m;
            else if(nums[m] < target) l = m + 1;
            else return m;
        }
        if(nums[r] < target) return r + 1;
        return l;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

