/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1720.cpp
* Author:   roeexu
* Date:     2021-01-20 21:47:36
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> arr(n + 1);
        arr[0] = first;
        for(int i = 1; i <= n; i++)
            arr[i] = arr[i - 1] ^ encoded[i - 1];
        return arr;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

