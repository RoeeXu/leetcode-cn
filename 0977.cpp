/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0977.cpp
* Author:   roeexu
* Date:     2019-12-24 10:56:40
* Brief:
****************************************************/

static const auto init = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        vector<int> res(A.size(), 0);
        int i = 0;
        int j = A.size() - 1;
        int k = A.size() - 1;
        while (i <= j)
        {
            int x = A[j] * A[j], y = A[i] * A[i];
            res[k--] = x > y ? (j--, x) : (i++, y);
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

