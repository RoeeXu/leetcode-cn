/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0003.cpp
* Author:   roee
* Date:     2019-11-18 23:15:20
* Brief:
****************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.length();
        int res = 0, tmp = 0;
        int save[128] = {0};
        while (r < n)
        {
            while (r < n && save[s[r]] == 0)
            {
                save[s[r++]] = 1;
                tmp++;
            }
            res = max(res, tmp);
            if (r == n) return res;
            while (s[l] != s[r])
            {
                save[s[l++]] = 0;
                tmp--;
            }
            l++;
            r++;
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> tp;
        int n = s.length(), res = 0;
        int head = 0, tail = 0;
        char tmp;
        if(n == 0) return 0;
        for(int i = 0;i < n;i++)
        {
            tmp = s[i];
            if(tp.count(tmp) == 0 || tp[tmp] < head)
            {
                tp[tmp] = i;
                tail = i;
            }
            else
            {
                head = tp[tmp] + 1;
                tp[tmp] = i;
                tail = i;
            }
            if(tail - head + 1 > res) res = tail - head + 1;
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

