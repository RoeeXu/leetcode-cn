/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0424.cpp
* Author:   root
* Date:     2021-07-28 01:07:21
* Brief:
****************************************************/
 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        int cnt[26] = {0};
        int n = s.length();
        int maxn = 0;
        while (right < n)
        {
            cnt[s[right] - 'A']++;
            maxn = max(maxn, cnt[s[right] - 'A']);
            if (right - left + 1 - maxn > k)
            {
                cnt[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

