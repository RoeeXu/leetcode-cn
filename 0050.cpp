/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0050.cpp
* Author:   roee
* Date:     2019-11-19 00:47:20
* Brief:
****************************************************/

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        double tmp = myPow(x, n / 2);
        tmp *= tmp;
        if(n % 2 == 1) tmp *= x;
        if(n % 2 == -1) tmp /= x;
        return tmp;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

