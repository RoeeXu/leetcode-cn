/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0076.cpp
* Author:   root
* Date:     2019-11-22 04:53:01
* Brief:
****************************************************/

class Solution {
public:
    // string minWindow(string s, string t) {
    //     int n = s.length(), required = 0, l = 0, r = 0, formed = 0, res = n + 1, lm = -1, rm = -1;
    //     int dic[128] = { 0 };
    //     char tmp;
    //     for(auto x : t)
    //         if(dic[x] > 0) dic[x]++;
    //         else { required++; dic[x] = 1; }
    //     int cnt[128] = { 0 };
    //     while(r < n)
    //     {
    //         tmp = s[r];
    //         if(cnt[tmp] > 0) cnt[tmp] += 1;
    //         else cnt[tmp] = 1;
    //         if(dic[tmp] > 0 && cnt[tmp] == dic[tmp]) formed++;
    //         while(l <= r && formed == required)
    //         {
    //             tmp = s[l];
    //             cnt[tmp] -= 1;
    //             if(dic[tmp] > 0 && cnt[tmp] < dic[tmp])
    //             {
    //                 formed--;
    //                 if(r - l + 1 < res)
    //                 {
    //                     res = r - l + 1;
    //                     lm = l;
    //                     rm = r;
    //                 }
    //             }
    //             l++;
    //         }
    //         r++;
    //     }
    //     return (lm == -1) ? "" : s.substr(lm, res);
    // }

    string minWindow(string s, string t) {
        int count[128] = { 0 };
        for (auto c : t) ++count[c];
        int len = 0, minLength = s.length();
        int lm = -1;
        for (int l = 0, r = 0; r < s.length(); ++r) {
            if (--count[s[r]] >= 0) ++len;
            while (len == t.length()) {
                if (r - l + 1 <= minLength) {
                    minLength = r - l + 1;
                    lm = l;
                }
                if (++count[s[l++]] > 0) --len;
            }
        }
        return (lm == -1) ? "" : s.substr(lm, minLength);
    }
};
        

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

