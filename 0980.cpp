/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0980.cpp
* Author:   roeexu
* Date:     2019-12-24 13:16:05
* Brief:
****************************************************/

class Solution {
public:
    int res = 0, s = 0, m, n;
    bool board[21][21] = {0};
    
    void dfs(vector<vector<int>>& grid, int x, int y, int remain) {
        if(x < 0 || x >= m || y < 0 || y >= n) return;
        if(grid[x][y] == -1) return;
        if(grid[x][y] == 2 && remain != 1) return;
        if(grid[x][y] == 2 && remain == 1) {res++; return;}
        if(board[x][y]) return;
        board[x][y] = 1;
        remain--;
        dfs(grid, x+1, y, remain);
        dfs(grid, x-1, y, remain);
        dfs(grid, x, y+1, remain);
        dfs(grid, x, y-1, remain);
        remain++;
        board[x][y] = 0;
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int a, b;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != -1) s++;
                if(grid[i][j] == 1) a = i, b = j;
            }
        dfs(grid, a, b, s);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

