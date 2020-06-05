/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1332.cpp
* Author:   roeexu
* Date:     2020-06-05 11:14:12
* Brief:
****************************************************/
 
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length() == 0) return 0;
        for(int l = 0, r = s.length() - 1; l <= r; l++, r--)
            if(s[l] != s[r]) return 2;
        return 1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

