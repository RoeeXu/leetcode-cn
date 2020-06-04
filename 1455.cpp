/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1455.cpp
* Author:   roeexu
* Date:     2020-06-04 11:06:23
* Brief:
****************************************************/
 
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string str;
        for (int i = 1; ss >> str; i ++)
            if (str.find(searchWord) == 0) return i;
        return -1;
    }
    
    // int isPrefixOfWord(string sentence, string searchWord) {
    //     int res = 0, n = sentence.length(), flag;
    //     for(int i = 0; i < n; i++) {
    //         if(sentence[i] == ' ') res++;
    //         else {
    //             flag = 1;
    //             for(int j = 0; j < searchWord.length(); j++) {
    //                 if(sentence[i] == ' ') {
    //                     flag = 0;
    //                     break;
    //                 }
    //                 else if(i + j < n && searchWord[j] == sentence[i + j]) continue;
    //                 else {
    //                     flag = 0;
    //                     break;
    //                 }
    //             }
    //             if(flag == 1) return res + 1;
    //             while(i < n && sentence[i] != ' ') i++;
    //             res++;
    //         }
    //     }
    //     return -1;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

