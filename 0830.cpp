/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0830.cpp
* Author:   root
* Date:     2019-11-25 16:23:26
* Brief:
****************************************************/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int cnt = 1, p = 1, n = S.length();
        vector<vector<int>> res;
        if(n == 0) return res;
        char tmp = S[0];
        while(p < n)
        {
            if(S[p] == tmp) cnt++;
            else
            {
                if(cnt > 2) res.push_back({p - cnt, p - 1});
                cnt = 1;
                tmp = S[p];
            }
            p++;
        }
        if(cnt > 2) res.push_back({p - cnt, p - 1});
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

