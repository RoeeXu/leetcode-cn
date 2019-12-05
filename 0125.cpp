/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0125.cpp
* Author:   root
* Date:     2019-12-06 02:41:52
* Brief:
****************************************************/

class Solution {
public:
    // stl
    bool isPalindrome(string s) {
        int len = s.size();
        int i = 0, j = len - 1;
        while(i < j){
            while(!std::isalnum(s[i]) && i < j) { i++;}
            while(!std::isalnum(s[j]) && j > i) {j--;}
            int t = std::isalpha(s[i]) ? std::tolower(s[i]) : s[i];
            int p = std::isalpha(s[j]) ? std::tolower(s[j]) : s[j];
            if(t != p){
                return false;
            } else{
                i++;
                j--;
            }
        }
        return true;
    }

    // mine
    // bool isPalindrome(string s) {
    //     if(s.length() == 0) return 1;
    //     int l = 0, r = s.length() - 1;
    //     while(l < r)
    //     {
    //         if(!((s[l] <= 'z' && s[l] >= 'a') || (s[l] <= 'Z' && s[l] >= 'A') || (s[l] <= '9' && s[l] >= '0'))) l++;
    //         else if(!((s[r] <= 'z' && s[r] >= 'a') || (s[r] <= 'Z' && s[r] >= 'A') || (s[r] <= '9' && s[r] >= '0'))) r--;
    //         else if((s[l] <= 'Z' && s[l] >= 'A' && s[l] - s[r] == 'A' - 'a') || (s[r] <= 'Z' && s[r] >= 'A' && s[l] - s[r] == 'a' - 'A') || s[l] - s[r] == 0) {l++; r--;}
    //         else return 0;
    //     }
    //     return 1;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

