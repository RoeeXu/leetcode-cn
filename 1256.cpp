/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1256.cpp
* Author:   roeexu
* Date:     2019-11-18 13:49:00
* Brief:
****************************************************/

class Solution {
public:
    string encode(int num) {
        string res;
        for(num += 1; num > 1; num >>= 1)
            res.insert(res.begin(), num % 2 + '0');
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

