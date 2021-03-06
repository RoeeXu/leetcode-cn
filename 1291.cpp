/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1291.cpp
* Author:   roeexu
* Date:     2019-12-23 09:13:07
* Brief:
****************************************************/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int L[] = {12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};
        int l = 0, r = 35;
        while(l < 36 && L[l] < low) l++;
        while(r >= 0 && L[r] > high) r--;
        return vector<int>(L+l, L+r+1);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

