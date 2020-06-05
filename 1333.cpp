/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1333.cpp
* Author:   roeexu
* Date:     2020-06-05 11:28:37
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> filter;
        for(auto& r : restaurants) {
            if(veganFriendly && !r[2]) continue;
            if(r[3] > maxPrice || r[4] > maxDistance) continue;
            filter.push_back({-r[1], -r[0]});
        }
        sort(filter.begin(), filter.end());
        vector<int> res;
        for(auto& t : filter) res.push_back(-t.second);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

