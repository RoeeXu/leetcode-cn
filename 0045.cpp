/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0045.cpp
* Author:   roeexu
* Date:     2019/11/18 13:20:52
* Brief:
****************************************************/

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, max_pos = 0, next_pos = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (max_pos < i)
            {
                max_pos = next_pos;
                step++;
            }
            next_pos = max(next_pos, i + nums[i]);
        }
        return step;
    }
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int tail = 0, head = 0, step = 0, tmp;
        while(1)
        {
            if(tail >= n - 1) return step;
            tmp = tail;
            for(int i = head; i <= tmp; i++)
                tail = max(tail, i + nums[i]);
            head = tmp + 1;
            step++;
        }
        return 0;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

