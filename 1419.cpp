/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1419.cpp
* Author:   roee
* Date:     2020-07-02 00:30:26
* Brief:
****************************************************/

static const auto _ = [](){ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string pos = "croa";
        vector<int> board = {0, 0, 0, 0};
        int cnt = 0, res = 0;
        for(auto& c : croakOfFrogs) {
            int p = pos.find(c);
            if(p == 0) {
                board[0]++;
                cnt++;
            }
            else if(p > 0 && p < 4) {
                if(board[p - 1] == 0) return -1;
                board[p - 1]--;
                board[p]++;
            }
            else {
                if(board[3] == 0) return -1;
                board[3]--;
                cnt--;
            }
            res = max(res, cnt);
        }
        for(auto& b : board) if(b > 0) return -1;
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
