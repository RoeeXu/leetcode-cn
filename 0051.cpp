/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0051.cpp
* Author:   roee
* Date:     2019-11-19 01:23:02
* Brief:
****************************************************/

typedef long long LL;

class Solution {
public:
    void backtracking(vector<vector<string>>& res, LL& col, LL& lef, LL& rig, int *tmp, int pos, int n)
    {
        if(pos == n)
        {
            vector<string> re;
            for(int i = 0; i < n; i++)
            {
                string r = "";
                for(int j = 0; j < n; j++)
                    if(j == tmp[i]) r += "Q";
                    else r += ".";
                re.push_back(r);
            }
            res.push_back(re);
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if((col >> i) & 1) continue;
            if((lef >> (n - 1 - i + pos)) & 1) continue;
            if((rig >> (i + pos)) & 1) continue;
            col |= 1 << i;
            lef |= 1 << (n - 1 - i + pos);
            rig |= 1 << (i + pos);
            tmp[pos] = i;
            backtracking(res, col, lef, rig, tmp, pos + 1, n);
            col &= ~(1 << i);
            lef &= ~(1 << (n - 1 - i + pos));
            rig &= ~(1 << (i + pos));
            tmp[pos] = -1;
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        LL col = 0, lef = 0, rig = 0;
        int *tmp = new int[n]();
        backtracking(res, col, lef, rig, tmp, 0, n);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

