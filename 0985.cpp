/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0985.cpp
* Author:   root
* Date:     2019-11-25 05:20:01
* Brief:
****************************************************/

static auto s = [](){ ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int s = 0, m, n;
        vector<int> res;
        for(auto a : A) s += a % 2 ? 0 : a;
        for(auto& p : queries) {
            m = (A[p[1]] > 0 ? A[p[1]] : -A[p[1]]) % 2;
            n = (p[0] > 0 ? p[0] : -p[0]) % 2;
            s += n * (2 * m - 1) * A[p[1]] + ((1 - m) ^ n) * p[0];
            A[p[1]] += p[0];
            res.push_back(s);
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

