/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0172.cpp
* Author:   roeexu
* Date:     2021-02-20 16:58:32
* Brief:
****************************************************/
 
class Solution {
public:
    int trailingZeroes(int n) {
        int t = 5, r = 0;
        while(n / t > 0)
        {
            r += n / t;
            t *= 5;
        }
        return r;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

