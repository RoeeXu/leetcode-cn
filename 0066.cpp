/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0066.cpp
* Author:   roeexu
* Date:     2019-11-21 15:20:40
* Brief:
****************************************************/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int p = digits.size() - 1;
        int up = 1;
        while(p >= 0)
        {
            digits[p] += up;
            if(digits[p] > 9)
            {
                digits[p] = 0;
                up = 1;
            }
            else
            {
                up = 0;
                break;
            }
            p -= 1;
        }
        if(up == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

