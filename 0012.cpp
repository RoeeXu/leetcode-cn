/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0012.cpp
* Author:   roee
* Date:     2019-11-18 23:21:20
* Brief:
****************************************************/

class Solution
{
public:
    string intToRoman(int num)
    {
        int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string reps[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res = "";
        for (int i = 0; i < 13; i++)
        {
            while (num >= values[i])
            {
                num -= values[i];
                res += reps[i];
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

