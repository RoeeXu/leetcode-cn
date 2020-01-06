/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1200.cpp
* Author:   roeexu
* Date:     2020-01-06 10:51:20
* Brief:
****************************************************/
 
static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); return 0; }();

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int m = 1e7, n = arr.size();
        for(int i = 0; i < n - 1; i++)
            if(arr[i + 1] - arr[i] < m) m = arr[i + 1] - arr[i];
        vector<vector<int>> res;
        for(int i = 0; i < n - 1; i++)
            if(arr[i + 1] - arr[i] == m) res.push_back({arr[i], arr[i + 1]});
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

