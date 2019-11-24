/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0986.cpp
* Author:   root
* Date:     2019-11-25 05:25:51
* Brief:
****************************************************/

static auto s = [](){ ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int p = 0, q = 0, m = A.size(), n = B.size(), a, b, c, d;
        vector<vector<int>> res;
        if(n == 0 || m == 0) return res;
        while(p < m && q < n)
        {
            a = A[p][0];
            b = A[p][1];
            c = B[q][0];
            d = B[q][1];
            if((c >= a && b >= c) || (c <= a && d >= a))
                res.push_back({max(a, c), min(b, d)});
            if(b < d) p++;
            else if(b >= d) q++;
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

