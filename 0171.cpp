/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0171.cpp
* Author:   roeexu
* Date:     2021-02-19 16:45:26
* Brief:
****************************************************/
 
class Solution {
public:
    int titleToNumber(string s) {
        int r = 0;
        for(auto c : s) r = r * 26 + (c - '@');
        return r;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

