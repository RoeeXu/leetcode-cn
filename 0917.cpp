/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0917.cpp
* Author:   root
* Date:     2019-11-25 18:46:35
* Brief:
****************************************************/

#define bug(S, l) ((S[l] >= 'A' && S[l] <= 'Z') || (S[l] >= 'a' && S[l] <= 'z'))

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.length() - 1;
        while(l < r)
        {
            if(bug(S, l) && bug(S, r))
            {
                swap(S[l], S[r]);
                l++;
                r--;
            }
            else if(bug(S, l)) r--;
            else l++;
        }
        return S;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

