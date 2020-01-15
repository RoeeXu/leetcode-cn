/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0888.cpp
* Author:   roeexu
* Date:     2020-01-15 15:05:58
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        bool bB[100001] = {0};
        int a = 0, b = 0;
        for(auto p : A) {a += p;}
        for(auto q : B) {b += q; bB[q] = 1;}
        int c = (a + b) / 2;
        for(auto p : A) if(p - a + c >= 0 && p - a + c <= 100000 && bB[p - a + c]) return {p, p - a + c};
        return {};
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

