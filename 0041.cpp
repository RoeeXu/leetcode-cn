/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0041.cpp
* Author:   roeexu
* Date:     2019/11/15 17:33:21
* Brief:
****************************************************/

class Solution {
public:
    // best
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), idx;
        for (int i = 0; i < n; i++)
        	nums[i] = (nums[i] >= 1 && nums[i] <= n) ? nums[i] : n + 1;
        for (int i = 0; i < n; i++) {
        	idx = abs(nums[i]);
        	if (idx != n + 1 && nums[idx - 1] > 0)
        		nums[idx - 1] = -nums[idx - 1];
        }
        for (int i = 0; i < n; i++)
        	if (nums[i] > 0)
        		return i + 1;
        return n + 1;
    }

    // offical
    // int firstMissingPositive(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n == 1 && nums[0] == 1) return 2;
    //     int flag = 1;
    //     for(int i = 0; i < n; i++)
    //         if(nums[i] == 1) {flag = 0; break;}
    //     if(flag) return 1;
    //     for(int i = 0; i < n; i++)
    //         if(nums[i] <= 0 || nums[i] > n) nums[i] = 1;
    //     int idx;
    //     for(int i = 0; i < n; i++)
    //     {
    //         idx = abs(nums[i]);
    //         if(idx == n && nums[0] > 0) nums[0] = -nums[0];
    //         else if(idx < n && nums[idx] > 0) nums[idx] = -nums[idx];
    //     }
    //     for(int i = 1; i < n; i++)
    //         if(nums[i] > 0) return i;
    //     if(nums[0] > 0) return n;
    //     return n + 1;
    // }

    // mine
    // int firstMissingPositive(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     int res = 1;
    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         if(nums[i] == res) res++;
    //         else if(nums[i] > res) return res;
    //     }
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

