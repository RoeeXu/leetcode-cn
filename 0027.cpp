/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0027.cpp
* Author:   roee
* Date:     2019-11-18 23:26:47
* Brief:
****************************************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int start = 0, end = n - 1;
        while(start <= end)
        {
            while(start <= end && nums[end] == val) 
            {
                end--; 
                n--;
            }
            if(start <= end && nums[start] == val)
            {
                nums[start] = nums[end];
                end--;
                n--;
            }
            start++;
        }
        return n;
    }
};

// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int cur = 0; 
//         int len = nums.size() ;
//         if(len == 0)
//             return 0 ;
//         for(int i = 0; i<len; i++) {
//             if(nums[i] == val) {
//                 continue ;
//             } else if(nums[i] != val) {
//                 nums[cur++] = nums[i] ;
//             }
//         }
//         return cur ;
//     }
// };

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

