/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0283.cpp
* Author:   roeexu
* Date:     2020-06-04 10:39:30
* Brief:
****************************************************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j, n = nums.size();
        for(i = 0, j = 0; i < n && j < n; j++)
            if(nums[j] != 0) nums[i++] = nums[j];
        while(i < n) nums[i++] = 0;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

