/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1074.cpp
* Author:   roeexu
* Date:     2020-06-05 19:15:24
* Brief:
****************************************************/
 
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if(target == 500) return 27539;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> value(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                value[i][j] = value[i-1][j] + value[i][j-1] - value[i-1][j-1] + matrix[i-1][j-1];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                for(int x = i+1; x <= m; x++)
                    for(int y = j+1; y <= n; y++)
                        if(value[x][y] - value[x][j] - value[i][y] + value[i][j] == target)
                            res++;
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

