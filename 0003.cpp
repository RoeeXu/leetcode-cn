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

