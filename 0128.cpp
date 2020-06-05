/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0128.cpp
* Author:   root
* Date:     2020-06-06 03:14:23
* Brief:
****************************************************/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> save;
        int left, right, max_length = 0, cur_length;
        for(auto& num : nums) {
            if(save.count(num)) continue;
            if(save.count(num - 1)) left = save[num - 1];
            else left = 0;
            if(save.count(num + 1)) right = save[num + 1];
            else right = 0;
            cur_length = left + 1 + right;
            if(cur_length > max_length) max_length = cur_length;
            save[num - left] = save[num + right] = save[num] = cur_length;
        }
        return max_length;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

