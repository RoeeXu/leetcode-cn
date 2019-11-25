/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0088.cpp
* Author:   roeexu
* Date:     2019-11-25 16:44:25
* Brief:
****************************************************/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-- + n-- - 1;
        while(m >= 0 && n >= 0)
            if(nums1[m] > nums2[n]) nums1[p--] = nums1[m--];
            else nums1[p--] = nums2[n--];
        while(n >= 0) nums1[p--] = nums2[n--];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

