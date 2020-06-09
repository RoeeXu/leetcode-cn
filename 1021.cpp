/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1021.cpp
* Author:   roeexu
* Date:     2020-06-09 14:18:24
* Brief:
****************************************************/
 
class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        int cnt = 0;
        for(auto c : S)
        {
            if(c == '(') cnt++;
            else cnt--;
            if(!(cnt == 1 && c == '(') && !(cnt == 0 && c == ')')) res += c;
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

