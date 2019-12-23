/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1292.cpp
* Author:   roeexu
* Date:     2019-12-23 08:59:45
* Brief:
****************************************************/

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        int b[301][301] = {0};
        int res = 0;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                b[i][j] = b[i][j-1] + b[i-1][j] - b[i-1][j-1] + mat[i-1][j-1];
        for(int i = 0; i < m; i++)
            for(int j = 0, k=res+1; j < n; j++)
                while(i+k<=m && j+k<=n)
                {
                    int v = b[i+k][j+k]+b[i][j]-b[i+k][j]-b[i][j+k];
                    if(v <= threshold) res = max(res, k);
                    else break;
                    k++;
                }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

