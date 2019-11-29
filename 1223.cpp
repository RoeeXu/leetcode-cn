/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1223.cpp
* Author:   roeexu
* Date:     2019-11-29 13:43:22
* Brief:
****************************************************/

const int Mod = 1e9 + 7;
using ll = long long;

class Solution {
public:
    //sum[n][0] 表示n个的总数，sum[n][1] 表示n个数中以1结尾的总个数
    ll sum[5005][7];
    int dieSimulator(int n, vector<int>& rollMax) {
        if (n == 1) return 6;
        memset(sum, 0, sizeof(sum));
        sum[1][0] = 6; sum[0][0] = 1;
        for (int i = 1; i < 7; ++i) sum[1][i] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < 7; ++j) {
                int cur = rollMax[j - 1];
                (sum[i][j] += sum[i - 1][0] - sum[i - 1][j]) %= Mod;
                if (cur >= i) (sum[i][j] += sum[i - 1][j]) %= Mod;
                else if (cur > 1) {
                    (sum[i][j] += sum[i - 1][j] - sum[i - cur - 1][0] + sum[i - cur - 1][j]) %= Mod;
                    if (sum[i][j] < 0) sum[i][j] += Mod;
                }
                (sum[i][0] += sum[i][j]) %= Mod;
            }
        }
        return sum[n][0];
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

