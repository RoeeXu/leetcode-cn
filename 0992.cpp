/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0992.cpp
* Author:   roee
* Date:     2020-07-02 02:08:53
* Brief:
****************************************************/

class Solution {
public:
    int sub(vector<int>& A, int k) {
        int n = A.size();
        vector<int> cnt(n + 1, 0);
        int res = 0, i = 0;
        for(int j = 0; j < n; j++) {
            if(cnt[A[j]]++ == 0) k--;
            while(k < 0) if(--cnt[A[i++]] == 0) k++;
            res += j - i + 1;
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return sub(A, K) - sub(A, K - 1);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
