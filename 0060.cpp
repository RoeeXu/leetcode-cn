/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0060.cpp
* Author:   roee
* Date:     2019-11-20 01:09:20
* Brief:
****************************************************/

class Solution {
public:
    string getPermutation(int n, int k) {
        string tmp = "123456789";
        int frac = 1;
        for(int i = 1; i < n; i++)
            frac *= i;
        k--;
        string res = "";
        int pos, flag = n - 1;
        while(tmp.size() > 9 - n)
        {
            if(flag > 0)
            {
                pos = k / frac;
                k = k % frac;
                frac /= flag;
                flag--;
            }
            else pos = 0;
            res += tmp[pos];
            tmp.erase(tmp.begin() + pos);
            
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

