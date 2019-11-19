/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0056.cpp
* Author:   roeexu
* Date:     2019-11-19 13:45:36
* Brief:
****************************************************/

class Solution {
public:
    // best
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() == 0) return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
        });
        int left = intervals[0][0], right = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] == left)
                continue;
            else if(intervals[i][0] <= right)
                right = max(intervals[i][1], right);
            else{
                ans.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        ans.push_back({left, right});
        return ans;
    }

    // mine
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     map<int, int> saver;
    //     vector<int> block;
    //     int old_len = intervals.size();
    //     for(int i = 0; i < intervals.size(); i++)
    //     {
    //         if(saver.count(intervals[i][0]) > 0)
    //         {
    //             if(intervals[saver[intervals[i][0]]][1] <= intervals[i][1])
    //             {
    //                 block.push_back(saver[intervals[i][0]]);
    //                 saver[intervals[i][0]] = i;
    //             }
    //             else
    //                 block.push_back(i);
    //         }
    //         else
    //             saver[intervals[i][0]] = i;
    //     }
    //     int l, r;
    //     for(auto& p : saver)
    //     {
    //         l = p.first;
    //         r = intervals[p.second][1];
    //         for(auto& q : saver)
    //         {
    //             if(q.first <= l) continue;
    //             else if(q.first > l && q.first <= r)
    //             {
    //                 if(intervals[q.second][1] >= r)
    //                 {
    //                     intervals[p.second][1] = intervals[q.second][1];
    //                     r = intervals[q.second][1];
    //                 }
    //                 block.push_back(q.second);
    //                 saver.erase(q.first);
    //             }
    //             else break;
    //         }
    //     }
    //     sort(block.begin(), block.end(), greater<int>());
    //     for(auto p : block)
    //         intervals.erase(intervals.begin() + p);
    //     int new_len = intervals.size();
    //     if(new_len != old_len) return merge(intervals);
    //     return intervals;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

