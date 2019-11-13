/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0031.cpp
* Author:   roeexu
* Date:     2019/11/13 15:48:38
* Brief:
****************************************************/

class Solution {
public:
    int find_first_bigger_pos(vector<int>& nums, int left, int right, int target)
    {
        int mid;
        while(left < right)
        {
            if(left + 1 == right)
                return nums[right] > target ? right : left;
            mid = (left + right) / 2;
            if(nums[mid] > target)
                left = mid;
            else
                right = mid;
        }
        return -1;
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int tmp;
        if(n <= 1) return;
        if(nums[n - 1] > nums[n - 2])
        {
            tmp = nums[n - 1];
            nums[n - 1] = nums[n - 2];
            nums[n - 2] = tmp;
            return;
        }
        int p = 1;
        while(p < n && nums[n - p] <= nums[n - p - 1])
            p++;
        if(p == n)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int q;
        q = find_first_bigger_pos(nums, n - p, n - 1, nums[n - p - 1]);
        tmp = nums[n - p - 1];
        nums[n - p - 1] = nums[q];
        nums[q] = tmp;
        reverse(nums.begin() + n - p, nums.end());
        return;
        // STL
        // next_permutation(nums.begin(),nums.end());
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

