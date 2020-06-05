/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1071.cpp
* Author:   roeexu
* Date:     2020-06-05 18:24:02
* Brief:
****************************************************/
 
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd((int)str1.length(), (int)str2.length()));
    }
    // string gcdOfStrings(string str1, string str2) {
    //     int tmp = strcmp(str1.c_str(), str2.c_str());
    //     if(tmp == 0) return str1;
    //     else if(tmp > 0) return gcdOfStrings(str2, str1);
    //     else {
    //         string str3 = str2.substr(0, str1.length()), str4 = str2.substr(str1.length());
    //         if(str3 == str1) return gcdOfStrings(str4, str1);
    //         else return "";
    //     }
    //     return "";
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

