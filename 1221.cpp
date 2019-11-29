/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1221.cpp
* Author:   roeexu
* Date:     2019-11-29 12:58:54
* Brief:
****************************************************/

class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0, r = 0, res = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'L') l++;
            else r++;
            if(l == r)
            {
                l = r = 0;
                res++;
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

