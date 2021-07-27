/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0560.cpp
* Author:   root
* Date:     2021-07-28 02:11:06
* Brief:
****************************************************/
 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1, 0);
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + nums[i];
        unordered_map<int, int> cnt;
        for (auto x : s) cnt[x]++;
        int res = 0;
        for (auto x : s)
        {
            cnt[x]--;
            res += cnt[x + k];
        }
        return res;  
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

