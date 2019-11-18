/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0009.cpp
* Author:   roee
* Date:     2019-11-18 23:18:20
* Brief:
****************************************************/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return 0;
        int tmp = 0;
        while (x > tmp)
        {
            tmp = tmp * 10 + x % 10;
            x /= 10;
        }
        return x == tmp || x == tmp / 10;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

