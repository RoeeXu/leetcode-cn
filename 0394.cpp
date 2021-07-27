/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0394.cpp
* Author:   root
* Date:     2021-07-27 22:12:34
* Brief:
****************************************************/
 
class Solution {
public:
    int helper(string& s, string& t, int p)
    {
        string num;
        while (p < s.length())
        {
            if (s[p] >= 'a' && s[p] <= 'z')
                t += s[p];
            else if (s[p] >= '0' && s[p] <= '9')
                num += s[p];
            else if (s[p] == '[')
            {
                string tt;
                p = helper(s, tt, p + 1);
                int k = atoi(num.c_str());
                num = "";
                while (k--) t += tt;
            }
            else
                return p;
            p++;
        }
        return p;
    }

    string decodeString(string s) {
        string t;
        helper(s, t, 0);
        return t;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

