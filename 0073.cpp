/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0073.cpp
* Author:   root
* Date:     2019-11-22 02:13:03
* Brief:
****************************************************/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int m = matrix.size(), n = matrix[0].size(), flag = 1;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0)
                {
                    if(j == 0) flag = 0;
                    else matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if(matrix[0][0] == 0)
            for(int j = 1; j < n; j++)
                matrix[0][j] = 0;
        if(flag == 0)
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;
        return;
    }  
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

