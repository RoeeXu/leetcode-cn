/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0037.cpp
* Author:   roeexu
* Date:     2019/11/15 10:36:31
* Brief:
****************************************************/

#include <iostream>
#include <vector>
#define cz(x, p) (((x) & (1 << (p))) >> (p)) == 0

using namespace std;

class Solution {
public:
    int *row  = new int[9]();
    int *column  = new int[9]();
    int *square  = new int[9]();

    void print_board(vector<vector<char> >& board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }

    int dp(vector<vector<char> >& board, int i, int j)
    {
        if(i == 8 && j == 9) return 1;
        if(i < 8 && j == 9) return dp(board, i + 1, 0);
        if(board[i][j] != '.') return dp(board, i, j + 1);
        int idx = 3 * (int)(i / 3) + (int)(j / 3);
        for(int k = 0; k < 9; k++)
            if(cz(row[i], k) && cz(column[j], k) && cz(square[idx], k))
            {
                board[i][j] = k + '1';
                int tmp = 1 << k;
                row[i] |= tmp;
                column[j] |= tmp;
                square[idx] |= tmp;
                // cout << i << ' ' << j << ' ' << k << endl;
                // print_board(board);
                int flag = dp(board, i, j + 1);
                if(flag) return flag;
                row[i] &= ~tmp;
                column[j] &= ~tmp;
                square[idx] &= ~tmp;
                board[i][j] = '.';
            }
        return 0;
    }

    void solveSudoku(vector<vector<char> >& board) {
        int tmp, idx;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] != '.')
                {
                    tmp = 1 << (board[i][j] - '1');
                    row[i] |= tmp;
                    column[j] |= tmp;
                    idx = 3 * (int)(i / 3) + (int)(j / 3);
                    square[idx] |= tmp;
                }
        dp(board, 0, 0);
        print_board(board);
    }
};


int main(){
	vector<vector<char> > board;
    vector<char> b;
    b.clear();
    b.push_back('5');
    b.push_back('3');
    b.push_back('.');
    b.push_back('.');
    b.push_back('7');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    board.push_back(b);
    b.clear();
    b.push_back('6');
    b.push_back('.');
    b.push_back('.');
    b.push_back('1');
    b.push_back('9');
    b.push_back('5');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    board.push_back(b);
    b.clear();
    b.push_back('.');
    b.push_back('9');
    b.push_back('8');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('6');
    b.push_back('.');
    board.push_back(b);
    b.clear();
    b.push_back('8');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('6');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('3');
    board.push_back(b);
    b.clear();
    b.push_back('4');
    b.push_back('.');
    b.push_back('.');
    b.push_back('8');
    b.push_back('.');
    b.push_back('3');
    b.push_back('.');
    b.push_back('.');
    b.push_back('1');
    board.push_back(b);
    b.clear();
    b.push_back('7');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('2');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('6');
    board.push_back(b);
    b.clear();
    b.push_back('.');
    b.push_back('6');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('2');
    b.push_back('8');
    b.push_back('.');
    board.push_back(b);
    b.clear();
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('4');
    b.push_back('1');
    b.push_back('9');
    b.push_back('.');
    b.push_back('.');
    b.push_back('5');
    board.push_back(b);
    b.clear();
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('.');
    b.push_back('8');
    b.push_back('.');
    b.push_back('.');
    b.push_back('7');
    b.push_back('9');
    board.push_back(b);
	Solution solver = Solution();
	solver.solveSudoku(board);
}



















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
