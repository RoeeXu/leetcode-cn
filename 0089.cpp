/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0089.cpp
* Author:   root
* Date:     2019-11-25 11:24:03
* Brief:
****************************************************/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0; i < 1 << n; i++)
            res.push_back(i ^ (i >> 1));
        return res;
    }

    // mine
    // int pow(int x, int p)
    // {
    //     if(p == 0) return 1;
    //     int z = pow(x, p / 2);
    //     z *= z;
    //     if(p % 2) z *= x;
    //     return z;
    // }

    // vector<int> grayCode(int n) {
    //     vector<int> res;
    //     int p = 0, m;
    //     res.push_back(0);
    //     while(p < n)
    //     {
    //         m = res.size();
    //         for(int i = 0; i < m; i++)
    //             res.push_back(pow(2, p) + res[m - 1 - i]);
    //         p += 1;
    //     }
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

