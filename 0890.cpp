/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0890.cpp
* Author:   roeexu
* Date:     2020-01-15 15:14:11
* Brief:
****************************************************/
 
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_set<char> p(pattern.begin(), pattern.end());
        vector<string> res;
        for(auto& word : words) {
            unordered_set<char> w(word.begin(), word.end());
            if(w.size() == p.size() && word.length() == pattern.length()) {
                unordered_map<char, char> link;
                int flag = 1;
                for(int i = 0; i < word.length(); i++)
                    if(link.count(word[i]) == 0) link[word[i]] = pattern[i];
                    else if(link.count(word[i]) > 0 && link[word[i]] != pattern[i]) {flag = 0; break;}
                if(flag) res.push_back(word);
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

