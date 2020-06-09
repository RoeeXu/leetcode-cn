/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1001.cpp
* Author:   roeexu
* Date:     2020-06-09 19:39:44
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> X, Y, D, B;
        vector<int> res;
        set<tuple<int, int>> save;
        int x, y;
        for(auto& l : lamps) {
            x = l[0];
            y = l[1];
            if(X.count(x)) X[x]++;
            else X[x] = 1;
            if(Y.count(y)) Y[y]++;
            else Y[y] = 1;
            if(D.count(x + y)) D[x + y]++;
            else D[x + y] = 1;
            if(B.count(x - y)) B[x - y]++;
            else B[x - y] = 1;
            save.insert({x, y});
        }
        int a, b;
        for(auto& q : queries) {
            x = q[0];
            y = q[1];
            if(X.count(x) || Y.count(y) || D.count(x + y) || B.count(x - y)) res.push_back(1);
            else res.push_back(0);
            if(res.back() == 1) {
                for(int i = -1; i < 2; i++)
                    for(int j = -1; j < 2; j++) {
                        a = x + i;
                        b = y + j;
                        if(save.count({a, b})) {
                            if(--X[a] == 0) X.erase(a);
                            if(--Y[b] == 0) Y.erase(b);
                            if(--D[a + b] == 0) D.erase(a + b);
                            if(--B[a - b] == 0) B.erase(a - b);
                            save.erase({a, b});
                        }
                    }
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

