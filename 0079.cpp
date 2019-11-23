/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0079.cpp
* Author:   root
* Date:     2019-11-24 03:12:22
* Brief:
****************************************************/

int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
    int m, n, k;

    bool backtracking(vector<vector<char>>& board, string& word, int pos, int x, int y)
    {
        if(x < 0 || x >= m || y < 0 || y >= n) return 0;
        if(board[x][y] != word[pos] || board[x][y] == 0) return 0;
        if(pos == k - 1) return 1;
        char c = board[x][y];
        board[x][y] = 0;
        for(int i = 0; i < 4; i++)
            if(backtracking(board, word, pos + 1, x + d[i][0], y + d[i][1]))
                return 1;
        board[x][y] = c;
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        k = word.length();
        if(m == 0) return k == 0;
        n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(backtracking(board, word, 0, i, j))
                    return 1;
        return 0;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

