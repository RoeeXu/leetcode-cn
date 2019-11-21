/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0069.cpp
* Author:   roeexu
* Date:     2019-11-21 17:43:04
* Brief:
****************************************************/

class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x, m;
        while(l <= r)
        {
            m = (l + r) / 2;
            if(m * m > x) r = m - 1;
            else if(m * m == x) return m;
            else l = m + 1;
        }
        if(l * l > x) return l - 1;
        return l;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

