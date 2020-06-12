/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0942.cpp
* Author:   roeexu
* Date:     2020-06-12 20:10:28
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.length();
        int lo = 0, hi = N;
        vector<int> ans(N+1);
        for (int i = 0; i < N; ++i) {
            if (S[i] == 'I')
                ans[i] = lo++;
            else
                ans[i] = hi--;
        }
        ans[N] = lo;
        return ans;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

