/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0989.cpp
* Author:   roee
* Date:     2020-07-02 01:20:16
* Brief:
****************************************************/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n  = A.size();
        int i = n - 1;
        int k = K, t = 0;
        while(k != 0 && i != -1) {
            A[i] += k % 10 + t;
            t = A[i] / 10;
            A[i] %= 10;
            k /= 10;
            i--;
        }
        while(i != -1 && k == 0 && t != 0) {
            A[i] += t;
            t = A[i] / 10;
            A[i] %= 10;
            i--;
        }
        while(i == -1 && k != 0) {
            A.insert(A.begin(), k % 10 + t);
            t = A[0] / 10;
            A[0] %= 10;
            k /= 10;
        }
        if(t != 0) A.insert(A.begin(), t);
        return A;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
