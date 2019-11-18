/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     lcp1.cpp
* Author:   roeexu
* Date:     2019-11-18 22:29:54
* Brief:
****************************************************/

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int res = 0;
        for(int i = 0; i < 3; i++)
            res += (int)(guess[i] == answer[i]);
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

