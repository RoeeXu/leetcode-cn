/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1404.cpp
* Author:   roeexu
* Date:     2020-06-05 19:50:39
* Brief:
****************************************************/
 
class Solution {
public:
    int numSteps(string s) {
        int step = 0;
        while(s != "1") {
            step++;
            if(s.back() == '0') s.pop_back();
            else {
                for(int i = s.length() - 1; i >= 0; i--) {
                    if(s[i] == '1') {
                        s[i] = '0';
                        if(i == 0) {
                            s = '1' + s; 
                            break;
                        }
                    }
                    else {
                        s[i] = '1';
                        break;
                    }
                }
            }
        }
        return step;
    }
    
    // 递归会很慢
    // int numSteps(string s) {
    //     int n = s.size();
    //     if(n == 1) return 0;
    //     if(s[n - 1] == '0') return 1 + numSteps(s.substr(0, n - 1));
    //     bool tmp = 1;
    //     for(int i = n - 1; i >= 0; i--) {
    //         if(s[i] == '1') s[i] = '0';
    //         else {
    //             s[i] = '1';
    //             tmp = 0;
    //             break;
    //         }
    //     }
    //     if(tmp) s = '1' + s;
    //     return 1 + numSteps(s);
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

