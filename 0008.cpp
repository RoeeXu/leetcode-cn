/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0008.cpp
* Author:   roee
* Date:     2019-11-18 23:18:09
* Brief:
****************************************************/

class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int k = 0;
        int flag = 1;
        while(str[k] == ' ') k++;
        if(str[k] != '+' && str[k] != '-' && (str[k] < '0' || str[k] > '9')) return 0;
        if(str[k] == '-') flag = -1;
        if(str[k] == '+' || str[k] == '-') k++;
        while(str[k] >= '0' && str[k] <= '9')
        {
            res *= 10;
            res += flag * (str[k] - '0');
            k++;
            if(res > INT_MAX) return INT_MAX;
            if(res < INT_MIN) return INT_MIN;
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

