/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0991.cpp
* Author:   roee
* Date:     2020-07-02 02:00:24
* Brief:
****************************************************/

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X >= Y) return X - Y;
        else if(Y % 2 == 0) return brokenCalc(X, Y / 2) + 1;
        else return brokenCalc(X, Y + 1) + 1;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
