/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0838.cpp
* Author:   roeexu
* Date:     2020-01-03 16:26:22
* Brief:
****************************************************/

class Solution {
public:
    void helper(string& s, int l, int r) {
        if(s[l] == 'R' && s[r] == 'L') while(l < r) {s[l++] = 'R'; s[r--] = 'L';}
        else if(s[l] == 'R') for(int i = l; i <= r; i++) s[i] = 'R';
        else if(s[r] == 'L') for(int i = l; i <= r; i++) s[i] = 'L';
    }

    string pushDominoes(string dominoes) {
        int n = dominoes.length(), l, r;
        for(int i = 0; i < n; i++)
            if(dominoes[i] == '.' && (i == 0 || dominoes[i - 1] != '.'))
            {
                l = i, r = i;
                while(l >= 0 && dominoes[l] == '.') l--;
                while(r < n && dominoes[r] == '.') r++;
                if(l == -1) l = 0;
                if(r == n) r = n - 1;
                helper(dominoes, l, r);
            }
        return dominoes;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

