/***************************************************
* Copyright (c) 2020 Roee Xu. All Rights Reserved
****************************************************
* File:     0836.cpp
* Author:   roeexu
* Date:     2020-01-03 15:58:21
* Brief:
****************************************************/

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec2[2] <= rec1[0] || rec2[3] <= rec1[1] || rec2[0] >= rec1[2] || rec2[1] >= rec1[3]);
    }
};

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100 */

