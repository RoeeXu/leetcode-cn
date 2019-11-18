/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0015.cpp
* Author:   roee
* Date:     2019-11-18 23:23:11
* Brief:
****************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(n < 3 || nums[0] > 0 || nums[n-1] < 0) return res;
        for(int i=0;i<n-2;i++)
        {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int head = i + 1, tail = n - 1;
            while(head < tail)
            {
                if(nums[head] + nums[tail] == target)
                {
                    if(head>i+1&&nums[head]==nums[head-1])
                    {
                        head++;
                        continue;
                    }
                    if(tail<n-1&&nums[tail]==nums[tail+1])
                    {
                        tail--;
                        continue;
                    }
                    res.push_back(vector<int>({nums[i], nums[head], nums[tail]}));
                    head++;
                    tail--;
                }
                else if(nums[head] + nums[tail] > target) tail--;
                else head++;
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

