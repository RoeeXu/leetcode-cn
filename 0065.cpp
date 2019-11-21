/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0065.cpp
* Author:   roeexu
* Date:     2019-11-21 15:15:43
* Brief:
****************************************************/

class Solution {
public:
    bool isNumber(string s) {
        int i=0, n=s.size();
        while(i < n && s[i] == ' ') i++;
        if(i<n && (s[i] == '+' || s[i] == '-')) i++;
        bool isNumeric = false;

        while(i<n && isdigit(s[i])) {
            i++;
            isNumeric = true;
        }
        if(i < n && s[i] == '.') {
            i++;
            while(i<n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }
        if(isNumeric) {
            if(i < n && s[i] == 'e'){
                i++;
                isNumeric = false;
                if(i<n && (s[i] == '+' || s[i] == '-')) i++;

                while(i<n && isdigit(s[i])) {
                    i++;
                    isNumeric = true;
                }
            }
        } 
        while(i < n && s[i] == ' ') i++;
        return isNumeric && i == n;
        
    }


    // bool isFloat(string s)
    // {
    //     int p = s.length() - 1;
    //     if(p == 0 && s[0] == '.') return 0;
    //     if(p < 0) return 0;
    //     int n = 0, flag = 1;
    //     while(p >= 0 && ((s[p] >= '0' && s[p] <= '9') || s[p] == '.'))
    //     {
    //         if(s[p] == '.')
    //         {
    //             if(flag) flag = 0;
    //             else return 0;
    //         }
    //         if(s[p] >= '0' && s[p] <= '9') n += 1;
    //         p -= 1;
    //     }
    //     if(p > 0) return 0;
    //     else if(p == 0 && (s[0] == '+' || s[0] == '-') && n > 0) return 1;
    //     else if(p < 0) return 1;
    //     else return 0;
    // }

    // bool isInteger(string s)
    // {
    //     int p = s.length() - 1;
    //     if(p < 0) return 0;
    //     int n = 0;
    //     while(p >= 0 && s[p] >= '0' && s[p] <= '9')
    //     {
    //         p -= 1;
    //         n += 1;
    //     }
    //     if(p > 0) return 0;
    //     else if(p == 0 && (s[0] == '+' || s[0] == '-') && n > 0) return 1;
    //     else if(p < 0) return 1;
    //     else return 0;
    // }

    // bool isNumber(string s) {
    //     int left = 0, right = s.length() - 1;
    //     if(right == -1) return 0;
    //     while(left <= right && s[left] == ' ') left++;
    //     while(left <= right && s[right] == ' ') right--;
    //     if(left > right) return 0;
    //     s = s.substr(left, right - left + 1);
    //     int e_pos = s.find('e');
    //     if(e_pos != -1)
    //     {
    //         string a = s.substr(0, e_pos);
    //         string b = s.substr(e_pos + 1);
    //         if(a.length() == 0 || a[a.length() - 1] == ' ') return 0;
    //         if(b.length() == 0 || b[0] == ' ') return 0;
    //         return isFloat(a) && isInteger(b);
    //     }
    //     else return isFloat(s);
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

