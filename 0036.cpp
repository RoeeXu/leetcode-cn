/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0036.cpp
* Author:   roeexu
* Date:     2019/11/14 11:04:31
* Brief:
****************************************************/

// best
#define SET(num, flag) flag |= (1 << num)
#define CHECK(num, flag) flag & (1 << num)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row;
        int col[9] = {0}, matrix[9] = {0};
        for (int i = 0; i < 9; i++) {
            row = 0;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int x = board[i][j] - '0';
                int m_idx = (i / 3) * 3 + j / 3;
                if (CHECK(x,row) || CHECK(x, col[j]) || CHECK(x, matrix[m_idx]))
                    return false;
                else {
                    SET(x, row);
                    SET(x, col[j]);
                    SET(x, matrix[m_idx]);
                }
            }
        }
        return true;
    }
};

// mine
// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         // row check
//         for(int i = 0; i < 9; i++)
//         {
//             int *tmp = new int[9]();
//             for(int j = 0; j < 9; j++)
//             {
//                 int x = board[i][j] - '1';
//                 if(x < 9 && x >= 0)
//                 {
//                     if(tmp[x] == 1) return 0;
//                     else tmp[x] = 1;
//                 } 
//             }
//         }

//         // column check
//         for(int i = 0; i < 9; i++)
//         {
//             int *tmp = new int[9]();
//             for(int j = 0; j < 9; j++)
//             {
//                 int x = board[j][i] - '1';
//                 if(x < 9 && x >= 0)
//                 {
//                     if(tmp[x] == 1) return 0;
//                     else tmp[x] = 1;
//                 } 
//             }
//         }

//         // square check
//         for(int a = 0; a < 3; a++)
//             for(int b = 0; b < 3; b++)
//             {
//                 int *tmp = new int[9]();
//                 for(int i = 0; i < 3; i++)
//                 {
                    
//                     for(int j = 0; j < 3; j++)
//                     {
//                         int x = board[a * 3 + i][b * 3 + j] - '1';
//                         if(x < 9 && x >= 0)
//                         {
//                             if(tmp[x] == 1) return 0;
//                             else tmp[x] = 1;
//                         } 
//                     }
//                 }
//             }
//         return 1;
//     }
// };

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

