/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0042.cpp
* Author:   roeexu
* Date:     2019/11/15 18:01:33
* Brief:
****************************************************/

class Solution {
public:
    // best
    int trap(vector<int>& height)
    {
        int left = 0, length = height.size(), right = length-1;
        int lmax = 0, rmax = 0, sum = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                height[left] <= lmax ? sum += lmax-height[left] : lmax = height[left];
                ++left;
            }
            else
            {
                height[right] <= rmax ? sum += rmax-height[right] : rmax = height[right];
                --right;
            }
        }
        return sum;
    }

    // mine
    // int trap(vector<int>& height) {
    //     int flag = 1, n = height.size(), p, l, r, s = 0, m;
    //     if(n < 3) return 0;
    //     while(flag)
    //     {
    //         flag = 0;
    //         p = 1;
    //         while(p < n && height[p] >= height[p - 1])
    //             p++;
    //         l = p - 1;
    //         while(p < n && height[p] <= height[p - 1])
    //             p++;
    //         while(p < n && height[p] >= height[p - 1])
    //             p++;
    //         r = p - 1;
    //         m = min(height[l], height[r]);
    //         for(int i = l; i <= r; i++)
    //             if(m > height[i])
    //             {
    //                 s += m - height[i];
    //                 height[i] = m;
    //                 flag = 1;
    //             }
    //     }
    //     return s;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

