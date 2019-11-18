/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     0001.cpp
* Author:   roee
* Date:     2019-11-18 23:13:56
* Brief:
****************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        for(int i=0;i<nums.size();i++)
        {
            if(hashmap.count(target - nums[i]) == 1)
            {
                return vector<int>({hashmap[target - nums[i]], i});
            }
            hashmap[nums[i]] = i;
        }
        return vector<int>({});
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

