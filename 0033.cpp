/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0033.cpp
* Author:   roeexu
* Date:     2019/11/13 15:46:32
* Brief:
****************************************************/

class Solution {
public:
    // int search(vector<int>& nums, int target) {
    //     int left=0;
    //     int right=nums.size()-1;
    //     while(left<=right)
    //     {
    //         int mid=(left+right)/2;
    //         if(nums[mid]==target)
    //             return mid;
    //         if(nums[mid]<nums[0])//on the right side
    //         {
    //             if(target>nums[mid]&&target<nums[0])//terget>nums[mid]有两种情况
    //                 left=mid+1;
    //             else
    //                 right=mid-1;
    //         }
    //         else
    //         {
    //             if(target<nums[mid]&&target>=nums[0])//terget<nums[mid]有两种情况
    //                 right=mid-1;
    //             else
    //                 left=mid+1;
    //         }
    //     }
    //     return -1;
    // }

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        if(right == -1) return -1;
        if(right == 0) return nums[0] == target ? 0 : -1;
        if(target > nums[right] && target < nums[left]) return -1;
        while(1)
        {
            if(left > right) return -1;
            if(target == nums[right]) return right;
            if(target == nums[left]) return left;
            mid = (left + right) / 2;
            if(target == nums[mid]) return mid;
            if(nums[left] < target && target < nums[right])
            {
                if(nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
            else if(target > nums[left] && nums[left] > nums[right])
            {
                if(nums[mid] < target && nums[mid] > nums[left])
                    left = mid + 1;
                else right = mid - 1;
            }
            else{
                if(nums[mid] > target && nums[mid] < nums[right])
                    right = mid - 1;
                else left = mid + 1;
            }
        }
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

