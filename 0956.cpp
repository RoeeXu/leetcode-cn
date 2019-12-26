/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0956.cpp
* Author:   root
* Date:     2019-12-26 08:04:58
* Brief:
****************************************************/

class Solution {
public:
    int res = 0;
    
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        if(n < 2) return 0;
        sort(rods.begin(), rods.end(), greater<int>());
        int sum = 0;
        for(int i : rods) sum += i;
        dfs(rods, 0, rods[0], 0, sum - rods[0]);
        dfs(rods, 0, 0, 0, sum - rods[0]);
        return res;
    }
    
    void dfs(vector<int>& v, int idx, int left, int right, int remain)
    {
        if(abs(left - right) > remain || left + right + remain >> 1 <= res) return;
        if(left == right && left > res) res = left;
        if(++idx == v.size()) return;
        dfs(v, idx, left + v[idx], right, remain - v[idx]);
        dfs(v, idx, left, right + v[idx], remain - v[idx]);
        dfs(v, idx, left, right, remain - v[idx]);
    }
    
//     int INF = INT_MIN / 3;
//     int memo[21][10001] = {0};

//     int tallestBillboard(vector<int>& rods) {
//         return dp(rods, 0, 5000);
//     }
    
//     int dp(vector<int>& rods, int i, int s) {
//         if(i == rods.size()) return s == 5000 ? 0 : INF;
//         else if(memo[i][s] != 0) return memo[i][s];
//         else {
//             int ans = dp(rods, i+1, s);
//             ans = max(ans, dp(rods, i+1, s-rods[i]));
//             ans = max(ans, rods[i] + dp(rods, i+1, s+rods[i]));
//             memo[i][s] = ans;
//             return ans;
//         }
//         return 0;
//     }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

