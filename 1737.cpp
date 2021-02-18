/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1737.cpp
* Author:   roeexu
* Date:     2021-01-29 17:32:16
* Brief:
****************************************************/
 
class Solution {
public:
    int minCharacters(string a, string b) {
        int x[26], y[26], tmp, r1, r2, r3;
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        for(auto c : a) x[c - 'a']++;
        for(auto c : b) y[c - 'a']++;
        r1 = accumulate(x, x+26, 0) + accumulate(y, y+26, 0) - *max_element(x, x+26) - *max_element(y, y+26);
        r3 = r2 = 100001;
        for(int i = 0; i < 25; i++)
        {
            tmp = accumulate(x+i+1, x+26, 0) + accumulate(y, y+i+1, 0);
            if(tmp < r2) r2 = tmp;
        }
        for(int i = 0; i < 25; i++)
        {
            tmp = accumulate(y+i+1, y+26, 0) + accumulate(x, x+i+1, 0);
            if(tmp < r3) r3 = tmp;
        }
        return r1 < r2 && r1 < r3 ? r1 : (r2 < r3 ? r2 : r3);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

