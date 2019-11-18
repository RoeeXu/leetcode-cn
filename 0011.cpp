/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0011.cpp
* Author:   roee
* Date:     2019-11-18 23:18:53
* Brief:
****************************************************/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int head = 0, tail = height.size() - 1, res = 0, tmp;
        while (head < tail)
        {
            res = max(res, min(height[head], height[tail]) * (tail - head));
            if (height[head] < height[tail])
            {
                tmp = height[head];
                while (head < height.size() && height[head] <= tmp)
                    head++;
            }
            else
            {
                tmp = height[tail];
                while (tail >= 0 && height[tail] <= tmp)
                    tail--;
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

