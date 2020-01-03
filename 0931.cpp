/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0931.cpp
* Author:   roeexu
* Date:     2020-01-03 18:55:50
* Brief:
****************************************************/
 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for(int i = 1; i < m; i++)
            for(int j = 0; j < n; j++)
                A[i][j] += min(min((j>0?A[i-1][j-1]:101), (j<n-1?A[i-1][j+1]:101)), A[i-1][j]);
        return *min_element(A[m-1].begin(), A[m-1].end());
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

