/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0853.cpp
* Author:   root
* Date:     2019-11-25 11:06:12
* Brief:
****************************************************/

static const auto io_speed_up=[] { ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        vector<double> times;
        int n = position.size(), ans = 1;
        if(n == 0) return 0;
        double lead;
        for(int i = 0; i < n; i++)
            cars.push_back({position[i], speed[i]});
        sort(cars.begin(), cars.end());
        for(auto& c : cars)
            times.push_back((double)(target - c.first) / c.second);
        lead = times.back();
        for (int i = times.size() - 1; i >= 0; i--) {
            if (times[i] <= lead) continue;
            else {
                ans++;
                lead = times[i];
            }
        }
        return ans;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

