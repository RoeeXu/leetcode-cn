/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0010.cpp
* Author:   roee
* Date:     2019-11-18 23:18:36
* Brief:
****************************************************/

class Solution
{
public:
    bool nMatch(int *dp, string &s, string &p, int i, int j)
    {
        int n = s.length(), m = p.length(), ans;
        if (dp[i * (m + 1) + j] == -1)
        {
            if (j == m)
                ans = (i == n);
            else
            {
                bool tmp = (i < n) && ((p[j] == s[i]) || p[j] == '.');
                if (j + 1 < m && p[j + 1] == '*')
                    ans = nMatch(dp, s, p, i, j + 2) || (tmp && nMatch(dp, s, p, i + 1, j));
                else
                    ans = tmp && nMatch(dp, s, p, i + 1, j + 1);
            }
            dp[i * (m + 1) + j] = ans;
        }
        return dp[i * (m + 1) + j];
    }
    bool isMatch(string s, string p)
    {
        int n = s.length(), m = p.length();
        int *dp = new int[(n + 1) * (m + 1)];
        memset(dp, -1, (n + 1) * (m + 1) * sizeof(int));
        return nMatch(dp, s, p, 0, 0);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

