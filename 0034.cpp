/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0034.cpp
* Author:   roeexu
* Date:     2019/11/13 16:20:59
* Brief:
****************************************************/

class Solution {
public:
    // STL
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     if (nums.empty()) return {-1, -1};
    //     auto left = lower_bound(nums.begin(), nums.end(), target);
    //     auto right = upper_bound(nums.begin(), nums.end(), target);
    //     if (left == right) return {-1, -1};
    //     return {left - nums.begin(), right - nums.begin() - 1};
    // }

    // best
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, n = nums.size() - 1, mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] > target) r = mid - 1;
            else if(nums[mid] < target)l = mid + 1;
            else{
                int head = mid, tail = mid;
                l = 0; r = n;
                while(l <= head){
                    mid = (l + head) / 2;
                    if(nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {head = mid; break;}
                    else if(nums[mid] != target) l = mid + 1;
                    else head = mid - 1;
                }
                while(tail <= r){
                    mid = (tail + r) / 2;
                    if(nums[mid] == target && (mid == n || nums[mid + 1] != target)) {tail = mid; break;}
                    else if(nums[mid] != target) r = mid - 1;
                    else tail = mid + 1;
                }
                return {head, tail};
            }
        }
        return {-1, -1};
    }

    // mine
    // int search_left_pos(vector<int>& nums, int target)
    // {
    //     int left = 0, right = nums.size() - 1, mid;
    //     while(left < right)
    //     {
    //         mid = (left + right) / 2;
    //         if(nums[mid] < target) left = mid + 1;
    //         else right = mid;
    //     }
    //     if(left == right && nums[left] == target) return left;
    //     return -1;
    // }

    // int search_right_pos(vector<int>& nums, int target)
    // {
    //     int left = 0, right = nums.size() - 1, mid;
    //     while(left < right - 1)
    //     {
    //         mid = (left + right) / 2;
    //         if(nums[mid] <= target) left = mid;
    //         else right = mid - 1;
    //     }
    //     if(left == right - 1 && nums[right] == target) return right;
    //     if((left == right || left == right - 1) && nums[left] == target) return left;
    //     return -1;
    // }

    // vector<int> searchRange(vector<int>& nums, int target) {
    //     if(nums.size() == 0) return vector<int>({-1, -1});
    //     int left = search_left_pos(nums, target);
    //     int right = search_right_pos(nums, target);
    //     return vector<int>({left, right});
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

