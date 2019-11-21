/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0075.cpp
* Author:   root
* Date:     2019-11-22 03:08:20
* Brief:
****************************************************/

class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     int n = nums.size(), l = 0, r = n - 1;
    //     for(int i = 0; i <= r; i++)
    //     {
    //         while(r >= 0 && nums[r] == 2) r--;
    //         while(l < n && nums[l] == 0) l++;
    //         if(r < 0 || l >= n || r < l) return;
    //         i = max(i, l);
    //         if(nums[i] == 1) continue;
    //         else if(nums[i] == 2)
    //         {
    //             swap(nums[i], nums[r]);
    //             i--;
    //             r--;
    //         }
    //         else
    //         {
    //             swap(nums[i], nums[l]);
    //             i--;
    //             l++;
    //         }
    //     }
    //     return;
    // }

    void sortColors(vector<int>& nums) {
        int p0 = 0, curr = 0;
        int p2 = nums.size() - 1;
        while (curr <= p2)
            if (nums[curr] == 0) swap(nums[curr++], nums[p0++]);
            else if (nums[curr] == 2) swap(nums[curr], nums[p2--]);
        else curr++;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

