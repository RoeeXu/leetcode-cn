/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     1190.cpp
* Author:   root
* Date:     2021-07-27 14:05:56
* Brief:
****************************************************/
 
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> stk;
        vector<int> pos(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')')
            {
                pos[i] = stk.top();
                pos[stk.top()] = i;
                stk.pop();
            }
        }
        string res = "";
        int now = 0, step = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[now] == '(' || s[now] == ')')
            {
                now = pos[now];
                step = -step;
            }
            else
                res += s[now];
            now += step;
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

