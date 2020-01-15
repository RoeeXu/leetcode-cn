/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0891.cpp
* Author:   roeexu
* Date:     2020-01-15 16:47:26
* Brief:
****************************************************/
 
class Solution {
public:
    long pow(int x, int y, int m) {
        if(x == 0) return 0;
        if(y == 0) return 1;
        long tmp = pow(x, y / 2, m);
        tmp *= tmp;
        tmp %= m;
        if(y % 2) tmp *= x;
        return tmp % m;
    }
    
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size(), m = 1e9 + 7;
        long res = 0;
        long p = pow(2, n - 1, m), q = 1;
        for(int i = 0; i < n / 2; i++) {
            res += (long)(A[n - 1 - i] - A[i]) * (p - q);
            res %= m;
            p = (p + (p % 2 ? m : 0)) / 2;
            q = (q * 2) % m;
        }
        return res < 0 ? res + m : res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

