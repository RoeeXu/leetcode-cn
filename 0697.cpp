/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0697.cpp
* Author:   roeexu
* Date:     2021-02-20 16:44:46
* Brief:
****************************************************/
 
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> save;
        for(int i = 0; i < nums.size(); i++)
        {
            if(save.count(nums[i]))
            {
                save[nums[i]][2] = i;
                save[nums[i]][0]++;
            }
            else save[nums[i]] = {1, i, i};
        }
        int res = nums.size(), tmp, degree = 0;
        for(auto it = save.begin(); it != save.end(); it++)
        {
            tmp = it->second[2] - it->second[1] + 1;
            if(degree == it->second[0])
                res = min(res, tmp);
            else if(degree < it->second[0])
            {
                res = tmp;
                degree = it->second[0];
            }
        }
        return res;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

