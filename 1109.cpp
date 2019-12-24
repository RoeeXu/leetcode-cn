/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1109.cpp
* Author:   roeexu
* Date:     2019-12-24 19:54:36
* Brief:
****************************************************/

// bool cmp(const vector<int>& x, const vector<int>& y)
// {
//     if(x[0] < y[0] || (x[0] == y[0] && x[1] < y[1])) return 1;
//     return 0;
// }

class Solution {
public:
    // best
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n + 1,0);
        for(auto a : bookings){
            res[a[0] - 1] += a[2];
            res[a[1]] -= a[2];
        }
        for(int i = 1; i < n; i++) res[i] += res[i - 1];
        res.pop_back();
        return res;
    }
    
    // mine
    // vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    //     vector<int> res;
    //     int p = 0, v = 0;
    //     unordered_map<int, int> save;
    //     sort(bookings.begin(), bookings.end(), cmp);
    //     for(auto a : bookings)
    //     {
    //         if(save.count(a[1]) == 0) save[a[1]] = 0;
    //         save[a[1]] += a[2];
    //         while(p != a[0])
    //         {
    //             res.push_back(v);
    //             if(save.count(p) > 0) v -= save[p];
    //             p++;
    //         }
    //         v += a[2];
    //     }
    //     while(p <= n)
    //     {
    //         res.push_back(v);
    //         if(save.count(p) > 0) v -= save[p];
    //         p++;
    //     }
    //     res.erase(res.begin());
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

