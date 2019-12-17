/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0893.cpp
* Author:   root
* Date:     2019-12-18 03:43:37
* Brief:
****************************************************/

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> st;
        for (string word : A) {
            string even, odd;
            for (int i = 0; i < word.size(); ++i) {
                if (i % 2 == 0) even += word[i];
                else odd += word[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            st.insert(even + odd);
        }
        return st.size();
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

