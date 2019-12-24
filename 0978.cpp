/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0978.cpp
* Author:   roeexu
* Date:     2019-12-24 11:15:45
* Brief:
****************************************************/

static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int up, down, p, q, n = A.size();
        up = down = 0;
        p = q = 1;
        for(int i = 0; i < n - 1; i++)
        {
            if((i % 2 && A[i] < A[i+1]) || (i % 2 == 0 && A[i] > A[i+1])) p++;
            else
            {
                up = max(up, p);
                p = 1;
            }
            if((i % 2 && A[i] > A[i+1]) || (i % 2 == 0 && A[i] < A[i+1])) q++;
            else
            {
                down = max(down, q);
                q = 1;
            }
        }
        return max(max(up, p), max(down, q));
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

