/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     lcp3.cpp
* Author:   roeexu
* Date:     2019-11-18 22:31:50
* Brief:
****************************************************/

typedef unsigned long long ULL;

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        unordered_map<ULL, bool> saver;
        ULL a = 0, b = 0;
        ULL tmp = 0, target, block;
        saver[tmp] = 1;
        int n = command.length();
        int m = obstacles.size();
        for(int i = 0; i < n; i++)
        {
            if(command[i] == 'R')
                tmp += (1 << 30);
            else
                tmp += 1;
            saver[tmp] = 1;
        }
        target = ((ULL)x << 30) + (ULL)y;
        if(saver.count(target % tmp) == 0) return 0;
        for(int i = 0; i < m; i++)
        {
            block = ((ULL)obstacles[i][0] << 30) + (ULL)obstacles[i][1];
            if(block > target) continue;
            if(saver.count(block % tmp) > 0) return 0;
        }
        return 1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

