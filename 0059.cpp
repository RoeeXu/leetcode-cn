/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0059.cpp
* Author:   roee
* Date:     2019-11-20 00:20:05
* Brief:
****************************************************/

class Solution {
public:
    void padding(vector<vector<int>>& grid, int a, int b, int x, int y, int start, int pos)
    {
        if(a > x || b > y) return;
        if(pos == 0)
        {
            for(int i = b; i <= y; i++)
                grid[a][i] = start++;
            a++;
            padding(grid, a, b, x, y, start, 1);
        }
        else if(pos == 1)
        {
            for(int i = a; i <= x; i++)
                grid[i][y] = start++;
            y--;
            padding(grid, a, b, x, y, start, 2);
        }
        else if(pos == 2)
        {
            for(int i = y; i >= b; i--)
                grid[x][i] = start++;
            x--;
            padding(grid, a, b, x, y, start, 3);
        }
        else
        {
            for(int i = x; i >= a; i--)
                grid[i][b] = start++;
            b++;
            padding(grid, a, b, x, y, start, 0);
        }
        return;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        padding(res, 0, 0, n - 1, n - 1, 1, 0);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

