/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0898.cpp
* Author:   roeexu
* Date:     2019-11-28 20:49:31
* Brief:
****************************************************/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        vector<int> res;
        for (auto i = 0, st = 0, en = 0; i < A.size(); ++i, st = en, en = res.size()) {
            res.push_back(A[i]);
            for (auto j = st; j < en; ++j)
                if (res.back() != (res[j] | A[i])) res.push_back(res[j] | A[i]);
        }
        return unordered_set<int>(begin(res), end(res)).size();
      }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

