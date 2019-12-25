/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0955.cpp
* Author:   root
* Date:     2019-12-26 07:18:55
* Brief:
****************************************************/

class Solution {
public:
    void helper(vector<string>& A, unordered_set<int>& res, int l, int r, int pos)
    {
        if(pos == A[0].size()) return;
        if(res.count(pos) > 0) {helper(A, res, l, r, pos+1); return;}
        for(int i = l; i < r; i++)
            if(A[i][pos] > A[i+1][pos])
            {
                res.insert(pos);
                helper(A, res, l, r, pos+1);
                return;
            }
        for(int i = l; i < r; i++)
            if(A[i][pos] == A[i+1][pos])
            {
                int j = i;
                while(j <= r && A[j][pos] == A[i][pos]) j++;
                helper(A, res, i, j-1, pos+1);
                i = j-1;
            }
        return;
    }
    
    int minDeletionSize(vector<string>& A) {
        unordered_set<int> res;
        helper(A, res, 0, A.size() - 1, 0);
        return res.size();
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

