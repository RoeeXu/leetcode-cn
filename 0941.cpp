/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0941.cpp
* Author:   roeexu
* Date:     2020-06-12 19:48:30
* Brief:
****************************************************/
 
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if(n < 3) return false;
        int idx = 0;
        while(idx < n - 1)
            if(A[idx] == A[idx + 1]) return false;
            else if(A[idx] > A[idx + 1]) break;
            else idx++;
        if(idx == 0 || idx == n - 1) return false;
        while(idx < n - 1)
            if(A[idx] > A[idx + 1]) idx++;
            else return false;
        return true;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

