/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0057.cpp
* Author:   roeexu
* Date:     2019-11-19 13:51:47
* Brief:
****************************************************/

class Solution {
public:
    // best
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0])
            res.push_back(intervals[i++]);
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n)
            res.push_back(intervals[i++]);
        return res;
    }

    // mine
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     vector<vector<int>> ans;
    //     if(intervals.size() == 0) return intervals;
    //     sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
    //         return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
    //     });
    //     int left = intervals[0][0], right = intervals[0][1];
    //     for(int i=1;i<intervals.size();i++){
    //         if(intervals[i][0] == left)
    //             continue;
    //         else if(intervals[i][0] <= right)
    //             right = max(intervals[i][1], right);
    //         else{
    //             ans.push_back({left, right});
    //             left = intervals[i][0];
    //             right = intervals[i][1];
    //         }
    //     }
    //     ans.push_back({left, right});
    //     return ans;
    // }

    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     intervals.push_back(newInterval);
    //     return merge(intervals);
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

