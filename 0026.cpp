/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0026.cpp
* Author:   roee
* Date:     2019-11-18 23:26:27
* Brief:
****************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int pos = 0;
        for(int i=1;i<n;i++)
        {
            if(nums[pos] == nums[i])
            {
                continue;
            }
            else
            {
                pos++;
                nums[pos] = nums[i];
            }
        }
        return pos + 1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

