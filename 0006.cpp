/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0006.cpp
* Author:   roee
* Date:     2019-11-18 23:17:33
* Brief:
****************************************************/

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), gap = 2*numRows-2, r = numRows;
        if(r == 1) return s;
        string res(n, ' ');
        int k = 0;
        for(int i=0;i<n;i+=gap) res[k++] = s[i];
        for(int j=1;j<r-1;j++)
        {
            int tmp = (j<<1);
            for(int i=j;i<n;i+=tmp)
            {
                res[k++] = s[i];
                tmp = gap - tmp;
            }
        }
        for(int i=r-1;i<n;i+=gap) res[k++] = s[i];
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

