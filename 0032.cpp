/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0032.cpp
* Author:   roeexu
* Date:     2019/11/13 15:47:26
* Brief:
****************************************************/

class Solution {
public:
    // dp
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n <= 1) return 0;
        int dp[n], m = 0;
        dp[0] = 0;
        for(int i = 1; i < n; i++)
        {
            if(s[i] == '(') dp[i] = 0;
            else
            {
                if(s[i - 1] == '(') dp[i] = 2 + ((i >= 2) ? dp[i - 2] : 0);
                else if(i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0);
                else dp[i] = 0;
            }
            if(dp[i] > m) m = dp[i];
        }
        return m;
    }

    // stack
    // int longestValidParentheses(string s) {
    //     stack<int> mystack;
    //     int start = 0;
    //     int ans = 0;
    //     for(int i=0;i<s.length();++i){
    //         if(s[i] == '('){
    //             mystack.push(i);
    //         }
    //         else{
    //             if(mystack.empty()){
    //                 start = i+1;
    //             }
    //             else{
    //                  mystack.pop();
    //             }
    //             ans = max(ans,mystack.empty() ? i-start+1 : i-mystack.top());
    //         }
    //     }
    //     return ans
    // }

    // forward & backward
    // int longestValidParentheses(string s) {
    //     int k = 0, n = s.length(), l = 0, m = 0;
    //     for(int i = 0; i < n; i++)
    //     {
    //         if(s[i] == '(') k++;
    //         else k--;
    //         while(l <= i && k < 0)
    //         {
    //             if(s[l] == '(') k--;
    //             else k++;
    //             l++;
    //         }
    //         if(k == 0 && i - l + 1 > m) m = i - l + 1;
    //     }
    //     k = 0;
    //     l = n - 1;
    //     for(int i = 0; i < n; i++)
    //     {
    //         if(s[n - 1 - i] == ')') k++;
    //         else k--;
    //         while(l >= n - 1 - i && k < 0)
    //         {
    //             if(s[l] == ')') k--;
    //             else k++;
    //             l--;
    //         }
    //         if(k == 0 && l - n + 1 + i + 1 > m) m = l - n + 1 + i + 1;
    //     }
    //     return m;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

