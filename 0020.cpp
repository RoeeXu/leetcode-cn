/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0020.cpp
* Author:   roee
* Date:     2019-11-18 23:24:36
* Brief:
****************************************************/

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') t.push(s[i]);
            else {
                if (t.empty()) return false;
                if (s[i] == ')' && t.top() != '(') return false;
                if (s[i] == ']' && t.top() != '[') return false;
                if (s[i] == '}' && t.top() != '{') return false;
                t.pop();
            }
        }
        return t.empty();
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

