/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1725.cpp
* Author:   roeexu
* Date:     2021-01-20 14:21:21
* Brief:
****************************************************/
 
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> s;
        for(auto& x: rectangles)
            s.push_back(min(x[0], x[1]));
        int value = s[0];
        for(auto x : s) if(x > value) value = x;
        int r = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == value) r++;
        return r;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

