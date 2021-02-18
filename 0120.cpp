/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0120.cpp
* Author:   roeexu
* Date:     2021-02-18 20:55:25
* Brief:
****************************************************/
 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& A) {
        int n = A.size();
        for(int i = n - 2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                A[i][j] += min(A[i + 1][j], A[i + 1][j + 1]);
        return A[0][0];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

