/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0240.cpp
* Author:   root
* Date:     2019-11-22 02:24:32
* Brief:
****************************************************/

static auto x = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return 0;
        int col = matrix[0].size() - 1, row = 0, m = matrix.size();
        while(col >= 0 && row < m)
        {
            if(matrix[row][col] == target) return 1;
            else if(matrix[row][col] > target) col--;
            else row++;
        }
        return 0;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

