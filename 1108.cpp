/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1108.cpp
* Author:   roeexu
* Date:     2019-12-24 17:00:00
* Brief:
****************************************************/

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for(auto c : address)
            if(c == '.') res += "[.]";
            else res += c;
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

