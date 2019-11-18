/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0016.cpp
* Author:   roee
* Date:     2019-11-18 23:23:31
* Brief:
****************************************************/

class Solution {
public:
    int abs(int x)
    {
        return (x)>0?(x):(-(x));
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        for(int i=0;i<n;i++)
        {
            int head = i + 1;
            int tail = n - 1;
            int sum;
            while(head < tail)
            {
                sum = nums[i] + nums[head] + nums[tail];
                if(sum == target)
                    return target;
                else if(sum > target)
                {
                    res = abs(sum - target) < abs(res - target) ? sum : res;
                    tail--;
                }
                else
                {
                    res = abs(sum - target) < abs(res - target) ? sum : res;
                    head++;
                }
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

