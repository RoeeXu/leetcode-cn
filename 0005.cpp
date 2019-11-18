/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0005.cpp
* Author:   roee
* Date:     2019-11-18 23:17:03
* Brief:
****************************************************/

class Solution {
public:
    string init(string s){
        int len = s.length();
        string ans = "$";
        for(int i = 0; i < len; i++){
            ans += ("#");
            ans += s[i];
        }
        ans += "#^";
        return ans;
    }
    string Manacher(string s, int slen, string ys){
        int id = 0, mx = 0, po = 0, ans = 0;
        vector<int> ve(slen + 5, 0);
        for(int i = 1; i < slen; i++){
            if(i < mx){
                ve[i] = min(ve[2 * id - i], mx - i);
            }
            else{
                ve[i] = 1;
            }
            while(s[i - ve[i]] == s[i + ve[i]]){
                ve[i]++;
            }
            if(mx < (i + ve[i])){
                id = i;
                mx = i + ve[i];
            }
            if(ve[i] - 1 > ans){
                ans = ve[i] - 1;
                po = i;
            }

        }
        //cout << po << " " << ans << endl;
        //cout << s << endl;
        //string anss = ys.substr((po - ans - 1) / 2, ans);
        //cout << anss << endl;
        //return anss;
        auto start = ys.cbegin() + (po - ans - 1) / 2;
        return string(start, start + ans);
    }
    string longestPalindrome(string s) {
        string nowS = init(s);
        return Manacher(nowS, nowS.length(), s);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

