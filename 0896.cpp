/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0896.cpp
* Author:   roeexu
* Date:     2019-11-28 20:26:56
* Brief:
****************************************************/

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if(n < 2) return 1;
        if(A[0] == A[n - 1]) for(int i = 1; i < n; i++) {if(A[i] != A[i - 1]) return 0;}
        else if(A[0] > A[n - 1]) for(int i = 1; i < n; i++) {if(A[i - 1] < A[i]) return 0;}
        else for(int i = 1; i < n; i++) {if(A[i - 1] > A[i]) return 0;}
        return 1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

