/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0899.cpp
* Author:   roeexu
* Date:     2019-11-28 20:35:49
* Brief:
****************************************************/

class Solution {
public:
    string orderlyQueue(string S, int K) {
        string res = S, s;
        if(K == 1)
            for(int i = 0; i < S.length(); i++) {
                char tmp = S[0];
                S = S.substr(1) + tmp;
                if(S < res) res = S;
            }
        else sort(res.begin(), res.end());
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

