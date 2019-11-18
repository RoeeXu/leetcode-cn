/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0049.cpp
* Author:   roee
* Date:     2019-11-19 00:41:55
* Brief:
****************************************************/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> saver;
        vector<vector<string>> res;
        for(auto& str : strs)
        {
            string tmp(str);
            sort(tmp.begin(), tmp.end());
            if(saver.count(tmp) == 0)
            {
                saver[tmp] = res.size();
                res.push_back(vector<string>({str}));
            }
            else res[saver[tmp]].push_back(str);
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

