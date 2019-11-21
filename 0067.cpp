/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0067.cpp
* Author:   roeexu
* Date:     2019-11-21 15:39:36
* Brief:
****************************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(), n = b.length();
        if(m < n) return addBinary(b, a);
        int p = 1, up = 0;
        while(p <= m)
        {
            a[m - p] = a[m - p] + up + (p <= n ? b[n - p] - '0' : 0);
            if(a[m - p] >= '2') {a[m - p] -= 2; up = 1;}
            else up = 0;
            p++;
        }
        if(up == 1) a.insert(a.begin(), '1');
        return a;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

