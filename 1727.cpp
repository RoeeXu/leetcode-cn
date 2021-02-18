/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1727.cpp
* Author:   roeexu
* Date:     2021-01-20 15:58:43
* Brief:
****************************************************/
 
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        int prefix[m][n];
        for(int j = 0; j < n; j++)
            for(int i = 0; i < m; i++)
                if(i == 0) prefix[i][j] = matrix[i][j];
                else if(matrix[i][j] == 1) prefix[i][j] = prefix[i - 1][j] + 1;
                else prefix[i][j] = 0;
        int tmp[n];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++) tmp[j] = prefix[i][j];
            sort(tmp, tmp + n);
            for(int j = 0; j < n; j++) res = max(res, (n - j) * tmp[j]);
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

