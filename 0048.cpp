/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0048.cpp
* Author:   roee
* Date:     2019-11-19 00:27:13
* Brief:
****************************************************/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        reverse(matrix.begin(), matrix.end());
        int tmp;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = i + 1; j < matrix[0].size(); j++)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

