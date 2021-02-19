/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1004.cpp
* Author:   roeexu
* Date:     2021-02-19 16:39:42
* Brief:
****************************************************/
 
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r = 0, c = 0, n = A.size(), res = 0;
        while(l < n)
        {
            while(c < K && r < n) if(A[r++] == 0) c++;
            while(c == K && r < n && A[r] == 1) r++;
            if(c == K) res = max(res, r - l);
            if(r == n) {res = max(res, r - l); return res;}
            while(c == K && l < r) if(A[l++] == 0) c--;
            if(l == r) l = ++r;
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

