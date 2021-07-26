/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0005.cpp
* Author:   roee
* Date:     2019-11-18 23:17:03
* Brief:
****************************************************/

// cut extend O(n) O(n) 8ms
class Solution {
public:
    int mid_extend_len(string& s, int l, int r)
    {
        while (l >= 0 && r < s.length() && s[l] == s[r]) { l--; r++; }
        return (r - l - 2) / 2;
    }

    string longestPalindrome(string s) {
        string t = "#";
        for (auto c : s)
        {
            t += c;
            t += '#';
        }
        s = t;
        int right = -1, j = -1;
        int pos = 0, res = 1;
        vector<int> save;
        for (int i = 0; i < s.length(); i++)
        {
            int len = 0;
            if (right > i)
            {
                int gap = min(save[2 * j - i], right - i);
                len = mid_extend_len(s, i - gap, i + gap);
            }
            else
            {
                len = mid_extend_len(s, i, i);
            }
            save.push_back(len);
            if (i + len > right)
            {
                right = i + len;
                j = i;
            }
            if (2 * len + 1 > res)
            {
                res = 2 * len + 1;
                pos = i - len;
            }
        }
        string a = "";
        for (int i = pos; i < pos + res; i++)
            if (s[i] != '#')
                a += s[i];
        return a;
    }
};


// // extend O(n^2) O(1) 20ms
// class Solution {
// public:
//     pair<int, int> mid_extend(string& s, int l, int r)
//     {
//         while (l >= 0 && r < s.length() && s[l] == s[r]) { l--; r++; }
//         return {l + 1, r - 1};
//     }

//     string longestPalindrome(string s) {
//         int pos = 0, res = 1;
//         for (int i = 0; i < s.length() - 1; i++)
//         {
//             auto [x1, y1] = mid_extend(s, i, i);
//             auto [x2, y2] = mid_extend(s, i, i + 1);
//             if (y1 - x1 >= res)
//             {
//                 res = y1 - x1 + 1;
//                 pos = x1;
//             }
//             if (y2 - x2 >= res)
//             {
//                 res = y2 - x2 + 1;
//                 pos = x2;
//             }
//         }
//         return s.substr(pos, res);
//     }
// };


// // dp O(n^2) O(n^2) 220ms
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         if (n < 2)
//             return s;
//         bool dp[1001][1001];
//         memset(dp, 0, sizeof(dp));
//         for (int i = 0; i < n - 1; i++)
//         {
//             dp[i][i] = true;
//             dp[i][i + 1] = (s[i] == s[i + 1]);
//         }
//         dp[n - 1][n - 1] = true;
//         for (int L = 3; L <= n; L++)
//             for (int i = 0; i < n + 1 - L; i++)
//                 dp[i][i + L - 1] = dp[i + 1][i + L - 2] & (s[i] == s[i + L - 1]);
//         int res = 0, pos = -1;
//         for (int i = 0; i < n; i++)
//             for (int j = i + res; j < n; j++)
//                 if (dp[i][j])
//                 {
//                     int l = j - i + 1;
//                     if (l > res)
//                     {
//                         res = l;
//                         pos = i;
//                     }
//                 }
//         return s.substr(pos, res);
//     }
// };

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

