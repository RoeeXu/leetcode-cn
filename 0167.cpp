/***************************************************
* Copyright (c) 2021 Roee Xu. All Rights Reserved
****************************************************
* File:     0167.cpp
* Author:   roeexu
* Date:     2021-02-18 21:38:43
* Brief:
****************************************************/
 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0, tail = numbers.size() - 1, tmp;
        while(head < tail)
        {
            tmp = numbers[head] + numbers[tail];
            if(tmp == target) return {head + 1, tail + 1};
            else if(tmp > target) tail--;
            else head++;
        }
        return {};
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

