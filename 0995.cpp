/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0995.cpp
* Author:   roeexu
* Date:     2021-02-18 15:41:26
* Brief:
****************************************************/
 
class Solution {
public:
    int minKBitFlips(vector<int> &A, int K) {
        int n = A.size();
        int ans = 0, revCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= K && A[i - K] > 1) {
                revCnt ^= 1;
                // A[i - K] -= 2;
            }
            if (A[i] == revCnt) {
                if (i + K > n) return -1;
                ++ans;
                revCnt ^= 1;
                A[i] += 2;
            }
        }
        return ans;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

