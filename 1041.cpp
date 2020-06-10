/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     1041.cpp
* Author:   roeexu
* Date:     2020-06-10 10:47:01
* Brief:
****************************************************/
 
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, p = 0;
        vector<vector<int>> pos = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        for(auto& c : instructions) {
            if(c == 'G') {
                x += pos[p][0];
                y += pos[p][1];
            }
            else if(c == 'L') p = (p + 1) % 4;
            else p = (p + 3) % 4;
        }
        if(p == 0 && x == 0 && y == 0) return true;
        if(p != 0) return true;
        return false;
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

