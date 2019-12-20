/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1144.cpp
* Author:   roeexu
* Date:     2019-12-20 11:08:18
* Brief:
****************************************************/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int a = 0, b = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            if(i == 0) a += nums[0] < nums[1] ? 0 : nums[0] - nums[1] + 1;
            else if(i == n - 1 && i % 2 == 1) b += nums[n - 1] < nums[n - 2] ? 0 : nums[n - 1] - nums[n - 2] + 1;
            else if(i == n - 1 && i % 2 == 0) a += nums[n - 1] < nums[n - 2] ? 0 : nums[n - 1] - nums[n - 2] + 1;
            else if(i % 2 == 1) b += max((nums[i] < nums[i + 1] ? 0 : nums[i] - nums[i + 1] + 1), (nums[i] < nums[i - 1] ? 0 : nums[i] - nums[i - 1] + 1));
            else a += max((nums[i] < nums[i + 1] ? 0 : nums[i] - nums[i + 1] + 1), (nums[i] < nums[i - 1] ? 0 : nums[i] - nums[i - 1] + 1));
        return min(a, b);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

