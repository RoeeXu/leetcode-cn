/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1042.cpp
* Author:   roeexu
* Date:     2020-06-10 11:05:35
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N);
        vector<int> res(N, 0);
        for(auto& p : paths) {
            graph[p[0] - 1].push_back(p[1] - 1);
            graph[p[1] - 1].push_back(p[0] - 1);
        }
        for(int i = 0; i < N; i++) {
            set<int> cands = {1, 2, 3, 4};
            for(auto& x : graph[i]) cands.erase(res[x]);
            res[i] = *cands.begin();
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

