/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0200.cpp
* Author:   root
* Date:     2021-07-27 16:28:39
* Brief:
****************************************************/
 
class Solution {
public:
    vector<pair<int, int>> pos = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int m, n;

    void dfs_flood(vector<vector<char>>& grid, int x, int y)
    {
        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1')
        {
            grid[x][y] = '0';
            for (auto [a, b] : pos)
                dfs_flood(grid, x + a, y + b);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs_flood(grid, i, j);
                }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

