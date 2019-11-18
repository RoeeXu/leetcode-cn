/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0052.cpp
* Author:   roee
* Date:     2019-11-19 01:34:44
* Brief:
****************************************************/

typedef long long LL;

class Solution {
public:
    // best
    int totalNQueens(int n) {
        int res = 0;
        dfs(n, 0, 0, 0, 0, res);
        return res;
    }
    
    void dfs(int& n, int row, int col, int ld, int rd, int& res) {
        if (row >= n) { res++; return; }
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0) {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1, res);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }

    // mine
    // void backtracking(int& res, LL& col, LL& lef, LL& rig, int *tmp, int pos, int n)
    // {
    //     if(pos == n)
    //     {
    //         res++;
    //         return;
    //     }
    //     for(int i = 0; i < n; i++)
    //     {
    //         if((col >> i) & 1) continue;
    //         if((lef >> (n - 1 - i + pos)) & 1) continue;
    //         if((rig >> (i + pos)) & 1) continue;
    //         col |= 1 << i;
    //         lef |= 1 << (n - 1 - i + pos);
    //         rig |= 1 << (i + pos);
    //         tmp[pos] = i;
    //         backtracking(res, col, lef, rig, tmp, pos + 1, n);
    //         col &= ~(1 << i);
    //         lef &= ~(1 << (n - 1 - i + pos));
    //         rig &= ~(1 << (i + pos));
    //         tmp[pos] = -1;
    //     }
    //     return;
    // }

    // int totalNQueens(int n) {
    //     int res = 0;
    //     LL col = 0, lef = 0, rig = 0;
    //     int *tmp = new int[n]();
    //     backtracking(res, col, lef, rig, tmp, 0, n);
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

