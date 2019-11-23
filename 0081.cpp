/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0081.cpp
* Author:   root
* Date:     2019-11-24 04:05:37
* Brief:
****************************************************/

class Solution {
public:
    // best
    bool search(vector<int>& nums, int target) {
        int start=0,end=nums.size(), mid;
        while(start!=end){
            mid=(start+end)/2;
            if(nums[mid]==target) return true;
            if(nums[start]<nums[mid])
                if(nums[start]<=target&&target<nums[mid]) end=mid;
                else start=mid+1;
            else if(nums[start]>nums[mid])
                if(nums[mid]<target&&target<=nums[end-1]) start=mid+1;
                else end=mid;
            else start++;
        }
        return false;
    }

    // mine
    // int removeRepeat(vector<int>& nums) {
    //     int p = 0;
    //     for(auto n : nums)
    //         if(p < 1 || n != nums[p - 1])
    //             nums[p++] = n;
    //     return p;
    // }

    // bool search(vector<int>& nums, int target) {
    //     int n = removeRepeat(nums);
    //     while(n > 1 && nums[n - 1] == nums[0]) n--;
    //     int left = 0, right = n - 1, mid;
    //     while(left <= right)
    //     {
    //         mid = (left + right) / 2;
    //         if(nums[mid] == target) return 1;
    //         if(nums[mid] < nums[0])
    //             if(target > nums[mid] && target < nums[0]) left = mid + 1;
    //             else right = mid - 1;
    //         else
    //             if(target < nums[mid] && target >= nums[0]) right = mid - 1;
    //             else left = mid + 1;
    //     }
    //     return 0;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

