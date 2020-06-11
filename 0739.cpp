/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0739.cpp
* Author:   roeexu
* Date:     2020-06-11 20:05:33
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        if(n == 1) return res;
        for(int i = n - 2; i >= 0; i--) {
            int j = i + 1;
            while(T[j] <= T[i]) {
                if(res[j] == 0) break;
                j += res[j];
            }
            res[i] = T[j] > T[i] ? j - i : 0;
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

