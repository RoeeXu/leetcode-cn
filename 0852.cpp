/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0852.cpp
* Author:   root
* Date:     2019-11-25 10:44:17
* Brief:
****************************************************/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int p = 1;
        while(A[p - 1] < A[p]) p++;
        return p - 1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

