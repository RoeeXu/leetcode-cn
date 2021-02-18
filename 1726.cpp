/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1726.cpp
* Author:   roeexu
* Date:     2021-01-20 15:19:47
* Brief:
****************************************************/
 
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        int s[1000001];
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                s[cnt++] = nums[i] * nums[j];
        s[cnt] = -1;
        sort(s, s + cnt);
        int m = 0, f = 1;
        for(int i = 1; i < cnt + 1; i++)
            if(s[i] == s[i - 1]) f++;
            else
            {
                m += f * (f - 1) * 4;
                f = 1;
            }
        return m;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

