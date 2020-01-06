/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1202.cpp
* Author:   roeexu
* Date:     2020-01-06 15:02:20
* Brief:
****************************************************/
 
static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); return 0; }();

class Solution {
public:
    vector<int> root;
    
    int find(int x) {
        return x == root[x] ? x : root[x] = find(root[x]);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        root = vector<int>(n);
        for(int i = 0; i < n; i++) root[i] = i;
        for(auto& p : pairs) root[find(p[0])] = find(p[1]);
        for(int i = 0; i < n; i++) root[i] = find(i);
        vector<string> group(n);
        for(int i = 0; i < n; i++) group[root[i]] += s[i];
        for(int i = 0; i < group.size(); i++) sort(group[i].begin(), group[i].end(), greater<char>());
        for(int i = 0; i < n; i++) {
            s[i] = group[root[i]].back(); 
            group[root[i]].pop_back();
        }
        return s;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

