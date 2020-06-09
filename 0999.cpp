/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0999.cpp
* Author:   roeexu
* Date:     2020-06-09 18:16:40
* Brief:
****************************************************/
 
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x = -1, y = -1;
        for(int i = 0; i < 8 && x == -1; i++)
            for(int j = 0; j < 8 && x == -1; j++)
                if(board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                    break;
                }
        int res = 0;
        for(int i = x+1; i < 8; i++)
        {
            if(board[i][y] == '.') continue;
            else if(board[i][y] == 'p') {res++; break;}
            else break;
        }
        for(int i = x-1; i >= 0; i--)
        {
            if(board[i][y] == '.') continue;
            else if(board[i][y] == 'p') {res++; break;}
            else break;
        }
        for(int i = y+1; i < 8; i++)
        {
            if(board[x][i] == '.') continue;
            else if(board[x][i] == 'p') {res++; break;}
            else break;
        }
        for(int i = y-1; i >= 0; i--)
        {
            if(board[x][i] == '.') continue;
            else if(board[x][i] == 'p') {res++; break;}
            else break;
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

