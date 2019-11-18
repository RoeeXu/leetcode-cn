/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0014.cpp
* Author:   roee
* Date:     2019-11-18 23:21:56
* Brief:
****************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0) return res;
        for(int i=0;i<strs[0].length();i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j][i] != strs[0][i])
                    return res;
            }
            res += strs[0][i];
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

