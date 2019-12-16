/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0878.cpp
* Author:   roeexu
* Date:     2019-12-16 14:46:01
* Brief:
****************************************************/

class Solution {
public:
    int gcd(int x, int y)
    {
        return x == 0 ? y : gcd(y % x, x);
    }

    int nthMagicalNumber(int N, int A, int B) {
        long l = 0, r = 1e14, m;
        int lcm = A / gcd(A, B) * B, M = 1e9 + 7;
        while(l < r)
        {
            m = (l + r) / 2;
            if(m / A + m / B - m / lcm < N) l = m + 1;
            else r = m;
        }
        return l % M;
    }

    // 定基础，再暴力
    // int mulmod(int x, int y, int m)
    // {
    //     if(x > y) return mulmod(y, x, m);
    //     if(x == 1) return y;
    //     int z = mulmod(x, y / 2, m);
    //     z <<= 1;
    //     z %= m;
    //     if(y % 2) {z += x; z %= m;}
    //     return z;
    // }
    
    // int gcd(int x, int y)
    // {
    //     return x == 0 ? y : gcd(y % x, x);
    // }
    
    // int nthMagicalNumber(int N, int A, int B) {
    //     int m = 1000000007;
    //     if(A > B) return nthMagicalNumber(N, B, A);
    //     if(B % A == 0) return mulmod(N, A, m);
    //     int C = gcd(A, B);
    //     int n = A / C + B / C - 1;
    //     int D = mulmod(A / C, B, m);
    //     int base = 0;
    //     if(N >= n) base = mulmod(N / n, D, m);
    //     N %= n;
    //     if(N == 0) return base;
    //     long p = A, q = B;
    //     while(N-- > 1)
    //     {
    //         if(p > q) q += B;
    //         else p += A;
    //     }
    //     return (min(p, q) + base) % m;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

