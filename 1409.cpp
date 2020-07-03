/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1409.cpp
* Author:   roeexu
* Date:     2020-06-24 15:57:53
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> res;
        vector<int> q;
        for(int i = 1; i <= m; i++) q.push_back(i);
        for(auto& x : queries) {
            int idx = find(q.begin(), q.end(), x) - q.begin();
            res.push_back(idx);
            q.erase(q.begin() + idx);
            q.insert(q.begin(), x);
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

