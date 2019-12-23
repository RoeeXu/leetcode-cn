/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1288.cpp
* Author:   roeexu
* Date:     2019-12-23 11:08:34
* Brief:
****************************************************/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int ans = n;
        int rmax = intervals[0][1];
        for (int i = 1; i < n; ++i)
            if (intervals[i][1] <= rmax) ans--;
            else rmax = intervals[i][1];
        return ans;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

