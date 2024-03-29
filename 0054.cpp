/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0054.cpp
* Author:   roeexu
* Date:     2019-11-19 10:31:40
* Brief:
****************************************************/

class Solution {
public:
    void helper(vector<vector<int>>& mat, vector<int>& res, int a, int b, int c, int d)
    {
        for (int j = b; j <= d; j++)
            res.push_back(mat[a][j]);
        for (int i = a + 1; i <= c; i++)
            res.push_back(mat[i][d]);
        if (a < c)
            for (int j = d - 1; j >= b; j--)
                res.push_back(mat[c][j]);
        if (b < d)
            for (int i = c - 1; i >= a + 1; i--)
                res.push_back(mat[i][b]);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size(), r = 0;
        while (2 * r <= min(m, n) - 1)
        {
            helper(matrix, res, r, r, m - 1 - r, n - 1 - r);
            r++;
        }
        return res;
    }
};

class Solution {
public:
    void helper(vector<vector<int>>& matrix, int a, int b, int x, int y, int f, vector<int>& res)
    {
        if(a > x || b > y) return;
        if(f == 0)
        {
            for(int i = b; i <= y; i++)
                res.push_back(matrix[a][i]);
            a++;
        }
        else if(f == 1)
        {
            for(int i = a; i <= x; i++)
                res.push_back(matrix[i][y]);
            y--;
        }
        else if(f == 2)
        {
            for(int i = y; i >= b; i--)
                res.push_back(matrix[x][i]);
            x--;
        }
        else
        {
            for(int i = x; i >= a; i--)
                res.push_back(matrix[i][b]);
            b++;
        }
        helper(matrix, a, b, x, y, (f + 1) % 4, res);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        helper(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, 0, res);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

