/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0169.cpp
* Author:   roeexu
* Date:     2021-02-18 21:49:24
* Brief:
****************************************************/
 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1, cnt = 0;
        for(auto x : nums)
            if(res == x) cnt++;
            else
            {
                if(cnt == 0) { res = x; cnt++; }
                else cnt--;
            }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

