/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0828.cpp
* Author:   root
* Date:     2019-11-25 16:06:10
* Brief:
****************************************************/

class Solution {
public:
    int uniqueLetterString(string S) {
        int res = 0, n = S.length(), a;
        int first[26] = {0}, second[26] = {0};
        for(int i = 0; i < n; i++)
        {
            a = S[i] - 'A';
            if(first[a] != second[a]) 
                res += (i + 1 - first[a]) * (first[a] - second[a]);
            second[a] = first[a];
            first[a] = i + 1;
        }
        for(int i = 0; i < 26; i++)
            if(first[i] != second[i]) 
                res += (n + 1 - first[i]) * (first[i] - second[i]);
        return res;
    }

    // int uniqueLetterString(string S) {
    //     int res = 0, n = S.size(), cur = 0, g = 1e9 + 7, a;
    //     int first[26] = {0}, second[26] = {0};
    //     for(int i = 0; i < n; i++)
    //     {
    //         a = S[i] - 'A';
    //         cur += 1 + i - first[a] * 2 + second[a];
    //         res += cur;
    //         res %= g;
    //         second[a] = first[a];
    //         first[a] = i + 1;
    //     }
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

