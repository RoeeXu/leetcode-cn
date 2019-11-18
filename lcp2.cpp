/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     lcp2.cpp
* Author:   roeexu
* Date:     2019-11-18 22:30:32
* Brief:
****************************************************/

class Solution {
public:
    // 数归证明不需要约分
    // int gcd(int x, int y)
    // {
    //     if(x < y) return gcd(y, x);
    //     if(x % y == 0) return y;
    //     x %= y;
    //     return gcd(y, x);
    // }

    vector<int> fraction(vector<int>& cont) {
        int n = cont.size();
        int p = cont[n - 1], q = 1, s, t, r;
        for(int i = 0; i < n - 1; i++)
        {
            s = cont[n - 2 - i] * p + q;
            t = p;
            // r = gcd(s, t);
            // p = s / r;
            // q = t / r;
            p = s;
            q = t;
        }
        return {p, q};
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

