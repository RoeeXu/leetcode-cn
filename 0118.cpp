/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0118.cpp
* Author:   root
* Date:     2019-12-05 01:33:30
* Brief:
****************************************************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0) return {};
        vector<int> r;
        r.push_back(1);
        res.push_back(r);
        for(int i = 1; i < numRows; i++)
        {
            r.push_back(0);
            for(int j = r.size() - 1; j > 0; j--) r[j] += r[j-1];
            res.push_back(r);
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

