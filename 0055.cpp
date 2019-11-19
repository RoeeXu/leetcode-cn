/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0055.cpp
* Author:   roeexu
* Date:     2019-11-19 10:38:46
* Brief:
****************************************************/

class Solution {
public:
    // mine
    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     int tail = 0, head = 0, tmp;
    //     while(1)
    //     {
    //         if(tail >= n - 1) return 1;
    //         tmp = tail;
    //         for(int i = head; i <= tmp; i++)
    //             tail = max(tail, i + nums[i]);
    //         if(tail == tmp) return 0;
    //         head = tmp + 1;
    //     }
    //     return 0;
    // }

    // best
    bool canJump(vector<int>& nums) {
        int pos = nums.size() - 1;
        for(int i = pos - 1; i >= 0;i--)
            if(i + nums[i] >= pos)
                pos = i;
        return pos == 0;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

