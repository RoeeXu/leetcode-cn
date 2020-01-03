/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0839.cpp
* Author:   roeexu
* Date:     2020-01-03 17:40:29
* Brief:
****************************************************/
 
class Solution {
public:
    bool similar(string& x, string& y) {
        if(x.length() != y.length()) return 0;
        int n = x.length(), l = 0, r = n - 1;
        while(l < n && x[l] == y[l]) l++;
        while(r > -1 && x[r] == y[r]) r--;
        if(l == n || r == -1) {
            set<int> d;
            for(int i = 0; i < n; i++) {
                if(d.count(x[i]) > 0) return 1;
                else d.insert(x[i]);
            }
            return 0;
        }
        if(x[l] != y[r] || x[r] != y[l]) return 0;
        for(int i = l + 1; i < r; i++) if(x[i] != y[i]) return 0;
        return 1;
    }
    
    void helper(vector<string>& A, vector<int>& B, int a) {
        int n = A.size();
        for(int i = 0; i < n; i++)
            if(i == B[i] || B[i] != B[a])
                if(similar(A[i], A[a]))
                {
                    B[i] = -abs(B[a]);
                    helper(A, B, i);
                }
    }
    
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        vector<int> B(n, 0);
        for(int i = 0; i < n; i++) B[i] = i + 1;
        for(int i = 0; i < n; i++)
            if(B[i] > 0)
                helper(A, B, i);
        set<int> C(B.begin(), B.end());
        return C.size();
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

