/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1122.cpp
* Author:   root
* Date:     2021-04-24 14:09:24
* Brief:
****************************************************/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<pair<int, int>> line;
        unordered_map<int, int> rank;
        for(int i = 0; i < arr2.size(); i++) rank[arr2[i]] = i;
        for(int i = 0; i < arr1.size(); i++)
            if(rank.count(arr1[i])) line.push_back({rank[arr1[i]], arr1[i]});
            else line.push_back({(int)rank.size(), arr1[i]});
        sort(line.begin(), line.end());
        vector<int> res;
        for(auto x : line) res.push_back(x.second);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
