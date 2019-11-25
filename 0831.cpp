/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0831.cpp
* Author:   root
* Date:     2019-11-25 16:24:27
* Brief:
****************************************************/

class Solution {
public:
    string maskPII(string S) {
        int p = S.find('@'), gap = 'A' - 'a', n = S.length();
        string log = "";
        if(p != -1)
        {
            log += (S[0] >= 'A' && S[0] <= 'Z') ? S[0] - gap : S[0];
            log += "*****";
            log += (S[p - 1] >= 'A' && S[p - 1] <= 'Z') ? S[p - 1] - gap : S[p - 1];
            log += '@';
            for(int i = p + 1; i < n; i++)
                log += (S[i] >= 'A' && S[i] <= 'Z') ? S[i] - gap : S[i];
        }
        else
        {
            string tmp = "";
            int cnt = 0;
            for(int i = n - 1; i >= 0; i--)
                if(S[i] >= '0' && S[i] <= '9')
                {
                    if(tmp.length() < 4)
                        tmp += S[i];
                    cnt++;
                }
            reverse(tmp.begin(), tmp.end());
            if(cnt > 10)
            {
                log += '+';
                while(cnt-- > 10)
                    log += '*';
                log += "-";
            }
            log += "***-***-" + tmp;
        }
        return log;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

