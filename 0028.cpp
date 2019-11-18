/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0028.cpp
* Author:   roee
* Date:     2019-11-18 23:27:04
* Brief:
****************************************************/

class Solution {
public:
    void make_next(const char *string, int *next)
    {
        int k = 0;
        int m = strlen(string);
        next[0] = 0;
        for(int i = 1; i < m; i++)
        {
            while(k > 0 && string[i] != string[k])
                k = next[k - 1];
            if(string[i] == string[k])
                k++;
            next[i] = k;
        }
    }

    int kmp_first(const char *source, const char *str)
    {
        int n = strlen(source);
        int m = strlen(str);
        if(m == 0) return 0;
        int *next = new int[m];
        make_next(str, next);
        for(int i = 0, k = 0; i < n; i++)
        {
            while(k > 0 && str[k] != source[i])
                k = next[k - 1];
            if(str[k] == source[i])
                k++;
            if(k == m) return i - m + 1;
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        return kmp_first(haystack.c_str(), needle.c_str());
    }
    
    
    // int strStr(string haystack, string needle) {
    //     return haystack.find(needle);
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

