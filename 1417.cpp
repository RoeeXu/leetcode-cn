/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1417.cpp
* Author:   roee
* Date:     2020-07-02 00:22:33
* Brief:
****************************************************/

class Solution {
public:
    string reformat(string s) {
        int p = 0, q = 0, n = s.length();
        string res = "";
        while(res.length() < n) {
            while(p < n && !(s[p] >= '0' && s[p] <= '9')) p++;
            if(p < n) res += s[p++];
            else break;
            while(q < n && !(s[q] >= 'a' && s[q] <= 'z')) q++;
            if(q < n) res += s[q++];
            else break;
        }
        while(q < n && !(s[q] >= 'a' && s[q] <= 'z')) q++;
        if(q < n) res = s[q++] + res;
        if(res.length() == n) return res;
        return "";
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
