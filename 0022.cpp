/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0022.cpp
* Author:   roee
* Date:     2019-11-18 23:25:17
* Brief:
****************************************************/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return res;
        N=n;
        dnf(0,0,"");
        return res;
    }
    vector<string> res;
    int N;
    void dnf(int r,int l,string has)
    {
        if(l>r) return;
        if(r>N) return;
        if(l==N &&r==N)
        {
            res.push_back(has);
            return;
        }
        dnf(r+1,l,has+'(');
        dnf(r,l+1,has+')');
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

