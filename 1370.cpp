/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1370.cpp
* Author:   roeexu
* Date:     2020-06-12 12:11:13
* Brief:
****************************************************/
 
class Solution {
public:
    string sortString(string s) {
        vector<int> save(26, 0);
        for(auto& c : s) save[c - 'a']++;
        string res;
        while(res.size() < s.size()) {
            for(int i = 0; i < 26; i++) if(save[i]) res += i + 'a', save[i]--;
            for(int i = 25; i >= 0; i--) if(save[i]) res += i + 'a', save[i]--;
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

