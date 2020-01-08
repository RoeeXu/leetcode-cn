/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0854.cpp
* Author:   roeexu
* Date:     2020-01-08 11:24:22
* Brief:
****************************************************/
 
class Solution {
public:
    int helper(string& A, string& B, int p, int k) {
        int n = A.length(), res = 10000, tmp, q = p;
        if(p == n) return k;
        if(A[p] == B[p]) res = helper(A, B, p + 1, k);
        else {
            vector<int> pos;
            while(q < n) {
                if(B[q] == A[p] && A[q] == B[p]) {
                    pos.clear();
                    pos.push_back(q);
                    break;
                }
                if(B[q] == A[p]) pos.push_back(q);
                q++;
            }
            for(int i = 0; i < pos.size(); i++) {
                swap(B[p], B[pos[i]]);
                tmp = helper(A, B, p + 1, k + 1);
                if(res > tmp) res = tmp;
                swap(B[p], B[pos[i]]);
            }  
        } 
        return res;
    }
    
    int kSimilarity(string A, string B) {
        return helper(A, B, 0, 0);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

