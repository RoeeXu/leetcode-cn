/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0119.cpp
* Author:   root
* Date:     2019-12-06 02:31:30
* Brief:
****************************************************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r;
        r.push_back(1);
        for(int i = 0; i < rowIndex; i++)
        {
            r.push_back(0);
            for(int j = r.size() - 1; j > 0; j--) r[j] += r[j-1];
        }
        return r;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

