/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1201.cpp
* Author:   roeexu
* Date:     2020-01-06 11:15:14
* Brief:
****************************************************/
 
class Solution {
public:
    long gcd(long a, long b) {
        if(a < b) return gcd(b, a);
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
    long lcm(long a, long b) {
        long g = gcd(a, b);
        return a / g * b;
    }
    
    int compute(int m, int a, int b, int c) {
        long x = lcm(b, c), y = lcm(a, c), z = lcm(a, b), o = lcm(a, x);
        return m / a + m / b + m / c - m / x - m / y - m / z + m / o;
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        long l = 1, r = 2 * 1e9, m, v;
        while(l < r)
        {
            m = (l + r) / 2;
            v = compute(m, a, b, c);
            if(v >= n) r = m;
            else l = m + 1;
        }
        return l;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

