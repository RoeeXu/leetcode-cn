/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0053.cpp
* Author:   roeexu
* Date:     2019-11-19 10:31:13
* Brief:
****************************************************/

class Solution {
public:
    // best
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = 0;
        for(auto num : nums)
        {
            if(sum > 0) sum += num;
            else sum = num;
            res = max(res, sum);
        }
        return res;
    }

    // divide
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 0) return 0;
    //     if(n == 1) return nums[0];
    //     vector<int> lefts(nums.begin(), nums.begin() + n / 2);
    //     vector<int> rights(nums.begin() + n / 2, nums.end());
    //     int left_max = maxSubArray(lefts);
    //     int right_max = maxSubArray(rights);
    //     int l_max = lefts[lefts.size() - 1], r_max = rights[0], sum;
    //     if(lefts.size() > 1)
    //         sum = l_max;
    //         for(int i = lefts.size() - 2; i >= 0; i--)
    //         {
    //             sum += lefts[i];
    //             l_max = max(l_max, sum);
    //         }
    //     if(rights.size() > 1)
    //         sum = r_max;
    //         for(int i = 1; i < rights.size(); i++)
    //         {
    //             sum += rights[i];
    //             r_max = max(r_max, sum);
    //         }
    //     return max(max(left_max, right_max), l_max + r_max);
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

