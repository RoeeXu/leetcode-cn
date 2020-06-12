/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0944.cpp
* Author:   roeexu
* Date:     2020-06-12 19:56:03
* Brief:
****************************************************/
 
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n = A[0].length(), res = 0;
        if(m < 2) return 0;
        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                if(A[j - 1][i] > A[j][i]) {
                    res++;
                    break;
                }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

