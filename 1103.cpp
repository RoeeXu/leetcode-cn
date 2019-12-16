/***************************************************
* Copyright (c) 2019 Roee Xu. All Rights Reserved
****************************************************
* File:     1103.cpp
* Author:   roeexu
* Date:     2019-12-16 11:21:34
* Brief:
****************************************************/

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> v(num_people, 0);
        int can = 1, index = 0;
        while(candies - can >= 0)
        {
            v[index++ % num_people] += can;
            candies -= can++;
        }
        v[index % num_people] += candies;
        return v;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

