/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0168.cpp
* Author:   roeexu
* Date:     2021-02-18 21:42:24
* Brief:
****************************************************/
 
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n > 0)
        {
            s += 'A' + (n - 1) % 26;
            n = (n - 1) / 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

