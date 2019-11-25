/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0918.cpp
* Author:   root
* Date:     2019-11-25 19:03:10
* Brief:
****************************************************/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        if(n == 0) return 0;
        int s1, s2, res1, res2, sum = 0;
        s1 = s2 = res1 = res2 = -10e9;
        for(int i = 0; i < n; i++)
        {
            if(s1 < 0) s1 = A[i];
            else s1 += A[i];
            res1 = max(res1, s1);
            if(s2 < 0) s2 = -A[i];
            else s2 -= A[i];
            res2 = max(res2, s2);
            sum += A[i];
        }
        return sum + res2 != 0 ? max(res1, sum + res2) : res1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

