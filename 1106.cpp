/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1106.cpp
* Author:   roeexu
* Date:     2019-12-16 11:04:46
* Brief:
****************************************************/

class Solution {
public:
    // 栈
    bool parseBoolExpr(string expression) {
        stack<char> symbol;
        stack<char> values;
        for(auto c : expression)
        {
            if(c == '!' || c == '&' || c == '|') symbol.push(c);
            else if(c == ')')
            {
                char b = symbol.top();
                bool r = (values.top() == 't');
                symbol.pop();
                while(values.top() != '(')
                {
                    if(b == '|') r |= (values.top() == 't');
                    else if(b == '&') r &= (values.top() == 't');
                    else r = (values.top() == 'f');
                    values.pop();
                }
                values.pop();
                values.push(r ? 't' : 'f');
            }
            else if(c == ',') continue;
            else values.push(c);
        }
        return values.top() == 't';
    }

    // 递归
    // bool helper(string& expression, int l, int r)
    // {
    //     if(expression[l] == 't') return 1;
    //     if(expression[l] == 'f') return 0;
    //     char c = expression[l];
    //     int p = l + 2, q = l + 2, v = 0;
    //     vector<bool> res;
    //     while(p < r - 1)
    //     {
    //         if(expression[p] == '(') v++;
    //         else if(expression[p] == ')') v--;
    //         else if(expression[p] == ',' && v == 0)
    //         {
    //             res.push_back(helper(expression, q, p));
    //             q = p + 1;
    //             p = q;
    //         }
    //         p++;
    //     }
    //     res.push_back(helper(expression, q, p));
    //     if(c == '!') return !res[0];
    //     if(c == '&')
    //     {
    //         bool x = res[0];
    //         for(auto y : res) x &= y;
    //         return x;
    //     }
    //     if(c == '|')
    //     {
    //         bool x = res[0];
    //         for(auto y : res) x |= y;
    //         return x;
    //     }
    //     return 0;
    // }
    
    // bool parseBoolExpr(string expression) {
    //     return helper(expression, 0, expression.length());
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */
