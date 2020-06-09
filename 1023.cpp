/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1023.cpp
* Author:   roeexu
* Date:     2020-06-09 14:37:54
* Brief:
****************************************************/
 
class Solution {
public:
    bool match(string& query, string& pattern) {
        int a = 0, b = 0, A = query.length(), B = pattern.length();
        while(a < A && b < B) {
            if(query[a] <= 'Z')
                if(query[a] != pattern[b]) return false;
                else b++;
            else if(query[a] == pattern[b]) b++;
            a++;
        }
        if(b == B) {
            while(a < A) if(query[a] <= 'Z') return false; else a++;
            return true;
        }
        return false;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for(auto& query : queries) res.push_back(match(query, pattern));
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

