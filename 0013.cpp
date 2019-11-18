/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0013.cpp
* Author:   roee
* Date:     2019-11-18 23:21:36
* Brief:
****************************************************/

class Solution {
public:
    int romanToInt(string s) {
        int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string reps[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int res = 0;
        for (int i = 0; i < 13; i++)
        {
            while (s.find(reps[i]) == 0){
                s = s.substr(reps[i].length());
                res += values[i];
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

