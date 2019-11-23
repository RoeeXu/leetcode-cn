/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0080.cpp
* Author:   root
* Date:     2019-11-24 03:45:29
* Brief:
****************************************************/

class Solution {
public:
    // most short
    int removeDuplicates(vector<int>& nums) {
        int p = 0;
        for(auto n : nums)
            if(p < 2 || n > nums[p - 2])
                nums[p++] = n;
        return p;
    }

    // mine
    // int removeDuplicates(vector<int>& nums) {
    //     int x, d = 0, p = 0;
    //     for(auto n : nums)
    //     {
    //         if(d == 0 || n != x) d = 1;
    //         else if(d == 1 && n == x) d++;
    //         else continue;
    //         nums[p++] = x = n;
    //     }
    //     return p;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

