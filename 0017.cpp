/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0017.cpp
* Author:   roee
* Date:     2019-11-18 23:23:51
* Brief:
****************************************************/

class Solution {
public:
    vector<string> deepwalk(string digits, int pos, vector<string>& tmp)
    {
        if(int(digits.length()) <= pos) return tmp;
        char target = digits[pos];
        vector<string> res;
        res.clear();
        vector<string> saver{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string now = saver[target - '2'];
        for(int i=0;i<int(tmp.size());i++)
            for(int j=0;j<int(now.length());j++)
            {
                res.push_back(tmp[i] + now[j]);
            }
        tmp.clear();
        return deepwalk(digits, pos + 1, res);
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        res.clear();
        if(int(digits.length()) == 0) return res;
        res.push_back("");
        return deepwalk(digits, 0, res);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

