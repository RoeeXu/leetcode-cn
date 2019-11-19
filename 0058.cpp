/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0058.cpp
* Author:   roee
* Date:     2019-11-19 23:38:16
* Brief:
****************************************************/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), p = n - 1;
        while(p >= 0 && s[p] == ' ') p--;
        if(p == -1) return 0;
        n = p;
        while(p >= 0 && s[p] != ' ') p--;
        return n - p;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

