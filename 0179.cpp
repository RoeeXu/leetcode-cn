/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0179.cpp
* Author:   root
* Date:     2021-07-27 22:52:12
* Brief:
****************************************************/
 
bool cmp(int x, int y)
{
    long sx = 10, sy = 10;
    while (sx <= x) sx *= 10;
    while (sy <= y) sy *= 10;
    return sy * x + y > sx * y + x;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) return "0";
        string s;
        for (auto x : nums)
            s += to_string(x);
        return s;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

