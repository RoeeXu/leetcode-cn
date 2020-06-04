/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1111.cpp
* Author:   roeexu
* Date:     2020-06-04 20:11:42
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(), 0);
        int A = 0, B = 0, i = 0;
        for(char& c : seq) {
            if(c == '(') {
                if(A <= B) A++;
                else {
                    B++;
                    res[i] = 1;
                }
            }
            else {
                if(A >= B) A--;
                else {
                    B--;
                    res[i] = 1;
                }
            }
            i++;
        }
        return res;
    }
    
    // vector<int> maxDepthAfterSplit(string seq) {
    //     if(seq.length() == 0) return {};
    //     int depth = 0, max_depth = 0;
    //     for(auto& c : seq) {
    //         if(c == '(') depth++;
    //         else depth--;
    //         max_depth = max(max_depth, depth);
    //     }
    //     int aim_depth = max_depth / 2;
    //     depth = 0;
    //     vector<int> res;
    //     for(auto& c : seq) {
    //         if(c == '(' && depth < aim_depth) {
    //             depth++;
    //             res.push_back(0);
    //         }
    //         else if(c == '(' && depth >= aim_depth) res.push_back(1);
    //         else if(c == ')' && depth > 0) {
    //             depth--;
    //             res.push_back(0);
    //         }
    //         else res.push_back(1);
    //     }
    //     return res;
    // }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

