/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0892.cpp
* Author:   root
* Date:     2019-12-18 02:41:53
* Brief:
****************************************************/

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                res += grid[i][j] * 4 + (grid[i][j] > 0 ? 2 : 0);
                if(j < n - 1) res -= 2 * min(grid[i][j], grid[i][j + 1]);
                if(i < n - 1) res -= 2 * min(grid[i][j], grid[i + 1][j]);
            }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

