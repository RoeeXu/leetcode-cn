/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1408.cpp
* Author:   roeexu
* Date:     2020-06-24 15:47:16
* Brief:
****************************************************/
 
bool cmp(string& x, string& y) {
    return x.length() < y.length();
}

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(words[j].find(words[i]) != -1) {
                    res.push_back(words[i]);
                    break;
                }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

