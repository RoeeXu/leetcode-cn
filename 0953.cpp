/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0953.cpp
* Author:   root
* Date:     2019-12-26 07:16:57
* Brief:
****************************************************/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() <= 1) return true;
        int nums[26];
        for (int i = 0; i < 26; i++) nums[order[i] - 'a'] = i;
        for (int i = 0; i < words.size() - 1; i++)
        {
            string str1 = words[i];
            string str2 = words[i + 1];
            int j;
            for (j = 0; j < str1.size() && j < str2.size(); j++)
            {
                if (str1[j] == str2[j]) continue;
                else if (nums[str1[j] - 'a'] < nums[str2[j] - 'a']) break;
                else return false;
            }
            if (j == str2.size() && str1.size() > str2.size()) return false;
        }
        return true;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

