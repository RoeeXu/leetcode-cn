/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0997.cpp
* Author:   roeexu
* Date:     2020-06-09 18:14:47
* Brief:
****************************************************/
 
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N == 1) return 1;
        int *p = new int[N + 1]();
        for(auto& q : trust)
        {
            p[q[1]]++;
            p[q[0]]--;
        }
        for(int i = 1; i <= N; i++) if(p[i] == N - 1) return i;
        return -1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

