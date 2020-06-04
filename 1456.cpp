/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1456.cpp
* Author:   roeexu
* Date:     2020-06-04 11:18:47
* Brief:
****************************************************/
 
class Solution {
public:
    int aeiou(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
        return 0;
    }
    
    int maxVowels(string s, int k) {
        int num = 0, res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i >= k && aeiou(s[i - k])) num--;
            if(aeiou(s[i])) num++;
            if(i >= k - 1) res = max(res, num);
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

