/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1371.cpp
* Author:   roeexu
* Date:     2020-06-12 12:18:04
* Brief:
****************************************************/
 
class Solution {
public:
    // int findTheLongestSubstring(string s) {
    //     int n = s.length(), res = 0, now = 0;
    //     unordered_map<int, int> save;
    //     save[0] = -1;
    //     unordered_map<int, int> alpha = {{'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};
    //     for(int i = 0; i < n; i++) {
    //         if(alpha.count(s[i])) {
    //             if(save.count(now)) res = max(res, i - save[now] - 1);
    //             now ^= alpha[s[i]];
    //             if(!save.count(now)) save[now] = i;
    //         }
    //     }
    //     if(save.count(now)) res = max(res, n - save[now] - 1);
    //     return res;
    // }

    int findTheLongestSubstring(string s) {
        int ans = 0, status = 0, n = s.length();
        vector<int> pos(32, -1);
        pos[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') status ^= 1;
            else if (s[i] == 'e') status ^= 2;
            else if (s[i] == 'i') status ^= 4;
            else if (s[i] == 'o') status ^= 8;
            else if (s[i] == 'u') status ^= 16;
            if(~pos[status]) ans = max(ans, i + 1 - pos[status]);
            else pos[status] = i + 1;
        }
        return ans;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

